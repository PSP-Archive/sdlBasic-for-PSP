/*
 * PSP Software Development Kit - http://www.pspdev.org
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * scr_printf.c - Debug screen functions.
 *
 * Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
 * Copyright (c) 2005 James Forshaw <tyranid@gmail.com>
 * Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
 *
 * $Id: scr_printf.c 2319 2007-09-30 15:58:31Z tyranid $
 */

#include <stdio.h>
#include <psptypes.h>
#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspsysclib.h>
#include <pspge.h>
#include <stdarg.h>
#include <pspdebug.h>
#include <string.h>

/* baseado nas libs do Duke... */

void  _pspDveScreenClearLine( int Y);
void pspDveScreenInit(int mode);
void pspDveScreenInitEx(void *vram_base, int mode, int setup);
void pspDveScreenPrintf(const char *fmt, ...) __attribute__((format(printf,1,2)));
void pspDveScreenKprintf(const char *format, ...) __attribute__((format(printf,1,2)));
void pspDveScreenEnableBackColor(int enable);
void pspDveScreenSetBackColor(u32 color);
void pspDveScreenSetTextColor(u32 color);
void pspDveScreenSetColorMode(int mode);
void pspDveScreenPutChar(int x, int y, u32 color, u8 ch);
void pspDveScreenSetXY(int x, int y);
void pspDveScreenSetOffset(int offset);
void pspDveScreenSetBase(u32* base);
int pspDveScreenGetX(void);
int pspDveScreenGetY(void);
void pspDveScreenClear(void);
int pspDveScreenPrintData(const char *buff, int size);
int pspDveScreenPuts(const char *str);

static int PSP_FIELD_OFFSET = 262;
static int PSP_SCREEN_HEIGHT = 480;
static int PSP_SCREEN_WIDTH = 720;
static int PSP_LINE_SIZE = 768;
static int X = 0, Y = 0;
static int MX=102, MY=60;
static u32 bg_col = 0, fg_col = 0xFFFFFFFF;
static int bg_enable = 1;
static void* g_vram_base = (u32 *) 0x04000000;
static int g_vram_offset = 0;
static int g_vram_mode = PSP_DISPLAY_PIXEL_FORMAT_8888;
static int init = 0;

static u16 convert_8888_to_565(u32 color)
{
	int r, g, b;

	b = (color >> 19) & 0x1F;
	g = (color >> 10) & 0x3F;
	r = (color >> 3) & 0x1F;

	return r | (g << 5) | (b << 11);
}

static u16 convert_8888_to_5551(u32 color)
{
	int r, g, b, a;

	a = (color >> 24) ? 0x8000 : 0;
	b = (color >> 19) & 0x1F;
	g = (color >> 11) & 0x1F;
	r = (color >> 3) & 0x1F;

	return a | r | (g << 5) | (b << 10);
}

static u16 convert_8888_to_4444(u32 color)
{
	int r, g, b, a;

	a = (color >> 28) & 0xF;
	b = (color >> 20) & 0xF;
	g = (color >> 12) & 0xF;
	r = (color >> 4) & 0xF;

	return (a << 12) | r | (g << 4) | (b << 8);
}

static void clear_screen_16(u16 color)
{
	 int x;
	 u16 *vram = g_vram_base;

	vram += (g_vram_offset >> 1);

	 for(x = 0; x < (PSP_LINE_SIZE * PSP_SCREEN_HEIGHT); x++)
	 {
		*vram++ = color;
	 }
}

static void clear_screen_32(u32 color)
{
	 int x;
	 u32 *vram = g_vram_base;
	 vram +=	(g_vram_offset>>2);

	 for(x = 0; x < (PSP_LINE_SIZE * PSP_SCREEN_HEIGHT); x++)
	 {
		*vram++ = color;
	 }
}

static void clear_screen(u32 color)
{
	if(g_vram_mode == PSP_DISPLAY_PIXEL_FORMAT_8888)
	{
		clear_screen_32(color);
	}
	else
	{
		u16 c = 0;
		switch(g_vram_mode)
		{
			case PSP_DISPLAY_PIXEL_FORMAT_565:
			c = convert_8888_to_565(color);
			break;
			case PSP_DISPLAY_PIXEL_FORMAT_5551:
			c = convert_8888_to_5551(color);
			break;
			case PSP_DISPLAY_PIXEL_FORMAT_4444:
			c = convert_8888_to_4444(color);
			break;
		};
		clear_screen_16(c);
	}
}

void pspDveScreenInitEx(void *vram_base, int mode, int setup)
{
	switch(mode)
	{
		case PSP_DISPLAY_PIXEL_FORMAT_565:
		case PSP_DISPLAY_PIXEL_FORMAT_5551:
		case PSP_DISPLAY_PIXEL_FORMAT_4444:
		case PSP_DISPLAY_PIXEL_FORMAT_8888:
		break;
		default:
		mode = PSP_DISPLAY_PIXEL_FORMAT_8888;
	};

	X = Y = 0;
	/* Place vram in uncached memory */
	if(vram_base == NULL)
	{
		vram_base = (void*)(0x40000000 | ((u32)sceGeEdramGetAddr() + sceGeEdramGetSize() - 768*4*503));
	}
	g_vram_base = vram_base;
	g_vram_offset = 0;
	g_vram_mode = mode;
	if(setup)
	{
		switch (setup & 0x7f)
		{
			case 0:
			// composite
			pspDveMgrSetVideoOut(2, 0x1d1, 720, 503, 1, 15, 0);
			PSP_SCREEN_HEIGHT = 503;
			break;
			case 1:
			// component progressive
			pspDveMgrSetVideoOut(0, 0x1d2, 720, 480, 1, 15, 0);
			PSP_SCREEN_HEIGHT = 480;
			break;
			case 2:
			// component interlace
			pspDveMgrSetVideoOut(0, 0x1d1, 720, 503, 1, 15, 0);
			PSP_SCREEN_HEIGHT = 503;
			break;
		}

		sceDisplaySetFrameBuf((void *) g_vram_base, PSP_LINE_SIZE, mode, 1);
	}
	clear_screen(bg_col);
	init = 1;
}

void pspDveScreenInit(int vmode)
{
	X = Y = 0;
	pspDveScreenInitEx(NULL, PSP_DISPLAY_PIXEL_FORMAT_8888, vmode|0x80);
}

void pspDveScreenEnableBackColor(int enable)
{
	bg_enable = enable;
}

void pspDveScreenSetBackColor(u32 colour)
{
	bg_col = colour;
}

void pspDveScreenSetTextColor(u32 colour)
{
	fg_col = colour;
}

void pspDveScreenSetColorMode(int mode)
{
	switch(mode)
	{
		case PSP_DISPLAY_PIXEL_FORMAT_565:
		case PSP_DISPLAY_PIXEL_FORMAT_5551:
		case PSP_DISPLAY_PIXEL_FORMAT_4444:
		case PSP_DISPLAY_PIXEL_FORMAT_8888:
		break;
		default:
		mode = PSP_DISPLAY_PIXEL_FORMAT_8888;
	};

	g_vram_mode = mode;
}

int pspDveScreenGetX()
{
	return X;
}

int pspDveScreenGetY()
{
	return Y;
}

void pspDveScreenClear()
{
	int y;

	if(!init)
	{
		return;
	}

	for(y=0;y<MY;y++)
	{
		_pspDveScreenClearLine(y);
	}

	pspDveScreenSetXY(0,0);
	clear_screen(bg_col);
}

void pspDveScreenSetXY(int x, int y)
{
	if( x<MX && x>=0 ) X=x;
	if( y<MY && y>=0 ) Y=y;
}

void pspDveScreenSetOffset(int offset)
{
	g_vram_offset = offset;
}

void pspDveScreenSetBase(u32* base)
{
	g_vram_base = base;
}

extern u8 msx[];

static void debug_put_char_32(int x, int y, u32 color, u32 bgc, u8 ch)
{
	int i,j, l;
	u8	*font;
	u32 *vram_ptr;
	u32 *vram1;
	u32 *vram2;

	if(!init)
	{
		return;
	}

	if (PSP_SCREEN_HEIGHT == 480)
	{
		vram1 = g_vram_base;
		vram1 += (g_vram_offset >> 2) + x;
		vram1 += y * PSP_LINE_SIZE;

		font = &msx[ (int)ch * 8];
		for (i=l=0; i < 8; i++, l+= 8, font++)
		{
			vram_ptr  = vram1;
			for (j=0; j < 8; j++)
			{
				if ((*font & (128 >> j)))
					*vram_ptr = color;
				else if(bg_enable)
					*vram_ptr = bgc;
				vram_ptr++;
			}
			vram1 += PSP_LINE_SIZE;
		}
	}
	else
	{
		vram1 = g_vram_base;
		vram1 += (g_vram_offset >> 3) + x;
		vram1 += (y>>1) * PSP_LINE_SIZE;
		vram2 = vram1;
		vram2 += PSP_FIELD_OFFSET * PSP_LINE_SIZE;

		font = &msx[ (int)ch * 8];
		for (i=l=0; i < 8; i++, l+= 8, font++)
		{
			vram_ptr  = (i & 1) ? vram1 : vram2;
			for (j=0; j < 8; j++)
			{
				if ((*font & (128 >> j)))
					*vram_ptr = color;
				else if(bg_enable)
					*vram_ptr = bgc;
				vram_ptr++;
			}
			if (i & 1)
				vram1 += PSP_LINE_SIZE;
			else
				vram2 += PSP_LINE_SIZE;
		}
	}
}

static void debug_put_char_16(int x, int y, u16 color, u16 bgc, u8 ch)
{
	int i,j, l;
	u8	*font;
	u16 *vram_ptr;
	u16 *vram1;
	u16 *vram2;

	if(!init)
	{
		return;
	}

	if (PSP_SCREEN_HEIGHT == 480)
	{
		vram1 = g_vram_base;
		vram1 += (g_vram_offset >> 1) + x;
		vram1 += y * PSP_LINE_SIZE;

		font = &msx[ (int)ch * 8];
		for (i=l=0; i < 8; i++, l+= 8, font++)
		{
			vram_ptr  = vram1;
			for (j=0; j < 8; j++)
			{
				if ((*font & (128 >> j)))
					*vram_ptr = color;
				else if(bg_enable)
					*vram_ptr = bgc;
				vram_ptr++;
			}
			vram1 += PSP_LINE_SIZE;
		}
	}
	else
	{
		vram1 = g_vram_base;
		vram1 += (g_vram_offset >> 1) + x;
		vram1 += (y>>1) * PSP_LINE_SIZE;
		vram2 = vram1;
		vram2 += PSP_FIELD_OFFSET * PSP_LINE_SIZE;

		font = &msx[ (int)ch * 8];
		for (i=l=0; i < 8; i++, l+= 8, font++)
		{
			vram_ptr  = (i & 1) ? vram1 : vram2;
			for (j=0; j < 8; j++)
			{
				if ((*font & (128 >> j)))
					*vram_ptr = color;
				else if(bg_enable)
					*vram_ptr = bgc;
				vram_ptr++;
			}
			if (i & 1)
				vram1 += PSP_LINE_SIZE;
			else
				vram2 += PSP_LINE_SIZE;
		}
	}
}

void
pspDveScreenPutChar( int x, int y, u32 color, u8 ch)
{
	if(g_vram_mode == PSP_DISPLAY_PIXEL_FORMAT_8888)
	{
		debug_put_char_32(x, y, color, bg_col, ch);
	}
	else
	{
		u16 c = 0;
		u16 b = 0;
		switch(g_vram_mode)
		{
			case PSP_DISPLAY_PIXEL_FORMAT_565:
			c = convert_8888_to_565(color);
			b = convert_8888_to_565(bg_col);
			break;
			case PSP_DISPLAY_PIXEL_FORMAT_5551:
			c = convert_8888_to_5551(color);
			b = convert_8888_to_5551(bg_col);
			break;
			case PSP_DISPLAY_PIXEL_FORMAT_4444:
			c = convert_8888_to_4444(color);
			b = convert_8888_to_4444(bg_col);
			break;
		};
		debug_put_char_16(x, y, c, b, ch);
	}
}

void  _pspDveScreenClearLine( int Y)
{
	int i;

	if(bg_enable)
	{
		for (i=0; i < MX; i++)
		{
			pspDveScreenPutChar( i*7 , Y * 8, bg_col, 219);
		}
	}
}

/* Print non-nul terminated strings */
int pspDveScreenPrintData(const char *buff, int size)
{
	int i;
	int j;
	char c;

	if(!init)
	{
		return 0;
	}

	for (i = 0; i < size; i++)
	{
		c = buff[i];
		switch (c)
		{
			case '\n':
			X = 0;
			Y ++;
			if (Y == MY)
			Y = 0;
			_pspDveScreenClearLine(Y);
			break;
			case '\t':
			for (j = 0; j < 5; j++) {
				pspDveScreenPutChar( X*7 , Y * 8, fg_col, ' ');
				X++;
			}
			break;
			default:
			pspDveScreenPutChar( X*7 , Y * 8, fg_col, c);
			X++;
			if (X == MX)
			{
				X = 0;
				Y++;
				if (Y == MY)
					Y = 0;
				_pspDveScreenClearLine(Y);
			}
		}
	}

	return i;
}

int pspDveScreenPuts(const char *str)
{
	return pspDveScreenPrintData(str, strlen(str));
}

void pspDveScreenPrintf(const char *format, ...)
{
	va_list	opt;
	char	buff[2048];
	int		bufsz;

	va_start(opt, format);
	bufsz = vsnprintf( buff, (size_t) sizeof(buff), format, opt);
	(void) pspDveScreenPrintData(buff, bufsz);
}

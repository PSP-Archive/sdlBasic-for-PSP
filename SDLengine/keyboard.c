/*
_________________________________________________________________________________________________________________________

    SDLengine core of sdlBasic



    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Library General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    __vroby__
    __vroby__@libero.it

_________________________________________________________________________________________________________________________

*/

#include "SDLengine.h"

//_________________________________________________________________________________________________________________________

// KEYBOARD
//_________________________________________________________________________________________________________________________

//key(keycode)								: return 1 if is press the key keycode
int key (int keycode)
{
	Uint8 *keystate;
	//deniska::: adding mapping for some common gaming keys
	switch(keycode) {
		case  273: return getbuttonjoystick(0,8); //up
		case  274: return getbuttonjoystick(0,6); //down
		case  276: return getbuttonjoystick(0,7); //left
		case  275: return getbuttonjoystick(0,9); //right
		case  27: return getbuttonjoystick(0,12); //escape ->home
		case  13: return getbuttonjoystick(0,2); //return->X
		case  32: return getbuttonjoystick(0,1); //space->O
	}
	if (keycode<1 ||keycode>512){
	    error_description="SDLengine error - key: invalid keycode value ";
	    error_type=1;
	    SDLerr(stderr, "SDLengine error- key: %d is an invalid keycode value", keycode);
	    return -1;
	}
	if (autotimer()!=0)return -1;
	getevent();
	keystate = SDL_GetKeyState(NULL);
	if (keystate[keycode])return 1;
	return 0;
}
//_______________________________________________________________________________________________________________________

//inkey									: return ascii code of key press
//deniska mapping some joystick buttons...

int lookuparr[] = { -1, 32, 13, -1, -1, 274,276,273,275,-1,-1,27,-1,-1};
int inkey()
{

	if (autotimer()!=0)return -1;
	int i;
	for ( i=0; i<13; i++) {
		if (getbuttonjoystick(0,i)==1) return lookuparr[i];
	}
	
	getevent();
	return lastkey;
}
//_______________________________________________________________________________________________________________________

//waitkey(keycode)			: wait a key pression (-1 =any key)
int waitkey(int keycode)
{
	if (keycode==0)
		while(inkey()==0){
		    if (autotimer()!=0)return -1;
		}
	else
		while(inkey()!=keycode){
		    if (autotimer()!=0)return -1;
		}
	return 0;
}

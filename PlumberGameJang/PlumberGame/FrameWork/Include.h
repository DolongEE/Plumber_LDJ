#pragma once

/* ---------------------------------------------------
///////////////// 프로그램 파일 //////////////////////
-----------------------------------------------------*/

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dsound.lib")


#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include <d3d9.h>
#include <d3dx9.h>
#include <dsound.h>
#include "DXUTsound.h"
#include "FmodSound.h"

#include <windows.h>
#include "Define.h"
#include "DeviceFont.h"
#include "Sprite.h"
#include "Chap.h"


/* ---------------------------------------------------
///////////////// 사용자 추가 파일 ///////////////////
-----------------------------------------------------*/
#include "Game.h"
#include "Logo.h"
#include "Menu.h"
#include "Over.h"
#include "CMng.h"



#include "Map.h"
#include "Key.h"
#include "Sound.h"
#include "GameManager.h"
#include "Test.h"
#include "Pipe.h"
#include "EventBlock.h"
#include "Cursur.h"


/* ---------------------------------------------------
///////////////// 사용자 추가 파일 ///////////////////

		키 입력 처리 함수입니다.

//////////////////////////////////////////////////////
-----------------------------------------------------*/

inline int KeyDown	( int vk ) 
{ 
	return ( (GetAsyncKeyState(vk) & 0x8000) ? 1:0 ); 
}

inline int KeyUp	( int vk ) 
{ 
	return ( (GetAsyncKeyState(vk) & 0x8000) ? 0:1 ); 
}
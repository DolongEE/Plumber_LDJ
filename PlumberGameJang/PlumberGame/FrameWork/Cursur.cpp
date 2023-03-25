#pragma once
#include "Include.h"

Cursur cursur;

Cursur::Cursur(void)
{
	//커서 좌표 초기화
	cursur_W = 0;
	cursur_H = 0;
}

Cursur::~Cursur(void)
{

}

void Cursur::Init()
{
	cursurcount2 = 0;
	Click = false;

	char FileName[256];

	for (int i = 0; i < 3; i++) //마우스 커서 이미지 저장
	{
		sprintf_s(FileName, "./resource/images/Cursur/spanner%d.png", i);
		cursurimg[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
}


void Cursur::CursurMove(LPARAM lParam)
{
	cursur_W = LOWORD(lParam) - 10; //실제 위치보다 살짝 대각위치
	cursur_H = HIWORD(lParam) - 10;
}


void Cursur::Update()
{
	//파이프를 잡고 우클릭시
	if (Click == true)
	{
		//파이프 회전효과
		if (GetTickCount() - cursurani > 10)
		{
			if (cursurcount2 == 45)
			{
				cursurcount2 = 315;
			}
			else if (cursurcount2 >= 360)
			{
				cursurcount2 = 0;
				Click = false;
			}
			else
			{
				cursurcount2 += 5;
			}
			cursurani = GetTickCount();
		}
	}
}


void Cursur::Draw()
{
	//커서 그려줌
	cursurimg[0].Render(cursur_W, cursur_H, cursurcount2 * (D3DX_PI / 180.0f), 1, 1);
}


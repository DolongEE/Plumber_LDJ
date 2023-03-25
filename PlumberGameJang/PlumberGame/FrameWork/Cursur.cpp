#pragma once
#include "Include.h"

Cursur cursur;

Cursur::Cursur(void)
{
	//Ŀ�� ��ǥ �ʱ�ȭ
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

	for (int i = 0; i < 3; i++) //���콺 Ŀ�� �̹��� ����
	{
		sprintf_s(FileName, "./resource/images/Cursur/spanner%d.png", i);
		cursurimg[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
}


void Cursur::CursurMove(LPARAM lParam)
{
	cursur_W = LOWORD(lParam) - 10; //���� ��ġ���� ��¦ �밢��ġ
	cursur_H = HIWORD(lParam) - 10;
}


void Cursur::Update()
{
	//�������� ��� ��Ŭ����
	if (Click == true)
	{
		//������ ȸ��ȿ��
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
	//Ŀ�� �׷���
	cursurimg[0].Render(cursur_W, cursur_H, cursurcount2 * (D3DX_PI / 180.0f), 1, 1);
}


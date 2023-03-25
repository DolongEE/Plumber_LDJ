#define _CRT_NONSTDC_NO_DEPRECATE
#pragma once

#include "Include.h"

Logo::Logo()
{

	count = 0;
}

Logo::~Logo()
{
}

void Logo::Init()
{
	introsoundcheck = false; //��Ʈ�� ���� �ȳ���
	speed = 3000; // �ΰ� �������� �ӵ�
	alpha = 0; //����

	loadimg.Create("./resource/images/Logo/logo.png", false, D3DCOLOR_XRGB(0, 0, 0)); //�ΰ� �̹���

}

void Logo::Update(double frame)
{
	if (introsoundcheck == false)
	{
		// ù ��Ʈ�� ���� ���
		sound.m_Intro->Play(0);
		introsoundcheck = true;
	}

	//�ΰ� ������ ������ �Ⱥ��̰�
	alpha += speed * frame / 1000;
	if( alpha >= 255 )
	{
		alpha = 255;
		speed = -speed;
		Draw();
	}
	if(alpha <= 0) 
	{
		//������ �޴���
		g_Mng.n_Chap = MENU;
	}

}

void Logo::Draw()
{
	loadimg.Draw( 280 , 100 ) ;  //�̹������
}

void Logo::OnMessage( MSG* msg )
{


}
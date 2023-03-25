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
	introsoundcheck = false; //인트로 사운드 안나게
	speed = 3000; // 로고 지나가는 속도
	alpha = 0; //투명도

	loadimg.Create("./resource/images/Logo/logo.png", false, D3DCOLOR_XRGB(0, 0, 0)); //로고 이미지

}

void Logo::Update(double frame)
{
	if (introsoundcheck == false)
	{
		// 첫 인트로 사운드 출력
		sound.m_Intro->Play(0);
		introsoundcheck = true;
	}

	//로고 서서히 보엿다 안보이게
	alpha += speed * frame / 1000;
	if( alpha >= 255 )
	{
		alpha = 255;
		speed = -speed;
		Draw();
	}
	if(alpha <= 0) 
	{
		//끝나면 메뉴로
		g_Mng.n_Chap = MENU;
	}

}

void Logo::Draw()
{
	loadimg.Draw( 280 , 100 ) ;  //이미지출력
}

void Logo::OnMessage( MSG* msg )
{


}
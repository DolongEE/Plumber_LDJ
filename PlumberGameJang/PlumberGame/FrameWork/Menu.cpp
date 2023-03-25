#pragma once

#include "Include.h"

static DWORD KeyTime = GetTickCount();

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Init()
{
	mouseOverStart = 0; //시작 버튼 효과음 변수
	mouseOverExit = 0; //종료 버튼 효과음 변수
	mouseOverScore = 0; // Score버튼 효과음 변수

	bool  muteChk = 0;
	OnHelp = false; //Score 화면인지
	OnStage = false; //스테이지 선택 화면인지
	scoresize = 0; //스코어 창 사이즈는 0
	menusoundcheck = false; //메뉴 효과음 한 번만 나게

	for (int i = 0; i < 12; i++)
	{
		button_push[i] = 0;
	} //효과음


	mainimg.Create("./resource/images/Menu/MAIN.png", false, D3DCOLOR_XRGB(0, 0, 0)); //메인
	ScoreBoardimg.Create("./resource/images/score1111.png", false, D3DCOLOR_XRGB(0, 0, 0)); //스코어 보드용 이미지


	char FileName[256];

	sprintf_s(FileName, "./resource/images/Menu/START1.png"); //START버튼 이미지
	startimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/images/Menu/EXIT1.png"); // EXIT버튼 이미지
	exitimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/images/Menu/help.png"); //HELP버튼 이미지
	Helpimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));


	for (int i = 0; i < 2; i++) //스테이지 이미지
	{
		for (int k = 0; k < 9; k++)
		{
			if (i == 0)
			{
				// 스테이지 이미지 마우스 커서 올리기 전
				sprintf_s(FileName, "./resource/images/Stage/Stg_%d.png", k);
			}
			else
			{
				// 스테이지 이미지 마우스 커서 올린 후
				sprintf_s(FileName, "./resource/images/Stage/PStg_%d.png", k);
			}

			Stage[i][k].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

		}
	}
	Stage[0][9].Create("./resource/images/Stage/Stg_Custom.png", false, D3DCOLOR_XRGB(0, 0, 0)); //스테이지 이미지
	Stage[1][9].Create("./resource/images/Stage/PStg_Custom.png", false, D3DCOLOR_XRGB(0, 0, 0));
	StageBack[0].Create("./resource/images/Stage/Back.png", false, D3DCOLOR_XRGB(0, 0, 0));//배경
	StageBack[1].Create("./resource/images/Stage/PBack.png", false, D3DCOLOR_XRGB(0, 0, 0));//배경
	Black.Create("./resource/images/Stage/BlackBack.png", false, D3DCOLOR_XRGB(0, 0, 0));//배경
}



void Menu::Update(double frame)
{
	//메뉴 사운드 출력    
	if (menusoundcheck == false)
	{
		if (muteChk == 0)
		{
			sound.m_Menu->Reset();
			sound.m_Menu->Play(0, DSBPLAY_LOOPING);
			menusoundcheck = true;
		}
		else
		{
			sound.m_Menu->Stop();
			menusoundcheck = true;
		}
	}

	//메뉴에서 키입력 위함
	key.Update();

	//HELP 보드가 켜지면
	if (OnHelp)
	{
		if (scoresize < 1) //0이니까
		{
			//점점 커지게
			scoresize += 0.025;
		}

	}
	//아니면 0.99 니까
	else
	{
		if (scoresize > 0)
		{
			//점점 작아지게
			scoresize -= 0.025;
		}
	}
}

void Menu::Draw()
{
	mainimg.Render(0, 0, 0, 1, 1); //main 이미지출력

	Helpimg.Render(0, 0, 0, 1, 1); //score이미지출력

	startimg.Render(0, 0, 0, 1, 1); //start이미지출력

	exitimg.Render(0, 0, 0, 1, 1); //exit이미지출력

	ScoreBoardimg.Render(0, 0, 0, scoresize, scoresize);

	//스코어 버튼 눌럿을때
	if (OnHelp == true)
	{
		ScoreBoardimg.Render(0, 0, 0, scoresize, scoresize); //스코어보드 출력
	}
	// 스테이지선택창이 켜지면
	else if (OnStage == true)
	{
		//뒤에 흐려지는 이미지
		Black.Render(0, 0, 0, 1, 1);

		int buttoncount = 0;
		int stagecount = 1;

		//스테이지 버튼 출력
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (i == 2)
				{
					if (k == 0)
					{
						StageBack[button_push[buttoncount]].Render((k * Stage_X_P) + (k * Stage_X_Size) + Stage_X, (i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y, 0, 1, 1);
					}
					else if (k == 2)
					{
						Stage[button_push[buttoncount]][0].Render((k * Stage_X_P) + (k * Stage_X_Size) + Stage_X, (i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y, 0, 1, 1);
					}
					else if (k == 3)
					{
						Stage[button_push[buttoncount]][9].Render((k * Stage_X_P) + (k * Stage_X_Size) + Stage_X, (i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y, 0, 1, 1);
					}
				}
				else
				{
					Stage[button_push[buttoncount]][stagecount].Render((k * Stage_X_P) + (k * Stage_X_Size) + Stage_X, (i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y, 0, 1, 1);
					stagecount++;
				}
				buttoncount++;
			}

		}
	}


}


void Menu::StageMouseMove(LPARAM lParam)
{
	int button = 1;

	//스테이지 버튼 마우스 올라갓을떄 사운드
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if ((k * Stage_X_P) + (k * Stage_X_Size) + Stage_X + Stage_X_Size > LOWORD(lParam) &&
				LOWORD(lParam) > (k * Stage_X_P) + (k * Stage_X_Size) + Stage_X &&
				(i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y + Stage_Y_Size > HIWORD(lParam) &&
				HIWORD(lParam) > (i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y && muteChk == 0)  //마우스가 스테이지 버튼 안으로 들어갔으면
			{
				if (button >= 1 && button <= 8) // 1부터 8스테이지 까지
				{
					if (button_push[button - 1] == 0)
					{
						if (muteChk == 0)
							sound.m_Menuon->Play(0);
						else
							sound.m_Menuon->Stop();
					}
					button_push[button - 1] = 1;
				}
				else if (button == 11) //뒤로가기
				{
					if (button_push[10] == 0)
					{
						if (muteChk == 0)
							sound.m_Menuon->Play(0);
						else
							sound.m_Menuon->Stop();
					}
					button_push[10] = 1;
				}
				else if (button == 12)
				{
					if (button_push[11] == 0)
					{
						if (muteChk == 0)
							sound.m_Menuon->Play(0);
						else
							sound.m_Menuon->Stop();
					}
					button_push[11] = 1;
				}
				else if (button == 9)
				{
					if (button_push[8] == 0)
					{
						if (muteChk == 0)
							sound.m_Menuon->Play(0);
						else
							sound.m_Menuon->Stop();
					}
					button_push[8] = 1;
				}
			}
			//스테이지 버튼 마우스 내려갓을떄 사운드
			else
			{
				if (button >= 1 && button <= 8)
				{
					if (button_push[button - 1] == 1)
					{
						if (muteChk == 0)
							sound.m_Menuoff->Play(0);
						else
							sound.m_Menuoff->Stop();
					}
					button_push[button - 1] = 0;
				}
				else if (button == 11)
				{
					if (muteChk == 0)
						sound.m_Menuoff->Play(0);
					else
						sound.m_Menuoff->Stop();
					button_push[10] = 0;
				}
				else if (button == 12)
				{
					if (button_push[11] == 1)
					{
						if (muteChk == 0)
							sound.m_Menuoff->Play(0);
						else
							sound.m_Menuoff->Stop();
					}
					button_push[11] = 0;
				}
				else if (button == 9)
				{
					if (button_push[8] == 1)
					{
						if (muteChk == 0)
							sound.m_Menuoff->Play(0);
						else
							sound.m_Menuoff->Stop();
					}
					button_push[8] = 0;
				}
			}
			button++;
		}
	}
}

void Menu::StageMouseDown(LPARAM lParam)
{
	int button = 1;
	//스테이지 버튼 클릭햇을떄 사운드와 해당스테이지 로드후 넘어가기
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if ((k * Stage_X_P) + (k * Stage_X_Size) + Stage_X + Stage_X_Size > LOWORD(lParam) &&
				LOWORD(lParam) > (k * Stage_X_P) + (k * Stage_X_Size) + Stage_X &&
				(i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y + Stage_Y_Size > HIWORD(lParam) &&
				HIWORD(lParam) > (i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y)
			{
				if (button >= 1 && button <= 8)
				{
					pipe.Load(button);
					g_Mng.n_Chap = GAME;
					if (muteChk == 0)
					{
						sound.m_Menusel->Play(0);
						sound.m_Menu->Stop();
						sound.m_Play->Reset();
						sound.m_Play->Play(0, DSBPLAY_LOOPING);
					}
					else
					{
						sound.m_Play->Stop();
						sound.m_Menu->Stop();
						sound.m_Menusel->Stop();
					}
				}
				else if (button == 11)
				{
					pipe.Load(0);
					g_Mng.n_Chap = GAME;
					if (muteChk == 0)
					{
						sound.m_Menusel->Play(0);
						sound.m_Menu->Stop();
						sound.m_Play->Reset();
						sound.m_Play->Play(0, DSBPLAY_LOOPING);
					}
					else
					{
						sound.m_Play->Stop();
						sound.m_Menu->Stop();
						sound.m_Menusel->Stop();
					}
				}
				else if (button == 12)
				{
					pipe.Load(9);
					g_Mng.n_Chap = GAME;
					if (muteChk == 0)
					{
						sound.m_Menusel->Play(0);
						sound.m_Menu->Stop();
						sound.m_Play->Reset();
						sound.m_Play->Play(0, DSBPLAY_LOOPING);
					}
					else
					{
						sound.m_Play->Stop();
						sound.m_Menu->Stop();
						sound.m_Menusel->Stop();
					}
				}
				else if (button == 9)
				{
					if (muteChk == 0)
						sound.m_Menusel->Play(0);
					else
						sound.m_Menusel->Stop();

					OnStage = false;
				}
			}
			button++;
		}

	}
}


void Menu::OnMessage(MSG* msg)
{
	switch (msg->message)
	{
		//마우스가 메뉴버튼에 다가갔을 때
	case WM_MOUSEMOVE:
		if (OnHelp == false && OnStage == false)
		{
			//start버튼 효과용
			if (LOWORD(msg->lParam) >= 116 &&
				252 >= LOWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 515 &&
				602 > HIWORD(msg->lParam))
			{
				if (mouseOverStart == 0 && muteChk == 0)
				{
					sound.m_Menuon->Play(0);
				}
				mouseOverStart = 1;
			}
			else
			{
				if (mouseOverStart == 1 && muteChk == 0)
				{
					sound.m_Menuoff->Play(0);
				}

				mouseOverStart = 0;
			}

			//exit버튼 효과용
			if (950 >= LOWORD(msg->lParam) &&
				LOWORD(msg->lParam) >= 780 &&
				602 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 515)
			{
				if (mouseOverExit == 0 && muteChk == 0)
				{
					sound.m_Menuon->Play(0);
				}
				mouseOverExit = 1;
			}
			else
			{
				if (mouseOverExit == 1 && muteChk == 0)
				{
					sound.m_Menuoff->Play(0);
				}
				mouseOverExit = 0;
			}

			//help버튼 효과용
			if (75 > LOWORD(msg->lParam) &&
				LOWORD(msg->lParam) >= 0 &&
				69 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 0)
			{
				if (mouseOverScore == 0 && muteChk == 0)
				{
					sound.m_Menuon->Play(0);
				}
				mouseOverScore = 1;
			}
			else
			{
				if (mouseOverScore == 1 && muteChk == 0)
				{
					sound.m_Menuoff->Play(0);
				}
				mouseOverScore = 0;
			}
		}
		else if (OnStage == true)
		{
			StageMouseMove(msg->lParam);
		}
		break;

		//메뉴버튼을 클릭했을 때 게임 화면으로 넘어감
	case WM_LBUTTONDOWN:
		if (1025 > LOWORD(msg->lParam) && //음소거 버튼을 눌렀을때
			LOWORD(msg->lParam) >= 930 &&
			123 > HIWORD(msg->lParam) &&
			HIWORD(msg->lParam) >= 32)
		{
			if (muteChk == 0)
				muteChk = 1;
			else
				muteChk = 0;

			if (muteChk == 1)
			{
				sound.m_Menu->Stop();
			}
			else
			{
				sound.m_Menu->Play(0, DSBPLAY_LOOPING);
			}
		}
		if (OnHelp == false && OnStage == false)
		{
			//start버튼 눌럿을때
			if (LOWORD(msg->lParam) >= 116 &&
				252 >= LOWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 515 &&
				602 > HIWORD(msg->lParam))
			{
				//클릭사운드와 함께 스테이지 선택창 켜줌
				if (muteChk == 0)
				{
					sound.m_Menusel->Play(0);
				}
				else
				{
					sound.m_Menusel->Stop();
				}
				mouseOverStart = 0;
				g_Mng.chap[GAME]->Init();
				OnStage = true;

			}

			//exit 버튼 눌럿을떄
			else if (950 >= LOWORD(msg->lParam) &&
				LOWORD(msg->lParam) >= 780 &&
				602 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 515)
			{
				if (muteChk == 0)
				{
					sound.m_Menusel->Play(0);
				}
				else
				{
					sound.m_Menusel->Stop();
				}
				mouseOverExit = 0;

				PostQuitMessage(0);

			}

			//help버튼 눌럿을떄
			else if (115 > LOWORD(msg->lParam) &&
				LOWORD(msg->lParam) >= 14 &&
				100 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 30)
			{
				//클릭사운드와 함께 help 켜줌
				if (muteChk == 0)
				{
					sound.m_Menusel->Play(0);
				}
				else
				{
					sound.m_Menusel->Stop();
				}
				OnHelp = true;
			}
		}



		else if (OnHelp == true)
		{
			if (muteChk == 0)
				sound.m_Menusel->Play(0);
			else
				sound.m_Menusel->Stop();
			OnHelp = false;
			mouseOverScore = 0;
		}
		else if (OnStage == true)
		{
			StageMouseDown(msg->lParam);
		}
		break;
	}

}
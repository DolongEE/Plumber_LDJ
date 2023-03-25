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
	mouseOverStart = 0; //���� ��ư ȿ���� ����
	mouseOverExit = 0; //���� ��ư ȿ���� ����
	mouseOverScore = 0; // Score��ư ȿ���� ����

	bool  muteChk = 0;
	OnHelp = false; //Score ȭ������
	OnStage = false; //�������� ���� ȭ������
	scoresize = 0; //���ھ� â ������� 0
	menusoundcheck = false; //�޴� ȿ���� �� ���� ����

	for (int i = 0; i < 12; i++)
	{
		button_push[i] = 0;
	} //ȿ����


	mainimg.Create("./resource/images/Menu/MAIN.png", false, D3DCOLOR_XRGB(0, 0, 0)); //����
	ScoreBoardimg.Create("./resource/images/score1111.png", false, D3DCOLOR_XRGB(0, 0, 0)); //���ھ� ����� �̹���


	char FileName[256];

	sprintf_s(FileName, "./resource/images/Menu/START1.png"); //START��ư �̹���
	startimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/images/Menu/EXIT1.png"); // EXIT��ư �̹���
	exitimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/images/Menu/help.png"); //HELP��ư �̹���
	Helpimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));


	for (int i = 0; i < 2; i++) //�������� �̹���
	{
		for (int k = 0; k < 9; k++)
		{
			if (i == 0)
			{
				// �������� �̹��� ���콺 Ŀ�� �ø��� ��
				sprintf_s(FileName, "./resource/images/Stage/Stg_%d.png", k);
			}
			else
			{
				// �������� �̹��� ���콺 Ŀ�� �ø� ��
				sprintf_s(FileName, "./resource/images/Stage/PStg_%d.png", k);
			}

			Stage[i][k].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

		}
	}
	Stage[0][9].Create("./resource/images/Stage/Stg_Custom.png", false, D3DCOLOR_XRGB(0, 0, 0)); //�������� �̹���
	Stage[1][9].Create("./resource/images/Stage/PStg_Custom.png", false, D3DCOLOR_XRGB(0, 0, 0));
	StageBack[0].Create("./resource/images/Stage/Back.png", false, D3DCOLOR_XRGB(0, 0, 0));//���
	StageBack[1].Create("./resource/images/Stage/PBack.png", false, D3DCOLOR_XRGB(0, 0, 0));//���
	Black.Create("./resource/images/Stage/BlackBack.png", false, D3DCOLOR_XRGB(0, 0, 0));//���
}



void Menu::Update(double frame)
{
	//�޴� ���� ���    
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

	//�޴����� Ű�Է� ����
	key.Update();

	//HELP ���尡 ������
	if (OnHelp)
	{
		if (scoresize < 1) //0�̴ϱ�
		{
			//���� Ŀ����
			scoresize += 0.025;
		}

	}
	//�ƴϸ� 0.99 �ϱ�
	else
	{
		if (scoresize > 0)
		{
			//���� �۾�����
			scoresize -= 0.025;
		}
	}
}

void Menu::Draw()
{
	mainimg.Render(0, 0, 0, 1, 1); //main �̹������

	Helpimg.Render(0, 0, 0, 1, 1); //score�̹������

	startimg.Render(0, 0, 0, 1, 1); //start�̹������

	exitimg.Render(0, 0, 0, 1, 1); //exit�̹������

	ScoreBoardimg.Render(0, 0, 0, scoresize, scoresize);

	//���ھ� ��ư ��������
	if (OnHelp == true)
	{
		ScoreBoardimg.Render(0, 0, 0, scoresize, scoresize); //���ھ�� ���
	}
	// ������������â�� ������
	else if (OnStage == true)
	{
		//�ڿ� ������� �̹���
		Black.Render(0, 0, 0, 1, 1);

		int buttoncount = 0;
		int stagecount = 1;

		//�������� ��ư ���
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

	//�������� ��ư ���콺 �ö����� ����
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if ((k * Stage_X_P) + (k * Stage_X_Size) + Stage_X + Stage_X_Size > LOWORD(lParam) &&
				LOWORD(lParam) > (k * Stage_X_P) + (k * Stage_X_Size) + Stage_X &&
				(i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y + Stage_Y_Size > HIWORD(lParam) &&
				HIWORD(lParam) > (i * Stage_Y_P) + (i * Stage_Y_Size) + Stage_Y && muteChk == 0)  //���콺�� �������� ��ư ������ ������
			{
				if (button >= 1 && button <= 8) // 1���� 8�������� ����
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
				else if (button == 11) //�ڷΰ���
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
			//�������� ��ư ���콺 ���������� ����
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
	//�������� ��ư Ŭ�������� ����� �ش罺������ �ε��� �Ѿ��
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
		//���콺�� �޴���ư�� �ٰ����� ��
	case WM_MOUSEMOVE:
		if (OnHelp == false && OnStage == false)
		{
			//start��ư ȿ����
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

			//exit��ư ȿ����
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

			//help��ư ȿ����
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

		//�޴���ư�� Ŭ������ �� ���� ȭ������ �Ѿ
	case WM_LBUTTONDOWN:
		if (1025 > LOWORD(msg->lParam) && //���Ұ� ��ư�� ��������
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
			//start��ư ��������
			if (LOWORD(msg->lParam) >= 116 &&
				252 >= LOWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 515 &&
				602 > HIWORD(msg->lParam))
			{
				//Ŭ������� �Բ� �������� ����â ����
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

			//exit ��ư ��������
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

			//help��ư ��������
			else if (115 > LOWORD(msg->lParam) &&
				LOWORD(msg->lParam) >= 14 &&
				100 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 30)
			{
				//Ŭ������� �Բ� help ����
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
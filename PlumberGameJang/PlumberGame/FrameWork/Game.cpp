#define _CRT_NONSTDC_NO_DEPRECATE
#pragma once

#include "Include.h"
Menu menu;

Game::Game()
{

}

Game::~Game()
{
}

void Game::Init()
{
	speed = 1700;
	alpha = 0;
	soundcheck = false;

	GameSet = false;

	char FileName[256];
	Over.Create("./resource/images/Over/over.png", false, D3DCOLOR_XRGB(0, 0, 0));
	Clear.Create("./resource/images/Over/clear.png", false, D3DCOLOR_XRGB(0, 0, 0));
	Black.Create("./resource/images/Over/black.png", false, D3DCOLOR_XRGB(0, 0, 0));
	for (int i = 0; i < 3; i++)
	{
		sprintf_s(FileName, "./resource/images/Over/w00_00_00_%02d.png", i);
		Packing[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	map.Init();
	pipe.Init();

	Gmanager.Init();

	eventblock.Init();
}

void Game::Draw()
{
	map.Draw();
	eventblock.Draw();
	Gmanager.Draw();
	pipe.Draw();

	if (GameSet == true)
	{
		Black.Draw(0, 0);
		if (pipe.clear == 1)
		{
			Clear.SetColor(255, 255, 255, alpha);  // ���� ����
			Clear.Draw(0, 0);  //�̹������
		}
		else if (pipe.clear == 0)
		{
			for (int i = 0; i < 29; i++)			//�⸧���� ����
			{
				for (int j = 0; j < 29; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						if (i > 1 && i < 29 && j > 1 && j < 29)
						{
							map.BackGround[j][i] = Packing[k].Render((j * BLOCKSIZE + BACKSTART) / 3, (i * BLOCKSIZE + BACKSTART) / 3, 0, 1, 1);
						}
					}

				}
			}
			Over.SetColor(255, 255, 255, alpha);  // ���� ����
			Over.Draw(0, 0);  //�̹������
		}
	}
	char asd[10];

	//��׶��� �迭 �����ִ¿뵵
	if (map.debug_Background == true)
	{
		for (int i = 0; i < 29; i++)
		{
			for (int k = 0; k < 29; k++)
			{
				_itoa(map.BackGround[i][k], asd, 10);
				dv_font.DrawString(asd, k * 21 + 83, i * 21 + 75);
			}
		}
	}
}

void Game::Update(double frame)
{
	key.Update();

	pipe.Update();
	eventblock.Update();
	map.Update(frame);
	Gmanager.Update();

	if (map.cleartime == 10)
	{
		if (menu.muteChk == 0)
		{
			sound.m_Alert->Play(0);
			sound.m_Clock->Reset();
			sound.m_Clock->Play(0, DSBPLAY_LOOPING);
		}
		else
			sound.m_Alert->Stop();
		sound.m_Clock->Stop();
	}

	if (eventblock.valvecheck == false)			//��ŸƮ�� �����ʾ�����
	{
		if (GetTickCount() - GameTime > 1000)			//1�ʸ��� ���ѽð� 1�� ����
		{
			map.cleartime--;
			if (map.cleartime == 0)			//0�ʰ� �Ǹ� ������ ��ŸƮ
			{
				if (menu.muteChk == 0)
				{
					sound.m_Clock->Stop();
					sound.m_Play->Stop();
					sound.m_Valve->Play(0);
					sound.m_Water->Reset();
					sound.m_Water->Play(0, DSBPLAY_LOOPING);
				}
				else
				{
					sound.m_Clock->Stop();
					sound.m_Play->Stop();
					sound.m_Valve->Stop();
					sound.m_Water->Reset();
					sound.m_Water->Stop();
				}
				pipe.PipeBack();
				eventblock.valvecheck = true;
				pipe.pipeup_ok = false;
			}
			GameTime = GetTickCount();
		}
	}


	if (pipe.water_count == 1)		// �������� ���� ������
	{
		sound.m_Alert->Stop();
		sound.m_Clock->Stop();
		sound.m_Play->Stop();
		sound.m_Water->Stop();

		if (eventblock.ClearCheck() == true)			// Ŭ�����
		{
			if (soundcheck == false)
			{
				if (menu.muteChk == 0)
				{
					//Ŭ�������
					sound.m_Clear->Play(0);
					pipe.clear = 1;
					soundcheck = true;
				}
				else
					soundcheck = false;
			}

		}
		else	//Ŭ��� �ƴϸ�
		{
			if (soundcheck == false)
			{
				if (menu.muteChk == 0)
				{
					//���� ����
					sound.m_Over->Play(0);
					soundcheck = true;
				}
				else
					soundcheck = false;
			}
		}

		//������ ����̴ٰ� �˸�
		GameSet = true;

		if (GameSet == true)
		{
			eventblock.clockcount = true;
		}

		//Ŭ��� ���� �̹��� ������ �����ٰ� �������
		alpha += speed * frame / 1000;

		if (alpha >= 255)
		{
			alpha = 255;
			speed = -speed;
			Draw();
		}
		//Ŭ��� ���� �̹����� �������
		if (alpha <= 0)
		{
			//�޴��� �̵�
			g_Mng.chap[MENU]->Init();
			g_Mng.n_Chap = MENU;
		}
	}
}


void Game::OnMessage(MSG* msg)
{
	switch (msg->message)
	{
	case WM_LBUTTONDOWN:
		if (Gmanager.m_GameStart == true && pipe.pipeup_ok == true)
		{
			if (1025 > LOWORD(msg->lParam) && //���Ұ� ��ư�� ��������
				LOWORD(msg->lParam) >= 930 &&
				123 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 32)
			{
				if (menu.muteChk == 0)
				{
					menu.muteChk = 1;
					sound.m_Play->Stop();
				}
				else
				{
					menu.muteChk = 0;
					sound.m_Play->Play(0, DSBPLAY_LOOPING);
				}
			}

			else if (1023 > LOWORD(msg->lParam) && //�ð� �������� ��������
				LOWORD(msg->lParam) >= 943 &&
				747 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 673 && eventblock.clockcount == true)
			{
				pipe.mouse = 1;
				map.cleartime += 30;
				eventblock.clockcount = false;
			}

			else if (900 > LOWORD(msg->lParam) && //������ ��ư�� ��������
				LOWORD(msg->lParam) >= 803 &&
				123 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= 32)
			{
				eventblock.clockcount = true;
				g_Mng.chap[MENU]->Init();
				g_Mng.n_Chap = MENU;
			}


			if (pipe.m_W + 64 > LOWORD(msg->lParam) &&		// ��Ʈ�� ������ �������� ��������
				LOWORD(msg->lParam) >= pipe.m_W &&
				pipe.m_H + 64 > HIWORD(msg->lParam) &&
				HIWORD(msg->lParam) >= pipe.m_H)
			{
				if (menu.muteChk == 0)
					sound.m_PipePick->Play(0);
				else
					sound.m_PipePick->Stop();
				pipe.mouse = 1;		//������ ��Ѵٴ¶�
			}
			else		//�ƴϸ� ��긦 �������� Ȯ��
			{
				pipe.ValveOn(msg->lParam);
			}

			break;
		}
	case WM_LBUTTONUP:
		if (Gmanager.m_GameStart == true && pipe.pipeup_ok == true)
		{
			if (pipe.mouse == 1)
			{
				if (pipe.PipeMouseUP(msg->lParam) == 1)		//�������� ����������
				{
					if (menu.muteChk == 0)
						sound.m_PipeSet->Play(0);
					else
						sound.m_PipeSet->Stop();
					pipe.Reset();		// �� ����
				}

				else			//�������� �� ����������
				{
					//�ٽ� �������´�
					if (menu.muteChk == 0)
						sound.m_PipeWlong->Play(0);
					else
						sound.m_PipeWlong->Stop();
					pipe.PipeBack();
				}
			}
		}

		break;
	case WM_RBUTTONDOWN:
		if (Gmanager.m_GameStart == true && pipe.pipeup_ok == true)
		{
			for (int i = 0; i < 9; i++)
			{
				for (int k = 0; k < 9; k++)
				{
					// ���� �������մ� ������ �������� 
					if ((k * BLOCKSIZE + BACKSTART) + BLOCKSIZE > LOWORD(msg->lParam) &&
						LOWORD(msg->lParam) > (k * BLOCKSIZE + BACKSTART) &&
						(i * BLOCKSIZE + BACKSTART) + BLOCKSIZE > HIWORD(msg->lParam) &&
						HIWORD(msg->lParam) > (i * BLOCKSIZE + BACKSTART))
					{
						if (pipe.save[i][k].isStart == false && pipe.save[i][k].isClear == false)
						{
							pipe.mouse = 1;
							//eventblock.bSoil = false;
						}
					}
				}
			}
		}
		if (pipe.mouse == 1)
		{
			//Ŀ�� �̹��� ȸ��
			cursur.Click = true;

			//������ ȸ��
			if (pipe.type == 3)
			{
				pipe.rotate_num = 0;
			}
			else if (pipe.rotate_num == 3)
			{
				pipe.rotate_num = 0;
			}
			else
			{
				pipe.rotate_num++;
			}
			//ȸ���� ���� ���
			if (menu.muteChk == 0)
				sound.m_PipeRotate->Play(0);
			else
				sound.m_PipeRotate->Stop();
		}
		break;
	case WM_MOUSEMOVE:

		if (Gmanager.m_GameStart == true && pipe.pipeup_ok == true)
		{
			if (pipe.mouse == 1)		//���콺�� �������� �������
			{
				//�������� ���콺���� �����̰�
				pipe.PipeMove(msg->lParam);
			}
		}
		break;
	}
}


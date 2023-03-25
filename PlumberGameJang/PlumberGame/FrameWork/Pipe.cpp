#pragma once
#include "Include.h"

Pipe pipe;

Pipe::Pipe(void)
{
	
}

Pipe::~Pipe(void)
{

}

void Pipe::Reset()
{
	PipeCreate();
	m_W = PIPECREATE_W;
	m_H = PIPECREATE_H;
	//rotate_num = rand() % 4;
	//type = 0;
	//type = rand() % 4;
	rotate_ok = 1;
	mouse = 0;
}


void Pipe::PipeCreate()
{
	type = type1; //�̸��������� �������� ���� �������� �ϳ��� �о�ִ´�??
	type1 = type2;
	type2 = type3;
	type3 = Type();
	
	rotate_num = rotate1; //�����̼� �Ҷ����� ����� ����??
	rotate1 = rotate2;
	rotate2 = rotate3;
	rotate3 = Type();

	if (type == 3) // 4��° ������ 0������
	{
		rotate_num = 0;
	}
}

void Pipe::PipeBack()
{
	rotate_ok = 1;
	mouse = 0;
	m_W = PIPECREATE_W;
	m_H = PIPECREATE_H;
}


int Pipe::Type()
{
	//Ÿ�� Ȯ������
	int temp = rand() % 10;

	if (temp >= 0 && temp < 4)
	{
		return 0;
	}
	else if (temp >= 4 && temp < 7)
	{
		return 1;
	}
	else if (temp >= 7 && temp < 9)
	{
		return 2;
	}
	else if (temp == 9)
	{
		return 3;
	}
}
 
//�������� ���� �ҷ����� �Լ�
void Pipe::Load(int stage)
{
	char seps[] = ",\n";
	char *token;
	int clear = 0;

	char FileName[256];

	switch (stage)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		sprintf_s(FileName, "./resource/Stage/Stage_%02d.fss", stage);
		if ((fp = fopen(FileName, "rb")) == NULL)
		{
			return;
		}
		break;
	case 9:
		if ((fp = fopen("./Save/save.fss", "rb")) == NULL)
		{
			return;
		}
		break;
	}
	
	for (int i = 0; i < 9; i++)
	{
		for (int k = 0; k < 9; k++)
		{
			fread(&save[i][k], sizeof(pipedrowsave), 1, fp);
		}
	}
	fclose(fp);


	for (int i = 0; i < 9; i++)
	{
		for (int k = 0; k < 9; k++)
		{
			if (save[i][k].isPipe == true)
			{
				pipe.AddPipe(PIPE, i * 3 + 1, k * 3 + 1, save[i][k].rotate, save[i][k].type);
			}
			else if (save[i][k].isStart == true)
			{
				pipe.AddPipe(START, i * 3 + 1, k * 3 + 1, save[i][k].rotate);
			}
			else if (save[i][k].isClear == true)
			{
				pipe.AddPipe(CLEAR, i * 3 + 1, k * 3 + 1, save[i][k].rotate);
				clear++;
			}
			else if (save[i][k].isBlock == true)
			{
				pipe.AddPipe(BLOCK, i * 3 + 1, k * 3 + 1);
			}
		}
	}

	eventblock.clear_Count = clear;
}

void Pipe::Init()
{
	type = Type();
	type1 = Type();
	type2 = Type();
	type3 = Type();

	H_type3 = 209;
	H_type2 = 292;
	H_type1 = 375;
	W_type = PIPECREATE_W;


	m_W = PIPECREATE_W;
	m_H = PIPECREATE_H;
	rotate_num = 0;
	//type = 0;
	rotate_ok = 1; //ȸ������?
	mouse = 0; //Ŭ��üũ
	water_count = 0; //���� �帣����
	clear = 0; //�������� Ŭ��������

	pipeup_ok = true;

	for (int i = 0; i < 9; i++)
	{
		for (int k = 0; k < 9; k++)
		{
			save[i][k].WaterCount = 0;
			save[i][k].WaterMoveCount = 0;
			save[i][k].MaxWaterCount = 0;
			save[i][k].isPipe = false;	
			save[i][k].isWater = false;
			save[i][k].WaterMax = false;
			save[i][k].isStart = false;
			save[i][k].isClear = false;
			save[i][k].isBlock = false;			
		}
	}

    //������
	char FileName[256];
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			sprintf_s(FileName, "./resource/images/pipe/%02d_%02d.png", i, k);
			p_pipe[i][k].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
		}
	}

    //���ִϸ��̼� 
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int y = 0; y < 3; y++)
				{
					sprintf_s(FileName, "./resource/images/water/%02d/wc%02d_%02d_%02d_%02d.png", i, i, k, j, y);
					p_waterani[i][k][j][y].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
				}
			}
		}
	}
    //4�� �����ִ°Ŷ� 4��
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int y = 0; y < 3; y++)
				{
					sprintf_s(FileName, "./resource/images/water/%02d/w%02d_%02d_%02d_%02d.png", i, i, k, j, y);
					p_watermove[i][k][j][y].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
				}
			}
		}
	}
}



void Pipe::Update()
{
	if (Gmanager.m_GameStart == true)
	{
		if (eventblock.valvecheck == true)
		{
			if (GetTickCount() - waterupdate > 150)
			{
				pipe.NowWaterCheck();
				for (int i = 0; i < 9; i++)
				{
					for (int k = 0; k < 9; k++)
					{						
						if (save[i][k].WaterMax == true)		//�ش� �������� ���� �� ��������
						{
							if (save[i][k].WaterCount == 2)		//���� �帣�� ��������Ʈ ��� �����̰�
							{
								save[i][k].WaterCount = 0;
							}
							else
							{
								save[i][k].WaterCount++;
							}
						}
						if (save[i][k].MaxWaterCount >= 6)		//���� �� ���� �˻��� �� ������ �����ٰ� �˸�
						{
							save[i][k].WaterMax = true;
						}						
					}
				}
				waterupdate = GetTickCount();
			}
		}
	}
}



void Pipe::Draw()
{
	if (Gmanager.m_GameStart == true)
	{		
		for (int i = 0; i < 9; i++)
		{
			for (int k = 0; k < 9; k++)
			{
				if (save[i][k].isPipe == true)		//�ش���ġ�� �������� ���������� ����������� �׷��ش�
				{					
					p_pipe[save[i][k].type][save[i][k].rotate].Render((k * BLOCKSIZE + BACKSTART), (i * BLOCKSIZE + BACKSTART), 0, 1, 1);
				}
				if (save[i][k].isWater == true)			//�ش���ġ �������� ���� ������ ���� �׷��ش�
				{
					if (save[i][k].WaterMax == true)
					{
						p_waterani[save[i][k].type][save[i][k].rotate][save[i][k].water_In][save[i][k].WaterCount].Render((k * BLOCKSIZE + BACKSTART), (i * BLOCKSIZE + BACKSTART), 0, 1, 1);						
					}
					else
					{
						p_watermove[save[i][k].type][save[i][k].rotate][save[i][k].water_In][save[i][k].WaterMoveCount - 1].Render((k * BLOCKSIZE + BACKSTART), (i * BLOCKSIZE + BACKSTART), 0, 1, 1);					
					}
				}
			}
		}

		// ������ ���� ������ �̸� ������
		p_pipe[type3][rotate3].Render(W_type, H_type3, 0, 1, 1);
		p_pipe[type2][rotate2].Render(W_type, H_type2, 0, 1, 1);
		p_pipe[type1][rotate1].Render(W_type, H_type1, 0, 1, 1);

		map.Glass.Render(0, 0, 0, 1, 1);

		p_pipe[type][rotate_num].Render(m_W, m_H, 0, 1, 1);		// ���콺�� �����ϼ��մ� �������� �׷��ش�		
	}
}




void Pipe::PipeMove(LPARAM lParam)
{
	int check = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int k = 0; k < 9; k++)
		{
			// ���� �������մ� ������ �������� 
			if ((k * BLOCKSIZE + BACKSTART) + BLOCKSIZE > LOWORD(lParam) &&
				LOWORD(lParam) > (k * BLOCKSIZE + BACKSTART) &&
				(i * BLOCKSIZE + BACKSTART) + BLOCKSIZE > HIWORD(lParam) &&
				HIWORD(lParam) > (i * BLOCKSIZE + BACKSTART))
			{
				//�ٸ����� �ȳ����� ������
				if (save[i][k].isPipe == false && save[i][k].isStart == false &&
					save[i][k].isClear == false && save[i][k].isBlock == false)
				{
					m_W = (k * BLOCKSIZE + BACKSTART);		//�ش���ġ�� ����
					m_H = (i * BLOCKSIZE + BACKSTART);
					check = 1;
					break;
				}
			}
		}
	}

	if (check == 0)		// ���� �������մ� ������ ������ ������
	{
		m_W = LOWORD(lParam) - 32; // ���콺�� �߾ӿ� �޶�ٴ´�
		m_H = HIWORD(lParam) - 32; // ���콺�� �߾ӿ� �޶�ٴ´�
	}
}

int Pipe::PipeMouseUP(LPARAM lParam)
{
	int check = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int k = 0; k < 9 ; k++)
		{
			// ���� �������մ� ������ �������� 
			if ((k * BLOCKSIZE + BACKSTART) + BLOCKSIZE > LOWORD(lParam) &&
				LOWORD(lParam) > (k * BLOCKSIZE + BACKSTART) &&
				(i * BLOCKSIZE + BACKSTART) + BLOCKSIZE > HIWORD(lParam) &&
				HIWORD(lParam) > (i * BLOCKSIZE + BACKSTART))
			{
				//�ٸ����� �ȳ����� ������
				if (save[i][k].isPipe == false && save[i][k].isStart == false && 
					save[i][k].isClear == false && save[i][k].isBlock == false)
				{					
					m_W = (k * BLOCKSIZE + BACKSTART);		//�ش���ġ�� ����
					m_H = (i * BLOCKSIZE + BACKSTART);
					save[i][k] = { true, type,rotate_num };		//�׷��� ���� ����

					AddPipe(PIPE,i * 3 + 1, k * 3 + 1, rotate_num, type);		//��׶��� �迭�� �������迭 ����
					
					return 1;		//�������� �� �������ٰ� ����
				}
				else
				{
					return 0;		//�������� �� �������ٰ� ����
				}
			}
		}
	}
	return 0;		//�������� �� �������ٰ� ����
}


void Pipe::ValveOn(LPARAM lParam)
{
	for (int i = 0; i < 9; i++)
	{
		for (int k = 0; k < 9; k++)
		{
			// ���� �������մ� ������ �������� 
			if ((k * BLOCKSIZE + BACKSTART) + BLOCKSIZE > LOWORD(lParam) &&
				LOWORD(lParam) > (k * BLOCKSIZE + BACKSTART) &&
				(i * BLOCKSIZE + BACKSTART) + BLOCKSIZE > HIWORD(lParam) &&
				HIWORD(lParam) > (i * BLOCKSIZE + BACKSTART))
			{
				//��ŸƮ�� ������ ������
				if (save[i][k].isStart == true )
				{	
                    if(menu.muteChk == 0)
                    {
					sound.m_Clock->Stop();
					sound.m_Play->Reset();
					sound.m_Play->Stop();
					sound.m_Valve->Play(0);
					sound.m_Water->Play(0, DSBPLAY_LOOPING);
                    }
                    else 
                    {
                        sound.m_Clock->Stop();
                        sound.m_Play->Reset();
                        sound.m_Play->Stop();
                        sound.m_Valve->Stop();
                        sound.m_Water->Stop();

                    }
                    eventblock.valvecheck = true;

					pipeup_ok = false;
				}				
			}
		}
	}
}

void Pipe::AddPipe(int kind, int back1,int back2,int rotate,int type)
{
	//��׶��� �迭�� ������ �迭 ����
	switch (kind)
	{
	case PIPE:
	for (int i = back1; i < back1+3; i++)
	{
		for (int k = back2; k < back2+3; k++)
		{
			map.BackGround[i][k] = pipe_Block[type][rotate][i - back1][k - back2];
		}
	}
		break;

	case START:
		for (int i = back1; i < back1 + 3; i++)
		{
			for (int k = back2; k < back2 + 3; k++)
			{
				map.BackGround[i][k] = eventblock.start[rotate][i - back1][k - back2];
			}
		}
		break;

	case CLEAR:
		for (int i = back1; i < back1 + 3; i++)
		{
			for (int k = back2; k < back2 + 3; k++)
			{
				map.BackGround[i][k] = eventblock.clear[rotate][i - back1][k - back2];
			}
		}
		break;

	case BLOCK:
		for (int i = back1; i < back1 + 3; i++)
		{
			for (int k = back2; k < back2 + 3; k++)
			{

				map.BackGround[i][k] = eventblock.block[i - back1][k - back2];
			}
		}
		break;
	}
}


void Pipe::NowWaterCheck()
{
	// ���� �� �մ���ġ ����
	int count = 0;

	for (int i = 0; i < 29; i++)
	{
		for (int k = 0; k < 29; k++)
		{
			if (map.BackGround[i][k] == PP_NOW)
			{
				water[count] = { i,k };
				count++;
			}
		}
	}
	WaterMove(count);	//���� �� �մ°��� ����
}


void Pipe::WaterMove(int count)
{

	if (count == 0)		//������� ������ ���ٰ� ����
	{
		water_count = 1;
		return;
	}
/*
        ���� �� ��ġ���� ���Ʒ� �翷 ������ �˻��ؼ� 
		���� �������� �մ� ���� �����ĭ�� ����
*/
//////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < count; i++)
	{
		if (map.BackGround[water[i].i + 1][water[i].k] == PP_CLEAR)
		{
			map.BackGround[water[i].i + 1][water[i].k] = PP_CLEAR_CHECK;
		}
		else if (map.BackGround[water[i].i + 1][water[i].k] == PP_EMPTY)
		{
			map.BackGround[water[i].i + 1][water[i].k] = PP_LEAK;
		}
		else if (map.BackGround[water[i].i + 1][water[i].k] == PP_LINE)
		{
			map.BackGround[water[i].i + 1][water[i].k] = PP_NOW;
		}

/////////////////////////////////////////////////////////////////////////////////////

		if (map.BackGround[water[i].i - 1][water[i].k] == PP_CLEAR)
		{
			map.BackGround[water[i].i + 1][water[i].k] = PP_CLEAR_CHECK;
		}
		else if (map.BackGround[water[i].i - 1][water[i].k] == PP_EMPTY)
		{
			map.BackGround[water[i].i - 1][water[i].k] = PP_LEAK;
		}
		else if (map.BackGround[water[i].i - 1][water[i].k] == PP_LINE)
		{
			map.BackGround[water[i].i - 1][water[i].k] = PP_NOW;
		}

/////////////////////////////////////////////////////////////////////////////////////

		if (map.BackGround[water[i].i][water[i].k + 1] == PP_CLEAR)
		{
			map.BackGround[water[i].i + 1][water[i].k] = PP_CLEAR_CHECK;
		}
		else if (map.BackGround[water[i].i][water[i].k + 1] == PP_EMPTY)
		{
			map.BackGround[water[i].i][water[i].k + 1] = PP_LEAK;
		}
		else if (map.BackGround[water[i].i][water[i].k + 1] == PP_LINE)
		{
			map.BackGround[water[i].i][water[i].k + 1] = PP_NOW;
		}

//////////////////////////////////////////////////////////////////////////////////////

		if (map.BackGround[water[i].i][water[i].k - 1] == PP_CLEAR)
		{
			map.BackGround[water[i].i + 1][water[i].k] = PP_CLEAR_CHECK;
		}
		else if (map.BackGround[water[i].i][water[i].k - 1] == PP_EMPTY)
		{
			map.BackGround[water[i].i][water[i].k - 1] = PP_LEAK;
		}
		else if (map.BackGround[water[i].i][water[i].k - 1] == PP_LINE)
		{
			map.BackGround[water[i].i][water[i].k - 1] = PP_NOW;
		}

		map.BackGround[water[i].i][water[i].k] = PP_WATER;
	}
	WaterImgCheck();
}


void Pipe::WaterImgCheck()
{
	//�ش� ������ ��ġ�� ���� �������� ���� ���Ӵٰ� ����
	for (int i = 1; i < 28; i++)
	{
		for (int k = 1; k < 28; k++)
		{
			if (map.BackGround[i][k] == PP_WATER)
			{
				save[(i - 1) / 3][(k - 1) / 3].MaxWaterCount++;
			}

			if (map.BackGround[i][k] == PP_NOW)
			{
				if (save[(i - 1) / 3][(k - 1) / 3].isWater == false)
				{
					int temp_i = (i - 1) % 3;
					int temp_k = (k - 1) % 3;

					if (temp_i == 0 && temp_k == 1)
					{
						save[(i - 1) / 3][(k - 1) / 3].water_In = 0;
					}
					else if (temp_i == 1 && temp_k == 2)
					{
						save[(i - 1) / 3][(k - 1) / 3].water_In = 1;
					}
					else if (temp_i == 2 && temp_k == 1)
					{
						save[(i - 1) / 3][(k - 1) / 3].water_In = 2;
					}
					else if (temp_i == 1 && temp_k == 0)
					{
						save[(i - 1) / 3][(k - 1) / 3].water_In = 3;
					}
				}
						
				if (save[(i - 1) / 3][(k - 1) / 3].WaterMoveCount < 3)
				{
					save[(i - 1) / 3][(k - 1) / 3].WaterMoveCount++;
					save[(i - 1) / 3][(k - 1) / 3].isWater = true;
				}				
			}			
		}
	}
}
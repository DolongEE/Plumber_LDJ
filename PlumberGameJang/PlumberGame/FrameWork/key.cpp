#pragma once
#include "Include.h"

Key key;

Key::Key(void)
{


}

Key::~Key(void)
{
}


void Key::Update()
{
	//Ŭ����Ÿ�� 15 ġƮŰ
	if (KeyDown('1'))
	{
		if (GetTickCount() - KeyTime > 200)
		{
			map.cleartime = 15;
			KeyTime = GetTickCount();
		}
	}

	//Ŭ���� Ÿ�� 100 ġƮŰ
	if(KeyDown('2'))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			map.cleartime = 80;
			KeyTime = GetTickCount();
		}		
	}

	//if(KeyDown('3'))
	//{
	//	if(GetTickCount() - KeyTime > 200)
	//	{
	//	
	//		KeyTime = GetTickCount();
	//	}
	//	
	//}
	//
	//if(KeyDown('4'))
	//{
	//	if(GetTickCount() - KeyTime > 200)
	//	{

	//		KeyTime = GetTickCount();
	//	}
	//	
	//}


	//���� ����׿�
	if (KeyDown('5'))
	{
		if (GetTickCount() - KeyTime > 200)
		{
			if (map.debug_Background == true)
			{
				map.debug_Background = false;
			}
			else if (map.debug_Background == false)
			{
				map.debug_Background = true;
			}

			KeyTime = GetTickCount();
		}
	}
	/*
	if(KeyDown('6'))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}
	}


	if(KeyDown('7'))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}
	}

	if(KeyDown('8'))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}
	}

	if(KeyDown('9'))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}
	}


	if(KeyDown('0'))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}
	}

	if(KeyDown(VK_F1))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}
	}


	if(KeyDown(VK_F2))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}

	}


	if(KeyDown(VK_F3))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}

	}


	if(KeyDown(VK_F4))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}

	}


	if(KeyDown(VK_F5))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}

	}


	if(KeyDown(VK_F6))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}

	}


	if(KeyDown(VK_F7))
	{
		if(GetTickCount() - KeyTime > 200)
		{

			KeyTime = GetTickCount();
		}

	}


	if(KeyDown(VK_F8))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}

	}


	if(KeyDown(VK_F9))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}

	}


	if(KeyDown(VK_F10))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}

	}


	if(KeyDown(VK_F11))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}

	}


	if(KeyDown(VK_F12))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}

	}
*/



	if (KeyDown(VK_SPACE))  //��ȸ��
	{

		if (GetTickCount() - KeyTime2 > 200)
		{
			if (Gmanager.m_GameStart == true) //�������϶�
			{
				if (pipe.rotate_ok == 1) //���� �� ������
				{

					if (pipe.type == 3) //3�������� �����´ϱ� 0
					{
						pipe.rotate_num = 0;
					}
					else if (pipe.rotate_num == 3) //���� ����
					{
						pipe.rotate_num = 0;
					}
					else // �ƴϸ� ȸ��
					{
						pipe.rotate_num++;
					}
				}

			}

			KeyTime2 = GetTickCount();
		}

	}



	//if(KeyDown(VK_LEFT))
	//{
	//	if(GetTickCount() - KeyTime1 > 10)
	//	{

	//
	//		KeyTime1 = GetTickCount();
	//	}
	//}

	//if(KeyDown(VK_RIGHT))
	//{

	//	if(GetTickCount() - KeyTime1 > 10)
	//	{
	//	
	//		KeyTime1 = GetTickCount();
	//	}
	//	
	//}

	//
	//if(KeyDown(VK_UP))
	//{
	//	if(GetTickCount() - KeyTime3 > 10)
	//	{	

	//		KeyTime3 = GetTickCount();
	//	}
	//	
	//}

	//if(KeyDown(VK_DOWN))
	//{

	//	if(GetTickCount() - KeyTime3 > 10)
	//	{
	//		
	//	
	//		KeyTime3 = GetTickCount();
	//	}
	//	
	//}


	//if(KeyDown('C') )
	//{
	//	if(GetTickCount() - KeyTime1 > 200)
	//	{	
	//		KeyTime1 = GetTickCount();
	//	}
	//}




	//
	//if(KeyDown('N'))
	//{
	//	
	//	if(GetTickCount() - KeyTime > 200)
	//	{			
	//		KeyTime = GetTickCount();
	//	}
	//}

	//
	//if(KeyDown('A'))
	//{
	//	if(GetTickCount() - KeyTime > 200)
	//	{
	//		KeyTime = GetTickCount();
	//	}
	//}




	//if(KeyDown('W') )
	//{
	//	if(GetTickCount() - KeyTime > 200)
	//	{
	//		
	//		KeyTime = GetTickCount(); 
	//	}

	//}


	//if(KeyDown('E')  )
	//{
	//	if(GetTickCount() - KeyTime > 200)
	//	{	
	//		KeyTime = GetTickCount();
	//	}
	//	
	//}


	//if(KeyDown('R') )
	//{
	//	if(GetTickCount() - KeyTime > 200)
	//	{

	//		KeyTime = GetTickCount();
	//	}
	//}


	//if(KeyDown('S') )
	//{
	//	if(GetTickCount() - KeyTime > 200)
	//	{
	//
	//		KeyTime = GetTickCount();
	//	}
	//}


	//if(KeyDown('D') )
	//{
	//	if(GetTickCount() - KeyTime > 200)
	//	{
	//		
	//		KeyTime = GetTickCount();
	//	}
	//}


	/*if(KeyDown(VK_RETURN) )
	{
		system("pause");

	}
*/
}
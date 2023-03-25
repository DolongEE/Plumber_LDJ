#pragma once
#include "Include.h"


EventBlock eventblock;

EventBlock::EventBlock(void)
{
}

EventBlock::~EventBlock(void)
{
}

bool EventBlock::ClearCheck()
{
    int count = 0;
    for (int i = 0; i < 29; i++)
    {
        for (int k = 0; k < 29; k++)
        {
            //해당배열에 클리어 체크가 되어잇으면
            if (map.BackGround[i][k] == PP_CLEAR_CHECK)
            {
                //카운트1 증가
                count++;
            }
        }
    }

    //클리어 목표와 클리어체크의 갯수가 일치하면 트루
    if (clear_Count == count)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void EventBlock::Init()
{

    valvecount = 0;
    valvecheck = false;

    clear_Count = 0;

    char FileName[256];

    for (int i = 0; i < 4; i++)
    {
        sprintf_s(FileName, "./resource/images/start/Start%02d.png", i);
        Start[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
    }

    for (int i = 0; i < 4; i++)
    {
        sprintf_s(FileName, "./resource/images/start/Valve%02d.png", i);
        Start_Valve[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
    }


    Block.Create("./resource/images/start/obs.png", false, D3DCOLOR_XRGB(0, 0, 0));

    // 흙 그림
    Soil.Create("./resource/images/start/soil.png", false, D3DCOLOR_XRGB(0, 0, 0));


    for (int i = 0; i < 10; i++)
    {
        sprintf_s(FileName, "./resource/images/number/%d.png", i);
        Time[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
    }
}





void EventBlock::Update()
{
    if (Gmanager.m_GameStart == true)
    {
        //벨브가 켜졋으면
        if (valvecheck == true)
        {
            //돌아가는 애니메이션
            if (GetTickCount() - Valve_ani > 100)
            {
                valvecount++;
                if (valvecount > 3) valvecount = 0;
                Valve_ani = GetTickCount();
            }
        }
    }
}





void EventBlock::Draw()
{
    if (Gmanager.m_GameStart == true)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int k = 0; k < 9; k++)
            {
                if (pipe.save[i][k].isStart == false && pipe.save[i][k].isClear == false)
                {
                    Soil.Render((k * BLOCKSIZE + BACKSTART), (i * BLOCKSIZE + BACKSTART), 0, 1, 1);
                }
            }
        }
        for (int i = 0; i < 9; i++)
        {
            for (int k = 0; k < 9; k++)
            {
                if (pipe.save[i][k].isStart == true)		//해당위치가 스타트지점이면 스타트이미지를 그려준다
                {
                    Start[pipe.save[i][k].rotate].Render((k * BLOCKSIZE + BACKSTART), (i * BLOCKSIZE + BACKSTART), 0, 1, 1);
                    Start_Valve[valvecount].Render((k * BLOCKSIZE + BACKSTART), (i * BLOCKSIZE + BACKSTART), 0, 1, 1);

                }

                else if (pipe.save[i][k].isClear == true)		//해당위치가 클리어지점이면 클리어이미지를 그려준다
                {
                    Start[pipe.save[i][k].rotate].Render((k * BLOCKSIZE + BACKSTART), (i * BLOCKSIZE + BACKSTART), 0, 1, 1);


                }
                else if (pipe.save[i][k].isBlock == true)		//해당위치가 장애물이면 장애물이미지를 그려준다
                {
                    Block.Render((k * BLOCKSIZE + BACKSTART), (i * BLOCKSIZE + BACKSTART), 0, 1, 1);
                }
            }

        }

      


        //제한시간 그려주기

        //남은시간을 나눗셈과 빼기를 사용하여 10의자리수 1의자리수를 구해 해당 이미지를 출력

        int temp, temp1, temp2, temp3;

        temp = map.cleartime; // 152

        temp1 = temp / 100; // 100자리

        temp2 = (temp - temp1 * 100) / 10; // 10자리

        temp3 = temp - temp1 * 100 - temp2 * 10; // 1자리

        Time[temp1].Render(804, 673, 0, 1, 1);

        Time[temp2].Render(836, 673, 0, 1, 1);

        Time[temp3].Render(868, 673, 0, 1, 1);


    }
}



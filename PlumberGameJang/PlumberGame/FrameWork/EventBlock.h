#pragma once
#include "Include.h"


class EventBlock
{
public:
    EventBlock(void);
    ~EventBlock(void);

    //제한시간 이미지 스프라이트
    Sprite Time[10];

    //스타트,클리어블럭,벨브 스프라이트
    Sprite Start[4];
    Sprite Start_Valve[4];

    //벨브용 애니메이션 변수
    DWORD Valve_ani;
    int valvecount;
    bool valvecheck;
    bool clockcount = true;
    //클리어목표 저장
    int clear_Count;

    //장애물 이미지 스프라이트
    Sprite Block;

    //흙 이미지 스프라이트
    Sprite Soil;

    //장애물 배열정보
    int block[3][3] = {
        2,2,2,
        2,0,2,
        2,2,2
    };

    //스타트 배열정보
    int start[4][3][3] = {
        2,3,2,
        2,2,2,
        2,2,2,

        2,2,2,
        2,2,3,
        2,2,2,

        2,2,2,
        2,2,2,
        2,3,2,

        2,2,2,
        3,2,2,
        2,2,2
    };

    //클리어 배열정보
    int clear[4][3][3] = {
        2,6,2,
        2,2,2,
        2,2,2,

        2,2,2,
        2,2,6,
        2,2,2,

        2,2,2,
        2,2,2,
        2,6,2,

        2,2,2,
        6,2,2,
        2,2,2
    };


    void Init();
    void Update();
    void Draw();

    //클리어인지 아닌지 체크하는 함수
    bool ClearCheck();
};

extern EventBlock eventblock;
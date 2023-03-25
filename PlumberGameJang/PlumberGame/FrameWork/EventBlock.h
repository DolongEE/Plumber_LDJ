#pragma once
#include "Include.h"


class EventBlock
{
public:
    EventBlock(void);
    ~EventBlock(void);

    //���ѽð� �̹��� ��������Ʈ
    Sprite Time[10];

    //��ŸƮ,Ŭ�����,���� ��������Ʈ
    Sprite Start[4];
    Sprite Start_Valve[4];

    //����� �ִϸ��̼� ����
    DWORD Valve_ani;
    int valvecount;
    bool valvecheck;
    bool clockcount = true;
    //Ŭ�����ǥ ����
    int clear_Count;

    //��ֹ� �̹��� ��������Ʈ
    Sprite Block;

    //�� �̹��� ��������Ʈ
    Sprite Soil;

    //��ֹ� �迭����
    int block[3][3] = {
        2,2,2,
        2,0,2,
        2,2,2
    };

    //��ŸƮ �迭����
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

    //Ŭ���� �迭����
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

    //Ŭ�������� �ƴ��� üũ�ϴ� �Լ�
    bool ClearCheck();
};

extern EventBlock eventblock;
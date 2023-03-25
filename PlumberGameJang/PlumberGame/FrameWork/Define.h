#pragma once
#include "Include.h" 

#define SCREEN_WITH 1050		// ȭ�� ���� �ȼ�ũ��
#define SCREEN_HEIGHT 768	// ȭ�� ���� �ȼ�ũ��

#define FRAME 1000
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3


#define PIPECREATE_W 848
#define PIPECREATE_H 515


//����������ư ��ŸƮ����
#define Stage_X 70
#define Stage_Y 72

//�������� ��ư������ ����
#define Stage_X_P 50
#define Stage_Y_P 72

//�������� ��ư ������
#define Stage_X_Size 190
#define Stage_Y_Size 160



#define BACKSTART 96
#define BLOCKSIZE 64

#define CHOP(x) x[strlen(x) - 1] = ' '5


enum gamechap
{
	LOGO = 0,
	MENU = 1,
	GAME = 2,
	OVER = 3,
	TOTALCHAP
};

enum alphabet
{
	A_, B_, C_, D_, E_, F_, G_, H_, I_, J_, K_, L_
};
enum gamework
{
	INIT = 0,
	WORK = 1,
	DRAW = 2
};

enum blockkind
{
	PIPE = 0,
	START = 1,
	CLEAR = 2,
	BLOCK = 3
};



#define PP_EMPTY 0
#define PP_LINE 1
#define PP_WALL 2
#define PP_NOW 3
#define PP_WATER 4
#define PP_LEAK 5
#define PP_CLEAR 6
#define PP_CLEAR_CHECK 8


#pragma once
#include "Include.h"


class Cursur
{
public:
	Cursur(void);
	~Cursur(void);

	Sprite cursurimg[3];		//Ŀ�� �̹���

	//Ŀ�� ��ǥ
	double cursur_W;
	double cursur_H;

	//�ִϸ��̼ǿ� ����
	bool Click;
	DWORD cursurani;

	//Ŀ������
	float cursurcount2;

	void Init();
	void Update();
	void Draw();

	//���콺 �����϶� Ŀ�� ����ٴϰ��ϴ� �Լ�
	void CursurMove(LPARAM lParam);
};

extern Cursur cursur;
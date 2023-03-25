#pragma once
#include "Include.h"


class Cursur
{
public:
	Cursur(void);
	~Cursur(void);

	Sprite cursurimg[3];		//커서 이미지

	//커서 좌표
	double cursur_W;
	double cursur_H;

	//애니메이션용 변수
	bool Click;
	DWORD cursurani;

	//커서각도
	float cursurcount2;

	void Init();
	void Update();
	void Draw();

	//마우스 움직일때 커서 따라다니게하는 함수
	void CursurMove(LPARAM lParam);
};

extern Cursur cursur;
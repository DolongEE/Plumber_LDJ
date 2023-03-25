#pragma once
#include "Include.h"

class Map
{

public :
	Map();
	~Map();

	//제한시간
	int cleartime;

	//게임배경 이미지 스프라이트
	Sprite m_BackImg;
	Sprite Glass;
    Sprite soundIcon;
    Sprite exitButt;
    Sprite clock;

	//게임보드 배열
	int BackGround[29][29];

	//로직 검사용
	bool debug_Background;

	void Init();
	void Update(double frame);
	void Draw();

};

extern Map map;
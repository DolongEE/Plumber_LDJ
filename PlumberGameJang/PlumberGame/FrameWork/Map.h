#pragma once
#include "Include.h"

class Map
{

public :
	Map();
	~Map();

	//���ѽð�
	int cleartime;

	//���ӹ�� �̹��� ��������Ʈ
	Sprite m_BackImg;
	Sprite Glass;
    Sprite soundIcon;
    Sprite exitButt;
    Sprite clock;

	//���Ӻ��� �迭
	int BackGround[29][29];

	//���� �˻��
	bool debug_Background;

	void Init();
	void Update(double frame);
	void Draw();

};

extern Map map;
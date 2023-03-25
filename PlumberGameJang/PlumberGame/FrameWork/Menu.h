#ifndef __Menu_H__
#define __Menu_H__

class Menu : public Chap
{


public:
	Menu();
	~Menu();
	//메뉴 이미지용
	Sprite mainimg;
	Sprite startimg;
	Sprite exitimg;
	Sprite Helpimg;

	//스테이지 이미지용
	Sprite Stage[2][10];
	Sprite StageBack[2];
	Sprite Black;

	//스코어보드용
	Sprite ScoreBoardimg;

	//스테이지 버튼 효과용 변수
	int button_push[12];

	//시작 종료 스코어 버튼 효과용 변수
	int mouseOverStart;
	int mouseOverExit;
	int mouseOverScore;
	bool muteChk;
	//스코어 보드가 켜져잇는지
	bool OnHelp;

	//스테이지 선택창이 켜져잇는지
	bool OnStage;

	//스코어 보드 효과용
	float scoresize;

	//메뉴 사운드 한번만나게
	bool menusoundcheck;

	//스테이지버튼 마우스 입력용
	void StageMouseMove(LPARAM lParam);
	void StageMouseDown(LPARAM lParam);


	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

};

extern Menu menu;

#endif
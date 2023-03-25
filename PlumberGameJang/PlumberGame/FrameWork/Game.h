#ifndef __Game_H__
#define __Game_H__

class Game : public Chap
{
public:
	Game();
	~Game();
	
	//클리어 오버 이미지 알파값
	float speed;
	float alpha;

	//게임 종료됫는지 아닌지
	bool GameSet;

	//클리어,오버 효과용 이미지 스프라이트
	Sprite Over;
	Sprite Clear;
	Sprite Black;
	Sprite Packing[3];

	//클리어,오버 사운드가 한번만 나도록 하는 변수
	bool soundcheck;
	FILE *fp;

	DWORD GameTime;
	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

};

#endif
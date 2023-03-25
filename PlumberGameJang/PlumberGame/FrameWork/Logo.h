#ifndef __Logo_H__
#define __Logo_H__

class Logo : public Chap
{
public:
	Logo();
	~Logo();

	HWND hWnd;

	//로고 이미지 출력
	Sprite loadimg;

	//인트로사운드 한번만 나게
	bool introsoundcheck;

	//로고 알파값
	float speed;
	float alpha;

	// 데이타 베이스 테스트
	int count = 0;
	char cnt[256];
	char pw[256];


	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

	
};

#endif
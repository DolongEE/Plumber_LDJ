#ifndef __Game_H__
#define __Game_H__

class Game : public Chap
{
public:
	Game();
	~Game();
	
	//Ŭ���� ���� �̹��� ���İ�
	float speed;
	float alpha;

	//���� ����̴��� �ƴ���
	bool GameSet;

	//Ŭ����,���� ȿ���� �̹��� ��������Ʈ
	Sprite Over;
	Sprite Clear;
	Sprite Black;
	Sprite Packing[3];

	//Ŭ����,���� ���尡 �ѹ��� ������ �ϴ� ����
	bool soundcheck;
	FILE *fp;

	DWORD GameTime;
	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

};

#endif
#ifndef __Menu_H__
#define __Menu_H__

class Menu : public Chap
{


public:
	Menu();
	~Menu();
	//�޴� �̹�����
	Sprite mainimg;
	Sprite startimg;
	Sprite exitimg;
	Sprite Helpimg;

	//�������� �̹�����
	Sprite Stage[2][10];
	Sprite StageBack[2];
	Sprite Black;

	//���ھ���
	Sprite ScoreBoardimg;

	//�������� ��ư ȿ���� ����
	int button_push[12];

	//���� ���� ���ھ� ��ư ȿ���� ����
	int mouseOverStart;
	int mouseOverExit;
	int mouseOverScore;
	bool muteChk;
	//���ھ� ���尡 �����մ���
	bool OnHelp;

	//�������� ����â�� �����մ���
	bool OnStage;

	//���ھ� ���� ȿ����
	float scoresize;

	//�޴� ���� �ѹ�������
	bool menusoundcheck;

	//����������ư ���콺 �Է¿�
	void StageMouseMove(LPARAM lParam);
	void StageMouseDown(LPARAM lParam);


	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

};

extern Menu menu;

#endif
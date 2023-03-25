#pragma once



class GameManager
{
public:
	GameManager(void);
	~GameManager(void);

	//�Ͻ����� (�̱���)
	bool m_Pause;

	//������ ���۵̴��� �ƴ���
	bool m_GameStart;

	//���ӻ� ÷�� �ѹ��� �ʱ�ȭ�Ǵ� �κ�
	void GameReset();

	void Init();
	void Update();
	void Draw();
;	
};

extern GameManager Gmanager;
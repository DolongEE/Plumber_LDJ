#pragma once



class GameManager
{
public:
	GameManager(void);
	~GameManager(void);

	//일시정지 (미구현)
	bool m_Pause;

	//게임이 시작됫는지 아닌지
	bool m_GameStart;

	//게임상 첨에 한번만 초기화되는 부분
	void GameReset();

	void Init();
	void Update();
	void Draw();
;	
};

extern GameManager Gmanager;
#pragma once
#include "Include.h"


class Pipe
{
public:
	Pipe(void);
	~Pipe(void);

	Sprite p_pipe[4][4];	//파이프 이미지 스프라이트
	

	//물 이미지 스프라이트
	Sprite p_waterani[4][4][4][3];
	Sprite p_watermove[4][4][4][3];

	//스테이지 저장정보 로드용
	FILE *fp;


	//미리 보여주는 파이프값 설정
	int type1;
	double H_type1;
	int rotate1;

	int type2;
	double H_type2;
	int rotate2;

	int type3;
	double H_type3;
	int rotate3;

	double W_type;

	int type;	//파이프 타입

	int rotate_ok;	//돌릴수 잇는지없는지

	int mouse;		//마우스로 파이프를 잡앗는지 아닌지


	//컨트롤 가능한 파이프 위치
	double m_W;		
	double m_H;

	int rotate_num;		//돌린각도

	bool pipeup_ok;		//파이프 집을수 잇는지 없는지

	struct pipedrowsave		// 놓은 파이프 정보 저장 구조체
	{
		bool isPipe;
		int type;
		int rotate;
		bool isWater;
		bool WaterMax;
		int MaxWaterCount;
		int WaterCount;
		int WaterMoveCount;
		bool isStart;
		bool isClear;
		int water_In;
		bool isBlock;		
	};
	pipedrowsave save[9][9];

	DWORD waterupdate;	//물 흐르는 시간조절 변수

	struct Water		//현재 물위치 저장 구조체
	{
		int i;
		int k;
	};
	Water water[50];

	int water_count;	// 현재 흐르는물 잇는지 없는지   // 0 있음 // 1 없음 //

	int clear; //클리어정보

	void Init();	
	void Update();
	void Draw();



	void Reset();	//리셋
	void PipeBack();//파이프 처음위치로 되돌리기
	void PipeCreate();

	void AddPipe(int kind, int back1, int back2, int rotate = 0, int type = 0);	//파이프배열을 백그라운드 배열에 적용

	int PipeMouseUP(LPARAM lParam);	//파이프에서 마우스를 뗏을떄

	void PipeMove(LPARAM lParam);	//파이프를 들고 움직일때

	void ValveOn(LPARAM lParam);	//벨브를 눌럿을떄

	void NowWaterCheck();		//흐르는물 체크

	void WaterMove(int count);	//파이프따라 물 한칸씩 전진

	void WaterImgCheck();		//해당 파이프 위치에 물이 들어왓을떄 물이 들어왓다고 켜줌

	int Type();				//타입 확률조정

	void Load(int stage);		//스테이지 로드

	// 파이프 타입별 각도별 배열정보
	int pipe_Block[4][4][3][3] = {
		//ㅣ
        2,1,2,
		2,1,2,
		2,1,2,
        //ㅡ
		2,2,2,
		1,1,1,
		2,2,2,

		2,1,2,
		2,1,2,
		2,1,2,

		2,2,2,
		1,1,1,
		2,2,2,

		/////
        //ㅏ
		2,1,2,
		2,1,1,
		2,1,2,
        //ㅜ
		2,2,2,
		1,1,1,
		2,1,2,
        //ㅓ
		2,1,2,
		1,1,2,
		2,1,2,
        //ㅗ
		2,1,2,
		1,1,1,
		2,2,2,

		/////
        //
		2,2,2,
		2,1,1,
		2,1,2,
        //ㄱ
		2,2,2,
		1,1,2,
		2,1,2,

		2,1,2,
		1,1,2,
		2,2,2,
        //ㄴ
		2,1,2,
		2,1,1,
		2,2,2,

		/////
        //+
		2,1,2,
		1,1,1,
		2,1,2,

		2,1,2,
		1,1,1,
		2,1,2,

		2,1,2,
		1,1,1,
		2,1,2,

		2,1,2,
		1,1,1,
		2,1,2
	};
	
};

extern Pipe pipe;


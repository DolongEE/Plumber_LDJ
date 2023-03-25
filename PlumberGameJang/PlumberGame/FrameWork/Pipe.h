#pragma once
#include "Include.h"


class Pipe
{
public:
	Pipe(void);
	~Pipe(void);

	Sprite p_pipe[4][4];	//������ �̹��� ��������Ʈ
	

	//�� �̹��� ��������Ʈ
	Sprite p_waterani[4][4][4][3];
	Sprite p_watermove[4][4][4][3];

	//�������� �������� �ε��
	FILE *fp;


	//�̸� �����ִ� �������� ����
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

	int type;	//������ Ÿ��

	int rotate_ok;	//������ �մ���������

	int mouse;		//���콺�� �������� ��Ѵ��� �ƴ���


	//��Ʈ�� ������ ������ ��ġ
	double m_W;		
	double m_H;

	int rotate_num;		//��������

	bool pipeup_ok;		//������ ������ �մ��� ������

	struct pipedrowsave		// ���� ������ ���� ���� ����ü
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

	DWORD waterupdate;	//�� �帣�� �ð����� ����

	struct Water		//���� ����ġ ���� ����ü
	{
		int i;
		int k;
	};
	Water water[50];

	int water_count;	// ���� �帣�¹� �մ��� ������   // 0 ���� // 1 ���� //

	int clear; //Ŭ��������

	void Init();	
	void Update();
	void Draw();



	void Reset();	//����
	void PipeBack();//������ ó����ġ�� �ǵ�����
	void PipeCreate();

	void AddPipe(int kind, int back1, int back2, int rotate = 0, int type = 0);	//�������迭�� ��׶��� �迭�� ����

	int PipeMouseUP(LPARAM lParam);	//���������� ���콺�� ������

	void PipeMove(LPARAM lParam);	//�������� ��� �����϶�

	void ValveOn(LPARAM lParam);	//���긦 ��������

	void NowWaterCheck();		//�帣�¹� üũ

	void WaterMove(int count);	//���������� �� ��ĭ�� ����

	void WaterImgCheck();		//�ش� ������ ��ġ�� ���� �������� ���� ���Ӵٰ� ����

	int Type();				//Ÿ�� Ȯ������

	void Load(int stage);		//�������� �ε�

	// ������ Ÿ�Ժ� ������ �迭����
	int pipe_Block[4][4][3][3] = {
		//��
        2,1,2,
		2,1,2,
		2,1,2,
        //��
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
        //��
		2,1,2,
		2,1,1,
		2,1,2,
        //��
		2,2,2,
		1,1,1,
		2,1,2,
        //��
		2,1,2,
		1,1,2,
		2,1,2,
        //��
		2,1,2,
		1,1,1,
		2,2,2,

		/////
        //
		2,2,2,
		2,1,1,
		2,1,2,
        //��
		2,2,2,
		1,1,2,
		2,1,2,

		2,1,2,
		1,1,2,
		2,2,2,
        //��
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


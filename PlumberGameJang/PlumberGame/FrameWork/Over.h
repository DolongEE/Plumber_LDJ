#ifndef __Over_H__
#define __Over_H__

class Over : public Chap
{
public:
	Over();
	~Over();

	// 미사용중 데이타베이스 이니셜입력용으로 사용예정


	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);
};

#endif
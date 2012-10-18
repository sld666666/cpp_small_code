#pragma once
#include "interprocessConstant.h"

class GameOprator : public CWnd
{

public:
	GameOprator();
	~GameOprator();

	
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTimer(UINT_PTR nIDEvent);

private:
	void	doMsgQueueOperator();
	void	doOperator(MSG_QUEUE_TYPE type);

};

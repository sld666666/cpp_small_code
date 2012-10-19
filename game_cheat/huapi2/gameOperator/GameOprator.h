#pragma once
#include "MsgQueueListener.h"

class GameOprator : public CWnd
{

public:
	GameOprator();
	~GameOprator();

	
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTimer(UINT_PTR nIDEvent);

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
private:
	MsgQueueListener	msgQueueListener_;
};

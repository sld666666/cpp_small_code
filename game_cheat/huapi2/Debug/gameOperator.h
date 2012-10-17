// gameOperator.h : gameOperator DLL 的主头文件
//

#pragma once


class CgameOperatorApp : public CWinApp
{
public:
	CgameOperatorApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

#include "StdAfx.h"
#include "GameOprator.h"

BEGIN_MESSAGE_MAP(GameOprator, CWnd)
	ON_WM_TIMER()
	ON_WM_CREATE()
END_MESSAGE_MAP()

GameOprator::GameOprator()
{
	TRACE("create");
	msgQueueListener_.start();
//	AfxMessageBox(_T("new"));
// 	CWnd::CreateEx(WS_EX_TOOLWINDOW, AfxRegisterWndClass(0),0, 0,0,0,0
// 		,0,this-> GetSafeHwnd(), NULL, NULL);
}

GameOprator::~GameOprator()
{

}



void GameOprator::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ÔÚ´ËÌí¼ÓÏûÏ¢´¦Àí³ÌÐò´úÂëºÍ/»òµ÷ÓÃÄ¬ÈÏÖµ
// 	switch(nIDEvent)
// 	{
// 	case TT_MSGCHEACKER:
// 		TRACE("ontimer 1");
// 		AfxMessageBox(_T("OnTimer"));
// 		break;
// 	default:
// 		break;
// 	}

	CWnd::OnTimer(nIDEvent);
}

int GameOprator::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ÔÚ´ËÌí¼ÓÄú×¨ÓÃµÄ´´½¨´úÂë
	msgQueueListener_.start();

	AfxMessageBox(_T("create listener sucess"));
	return 0;
}

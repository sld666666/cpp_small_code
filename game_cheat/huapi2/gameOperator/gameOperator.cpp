// gameOperator.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "gameOperator.h"
#include "GameOprator.h"
#include "XmlConfig.h"
#include <boost/shared_ptr.hpp>

using namespace boost;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: 如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CgameOperatorApp

BEGIN_MESSAGE_MAP(CgameOperatorApp, CWinApp)
END_MESSAGE_MAP()


// CgameOperatorApp 构造

CgameOperatorApp::CgameOperatorApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CgameOperatorApp 对象

CgameOperatorApp theApp;
HHOOK gHook;
shared_ptr<GameOprator> gGameOpreator;

// CgameOperatorApp 初始化

BOOL CgameOperatorApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0); 
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

LRESULT CALLBACK LauncherHook(int nCode,WPARAM wParam,LPARAM lParam)
{
	if (!gGameOpreator.get())
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());

		TRACE("hook");
		//gGameOpreator = shared_ptr<GameOprator>(new GameOprator());

		AfxMessageBox(_T("hook secuss"));
	}

	LRESULT Result=CallNextHookEx(gHook,nCode,wParam,lParam);

	return Result;
}

_declspec(dllexport) void WINAPI installHook()
{
	XmlConfig::instance().init();
	wstring targetCaption = s2ws(XmlConfig::instance().getValue("game.caption"));

	HWND targetHandle = FindWindow(NULL,targetCaption.c_str());
	if (!targetHandle)
	{
		AfxMessageBox(_T("can not find the game window"));
		return;
	}

	DWORD processId = ::GetWindowThreadProcessId(targetHandle, NULL);

	gHook=(HHOOK)SetWindowsHookEx(WH_KEYBOARD,(HOOKPROC)LauncherHook,
		theApp.m_hInstance,processId);

}

_declspec(dllexport) void WINAPI unInstallHook()
{
	AfxMessageBox(_T("un hook"));
	::UnhookWindowsHookEx(gHook);
}

_declspec(dllexport)void WINAPI doOperator(int type)
{
// 	if (gGameOpreator.get())
// 		gGameOpreator->doMsgQueueOperator(type);

}




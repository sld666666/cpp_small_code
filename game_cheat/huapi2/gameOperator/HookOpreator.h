
#pragma once
#include <wtypes.h>

_declspec(dllexport)void WINAPI installHook();
_declspec(dllexport)void WINAPI unInstallHook();
_declspec(dllexport)void WINAPI doOperator(int type);


#pragma once

class __declspec(dllexport) GameOprator
{

public:
	GameOprator();
	~GameOprator();
private:
	HHOOK hook_;
};

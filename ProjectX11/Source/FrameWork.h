#pragma once
#include "System/WinApp.h"
class FrameWork {
public:
	FrameWork();
	~FrameWork() = default;

	bool Initialize();

	void Finalize();

	void Run();

private:
	WinApp m_winApp;
};

#include "FrameWork.h"

FrameWork::FrameWork()
	:m_winApp()
{}

bool FrameWork::Initialize() {

	//ウィンドウの初期化
	if (!m_winApp.Initialize(L"DirectX12 2DGame")) return false;

	return true;
}

void FrameWork::Run() {
	while (m_winApp.ProcessMassage())
	{

	}
}

void FrameWork::Finalize() {
	m_winApp.Finalize();
}
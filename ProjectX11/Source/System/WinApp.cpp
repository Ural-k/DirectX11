#include "WinApp.h"

WinApp::WinApp()
	:m_hwnd(nullptr),
	m_hInstance(nullptr),
	m_wc()
{}

bool WinApp::Initialize(const wchar_t* title) {
	//ハンドルインスタンスを取得
	m_hInstance = GetModuleHandle(nullptr);

	//ウィンドウクラスの設定
	m_wc.cbSize = sizeof(WNDCLASSEX);
	m_wc.style = CS_HREDRAW | CS_VREDRAW;
	m_wc.lpfnWndProc = WindowProcedure;
	m_wc.hInstance = m_hInstance;
	m_wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	m_wc.lpszClassName = L"DX12WindowClass";

	//ウィンドウクラスの登録
	if (!RegisterClassEx(&m_wc)) return false;

	//クライアント領域サイズを指定してウィンドウサイズを調整
	RECT wrc = { 0, 0, kDefaultWidth, kDefaultHeight };
	AdjustWindowRect( &wrc, WS_OVERLAPPEDWINDOW, FALSE );

	m_hwnd = CreateWindowEx(
		0,
		m_wc.lpszClassName,  //拡張ウィンドウスタイル
		title,				 //ウィンドウクラス名
		WS_OVERLAPPEDWINDOW, //タイトルバーの文字
		CW_USEDEFAULT,		 //表示X座標(OS)
		CW_USEDEFAULT,		 //表示Y座標(OS)
		wrc.right - wrc.left,//ウィンドウの横幅
		wrc.bottom - wrc.top,//ウィンドウの縦幅
		nullptr,			 //親ウィンドウハンドル
		nullptr,			 //メニューハンドル
		m_hInstance,         //インスタンスハンドル
		nullptr				 //追加パラメータ
	);

	if (!m_hwnd) return false;

	//ウィンドウの表示
	ShowWindow(m_hwnd, SW_SHOW);

	return true;

}

void WinApp::Finalize() 
{
	if (m_hwnd) 
	{
		DestroyWindow(m_hwnd);
		m_hwnd = nullptr;
	}

	//最初に登録したウィンドウクラスを解除する
	UnregisterClass(m_wc.lpszClassName, m_hInstance);
}

bool WinApp::ProcessMassage() {
	MSG msg{};

	//メッセージが来ているか確認し来ていたら処理する
	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) 
	{
		TranslateMessage(&msg); //キーボードメッセージを処理する
		DispatchMessage(&msg);  //ウィンドウプロシージャにメッセージを送る

		//終了メッセージが来たらfalseを返す
		if (msg.message == WM_QUIT) return false;
	}

	return true;
}

LRESULT WinApp::WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_KEYDOWN:
		//ESCキーが押されたら終了
		if (wparam == VK_ESCAPE) {
			PostQuitMessage(0);
		}
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}
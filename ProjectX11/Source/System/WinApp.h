#pragma once
#include <Windows.h>
#include <cstdint>

class WinApp {
public:
	//クライアント領域のデフォルトサイズ
	static constexpr int32_t kDefaultWidth = 1280;
	static constexpr int32_t kDefaultHeight = 720;

	WinApp();
	~WinApp() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	bool Initialize(const wchar_t* title);

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize();

	/// <summary>
	/// メッセージ処理
	/// </summary>
	bool ProcessMassage();


private:

	static LRESULT CALLBACK  WindowProcedure(HWND, UINT, WPARAM, LPARAM);

	HWND m_hwnd			  = nullptr; //どのウィンドウに対して操作するかのハンドル
	HINSTANCE m_hInstance = nullptr; //実行中のプログラムのインスタンスハンドル（インスタンスを識別・操作するためのハンドル）
	WNDCLASSEX m_wc{};               //ウィンドウの設計図を格納
};
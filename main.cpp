#include <Windows.h>
#include <wchar.h>
#include <d3d11.h>

LRESULT CALLBACK winprocedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hThis, HINSTANCE hPrev, LPSTR args, int NCMD) {
	HWND handle;
	WNDCLASSEXW wndClass = { sizeof(WNDCLASSEXW) };
	wndClass.lpszClassName = L"Wnd";
	wndClass.hInstance = hThis;
	wndClass.lpfnWndProc = winprocedure;

	if (!RegisterClassExW(&wndClass))
		MessageBoxW(nullptr, L"Cannot Register Class", L"Prog", MB_OK);

	handle = CreateWindowExW(0, wndClass.lpszClassName, L"Gaem", WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, wndClass.hInstance, nullptr);

	if (handle == INVALID_HANDLE_VALUE)
		MessageBoxW(nullptr, L"0xC8", L"game", MB_OK);

	MSG message;
	while (true) {
		if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);
			if ( message.message == WM_QUIT ) {
				break;
			}
		} else {
			//RENDER!
		}
	}
	return (int)message.wParam;
}

LRESULT CALLBACK winprocedure(HWND handle , UINT msg, WPARAM wp, LPARAM lp) {
	switch(msg) {
	default:
		return DefWindowProcW(handle, msg, wp, lp);
	}
}

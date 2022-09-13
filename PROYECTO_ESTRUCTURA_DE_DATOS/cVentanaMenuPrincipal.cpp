#include <Windows.h>
#include "resource.h"

BOOL CALLBACK cMenuPrincipal(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cMenuOpciones(HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain(_In_ HINSTANCE hInst,_In_opt_ HINSTANCE hPrev, _In_ PSTR cmdLine, int cShow) {

	HWND hMenuPrincial = CreateDialog(hInst, MAKEINTRESOURCE(DLG_MENUPRINCIPAL), NULL, cMenuPrincipal);
	HMENU hMenuOpciones = LoadMenu(hInst, MAKEINTRESOURCE(IDR_MENU1));
	SetMenu(hMenuPrincial, hMenuOpciones);

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	ShowWindow(hMenuPrincial, cShow);

	while (GetMessage(&msg, NULL, NULL, NULL)) {

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

	BOOL CALLBACK cMenuPrincipal(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

		switch (msg){
		case WM_CREATE: {
			break;
		}

		case	WM_CLOSE: {
			DestroyWindow(hwnd);
			break;
		}
		case WM_DESTROY: {
			PostQuitMessage(1);
			break;
		}

	}
	return FALSE;
}
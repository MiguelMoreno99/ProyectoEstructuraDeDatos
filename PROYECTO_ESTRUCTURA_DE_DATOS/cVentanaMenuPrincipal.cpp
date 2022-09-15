#include <Windows.h>
#include "resource.h"

BOOL CALLBACK cMenuPrincipal(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cInicioSesion(HWND, UINT, WPARAM, LPARAM);
HWND hMenuPrincial;
HMENU hMenuOpciones;

int WINAPI WinMain(_In_ HINSTANCE hInst,_In_opt_ HINSTANCE hPrev, _In_ PSTR cmdLine, int cShow) {

	hMenuPrincial = CreateDialog(hInst, MAKEINTRESOURCE(DLG_MENUPRINCIPAL), NULL, cMenuPrincipal);
	hMenuOpciones = LoadMenu(hInst, MAKEINTRESOURCE(IDR_MENU1));
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

		switch (msg) {

			case WM_INITDIALOG: {
				//DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_INICIOSESION), hwnd, cInicioSesion);
				break;
			}

			case WM_COMMAND: {

				switch (LOWORD(wParam)) {
					case MENU_REGISTRO_PERSONAS: {
						MessageBox(hwnd, L"Comando: Prueba", L"Mensaje de menú", MB_OK);
						break;
					}
					case MENU_SISTEMA_SALIR: {
						PostQuitMessage(0);
						break;
					}
				}
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

	BOOL CALLBACK cInicioSesion(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

		switch (msg) {
			case WM_INITDIALOG: {
				SetFocus(GetDlgItem(hwnd, BTN_INGRESAR));
				break;
			}

			case WM_COMMAND: {
				switch (LOWORD(wParam)) {
					case BTN_INGRESAR: {
						EnableWindow(hMenuPrincial, 1);
						EndDialog(hwnd, BTN_INGRESAR);
						break;
					}
					case BTN_SALIR: {
						PostQuitMessage(0);
						break;
					}
				}
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
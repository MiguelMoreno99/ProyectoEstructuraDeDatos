#include <Windows.h>
#include "resource.h"

BOOL CALLBACK cVentanaPrincipal(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cInicioSesion(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cRegistroPersonas(HWND, UINT, WPARAM, LPARAM);
HWND hVentanaPrincial;
HWND hInicioSesion;
HWND hRegistroPersonas;
HMENU hMenuOpciones;

int WINAPI WinMain(_In_ HINSTANCE hInst,_In_opt_ HINSTANCE hPrev, _In_ PSTR cmdLine, int cShow) {

	hVentanaPrincial = CreateDialog(hInst, MAKEINTRESOURCE(DLG_VENTANAPRINCIPAL), NULL, cVentanaPrincipal);
	hMenuOpciones = LoadMenu(hInst, MAKEINTRESOURCE(IDR_MENU1));
	SetMenu(hVentanaPrincial, hMenuOpciones);
	ShowWindow(hVentanaPrincial, SW_HIDE);

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

	BOOL CALLBACK cVentanaPrincipal(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg) {
			case WM_INITDIALOG: {
				hInicioSesion = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_INICIOSESION), hVentanaPrincial, cInicioSesion);
				hRegistroPersonas = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_REGISTROPERSONAS), hVentanaPrincial, cRegistroPersonas);
				ShowWindow(hInicioSesion, SW_SHOW);
			}break;
			case WM_COMMAND: {
				switch (LOWORD(wParam)) {
					case MENU_REGISTRO_PERSONAS: {
						ShowWindow(hwnd, SW_HIDE);
						ShowWindow(hRegistroPersonas, SW_SHOW);
					}break;
					case MENU_SISTEMA_SALIR: {
						PostQuitMessage(0);
					}break;
					case MENU_SISTEMA_CERRARSESION: {
						ShowWindow(hwnd, SW_HIDE);
						ShowWindow(hInicioSesion, SW_SHOW);
					}break;
				}
			}break;
			case	WM_CLOSE: {
				DestroyWindow(hwnd);
			}break;
			case WM_DESTROY: {
				PostQuitMessage(1);
			}break;
		}
		return FALSE;
	}

	BOOL CALLBACK cInicioSesion(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg) {
			case WM_INITDIALOG: {
				SetFocus(GetDlgItem(hwnd, BTN_INICIOSESION_INGRESAR));
			}break;
			case WM_COMMAND: {
				switch (LOWORD(wParam)) {
					case BTN_INICIOSESION_INGRESAR: {
						ShowWindow(hInicioSesion, SW_HIDE);
						ShowWindow(hVentanaPrincial, SW_SHOW);
					}break;
					case BTN_INICIOSESION_SALIR: {
						DestroyWindow(hwnd);
					}break;
				}
			}break;
			case WM_CLOSE: {
				DestroyWindow(hwnd);
			}break;
			case WM_DESTROY: {
				PostQuitMessage(0);
			}break;
		}
		return FALSE;
	}

	BOOL CALLBACK cRegistroPersonas(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg) {
		case WM_INITDIALOG: {
			SetFocus(GetDlgItem(hwnd, BTN_PERSONA_CAPTURAR));
		}break;
		case WM_COMMAND: {
			switch (LOWORD(wParam)) {
			case BTN_PERSONA_REGRESAR: {
				ShowWindow(hwnd, SW_HIDE);
				ShowWindow(hVentanaPrincial, SW_SHOW);
			}break;
			case BTN_PERSONA_CAPTURAR: {

			}break;
			}
		}break;
		case WM_CLOSE: {
			ShowWindow(hwnd, SW_HIDE);
			ShowWindow(hVentanaPrincial, SW_SHOW);
		}break;
		}
		return FALSE;
	}
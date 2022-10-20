#include <Windows.h>
#include "resource.h"
#include "cCapturaPersona.h"
#include "cCapturaUsuario.h"


//Variables Globales
BOOL CALLBACK cVentanaPrincipal(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cInicioSesion(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cRegistroPersonas(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cInicioSesionRegistro(HWND, UINT, WPARAM, LPARAM);
HWND hVentanaPrincial;
HWND hInicioSesion;
HWND hRegistroPersonas;
HWND hInicioSesionRegistro;
HMENU hMenuOpciones;
Persona Persona1;
Usuario Usuario1;

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
				hInicioSesionRegistro = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_INICIOSESION_REGISTRO), hInicioSesionRegistro, cInicioSesionRegistro);
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
				SetFocus(GetDlgItem(hwnd, BTN_INICIOSESION_REGISTRARSE));
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
					case BTN_INICIOSESION_REGISTRARSE: {
						ShowWindow(hInicioSesion, SW_HIDE);
						ShowWindow(hInicioSesionRegistro, SW_SHOW);
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

	BOOL CALLBACK cInicioSesionRegistro(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg) {
		case WM_INITDIALOG: {
			SetFocus(GetDlgItem(hwnd, BTN_INICIOSESION_REGISTRO_REGISTRARSE));
		}break;
		case WM_COMMAND: {
			switch (LOWORD(wParam)) {
				case BTN_INICIOSESION_REGISTRO_REGISTRARSE: {
					Usuario1.PasarInformacionUsuario(hwnd, TXTB_INICIOSESION_REGISTRO_USUARIO, TXTB_INICIOSESION_REGISTRO_CONTRASENA, TXTB_INICIOSESION_REGISTRO_NOMBRE, TXTB_INICIOSESION_REGISTRO_APELLIDOPATERNO, TXTB_INICIOSESION_REGISTRO_APELLIDOMATERNO);
					ShowWindow(hInicioSesion, SW_SHOW);
					ShowWindow(hInicioSesionRegistro, SW_HIDE);
				}break;
				case BTN_INICIOSESION_REGISTRO_SALIR: {
					ShowWindow(hInicioSesion, SW_SHOW);
					ShowWindow(hInicioSesionRegistro, SW_HIDE);
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
			HWND hComboBox;

			hComboBox =  GetDlgItem(hwnd, CB_PERSONA_ESTADOCIVIL);
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"SOLTERO(A)");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"CASADO(A)");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"DIVORCIADO(A)");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"VIUDO(A)");
			hComboBox = GetDlgItem(hwnd, CB_PERSONA_SEXO);
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"MASCULINO");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"FEMENINO");
			hComboBox = GetDlgItem(hwnd, CB_PERSONA_GRUPOOCUPACIONAL);
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"ESTUDIANTE");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"TRABAJADOR");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"DESEMPLEADO");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"AMA(O) DE CASA");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"OTRO");
			hComboBox = GetDlgItem(hwnd, CB_PERSONA_PERFILRIESGO);
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"ALTO");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"MODERADO");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"BAJO");

		}break;
		case WM_COMMAND: {
			switch (LOWORD(wParam)) {
			case BTN_PERSONA_REGRESAR: {
				ShowWindow(hwnd, SW_HIDE);
				ShowWindow(hVentanaPrincial, SW_SHOW);
			}break;
			case BTN_PERSONA_CAPTURAR: {

				Persona1.PasarInformacionPersona(hwnd, TXTB_PERSONA_APELLIDOPATERNO,TXTB_PERSONA_APELLIDOMATERNO,TXTB_PERSONA_NOMBRE,
				TXTB_PERSONA_CURP,TXTB_PERSONA_RFC,DTP_PERSONA_FECHANACIMIENTO,TXTB_PERSONA_CALLE,TXTB_PERSONA_COLONIA,
				TXTB_PERSONA_MUNICIPIO,TXTB_PERSONA_ESTADO,CB_PERSONA_ESTADOCIVIL,TXTB_PERSONA_TELEFONO,CB_PERSONA_SEXO,
				CB_PERSONA_GRUPOOCUPACIONAL,CB_PERSONA_PERFILRIESGO,BTN_PERSONA_CARGARDOCUMENTO);

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
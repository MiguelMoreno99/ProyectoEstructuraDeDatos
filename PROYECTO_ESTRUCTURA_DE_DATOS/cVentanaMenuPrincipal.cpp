#include <Windows.h>
#include "resource.h"
#include "cCapturaPersona.h"
#include "cCapturaUsuario.h"
#include "cCapturaCarnet.h"
#include "cCapturaVacuna.h"



//Variables Globales y Callbacks
BOOL CALLBACK cVentanaPrincipal(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cInicioSesion(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cInicioSesionRegistro(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cRegistroPersonas(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cRegistroCarnets(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cRegistroVacunas(HWND, UINT, WPARAM, LPARAM);
HWND hVentanaPrincipal;
HWND hInicioSesion;
HWND hInicioSesionRegistro;
HWND hRegistroPersonas;
HWND hRegistroCarnets;
HWND hRegistroVacunas;
HMENU hMenuOpciones;
Usuario Usuario1;
Persona Persona1;
Carnet Carnet1;
Vacuna Vacuna1;


int WINAPI WinMain(_In_ HINSTANCE hInst,_In_opt_ HINSTANCE hPrev, _In_ PSTR cmdLine, int cShow) {

	hVentanaPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(DLG_VENTANAPRINCIPAL), NULL, cVentanaPrincipal);
	hMenuOpciones = LoadMenu(hInst, MAKEINTRESOURCE(IDR_MENU1));
	SetMenu(hVentanaPrincipal, hMenuOpciones);
	ShowWindow(hVentanaPrincipal, SW_HIDE);

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
				hInicioSesion = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_INICIOSESION), hVentanaPrincipal, cInicioSesion);
				hInicioSesionRegistro = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_INICIOSESION_REGISTRO), hInicioSesionRegistro, cInicioSesionRegistro);
				hRegistroPersonas = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_REGISTROPERSONAS), hVentanaPrincipal, cRegistroPersonas);
				hRegistroCarnets = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_REGISTROCARNET), hVentanaPrincipal, cRegistroCarnets);
				hRegistroVacunas = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_REGISTROVACUNAS), hVentanaPrincipal, cRegistroVacunas);
				ShowWindow(hInicioSesion, SW_SHOW);
			}break;
			case WM_COMMAND: {
				switch (LOWORD(wParam)) {
					case MENU_REGISTRO_PERSONAS: {
						ShowWindow(hwnd, SW_HIDE);
						ShowWindow(hRegistroPersonas, SW_SHOW);
					}break;
					case MENU_REGISTRO_CARNETS: {
						ShowWindow(hwnd, SW_HIDE);
						ShowWindow(hRegistroCarnets, SW_SHOW);
					}break;
					case MENU_REGISTRO_VACUNAS: {
						ShowWindow(hwnd, SW_HIDE);
						ShowWindow(hRegistroVacunas, SW_SHOW);
					}break;
					case MENU_SISTEMA_SALIR: {
						Usuario1.GuardarUsuariosTxt(hwnd);
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
				Usuario1.GuardarUsuariosTxt(hwnd);
				PostQuitMessage(1);
			}break;
		}
		return FALSE;
	}

	BOOL CALLBACK cInicioSesion(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg) {
			case WM_INITDIALOG: {
				Usuario1.CargarUsuariosTxt(hwnd);
				SetFocus(GetDlgItem(hwnd, BTN_INICIOSESION_REGISTRARSE));
			}break;
			case WM_COMMAND: {
				switch (LOWORD(wParam)) {
					case BTN_INICIOSESION_INGRESAR: {
						Usuario1.ValidarUsuario(hInicioSesion, hVentanaPrincipal,TXTB_INICIOSESION_USUARIO, TXTB_INICIOSESION_CONTRASENA);
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
				Usuario1.GuardarUsuariosTxt(hwnd);
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
				ShowWindow(hVentanaPrincipal, SW_SHOW);
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
			ShowWindow(hVentanaPrincipal, SW_SHOW);
		}break;
		}
		return FALSE;
	}

	BOOL CALLBACK cRegistroCarnets(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg) {
		case WM_INITDIALOG: {
			SetFocus(GetDlgItem(hwnd, BTN_CARNET_CAPTURAR));
			HWND hComboBox;

			hComboBox = GetDlgItem(hwnd, CB_CARNET_IDVACUNA);
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"1");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"2");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"3");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"4");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"...");
			hComboBox = GetDlgItem(hwnd, CB_CARNET_DOSIS);
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"1 RA");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"2 DA");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"3 RA");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"4 TA");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"5 TA");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"6 TA");
			hComboBox = GetDlgItem(hwnd, CB_CARNET_CENTROVACUNACION);
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"NORTE");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"CENTRO");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"SUR");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"ESTE");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"OESTE");

		}break;
		case WM_COMMAND: {
			switch (LOWORD(wParam)) {
			case BTN_CARNET_REGRESAR: {
				ShowWindow(hwnd, SW_HIDE);
				ShowWindow(hVentanaPrincipal, SW_SHOW);
			}break;
			case BTN_CARNET_CAPTURAR: {

				Carnet1.PasarInformacionCarnet(hwnd, TXTB_CARNET_CURP, CB_CARNET_IDVACUNA, TXTB_CARNET_LOTE, 
				DTP_CARNET_FECHADOSIS, CB_CARNET_DOSIS, CB_CARNET_CENTROVACUNACION);

			}break;
			}
		}break;
		case WM_CLOSE: {
			ShowWindow(hwnd, SW_HIDE);
			ShowWindow(hVentanaPrincipal, SW_SHOW);
		}break;
		}
		return FALSE;
	}

	BOOL CALLBACK cRegistroVacunas(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg) {
		case WM_INITDIALOG: {
			SetFocus(GetDlgItem(hwnd, BTN_VACUNA_CAPTURAR));
			HWND hComboBox;

			hComboBox = GetDlgItem(hwnd, CB_VACUNA_MARCA);
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"PFIZER-BIONTECH");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"MODERNA");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"NOVAVAX");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"JANSSEN DE JOHNSON");
			hComboBox = GetDlgItem(hwnd, CB_VACUNA_DOSIS);
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"1");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"2");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"3");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"4");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"5");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"6");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"7");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"8");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"9");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"10");
			hComboBox = GetDlgItem(hwnd, CB_VACUNA_TIPO);
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"ARN MENSAJERO");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"SUB-UNIDADES PROTEICAS");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"VECTOR VIRAL");
			SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"OTRO");

		}break;
		case WM_COMMAND: {
			switch (LOWORD(wParam)) {
			case BTN_VACUNA_REGRESAR: {
				ShowWindow(hwnd, SW_HIDE);
				ShowWindow(hVentanaPrincipal, SW_SHOW);
			}break;
			case BTN_VACUNA_CAPTURAR: {

				Vacuna1.PasarInformacionVacuna(hwnd, CB_VACUNA_TIPO, CB_VACUNA_MARCA, CB_VACUNA_DOSIS, TXTB_VACUNA_PRECIO, TXTB_VACUNA_DESCRIPCION);


			}break;
			}
		}break;
		case WM_CLOSE: {
			ShowWindow(hwnd, SW_HIDE);
			ShowWindow(hVentanaPrincipal, SW_SHOW);
		}break;
		}
		return FALSE;
	}
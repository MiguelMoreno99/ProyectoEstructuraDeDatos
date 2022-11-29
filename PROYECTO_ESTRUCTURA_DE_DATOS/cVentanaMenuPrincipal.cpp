#include <Windows.h>
#include "resource.h"
#include "commctrl.h"
#include "cCapturaUsuario.h"
#include "cCapturaPersona.h"
#include "cCapturaVacuna.h"
#include "cCapturaCarnet.h"

//Variables Globales y Callbacks
BOOL CALLBACK cVentanaPrincipal(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cInicioSesion(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cInicioSesionRegistro(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cRegistroVacunas(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cRegistroPersonas(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cRegistroCarnets(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cReporteVacunas(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cReportePersonas(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK cReporteCarnets(HWND, UINT, WPARAM, LPARAM);
HWND hVentanaPrincipal;
HWND hInicioSesion;
HWND hInicioSesionRegistro;
HWND hRegistroVacunas;
HWND hRegistroPersonas;
HWND hRegistroCarnets;
HWND hReporteVacunas;
HWND hReportePersonas;
HWND hReporteCarnets;
HMENU hMenuOpciones;

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

				hRegistroVacunas = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_REGISTROVACUNAS), hVentanaPrincipal, cRegistroVacunas);
				hRegistroPersonas = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_REGISTROPERSONAS), hVentanaPrincipal, cRegistroPersonas);
				hRegistroCarnets = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_REGISTROCARNET), hVentanaPrincipal, cRegistroCarnets);

				hReporteVacunas = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_REPORTEVACUNAS), hVentanaPrincipal, cReporteVacunas);
				hReportePersonas = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_REPORTEPERSONAS), hVentanaPrincipal, cReportePersonas);
				hReporteCarnets = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_REPORTECARNETS), hVentanaPrincipal, cReporteCarnets);
				ShowWindow(hInicioSesion, SW_SHOW);
			}break;
			case WM_COMMAND: {
				switch (LOWORD(wParam)) {
					case MENU_REGISTRO_PERSONAS: {
						ShowWindow(hwnd, SW_HIDE);
						Persona1.CargarInfoComboBoxPersona(hRegistroPersonas,CB_PERSONA_ESTADOCIVIL,CB_PERSONA_SEXO,CB_PERSONA_GRUPOOCUPACIONAL,CB_PERSONA_PERFILRIESGO);
						ShowWindow(hRegistroPersonas, SW_SHOW);
					}break;
					case MENU_REGISTRO_CARNETS: {
						ShowWindow(hwnd, SW_HIDE);
						Carnet1.CargarInfoComboBoxCarnet(hRegistroCarnets, CB_CARNET_DOSIS,CB_CARNET_CENTROVACUNACION);
						Vacuna1.CargarInfoComboBoxIds(hRegistroCarnets,CB_CARNET_VACUNA_ID);
						Persona1.CargarInfoComboBoxCURP(hRegistroCarnets, CB_CARNET_PERSONA_CURP);
						ShowWindow(hRegistroCarnets, SW_SHOW);
					}break;
					case MENU_REGISTRO_VACUNAS: {
						ShowWindow(hwnd, SW_HIDE);
						Vacuna1.CargarInfoComboBoxVacuna(hRegistroVacunas, CB_VACUNA_MARCA, CB_VACUNA_DOSIS, CB_VACUNA_TIPO);
						ShowWindow(hRegistroVacunas, SW_SHOW);
					}break;
					case MENU_REPORTE_VACUNAS: {
						ShowWindow(hwnd, SW_HIDE);
						Vacuna1.CargarInfoComboBoxVacuna(hReporteVacunas,CB_REPORTE_VACUNA_MARCA,CB_REPORTE_VACUNA_DOSIS,CB_REPORTE_VACUNA_TIPO);
						Vacuna1.CargarInfoComboBoxIds(hReporteVacunas, CB_REPORTE_VACUNA_ID);
						ShowWindow(hReporteVacunas, SW_SHOW);
					}break;
					case MENU_REPORTE_PERSONAS: {
						ShowWindow(hwnd, SW_HIDE);
						Persona1.CargarInfoComboBoxPersona(hReportePersonas, CB_REPORTE_PERSONA_ESTADOCIVIL, CB_REPORTE_PERSONA_SEXO, CB_REPORTE_PERSONA_GRUPOOCUPACIONAL, CB_REPORTE_PERSONA_PERFILRIESGO);
						Persona1.CargarInfoComboBoxCURP(hReportePersonas, CB_REPORTE_PERSONA_CURP);
						ShowWindow(hReportePersonas, SW_SHOW);
					}break;
					case MENU_REPORTE_CARNETS: {
						ShowWindow(hwnd, SW_HIDE);
						Carnet1.CargarInfoComboBoxIds(hReporteCarnets, CB_REPORTE_CARNET_ID);
						Vacuna1.CargarInfoComboBoxIds(hReporteCarnets, CB_REPORTE_CARNET_IDVACUNA);
						ShowWindow(hReporteCarnets, SW_SHOW);
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
						Usuario1.PasarNombreUsuarioVentana(hVentanaPrincipal, LBL_NOMBREUSUARIO1);
						Usuario1.PasarNombreUsuarioVentana(hRegistroVacunas, LBL_NOMBREUSUARIO2);
						Usuario1.PasarNombreUsuarioVentana(hRegistroPersonas, LBL_NOMBREUSUARIO3);
						Usuario1.PasarNombreUsuarioVentana(hRegistroCarnets, LBL_NOMBREUSUARIO4);
						Usuario1.PasarNombreUsuarioVentana(hReporteVacunas, LBL_NOMBREUSUARIO5);
						Usuario1.PasarNombreUsuarioVentana(hReportePersonas, LBL_NOMBREUSUARIO6);
						Usuario1.PasarNombreUsuarioVentana(hReporteCarnets, LBL_NOMBREUSUARIO7);

					}break;
					case BTN_INICIOSESION_SALIR: {
						DestroyWindow(hwnd);
					}break;
					case BTN_INICIOSESION_REGISTRARSE: {
						ShowWindow(hwnd, SW_HIDE);
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
					Usuario1.PasarInformacionUsuario(hwnd, TXTB_INICIOSESION_REGISTRO_USUARIO, TXTB_INICIOSESION_REGISTRO_CONTRASENA,
					TXTB_INICIOSESION_REGISTRO_NOMBRE, TXTB_INICIOSESION_REGISTRO_APELLIDOPATERNO, TXTB_INICIOSESION_REGISTRO_APELLIDOMATERNO);
				}break;
				case BTN_INICIOSESION_REGISTRO_SALIR: {
					ShowWindow(hwnd, SW_HIDE);
					ShowWindow(hInicioSesion, SW_SHOW);
				}break;
			}
		}break;
		case WM_CLOSE: {
			ShowWindow(hwnd, SW_HIDE);
			ShowWindow(hInicioSesion, SW_SHOW);
		}break;
		}
		return FALSE;
	}

	BOOL CALLBACK cRegistroVacunas(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg) {
		case WM_INITDIALOG: {
			SetFocus(GetDlgItem(hwnd, BTN_VACUNA_CAPTURAR));
		}break;
		case WM_COMMAND: {
			switch (LOWORD(wParam)) {
			case BTN_VACUNA_REGRESAR: {
				ShowWindow(hwnd, SW_HIDE);
				ShowWindow(hVentanaPrincipal, SW_SHOW);
			}break;
			case BTN_VACUNA_CAPTURAR: {
				Vacuna1.GuardarInformacionVacuna(hwnd, CB_VACUNA_TIPO, CB_VACUNA_MARCA, CB_VACUNA_DOSIS, TXTB_VACUNA_PRECIO, TXTB_VACUNA_DESCRIPCION);
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

	BOOL CALLBACK cRegistroPersonas(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg) {
		case WM_INITDIALOG: {
			SetFocus(GetDlgItem(hwnd, BTN_PERSONA_CAPTURAR));
		}break;
		case WM_COMMAND: {
			switch (LOWORD(wParam)) {
			case BTN_PERSONA_REGRESAR: {
				ShowWindow(hwnd, SW_HIDE);
				ShowWindow(hVentanaPrincipal, SW_SHOW);
			}break;
			case BTN_PERSONA_CARGARDOCUMENTO: {
				Persona1.GuardarImagenPersona(hwnd,PC_PERSONA_DOCUMENTOIDENTIDAD);
			}break;
			case BTN_PERSONA_CAPTURAR: {
				Persona1.GuardarInformacionPersona(hwnd, TXTB_PERSONA_APELLIDOPATERNO,TXTB_PERSONA_APELLIDOMATERNO,TXTB_PERSONA_NOMBRE,
				TXTB_PERSONA_CURP,TXTB_PERSONA_RFC,DTP_PERSONA_FECHANACIMIENTO,TXTB_PERSONA_CALLE,TXTB_PERSONA_COLONIA,
				TXTB_PERSONA_MUNICIPIO,TXTB_PERSONA_ESTADO,CB_PERSONA_ESTADOCIVIL,TXTB_PERSONA_TELEFONO,CB_PERSONA_SEXO,
				CB_PERSONA_GRUPOOCUPACIONAL,CB_PERSONA_PERFILRIESGO);
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
		}break;
		case WM_COMMAND: {
			switch (LOWORD(wParam)) {
			case BTN_CARNET_REGRESAR: {
				ShowWindow(hwnd, SW_HIDE);
				ShowWindow(hVentanaPrincipal, SW_SHOW);
			}break;
			case BTN_CARNET_CAPTURAR: {
				Carnet1.CapturarInformacionCarnet(hwnd, CB_CARNET_PERSONA_CURP, CB_CARNET_VACUNA_ID, TXTB_CARNET_LOTE,
				DTP_CARNET_FECHADOSIS, CB_CARNET_DOSIS, CB_CARNET_CENTROVACUNACION, DTP_CARNET_FECHAPROXDOSIS, TXTB_CARNET_PERSONA_APELLIDOPATERNO, TXTB_CARNET_PERSONA_APELLIDOMATERNO, TXTB_CARNET_PERSONA_NOMBRE,
					TXTB_CARNET_PERSONA_CURP, TXTB_CARNET_PERSONA_RFC, TXTB_CARNET_PERSONA_FECHANACIMIENTO, TXTB_CARNET_PERSONA_CALLE, TXTB_CARNET_PERSONA_COLONIA,
					TXTB_CARNET_PERSONA_MUNICIPIO, TXTB_CARNET_PERSONA_ESTADO, TXTB_CARNET_PERSONA_ESTADOCIVIL, TXTB_CARNET_PERSONA_TELEFONO, TXTB_CARNET_PERSONA_SEXO,
					TXTB_CARNET_PERSONA_GRUPOOCUPACIONAL, TXTB_CARNET_PERSONA_PERFILDERIESGO, TXTB_CARNET_VACUNA_TIPO, TXTB_CARNET_VACUNA_MARCA, TXTB_CARNET_VACUNA_DOSIS, 
					TXTB_CARNET_VACUNA_PRECIO, TXTB_CARNET_VACUNA_DESCRIPCION);
			}break;
			case BTN_CARNET_BUSCARCURP: {
				Persona1.CargarInformacionPersona(hwnd,CB_CARNET_PERSONA_CURP, TXTB_CARNET_PERSONA_APELLIDOPATERNO, TXTB_CARNET_PERSONA_APELLIDOMATERNO, TXTB_CARNET_PERSONA_NOMBRE,
					TXTB_CARNET_PERSONA_CURP, TXTB_CARNET_PERSONA_RFC, TXTB_CARNET_PERSONA_FECHANACIMIENTO, TXTB_CARNET_PERSONA_CALLE, TXTB_CARNET_PERSONA_COLONIA,
					TXTB_CARNET_PERSONA_MUNICIPIO, TXTB_CARNET_PERSONA_ESTADO, TXTB_CARNET_PERSONA_ESTADOCIVIL, TXTB_CARNET_PERSONA_TELEFONO, TXTB_CARNET_PERSONA_SEXO,
					TXTB_CARNET_PERSONA_GRUPOOCUPACIONAL, TXTB_CARNET_PERSONA_PERFILDERIESGO, PC_CARNET_PERSONA_DOCUMENTOIDENTIFICACION);
			}break;
			case BTN_CARNET_BUSCARVACUNA: {
				Vacuna1.CargarInformacionVacuna(hwnd,CB_CARNET_VACUNA_ID, TXTB_CARNET_VACUNA_TIPO, TXTB_CARNET_VACUNA_MARCA, TXTB_CARNET_VACUNA_DOSIS, TXTB_CARNET_VACUNA_PRECIO, TXTB_CARNET_VACUNA_DESCRIPCION);
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

	BOOL CALLBACK cReporteVacunas(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg) {
		case WM_INITDIALOG: {
			SetFocus(GetDlgItem(hwnd, BTN_REPORTE_VACUNA_BUSCAR));
		}break;
		case WM_COMMAND: {
			switch (LOWORD(wParam)) {
			case BTN_REPORTE_VACUNA_REGRESAR: {
				ShowWindow(hwnd, SW_HIDE);
				ShowWindow(hVentanaPrincipal, SW_SHOW);
			}break;
			case BTN_REPORTE_VACUNA_BUSCAR: {
				Vacuna1.CargarInformacionVacuna(hwnd,CB_REPORTE_VACUNA_ID, CB_REPORTE_VACUNA_TIPO, CB_REPORTE_VACUNA_MARCA, CB_REPORTE_VACUNA_DOSIS, TXTB_REPORTE_VACUNA_PRECIO, TXTB_REPORTE_VACUNA_DESCRIPCION);
			}break;
			case BTN_REPORTE_VACUNA_EDITAR: {
				Vacuna1.EditarInformacionVacuna(hwnd, CB_REPORTE_VACUNA_ID, CB_REPORTE_VACUNA_TIPO, CB_REPORTE_VACUNA_MARCA, CB_REPORTE_VACUNA_DOSIS, TXTB_REPORTE_VACUNA_PRECIO, TXTB_REPORTE_VACUNA_DESCRIPCION);
			}break;
			case BTN_REPORTE_VACUNA_BORRAR: {
				Vacuna1.BorrarInformacionVacuna(hwnd, CB_REPORTE_VACUNA_ID, CB_REPORTE_VACUNA_TIPO, CB_REPORTE_VACUNA_MARCA, CB_REPORTE_VACUNA_DOSIS, TXTB_REPORTE_VACUNA_PRECIO, TXTB_REPORTE_VACUNA_DESCRIPCION);
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

	BOOL CALLBACK cReportePersonas(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg) {
		case WM_INITDIALOG: {
			SetFocus(GetDlgItem(hwnd, BTN_REPORTE_PERSONA_BUSCAR));
		}break;
		case WM_COMMAND: {
			switch (LOWORD(wParam)) {
			case BTN_REPORTE_PERSONA_REGRESAR: {
				ShowWindow(hwnd, SW_HIDE);
				ShowWindow(hVentanaPrincipal, SW_SHOW);
			}break;
			case BTN_REPORTE_PERSONA_BUSCAR: {
				Persona1.CargarInformacionPersona(hwnd, CB_REPORTE_PERSONA_CURP, TXTB_REPORTE_PERSONA_APELLIDOPATERNO, TXTB_REPORTE_PERSONA_APELLIDOMATERNO, TXTB_REPORTE_PERSONA_NOMBRE,
					NULL, TXTB_REPORTE_PERSONA_RFC, TXTB_REPORTE_PERSONA_FECHANACIMIENTO, TXTB_REPORTE_PERSONA_CALLE, TXTB_REPORTE_PERSONA_COLONIA,
					TXTB_REPORTE_PERSONA_MUNICIPIO, TXTB_REPORTE_PERSONA_ESTADO, CB_REPORTE_PERSONA_ESTADOCIVIL, TXTB_REPORTE_PERSONA_TELEFONO, CB_REPORTE_PERSONA_SEXO,
					CB_REPORTE_PERSONA_GRUPOOCUPACIONAL, CB_REPORTE_PERSONA_PERFILRIESGO, PC_REPORTE_PERSONA_DOCUMENTOIDENTIDAD);
			}break;
			case BTN_REPORTE_PERSONA_EDITAR: {
				Persona1.EditarInformacionPersona(hwnd, TXTB_REPORTE_PERSONA_APELLIDOPATERNO, TXTB_REPORTE_PERSONA_APELLIDOMATERNO, TXTB_REPORTE_PERSONA_NOMBRE,
					CB_REPORTE_PERSONA_CURP, TXTB_REPORTE_PERSONA_RFC, TXTB_REPORTE_PERSONA_FECHANACIMIENTO, TXTB_REPORTE_PERSONA_CALLE, TXTB_REPORTE_PERSONA_COLONIA,
					TXTB_REPORTE_PERSONA_MUNICIPIO, TXTB_REPORTE_PERSONA_ESTADO, CB_REPORTE_PERSONA_ESTADOCIVIL, TXTB_REPORTE_PERSONA_TELEFONO, CB_REPORTE_PERSONA_SEXO,
					CB_REPORTE_PERSONA_GRUPOOCUPACIONAL, CB_REPORTE_PERSONA_PERFILRIESGO);
			}break;
			case BTN_REPORTE_PERSONA_BORRAR: {
				Persona1.BorrarInformacionPersona(hwnd, TXTB_REPORTE_PERSONA_APELLIDOPATERNO, TXTB_REPORTE_PERSONA_APELLIDOMATERNO, TXTB_REPORTE_PERSONA_NOMBRE,
					CB_REPORTE_PERSONA_CURP, TXTB_REPORTE_PERSONA_RFC, TXTB_REPORTE_PERSONA_FECHANACIMIENTO, TXTB_REPORTE_PERSONA_CALLE, TXTB_REPORTE_PERSONA_COLONIA,
					TXTB_REPORTE_PERSONA_MUNICIPIO, TXTB_REPORTE_PERSONA_ESTADO, CB_REPORTE_PERSONA_ESTADOCIVIL, TXTB_REPORTE_PERSONA_TELEFONO, CB_REPORTE_PERSONA_SEXO,
					CB_REPORTE_PERSONA_GRUPOOCUPACIONAL, CB_REPORTE_PERSONA_PERFILRIESGO);
			}break;
			case BTN_REPORTE_PERSONA_CARGARDOCUMENTO: {
				Persona1.GuardarImagenPersona(hwnd,PC_REPORTE_PERSONA_DOCUMENTOIDENTIDAD);
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

	BOOL CALLBACK cReporteCarnets(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg) {
		case WM_INITDIALOG: {
			SetFocus(GetDlgItem(hwnd, BTN_REPORTE_CARNET_BUSCARID));
		}break;
		case WM_COMMAND: {
			switch (LOWORD(wParam)) {
			case BTN_REPORTE_CARNET_REGRESAR: {
				ShowWindow(hwnd, SW_HIDE);
				ShowWindow(hVentanaPrincipal, SW_SHOW);
			}break;
			case BTN_REPORTE_CARNET_BUSCARID: {
				Carnet1.CargarInformacionCarnetConID(hwnd, CB_REPORTE_CARNET_ID, TXTB_REPORTE_CARNET_APELLIDOPATERNO, TXTB_REPORTE_CARNET_APELLIDOMATERNO,
					TXTB_REPORTE_CARNET_NOMBRE, CB_REPORTE_CARNET_IDVACUNA, TXTB_REPORTE_CARNET_CURP, TXTB_REPORTE_CARNET_LOTE,
					TXTB_REPORTE_CARNET_FECHADOSIS, TXTB_REPORTE_CARNET_DOSIS, TXTB_REPORTE_CARNET_CENTROVACUNACION, TXTB_REPORTE_CARNET_FECHAPROXDOSIS);
			}break;
			case BTN_REPORTE_CARNET_BUSCARNOMBRE: {
				Carnet1.CargarInformacionCarnetConNombre(hwnd, CB_REPORTE_CARNET_ID,TXTB_REPORTE_CARNET_APELLIDOPATERNO, TXTB_REPORTE_CARNET_APELLIDOMATERNO, 
					TXTB_REPORTE_CARNET_NOMBRE, CB_REPORTE_CARNET_IDVACUNA, TXTB_REPORTE_CARNET_CURP, TXTB_REPORTE_CARNET_LOTE,
					TXTB_REPORTE_CARNET_FECHADOSIS, TXTB_REPORTE_CARNET_DOSIS, TXTB_REPORTE_CARNET_CENTROVACUNACION, TXTB_REPORTE_CARNET_FECHAPROXDOSIS);
			}break;
			case BTN_REPORTE_CARNET_EDITAR: {
				Carnet1.EditarInformacionCarnet(hwnd, CB_REPORTE_CARNET_ID, CB_REPORTE_CARNET_IDVACUNA, TXTB_REPORTE_CARNET_CURP, TXTB_REPORTE_CARNET_LOTE,
					TXTB_REPORTE_CARNET_FECHADOSIS, TXTB_REPORTE_CARNET_DOSIS, TXTB_REPORTE_CARNET_CENTROVACUNACION, TXTB_REPORTE_CARNET_FECHAPROXDOSIS);
			}break;
			case BTN_REPORTE_CARNET_BORRAR: {
				Carnet1.BorrarInformacionCarnet(hwnd, CB_REPORTE_CARNET_ID, CB_REPORTE_CARNET_IDVACUNA, TXTB_REPORTE_CARNET_CURP, TXTB_REPORTE_CARNET_LOTE,
					TXTB_REPORTE_CARNET_FECHADOSIS, TXTB_REPORTE_CARNET_DOSIS, TXTB_REPORTE_CARNET_CENTROVACUNACION, TXTB_REPORTE_CARNET_FECHAPROXDOSIS);
			}break;
			case BTN_REPORTE_CARNET_ORDENARPERSONASID: {
				Carnet1.CargarInformacionListBoxPorID(hwnd, LB_REPORTE_CARNET_LISTA);
			}break;
			case BTN_REPORTE_CARNET_ORDENARPERSONASNOMBRE: {
				Carnet1.CargarInformacionListBoxPorCURP(hwnd, LB_REPORTE_CARNET_LISTA);
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
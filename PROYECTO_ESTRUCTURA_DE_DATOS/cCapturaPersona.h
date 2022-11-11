#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string.h>
#include "cValidadores.h"
using namespace std;

class Persona {

private:
	// 16 Variables
	string String_Persona_ApellidoPaterno;
	string String_Persona_ApellidoMaterno;
	string String_Persona_Nombre;
	string String_Persona_CURP;
	string String_Persona_RFC;
	string String_Persona_FechaNacimiento;
	string String_Persona_Calle;
	string String_Persona_Colonia;
	string String_Persona_Municipio;
	string String_Persona_Estado;
	string String_Persona_EstadoCivil;
	string String_Persona_Telefono;
	string String_Persona_Sexo;
	string String_Persona_GrupoOcupacional;
	string String_Persona_PerfilRiesgo;
	string String_Persona_PathDocumentoIdentidad;
	int id;
	bool err = false;
	Persona* Ptr_Persona_anterior = NULL;
	Persona* Ptr_Persona_siguiente = NULL;

public:
	//Funcciones
	void PasarInformacionPersona(HWND hwnd, int _int_Persona_ApellidoPaterno,
		int _int_Persona_ApellidoMaterno,
		int _int_Persona_Nombre,
		int _int_Persona_CURP,
		int _int_Persona_RFC,
		int _int_Persona_FechaNacimiento,
		int _int_Persona_Calle,
		int _int_Persona_Colonia,
		int _int_Persona_Municipio,
		int _int_Persona_Estado,
		int _int_Persona_EstadoCivil,
		int _int_Persona_Telefono,
		int _int_Persona_Sexo,
		int _int_Persona_GrupoOcupacional,
		int _int_Persona_PerfilRiesgo) {

		err = false;
		err = ValidacionTexto(hwnd, _int_Persona_ApellidoPaterno, err);
		err = ValidacionTexto(hwnd, _int_Persona_ApellidoMaterno, err);
		err = ValidacionTexto(hwnd, _int_Persona_Nombre, err);
		err = ValidacionTexto(hwnd, _int_Persona_CURP, err);
		err = ValidacionTexto(hwnd, _int_Persona_RFC, err);
		err = ValidacionTexto(hwnd, _int_Persona_FechaNacimiento, err);
		err = ValidacionTexto(hwnd, _int_Persona_Calle, err);
		err = ValidacionTexto(hwnd, _int_Persona_Colonia, err);
		err = ValidacionTexto(hwnd, _int_Persona_Municipio, err);
		err = ValidacionTexto(hwnd, _int_Persona_Estado, err);
		err = ValidacionTexto(hwnd, _int_Persona_EstadoCivil, err);
		err = ValidacionTexto(hwnd, _int_Persona_Telefono, err);
		err = ValidacionTexto(hwnd, _int_Persona_Sexo, err);
		err = ValidacionTexto(hwnd, _int_Persona_GrupoOcupacional, err);
		err = ValidacionTexto(hwnd, _int_Persona_PerfilRiesgo, err);
		if (String_Persona_PathDocumentoIdentidad==""){
			err = true;
		}

		if (!err) {
			String_Persona_ApellidoPaterno = ValidacionCapturaTexto(hwnd, _int_Persona_ApellidoPaterno);
			String_Persona_ApellidoMaterno = ValidacionCapturaTexto(hwnd, _int_Persona_ApellidoMaterno);
			String_Persona_Nombre = ValidacionCapturaTexto(hwnd, _int_Persona_Nombre);
			String_Persona_CURP = ValidacionCapturaTexto(hwnd, _int_Persona_CURP);
			String_Persona_RFC = ValidacionCapturaTexto(hwnd, _int_Persona_RFC);
			String_Persona_FechaNacimiento = ValidacionCapturaTexto(hwnd, _int_Persona_FechaNacimiento);
			String_Persona_Calle = ValidacionCapturaTexto(hwnd, _int_Persona_Calle);
			String_Persona_Colonia = ValidacionCapturaTexto(hwnd, _int_Persona_Colonia);
			String_Persona_Municipio = ValidacionCapturaTexto(hwnd, _int_Persona_Municipio);
			String_Persona_Estado = ValidacionCapturaTexto(hwnd, _int_Persona_Estado);
			String_Persona_EstadoCivil = ValidacionCapturaTexto(hwnd, _int_Persona_EstadoCivil);
			String_Persona_Telefono = ValidacionCapturaTexto(hwnd, _int_Persona_Telefono);
			String_Persona_Sexo = ValidacionCapturaTexto(hwnd, _int_Persona_Sexo);
			String_Persona_GrupoOcupacional = ValidacionCapturaTexto(hwnd, _int_Persona_GrupoOcupacional);
			String_Persona_PerfilRiesgo = ValidacionCapturaTexto(hwnd, _int_Persona_PerfilRiesgo);
			SetDlgItemText(hwnd, _int_Persona_ApellidoPaterno, "");
			SetDlgItemText(hwnd, _int_Persona_ApellidoMaterno, "");
			SetDlgItemText(hwnd, _int_Persona_Nombre, "");
			SetDlgItemText(hwnd, _int_Persona_CURP, "");
			SetDlgItemText(hwnd, _int_Persona_RFC, "");
			SetDlgItemText(hwnd, _int_Persona_FechaNacimiento, "");
			SetDlgItemText(hwnd, _int_Persona_Calle, "");
			SetDlgItemText(hwnd, _int_Persona_Colonia, "");
			SetDlgItemText(hwnd, _int_Persona_Municipio, "");
			SetDlgItemText(hwnd, _int_Persona_Estado, "");
			SetDlgItemText(hwnd, _int_Persona_EstadoCivil, "");
			SetDlgItemText(hwnd, _int_Persona_Telefono, "");
			SetDlgItemText(hwnd, _int_Persona_Sexo, "");
			SetDlgItemText(hwnd, _int_Persona_GrupoOcupacional, "");
			SetDlgItemText(hwnd, _int_Persona_PerfilRiesgo, "");
			CargarInfoComboBoxPersona(hwnd);
			GuardarPersona();
			String_Persona_PathDocumentoIdentidad = "";
			MessageBox(hwnd, "Se ha registrado la Persona Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
		}
		else {
			MessageBox(hwnd, "Verifique que los datos ingresados sean válidos!", "ERROR", MB_ICONERROR);
		}
	}

	void GuardarImagenPersona(HWND hwnd) {

		OPENFILENAME OfnPersonaDocumento;
		ZeroMemory(&OfnPersonaDocumento, sizeof(OPENFILENAME));
		char cDirFile[MAX_PATH] = "";
		OfnPersonaDocumento.hwndOwner = hwnd;
		OfnPersonaDocumento.lpstrFile = cDirFile;
		OfnPersonaDocumento.lStructSize = sizeof(OPENFILENAME);
		OfnPersonaDocumento.nMaxFile = MAX_PATH;
		OfnPersonaDocumento.lpstrDefExt = "txt";
		OfnPersonaDocumento.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR;
		OfnPersonaDocumento.lpstrFilter = "ARCHIVOS BITMAP\0*.bmp*\0";
		if (GetOpenFileName(&OfnPersonaDocumento)) {
			HWND hDocumentoIdeintidad = GetDlgItem(hwnd, PC_PERSONA_DOCUMENTOIDENTIDAD);
			HBITMAP hpcDocumentoIdentidad = (HBITMAP)LoadImage(NULL, cDirFile, IMAGE_BITMAP, 150, 150, LR_LOADFROMFILE);
			SendMessage(hDocumentoIdeintidad, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hpcDocumentoIdentidad);
			String_Persona_PathDocumentoIdentidad = cDirFile;
			DeleteObject(hpcDocumentoIdentidad);
		}
	}

	void CargarInfoComboBoxPersona(HWND hwnd) {

		HWND hComboBox;
		hComboBox = GetDlgItem(hwnd, CB_PERSONA_ESTADOCIVIL);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"SOLTERO(A)");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"CASADO(A)");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"DIVORCIADO(A)");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"VIUDO(A)");
		hComboBox = GetDlgItem(hwnd, CB_PERSONA_SEXO);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"MASCULINO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"FEMENINO");
		hComboBox = GetDlgItem(hwnd, CB_PERSONA_GRUPOOCUPACIONAL);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"ESTUDIANTE");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"TRABAJADOR");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"DESEMPLEADO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"AMA(O) DE CASA");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"OTRO");
		hComboBox = GetDlgItem(hwnd, CB_PERSONA_PERFILRIESGO);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"ALTO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"MODERADO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"BAJO");
	}

	void GuardarPersona() {

		if (PtrOrigenPersona == NULL) {
			PtrOrigenPersona = new Persona;
			PtrOrigenPersona->id++;
			PtrOrigenPersona->String_Persona_ApellidoPaterno = String_Persona_ApellidoPaterno;
			PtrOrigenPersona->String_Persona_ApellidoMaterno = String_Persona_ApellidoMaterno;
			PtrOrigenPersona->String_Persona_Nombre = String_Persona_Nombre;
			PtrOrigenPersona->String_Persona_CURP = String_Persona_CURP;
			PtrOrigenPersona->String_Persona_RFC = String_Persona_RFC;
			PtrOrigenPersona->String_Persona_FechaNacimiento = String_Persona_FechaNacimiento;
			PtrOrigenPersona->String_Persona_Calle = String_Persona_Calle;
			PtrOrigenPersona->String_Persona_Colonia = String_Persona_Colonia;
			PtrOrigenPersona->String_Persona_Municipio = String_Persona_Municipio;
			PtrOrigenPersona->String_Persona_Estado = String_Persona_Estado;
			PtrOrigenPersona->String_Persona_EstadoCivil = String_Persona_EstadoCivil;
			PtrOrigenPersona->String_Persona_Telefono = String_Persona_Telefono;
			PtrOrigenPersona->String_Persona_Sexo = String_Persona_Sexo;
			PtrOrigenPersona->String_Persona_GrupoOcupacional = String_Persona_GrupoOcupacional;
			PtrOrigenPersona->String_Persona_PerfilRiesgo = String_Persona_PerfilRiesgo;
			PtrOrigenPersona->String_Persona_PathDocumentoIdentidad = String_Persona_PathDocumentoIdentidad;
			PtrOrigenPersona->Ptr_Persona_siguiente = NULL;
			PtrOrigenPersona->Ptr_Persona_anterior = NULL;
		}
		else {
			PtrAuxiliarPersona = PtrOrigenPersona;
			while (PtrAuxiliarPersona->Ptr_Persona_siguiente != NULL) {
				PtrAuxiliarPersona = PtrAuxiliarPersona->Ptr_Persona_siguiente;
			}
			PtrAuxiliarPersona->Ptr_Persona_siguiente = new Persona;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->id = PtrAuxiliarPersona->id + 1;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_ApellidoPaterno = String_Persona_ApellidoPaterno;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_ApellidoMaterno = String_Persona_ApellidoMaterno;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_Nombre = String_Persona_Nombre;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_CURP = String_Persona_CURP;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_RFC = String_Persona_RFC;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_FechaNacimiento = String_Persona_FechaNacimiento;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_Calle = String_Persona_Calle;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_Colonia = String_Persona_Colonia;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_Municipio = String_Persona_Municipio;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_Estado = String_Persona_Estado;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_EstadoCivil = String_Persona_EstadoCivil;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_Telefono = String_Persona_Telefono;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_Sexo = String_Persona_Sexo;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_GrupoOcupacional = String_Persona_GrupoOcupacional;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_PerfilRiesgo = String_Persona_PerfilRiesgo;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_PathDocumentoIdentidad = String_Persona_PathDocumentoIdentidad;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->Ptr_Persona_siguiente = NULL;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->Ptr_Persona_anterior = PtrAuxiliarPersona;
		}
		PtrAuxiliarPersona = PtrOrigenPersona;
		return;
	}

}*PtrOrigenPersona = NULL, * PtrAuxiliarPersona = NULL;
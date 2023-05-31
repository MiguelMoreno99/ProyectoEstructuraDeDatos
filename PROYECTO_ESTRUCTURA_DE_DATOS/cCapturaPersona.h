#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string.h>
#include "cValidadores.h"
#include <fstream>
using namespace std;

class Persona {

private:
	// 16 Variables Privadas
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
	bool borrado = false;
	bool vacunado = false;

	//2 Variables Publicas
public:
	Persona* Ptr_Persona_anterior = NULL;
	Persona* Ptr_Persona_siguiente = NULL;

public:
	//Funcciones
	void GuardarInformacionPersona(HWND hwnd, int _int_Persona_ApellidoPaterno, int _int_Persona_ApellidoMaterno, int _int_Persona_Nombre, int _int_Persona_CURP, int _int_Persona_RFC, int _int_Persona_FechaNacimiento, int _int_Persona_Calle, int _int_Persona_Colonia, int _int_Persona_Municipio, int _int_Persona_Estado, int _int_Persona_EstadoCivil, int _int_Persona_Telefono, int _int_Persona_Sexo, int _int_Persona_GrupoOcupacional, int _int_Persona_PerfilRiesgo) {

		err = false;
		err = ValidacionLetraConEspacios(hwnd, _int_Persona_ApellidoPaterno, err);
		err = ValidacionLetraConEspacios(hwnd, _int_Persona_ApellidoMaterno, err);
		err = ValidacionLetraConEspacios(hwnd, _int_Persona_Nombre, err);
		err = ValidacionLetraYNumeroSinEspacios(hwnd, _int_Persona_CURP, err);
		err = ValidacionLetraYNumeroSinEspacios(hwnd, _int_Persona_RFC, err);
		err = ValidacionFechaMenorAActual(hwnd, _int_Persona_FechaNacimiento, err);
		err = ValidacionLetraYNumeroConEspacios(hwnd, _int_Persona_Calle, err);
		err = ValidacionLetraYNumeroConEspacios(hwnd, _int_Persona_Colonia, err);
		err = ValidacionLetraYNumeroConEspacios(hwnd, _int_Persona_Municipio, err);
		err = ValidacionLetraYNumeroConEspacios(hwnd, _int_Persona_Estado, err);
		err = ValidacionLetraSinEspacios(hwnd, _int_Persona_EstadoCivil, err);
		err = ValidacionNumeroTelefonico(hwnd, _int_Persona_Telefono, err);
		err = ValidacionLetraSinEspacios(hwnd, _int_Persona_Sexo, err);
		err = ValidacionLetraConEspacios(hwnd, _int_Persona_GrupoOcupacional, err);
		err = ValidacionLetraSinEspacios(hwnd, _int_Persona_PerfilRiesgo, err);
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
			if (BuscarCURPyRFCRepetido(hwnd, String_Persona_CURP, String_Persona_RFC)){
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
				CargarInfoComboBoxPersona(hwnd, _int_Persona_EstadoCivil, _int_Persona_Sexo, _int_Persona_GrupoOcupacional, _int_Persona_PerfilRiesgo);
				GuardarPersona();
				String_Persona_PathDocumentoIdentidad = "";
				MessageBox(hwnd, "Se ha registrado la Persona Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
			}
		}
		else {
			MessageBox(hwnd, "Verifique que los datos ingresados sean válidos!", "ERROR", MB_ICONERROR);
		}
	}

	void EditarInformacionPersona(HWND hwnd, int _int_Persona_ApellidoPaterno, int _int_Persona_ApellidoMaterno, int _int_Persona_Nombre, int _int_Persona_CURPaEditar, int _int_Persona_RFC, int _int_Persona_FechaNacimiento, int _int_Persona_Calle, int _int_Persona_Colonia, int _int_Persona_Municipio, int _int_Persona_Estado, int _int_Persona_EstadoCivil, int _int_Persona_Telefono, int _int_Persona_Sexo, int _int_Persona_GrupoOcupacional, int _int_Persona_PerfilRiesgo) {

		err = false;
		err = ValidacionLetraConEspacios(hwnd, _int_Persona_ApellidoPaterno, err);
		err = ValidacionLetraConEspacios(hwnd, _int_Persona_ApellidoMaterno, err);
		err = ValidacionLetraConEspacios(hwnd, _int_Persona_Nombre, err);
		err = ValidacionLetraYNumeroSinEspacios(hwnd, _int_Persona_CURPaEditar, err);
		err = ValidacionLetraYNumeroSinEspacios(hwnd, _int_Persona_RFC, err);
		err = ValidacionFechaMenorAActual(hwnd, _int_Persona_FechaNacimiento, err);
		err = ValidacionLetraYNumeroConEspacios(hwnd, _int_Persona_Calle, err);
		err = ValidacionLetraYNumeroConEspacios(hwnd, _int_Persona_Colonia, err);
		err = ValidacionLetraYNumeroConEspacios(hwnd, _int_Persona_Municipio, err);
		err = ValidacionLetraYNumeroConEspacios(hwnd, _int_Persona_Estado, err);
		err = ValidacionLetraSinEspacios(hwnd, _int_Persona_EstadoCivil, err);
		err = ValidacionNumeroTelefonico(hwnd, _int_Persona_Telefono, err);
		err = ValidacionLetraSinEspacios(hwnd, _int_Persona_Sexo, err);
		err = ValidacionLetraConEspacios(hwnd, _int_Persona_GrupoOcupacional, err);
		err = ValidacionLetraSinEspacios(hwnd, _int_Persona_PerfilRiesgo, err);
		if (String_Persona_PathDocumentoIdentidad == "") {
			err = true;
		}
		if (!err) {
			String_Persona_ApellidoPaterno = ValidacionCapturaTexto(hwnd, _int_Persona_ApellidoPaterno);
			String_Persona_ApellidoMaterno = ValidacionCapturaTexto(hwnd, _int_Persona_ApellidoMaterno);
			String_Persona_Nombre = ValidacionCapturaTexto(hwnd, _int_Persona_Nombre);
			String_Persona_CURP = ValidacionCapturaTexto(hwnd, _int_Persona_CURPaEditar);
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
			SetDlgItemText(hwnd, _int_Persona_CURPaEditar, "");
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
			CargarInfoComboBoxPersona(hwnd, _int_Persona_EstadoCivil, _int_Persona_Sexo, _int_Persona_GrupoOcupacional, _int_Persona_PerfilRiesgo);
			CargarInfoComboBoxCURP(hwnd, _int_Persona_CURPaEditar);
			EditarPersona(id);
			String_Persona_PathDocumentoIdentidad = "";
			MessageBox(hwnd, "Se ha Editado la Persona Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
		}
		else {
			MessageBox(hwnd, "Verifique que los datos ingresados sean válidos!", "ERROR", MB_ICONERROR);
		}
	}

	void BorrarInformacionPersona(HWND hwnd, int _int_Persona_ApellidoPaterno, int _int_Persona_ApellidoMaterno, int _int_Persona_Nombre, int _int_Persona_CURPaBorrar, int _int_Persona_RFC, int _int_Persona_FechaNacimiento, int _int_Persona_Calle, int _int_Persona_Colonia, int _int_Persona_Municipio, int _int_Persona_Estado, int _int_Persona_EstadoCivil, int _int_Persona_Telefono, int _int_Persona_Sexo, int _int_Persona_GrupoOcupacional, int _int_Persona_PerfilRiesgo) {

		err = false;
		err = ValidacionLetraYNumeroSinEspacios(hwnd, _int_Persona_CURPaBorrar, err);
		if (!err) {
			SetDlgItemText(hwnd, _int_Persona_ApellidoPaterno, "");
			SetDlgItemText(hwnd, _int_Persona_ApellidoMaterno, "");
			SetDlgItemText(hwnd, _int_Persona_Nombre, "");
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
			BorrarPersona(id);
			CargarInfoComboBoxPersona(hwnd, _int_Persona_EstadoCivil, _int_Persona_Sexo, _int_Persona_GrupoOcupacional, _int_Persona_PerfilRiesgo);
			CargarInfoComboBoxCURP(hwnd, _int_Persona_CURPaBorrar);
			String_Persona_PathDocumentoIdentidad = "";
			MessageBox(hwnd, "Se ha Borrado la Persona Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
		}
		else {
			MessageBox(hwnd, "Verifique que los datos ingresados sean válidos!", "ERROR", MB_ICONERROR);
		}
	}

	void GuardarImagenPersona(HWND hwnd, int _PC_PERSONA_DOCUMENTOIDENTIDAD) {

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
			HWND hDocumentoIdeintidad = GetDlgItem(hwnd, _PC_PERSONA_DOCUMENTOIDENTIDAD);
			HBITMAP hpcDocumentoIdentidad = (HBITMAP)LoadImage(NULL, cDirFile, IMAGE_BITMAP, 150, 150, LR_LOADFROMFILE);
			SendMessage(hDocumentoIdeintidad, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hpcDocumentoIdentidad);
			String_Persona_PathDocumentoIdentidad = cDirFile;
			DeleteObject(hpcDocumentoIdentidad);
		}
	}

	void CargarInfoComboBoxPersona(HWND hwnd,int _CB_PERSONA_ESTADOCIVIL,int _CB_PERSONA_SEXO,int _CB_PERSONA_GRUPOOCUPACIONAL,int _CB_PERSONA_PERFILRIESGO) {

		HWND hComboBox;
		hComboBox = GetDlgItem(hwnd, _CB_PERSONA_ESTADOCIVIL);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"SOLTERO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"CASADO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"DIVORCIADO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"VIUDO");
		hComboBox = GetDlgItem(hwnd, _CB_PERSONA_SEXO);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"MASCULINO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"FEMENINO");
		hComboBox = GetDlgItem(hwnd, _CB_PERSONA_GRUPOOCUPACIONAL);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"ESTUDIANTE");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"TRABAJADOR");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"DESEMPLEADO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"AMA DE CASA");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"OTRO");
		hComboBox = GetDlgItem(hwnd, _CB_PERSONA_PERFILRIESGO);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"ALTO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"MODERADO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"BAJO");
	}

	void CargarInfoComboBoxCURP(HWND hwnd, int _CB_PERSONA_CURP) {

		HWND hComboBox;
		hComboBox = GetDlgItem(hwnd, _CB_PERSONA_CURP);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		if (PtrOrigenPersona != NULL) {
			PtrAuxiliarPersona = PtrOrigenPersona;
			while (PtrAuxiliarPersona != NULL) {
				if (!(PtrAuxiliarPersona->borrado)) {
					string CURP = PtrAuxiliarPersona->String_Persona_CURP;
					if (CURP != "") {
						SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)CURP.c_str());
					}
				}
				PtrAuxiliarPersona = PtrAuxiliarPersona->Ptr_Persona_siguiente;
			}
		}
		else {
			MessageBox(hwnd, "PRIMERO DEBE DE AGREGAR AL MENOS UNA PERSONA REGISTRADA!", "PRECAUCIÓN", MB_ICONWARNING);
		}
	}

	void CargarInformacionPersona(HWND hwnd, int _int_Persona_CURP_Buscar, int _int_Persona_ApellidoPaterno, int _int_Persona_ApellidoMaterno, int _int_Persona_Nombre, int _int_Persona_CURP, int _int_Persona_RFC, int _int_Persona_FechaNacimiento, int _int_Persona_Calle, int _int_Persona_Colonia, int _int_Persona_Municipio, int _int_Persona_Estado, int _int_Persona_EstadoCivil, int _int_Persona_Telefono, int _int_Persona_Sexo, int _int_Persona_GrupoOcupacional, int _int_Persona_PerfilRiesgo, int _int_Persona_PictureControl) {

		string CURP = ValidacionCapturaTexto(hwnd, _int_Persona_CURP_Buscar);
		if (CURP != "") {
			HWND hComboBox;
			SetDlgItemText(hwnd, _int_Persona_ApellidoPaterno, PasarDatosdelCURPCarnet(CURP, 1).c_str());
			SetDlgItemText(hwnd, _int_Persona_ApellidoMaterno, PasarDatosdelCURPCarnet(CURP, 2).c_str());
			SetDlgItemText(hwnd, _int_Persona_Nombre, PasarDatosdelCURPCarnet(CURP, 3).c_str());
			SetDlgItemText(hwnd, _int_Persona_CURP, PasarDatosdelCURPCarnet(CURP, 4).c_str());
			SetDlgItemText(hwnd, _int_Persona_RFC, PasarDatosdelCURPCarnet(CURP, 5).c_str());
			SetDlgItemText(hwnd, _int_Persona_FechaNacimiento, PasarDatosdelCURPCarnet(CURP, 6).c_str());
			SetDlgItemText(hwnd, _int_Persona_Calle, PasarDatosdelCURPCarnet(CURP, 7).c_str());
			SetDlgItemText(hwnd, _int_Persona_Colonia, PasarDatosdelCURPCarnet(CURP, 8).c_str());
			SetDlgItemText(hwnd, _int_Persona_Municipio, PasarDatosdelCURPCarnet(CURP, 9).c_str());
			SetDlgItemText(hwnd, _int_Persona_Estado, PasarDatosdelCURPCarnet(CURP, 10).c_str());

			hComboBox = GetDlgItem(hwnd, _int_Persona_EstadoCivil);
			SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelCURPCarnet(CURP, 11).c_str());
			SetDlgItemText(hwnd, _int_Persona_EstadoCivil, PasarDatosdelCURPCarnet(CURP, 11).c_str());

			SetDlgItemText(hwnd, _int_Persona_Telefono, PasarDatosdelCURPCarnet(CURP, 12).c_str());

			hComboBox = GetDlgItem(hwnd, _int_Persona_Sexo);
			SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelCURPCarnet(CURP, 13).c_str());
			SetDlgItemText(hwnd, _int_Persona_Sexo, PasarDatosdelCURPCarnet(CURP, 13).c_str());

			hComboBox = GetDlgItem(hwnd, _int_Persona_GrupoOcupacional);
			SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelCURPCarnet(CURP, 14).c_str());
			SetDlgItemText(hwnd, _int_Persona_GrupoOcupacional, PasarDatosdelCURPCarnet(CURP, 14).c_str());

			hComboBox = GetDlgItem(hwnd, _int_Persona_PerfilRiesgo);
			SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelCURPCarnet(CURP, 15).c_str());
			SetDlgItemText(hwnd, _int_Persona_PerfilRiesgo, PasarDatosdelCURPCarnet(CURP, 15).c_str());

			String_Persona_PathDocumentoIdentidad = PasarDatosdelCURPCarnet(CURP, 16);
			id = atoi(PasarDatosdelCURPCarnet(CURP, 17).c_str());

			OPENFILENAME OfnPersonaDocumento;
			ZeroMemory(&OfnPersonaDocumento, sizeof(OPENFILENAME));
			HWND hDocumentoIdeintidad = GetDlgItem(hwnd, _int_Persona_PictureControl);
			HBITMAP hpcDocumentoIdentidad = (HBITMAP)LoadImage(NULL, String_Persona_PathDocumentoIdentidad.c_str(), IMAGE_BITMAP, 150, 150, LR_LOADFROMFILE);
			SendMessage(hDocumentoIdeintidad, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hpcDocumentoIdentidad);
			DeleteObject(hpcDocumentoIdentidad);
		}
		else {
			MessageBox(hwnd, "Seleccione un CURP primero!", "Advertencia", MB_ICONEXCLAMATION);
		}

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

	void EditarPersona(int _id) {
		PtrAuxiliarPersona = PtrOrigenPersona;
		while (PtrAuxiliarPersona != NULL) {
			if (PtrAuxiliarPersona->id == id) {
				PtrAuxiliarPersona->String_Persona_ApellidoPaterno = String_Persona_ApellidoPaterno;
				PtrAuxiliarPersona->String_Persona_ApellidoMaterno = String_Persona_ApellidoMaterno;
				PtrAuxiliarPersona->String_Persona_Nombre = String_Persona_Nombre;
				PtrAuxiliarPersona->String_Persona_RFC = String_Persona_RFC;
				PtrAuxiliarPersona->String_Persona_FechaNacimiento = String_Persona_FechaNacimiento;
				PtrAuxiliarPersona->String_Persona_Calle = String_Persona_Calle;
				PtrAuxiliarPersona->String_Persona_Colonia = String_Persona_Colonia;
				PtrAuxiliarPersona->String_Persona_Municipio = String_Persona_Municipio;
				PtrAuxiliarPersona->String_Persona_Estado = String_Persona_Estado;
				PtrAuxiliarPersona->String_Persona_EstadoCivil = String_Persona_EstadoCivil;
				PtrAuxiliarPersona->String_Persona_Telefono = String_Persona_Telefono;
				PtrAuxiliarPersona->String_Persona_Sexo = String_Persona_Sexo;
				PtrAuxiliarPersona->String_Persona_GrupoOcupacional = String_Persona_GrupoOcupacional;
				PtrAuxiliarPersona->String_Persona_PerfilRiesgo = String_Persona_PerfilRiesgo;
				PtrAuxiliarPersona->String_Persona_PathDocumentoIdentidad = String_Persona_PathDocumentoIdentidad;
				return;
			}
			else {
				PtrAuxiliarPersona = PtrAuxiliarPersona->Ptr_Persona_siguiente;
			}
		}
		return;
	}

	void BorrarPersona(int _id) {
		PtrAuxiliarPersona = PtrOrigenPersona;
		while (PtrAuxiliarPersona != NULL) {
			if (PtrAuxiliarPersona->id == id) {
				PtrAuxiliarPersona->borrado = true;
				return;
			}
			else {
				PtrAuxiliarPersona = PtrAuxiliarPersona->Ptr_Persona_siguiente;
			}
		}
		return;
	}

	void GuardarPersonasTxt(HWND hwnd) {
		/*
		if (PtrOrigenPersona != NULL) {
			ofstream OfGuardar("CapturaPersona.txt");
			if (PtrOrigenPersona->Ptr_Persona_siguiente == NULL) {
				OfGuardar << PtrOrigenPersona->String_Persona_ApellidoPaterno << "\n";
				OfGuardar << PtrOrigenPersona->String_Persona_ApellidoMaterno << "\n";
				OfGuardar << PtrOrigenPersona->String_Persona_Nombre << "\n";
				OfGuardar << PtrOrigenPersona->String_Persona_CURP << "\n";
				OfGuardar << PtrOrigenPersona->String_Persona_RFC << "\n";
				OfGuardar << PtrOrigenPersona->String_Persona_FechaNacimiento << "\n";
				OfGuardar << PtrOrigenPersona->String_Persona_Calle << "\n";
				OfGuardar << PtrOrigenPersona->String_Persona_Colonia << "\n";
				OfGuardar << PtrOrigenPersona->String_Persona_Municipio << "\n";
				OfGuardar << PtrOrigenPersona->String_Persona_Estado << "\n";
				OfGuardar << PtrOrigenPersona->String_Persona_EstadoCivil << "\n";
				OfGuardar << PtrOrigenPersona->String_Persona_Telefono << "\n";
				OfGuardar << PtrOrigenPersona->String_Persona_Sexo << "\n";
				OfGuardar << PtrOrigenPersona->String_Persona_GrupoOcupacional << "\n";
				OfGuardar << PtrOrigenPersona->String_Persona_PerfilRiesgo << "\n";
				OfGuardar << PtrOrigenPersona->String_Persona_PathDocumentoIdentidad << "\n";
				OfGuardar << PtrOrigenPersona->id << "\n";
				OfGuardar << PtrOrigenPersona->borrado << "\n";
				OfGuardar << PtrOrigenPersona->vacunado << "\n";
			}
			else {
				PtrAuxiliarPersona = PtrOrigenPersona;
				while (PtrAuxiliarPersona != NULL) {
					OfGuardar << PtrAuxiliarPersona->String_Persona_ApellidoPaterno << "\n";
					OfGuardar << PtrAuxiliarPersona->String_Persona_ApellidoMaterno << "\n";
					OfGuardar << PtrAuxiliarPersona->String_Persona_Nombre << "\n";
					OfGuardar << PtrAuxiliarPersona->String_Persona_CURP << "\n";
					OfGuardar << PtrAuxiliarPersona->String_Persona_RFC << "\n";
					OfGuardar << PtrAuxiliarPersona->String_Persona_FechaNacimiento << "\n";
					OfGuardar << PtrAuxiliarPersona->String_Persona_Calle << "\n";
					OfGuardar << PtrAuxiliarPersona->String_Persona_Colonia << "\n";
					OfGuardar << PtrAuxiliarPersona->String_Persona_Municipio << "\n";
					OfGuardar << PtrAuxiliarPersona->String_Persona_Estado << "\n";
					OfGuardar << PtrAuxiliarPersona->String_Persona_EstadoCivil << "\n";
					OfGuardar << PtrAuxiliarPersona->String_Persona_Telefono << "\n";
					OfGuardar << PtrAuxiliarPersona->String_Persona_Sexo << "\n";
					OfGuardar << PtrAuxiliarPersona->String_Persona_GrupoOcupacional << "\n";
					OfGuardar << PtrAuxiliarPersona->String_Persona_PerfilRiesgo << "\n";
					OfGuardar << PtrAuxiliarPersona->String_Persona_PathDocumentoIdentidad << "\n";
					OfGuardar << PtrAuxiliarPersona->id << "\n";
					OfGuardar << PtrAuxiliarPersona->borrado << "\n";
					OfGuardar << PtrAuxiliarPersona->vacunado << "\n";
					PtrAuxiliarPersona = PtrAuxiliarPersona->Ptr_Persona_siguiente;
				}
			}
			OfGuardar.close();
		}*/
	}

	void CargarPersonasTxt(HWND hwnd) {
		/*
		ifstream IfCargar("CapturaPersona.txt", ios::app);
		while (!IfCargar.eof()) {
			IfCargar >> String_Persona_ApellidoPaterno;
			IfCargar >> String_Persona_ApellidoMaterno;
			IfCargar >> String_Persona_Nombre;
			IfCargar >> String_Persona_CURP;
			IfCargar >> String_Persona_RFC;
			IfCargar >> String_Persona_FechaNacimiento;
			IfCargar >> String_Persona_Calle;
			IfCargar >> String_Persona_Colonia;
			IfCargar >> String_Persona_Municipio;
			IfCargar >> String_Persona_Estado;
			IfCargar >> String_Persona_EstadoCivil;
			IfCargar >> String_Persona_Telefono;
			IfCargar >> String_Persona_Sexo;
			IfCargar >> String_Persona_GrupoOcupacional;
			IfCargar >> String_Persona_PerfilRiesgo;
			IfCargar >> String_Persona_PathDocumentoIdentidad;
			IfCargar >> id;
			IfCargar >> borrado;
			IfCargar >> vacunado;
			if (String_Persona_ApellidoMaterno == "") {
				break;
			}
			else {
				GuardarPersona();
				String_Persona_ApellidoPaterno = "";
				String_Persona_ApellidoMaterno = "";
				String_Persona_Nombre = "";
				String_Persona_CURP = "";
				String_Persona_RFC = "";
				String_Persona_FechaNacimiento = "";
				String_Persona_Calle = "";
				String_Persona_Colonia = "";
				String_Persona_Municipio = "";
				String_Persona_Estado = "";
				String_Persona_EstadoCivil = "";
				String_Persona_Telefono = "";
				String_Persona_Sexo = "";
				String_Persona_GrupoOcupacional = "";
				String_Persona_PerfilRiesgo = "";
				String_Persona_PathDocumentoIdentidad = "";
			}
		}
		IfCargar.close();
		 */
	}

	bool BuscarCURPyRFCRepetido(HWND hwnd, string _String_Persona_CURP, string _String_Persona_RFC) {

		if (PtrOrigenPersona != NULL) {
			PtrAuxiliarPersona = PtrOrigenPersona;
			do {
				if (!PtrAuxiliarPersona->borrado) {
					if ((PtrAuxiliarPersona->String_Persona_CURP == _String_Persona_CURP) || (PtrAuxiliarPersona->String_Persona_RFC == _String_Persona_RFC)) {
						MessageBox(hwnd, "Ya hay un	CURP o RFC, Verifique los datos Capturados.", "ERROR", MB_ICONEXCLAMATION);
						return false;
					}
					else {
						PtrAuxiliarPersona = PtrAuxiliarPersona->Ptr_Persona_siguiente;
					}
				}
				else {
					PtrAuxiliarPersona = PtrAuxiliarPersona->Ptr_Persona_siguiente;
				}
			} while (PtrAuxiliarPersona != NULL);
			return true;
		}
		else {
			return true;
		}
	}

	string PasarCURPsiIgualNombre(string _APaterno, string _AMaterno, string _Nombre) {

		PtrAuxiliarPersona = PtrOrigenPersona;
		while (PtrAuxiliarPersona!=NULL){
			if ((PtrAuxiliarPersona->String_Persona_ApellidoPaterno ==_APaterno) && (PtrAuxiliarPersona->String_Persona_ApellidoMaterno == _AMaterno) && (PtrAuxiliarPersona->String_Persona_Nombre == _Nombre)){
				return PtrAuxiliarPersona->String_Persona_CURP;
			}
			PtrAuxiliarPersona = PtrAuxiliarPersona->Ptr_Persona_siguiente;
		}
	return "";
	}

	string PasarDatosdelCURPCarnet(string _String_Persona_CURP, int DatoSolicitado) {

		if (PtrOrigenPersona != NULL) {
			PtrAuxiliarPersona = PtrOrigenPersona;
			do {
				if ((PtrAuxiliarPersona->String_Persona_CURP == _String_Persona_CURP) && !(PtrAuxiliarPersona->borrado)) {
					switch (DatoSolicitado){
						case 1: {
							return PtrAuxiliarPersona->String_Persona_ApellidoPaterno;
							break;
						}
						case 2: {
							return PtrAuxiliarPersona->String_Persona_ApellidoMaterno;
							break;
						}
						case 3: {
							return PtrAuxiliarPersona->String_Persona_Nombre;
							break;
						}
						case 4: {
							return PtrAuxiliarPersona->String_Persona_CURP;
							break;
						}
						case 5: {
							return PtrAuxiliarPersona->String_Persona_RFC;
							break;
						}
						case 6: {
							return PtrAuxiliarPersona->String_Persona_FechaNacimiento;
							break;
						}
						case 7: {
							return PtrAuxiliarPersona->String_Persona_Calle;
							break;
						}
						case 8: {
							return PtrAuxiliarPersona->String_Persona_Colonia;
							break;
						}
						case 9: {
							return PtrAuxiliarPersona->String_Persona_Municipio;
							break;
						}
						case 10: {
							return PtrAuxiliarPersona->String_Persona_Estado;
							break;
						}
						case 11: {
							return PtrAuxiliarPersona->String_Persona_EstadoCivil;
							break;
						}
						case 12: {
							return PtrAuxiliarPersona->String_Persona_Telefono;
							break;
						}
						case 13: {
							return PtrAuxiliarPersona->String_Persona_Sexo;
							break;
						}
						case 14: {
							return PtrAuxiliarPersona->String_Persona_GrupoOcupacional;
							break;
						}
						case 15: {
							return PtrAuxiliarPersona->String_Persona_PerfilRiesgo;
							break;
						}
						case 16: {
							return PtrAuxiliarPersona->String_Persona_PathDocumentoIdentidad;
							break;
						}
						case 17: {
							char id[10] = "";
							_itoa_s(PtrAuxiliarPersona->id, id, 10);
							return id;
							break;
						}
						default:
						break;
					}
				}
				else {
					PtrAuxiliarPersona = PtrAuxiliarPersona->Ptr_Persona_siguiente;
				}
			} while (PtrAuxiliarPersona != NULL);
		}
		return "";
	}

}*PtrOrigenPersona = NULL, * PtrAuxiliarPersona = NULL;
Persona Persona1;
#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string.h>
#include "cValidadores.h"
#include "cCapturaVacuna.h"
using namespace std;

class Carnet {

private:
	// 7 Variables Privadas
	string String_Carnet_CURP;
	string String_Carnet_IdVacuna;
	string String_Carnet_Lote;
	string String_Carnet_FechaDosis;
	string String_Carnet_NoDosis;
	string String_Carnet_CentroVacunacion;
	string String_Carnet_FechaProximaDosis;
	int id;
	bool err = false;
	Carnet* Ptr_Carnet_anterior = NULL;
	Carnet* Ptr_Carnet_siguiente = NULL;
	// 2 Variables Publicas
public:
	//Funcciones
	void PasarInformacionCarnet(HWND hwnd, int _int_Carnet_CURP, int _int_Carnet_IdVacuna, int _int_Carnet_Lote, int _int_Carnet_FechaDosis, int _int_Carnet_NoDosis, int _int_Carnet_CentroVacunacion, int _int_Carnet_FechaProximaDosis ,int _int_Persona_ApellidoPaterno, int _int_Persona_ApellidoMaterno, int _int_Persona_Nombre, int _int_Persona_CURP, int _int_Persona_RFC, int _int_Persona_FechaNacimiento, int _int_Persona_Calle, int _int_Persona_Colonia, int _int_Persona_Municipio, int _int_Persona_Estado, int _int_Persona_EstadoCivil, int _int_Persona_Telefono, int _int_Persona_Sexo, int _int_Persona_GrupoOcupacional, int _int_Persona_PerfilRiesgo, int _int_Vacuna_Tipo, int _int_Vacuna_Marca, int _int_Vacuna_NoDosis, int _int_Vacuna_Precio, int _int_Vacuna_Desc) {

		err = false;
		err = ValidacionLetraYNumeroSinEspacios(hwnd, _int_Carnet_CURP, err);
		err = ValidacionMayorACero(hwnd, _int_Carnet_IdVacuna, err);
		err = ValidacionLetraYNumeroSinEspacios(hwnd, _int_Carnet_Lote, err);
		err = ValidacionFechaMayorIgualAActual(hwnd, _int_Carnet_FechaDosis, err);
		err = ValidacionMayorACero(hwnd, _int_Carnet_NoDosis, err);
		err = ValidacionLetraSinEspacios(hwnd, _int_Carnet_CentroVacunacion, err);
		err = ValidacionFechaMayorACaptura(hwnd, _int_Carnet_FechaDosis, _int_Carnet_FechaProximaDosis, err);

		if (!err) {
			String_Carnet_CURP = ValidacionCapturaTexto(hwnd, _int_Carnet_CURP);
			String_Carnet_IdVacuna = ValidacionCapturaTexto(hwnd, _int_Carnet_IdVacuna);
			String_Carnet_Lote = ValidacionCapturaTexto(hwnd, _int_Carnet_Lote);
			String_Carnet_FechaDosis = ValidacionCapturaTexto(hwnd, _int_Carnet_FechaDosis);
			String_Carnet_NoDosis = ValidacionCapturaTexto(hwnd, _int_Carnet_NoDosis);
			String_Carnet_CentroVacunacion = ValidacionCapturaTexto(hwnd, _int_Carnet_CentroVacunacion);
			String_Carnet_FechaProximaDosis = ValidacionCapturaTexto(hwnd, _int_Carnet_FechaProximaDosis);
			SetDlgItemText(hwnd, _int_Carnet_CURP, "");
			SetDlgItemText(hwnd, _int_Carnet_IdVacuna, "");
			SetDlgItemText(hwnd, _int_Carnet_Lote, "");
			SetDlgItemText(hwnd, _int_Carnet_FechaDosis, "");
			SetDlgItemText(hwnd, _int_Carnet_NoDosis, "");
			SetDlgItemText(hwnd, _int_Carnet_CentroVacunacion, "");
			SetDlgItemText(hwnd, _int_Carnet_FechaProximaDosis, "");
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
			SetDlgItemText(hwnd, _int_Vacuna_Tipo, "");
			SetDlgItemText(hwnd, _int_Vacuna_Marca, "");
			SetDlgItemText(hwnd, _int_Vacuna_NoDosis, "");
			SetDlgItemText(hwnd, _int_Vacuna_Precio, "");
			SetDlgItemText(hwnd, _int_Vacuna_Desc, "");
			CargarInfoComboBoxCarnet(hwnd);
			GuardarCarnet();
			MessageBox(hwnd, "Se ha registrado el Carnet Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
		}
		else {
			MessageBox(hwnd, "Verifique que los datos ingresados sean válidos!", "ERROR", MB_ICONERROR);
		}
	}

	void CargarInfoComboBoxCarnet(HWND hwnd) {

		HWND hComboBox;
		hComboBox = GetDlgItem(hwnd, CB_CARNET_IDVACUNA);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		if (PtrOrigenVacuna != NULL) {
			PtrAuxiliarVacuna = PtrOrigenVacuna;
			while (PtrAuxiliarVacuna != NULL) {
				string id = Vacuna1.PasarIdVacunaCarnet(PtrAuxiliarVacuna);
				SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)id.c_str());
				PtrAuxiliarVacuna = PtrAuxiliarVacuna->Ptr_Vacuna_siguiente;
			}
		}
		else{
			MessageBox(hwnd, "PRIMERO DEBE DE AGREGAR AL MENOS UNA VACUNA!", "PRECAUCIÓN", MB_ICONWARNING);
		}
		hComboBox = GetDlgItem(hwnd, CB_CARNET_CURP);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		if (PtrOrigenPersona != NULL) {
			PtrAuxiliarPersona = PtrOrigenPersona;
			while (PtrAuxiliarPersona != NULL) {
				string CURP = Persona1.PasarCURPCarnet(PtrAuxiliarPersona);
				SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)CURP.c_str());
				PtrAuxiliarPersona = PtrAuxiliarPersona->Ptr_Persona_siguiente;
			}
		}
		else {
			MessageBox(hwnd, "PRIMERO DEBE DE AGREGAR AL MENOS UNA PERSONA!", "PRECAUCIÓN", MB_ICONWARNING);
		}
		hComboBox = GetDlgItem(hwnd, CB_CARNET_DOSIS);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
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
		hComboBox = GetDlgItem(hwnd, CB_CARNET_CENTROVACUNACION);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"NORTE");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"CENTRO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"SUR");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"ESTE");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"OESTE");
	}

	void GuardarCarnet() {

		if (PtrOrigenCarnet == NULL) {
			PtrOrigenCarnet = new Carnet;
			PtrOrigenCarnet->id++;
			PtrOrigenCarnet->String_Carnet_CURP = String_Carnet_CURP;
			PtrOrigenCarnet->String_Carnet_IdVacuna = String_Carnet_IdVacuna;
			PtrOrigenCarnet->String_Carnet_Lote = String_Carnet_Lote;
			PtrOrigenCarnet->String_Carnet_FechaDosis = String_Carnet_FechaDosis;
			PtrOrigenCarnet->String_Carnet_NoDosis = String_Carnet_NoDosis;
			PtrOrigenCarnet->String_Carnet_CentroVacunacion = String_Carnet_CentroVacunacion;
			PtrOrigenCarnet->String_Carnet_FechaProximaDosis = String_Carnet_FechaProximaDosis;
			PtrOrigenCarnet->Ptr_Carnet_siguiente = NULL;
			PtrOrigenCarnet->Ptr_Carnet_anterior = NULL;
		}
		else {
			PtrAuxiliarCarnet = PtrOrigenCarnet;
			while (PtrAuxiliarCarnet->Ptr_Carnet_siguiente != NULL) {
				PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
			}
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente = new Carnet;
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente->id = PtrAuxiliarCarnet->id + 1;
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente->String_Carnet_CURP = String_Carnet_CURP;
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente->String_Carnet_IdVacuna = String_Carnet_IdVacuna;
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente->String_Carnet_Lote = String_Carnet_Lote;
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente->String_Carnet_FechaDosis = String_Carnet_FechaDosis;
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente->String_Carnet_NoDosis = String_Carnet_NoDosis;
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente->String_Carnet_CentroVacunacion = String_Carnet_CentroVacunacion;
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente->String_Carnet_FechaProximaDosis = String_Carnet_FechaProximaDosis;
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente->Ptr_Carnet_siguiente = NULL;
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente->Ptr_Carnet_anterior = PtrAuxiliarCarnet;
		}
		PtrAuxiliarCarnet = PtrOrigenCarnet;
		return;
	}

	void CargarInformacionPersonaCarnet(HWND hwnd, int _int_Persona_ApellidoPaterno, int _int_Persona_ApellidoMaterno, int _int_Persona_Nombre, int _int_Persona_CURP, int _int_Persona_RFC, int _int_Persona_FechaNacimiento, int _int_Persona_Calle, int _int_Persona_Colonia, int _int_Persona_Municipio, int _int_Persona_Estado, int _int_Persona_EstadoCivil, int _int_Persona_Telefono, int _int_Persona_Sexo, int _int_Persona_GrupoOcupacional, int _int_Persona_PerfilRiesgo) {
		
		string CURP = ValidacionCapturaTexto(hwnd, CB_CARNET_CURP);
		if (CURP!=""){
			SetDlgItemText(hwnd, _int_Persona_ApellidoPaterno, Persona1.PasarDatosdelCURPCarnet(CURP, 1).c_str());
			SetDlgItemText(hwnd, _int_Persona_ApellidoMaterno, Persona1.PasarDatosdelCURPCarnet(CURP, 2).c_str());
			SetDlgItemText(hwnd, _int_Persona_Nombre, Persona1.PasarDatosdelCURPCarnet(CURP, 3).c_str());
			SetDlgItemText(hwnd, _int_Persona_CURP, Persona1.PasarDatosdelCURPCarnet(CURP, 4).c_str());
			SetDlgItemText(hwnd, _int_Persona_RFC, Persona1.PasarDatosdelCURPCarnet(CURP, 5).c_str());
			SetDlgItemText(hwnd, _int_Persona_FechaNacimiento, Persona1.PasarDatosdelCURPCarnet(CURP, 6).c_str());
			SetDlgItemText(hwnd, _int_Persona_Calle, Persona1.PasarDatosdelCURPCarnet(CURP, 7).c_str());
			SetDlgItemText(hwnd, _int_Persona_Colonia, Persona1.PasarDatosdelCURPCarnet(CURP, 8).c_str());
			SetDlgItemText(hwnd, _int_Persona_Municipio, Persona1.PasarDatosdelCURPCarnet(CURP, 9).c_str());
			SetDlgItemText(hwnd, _int_Persona_Estado, Persona1.PasarDatosdelCURPCarnet(CURP, 10).c_str());
			SetDlgItemText(hwnd, _int_Persona_EstadoCivil, Persona1.PasarDatosdelCURPCarnet(CURP, 11).c_str());
			SetDlgItemText(hwnd, _int_Persona_Telefono, Persona1.PasarDatosdelCURPCarnet(CURP, 12).c_str());
			SetDlgItemText(hwnd, _int_Persona_Sexo, Persona1.PasarDatosdelCURPCarnet(CURP, 13).c_str());
			SetDlgItemText(hwnd, _int_Persona_GrupoOcupacional, Persona1.PasarDatosdelCURPCarnet(CURP, 14).c_str());
			SetDlgItemText(hwnd, _int_Persona_PerfilRiesgo, Persona1.PasarDatosdelCURPCarnet(CURP, 15).c_str());
			OPENFILENAME OfnPersonaDocumento;
			ZeroMemory(&OfnPersonaDocumento, sizeof(OPENFILENAME));
			HWND hDocumentoIdeintidad = GetDlgItem(hwnd, PC_CARNET_PERSONA_DOCUMENTOIDENTIFICACION);
			HBITMAP hpcDocumentoIdentidad = (HBITMAP)LoadImage(NULL, Persona1.PasarDatosdelCURPCarnet(CURP, 16).c_str(), IMAGE_BITMAP, 150, 150, LR_LOADFROMFILE);
			SendMessage(hDocumentoIdeintidad, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hpcDocumentoIdentidad);
			DeleteObject(hpcDocumentoIdentidad);
		}
		else{
			MessageBox(hwnd, "Seleccione un CURP primero!", "Advertencia", MB_ICONEXCLAMATION);
		}

	}

	void CargarInformacionVacunaCarnet(HWND hwnd, int _int_Vacuna_Tipo, int _int_Vacuna_Marca, int _int_Vacuna_NoDosis, int _int_Vacuna_Precio, int _int_Vacuna_Desc) {

		string id = ValidacionCapturaTexto(hwnd, CB_CARNET_IDVACUNA);
		if (id != "") {
			SetDlgItemText(hwnd, _int_Vacuna_Tipo, Vacuna1.PasarDatosdelIdVacunaCarnet(id,1).c_str());
			SetDlgItemText(hwnd, _int_Vacuna_Marca, Vacuna1.PasarDatosdelIdVacunaCarnet(id, 2).c_str());
			SetDlgItemText(hwnd, _int_Vacuna_NoDosis, Vacuna1.PasarDatosdelIdVacunaCarnet(id, 3).c_str());
			SetDlgItemText(hwnd, _int_Vacuna_Precio, Vacuna1.PasarDatosdelIdVacunaCarnet(id, 4).c_str());
			SetDlgItemText(hwnd, _int_Vacuna_Desc, Vacuna1.PasarDatosdelIdVacunaCarnet(id, 5).c_str());
		}
		else {
			MessageBox(hwnd, "Seleccione una Id de Vacuna primero!", "Advertencia", MB_ICONEXCLAMATION);
		}

	}

}*PtrOrigenCarnet = NULL, * PtrAuxiliarCarnet = NULL;
Carnet Carnet1;
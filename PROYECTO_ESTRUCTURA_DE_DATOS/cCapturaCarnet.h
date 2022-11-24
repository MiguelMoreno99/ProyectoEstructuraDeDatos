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
	bool borrado = false;

	// 2 Variables Publicas
public:
	Carnet* Ptr_Carnet_anterior = NULL;
	Carnet* Ptr_Carnet_siguiente = NULL;

	//Funciones
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
			CargarInfoComboBoxCarnet(hwnd, _int_Carnet_NoDosis, _int_Carnet_CentroVacunacion);
			Vacuna1.CargarInfoComboBoxIds(hwnd, _int_Carnet_IdVacuna);
			Persona1.CargarInfoComboBoxCURP(hwnd, _int_Carnet_CURP);
			if (_int_Persona_CURP==NULL){
				int id = atoi(String_Carnet_IdVacuna.c_str());
				EditarCarnet(id);
				MessageBox(hwnd, "Se ha Editado el Carnet Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
			}
			else{
				GuardarCarnet();
				MessageBox(hwnd, "Se ha registrado el Carnet Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
			}
		}
		else {
			MessageBox(hwnd, "Verifique que los datos ingresados sean v�lidos!", "ERROR", MB_ICONERROR);
		}
	}

	void PasarInformacionCarnetEditar(HWND hwnd, int _int_Carnet_CURP, int _int_Carnet_IdVacuna, int _int_Carnet_Lote, int _int_Carnet_FechaDosis, int _int_Carnet_NoDosis, int _int_Carnet_CentroVacunacion, int _int_Carnet_FechaProximaDosis) {

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
			CargarInfoComboBoxCarnet(hwnd, _int_Carnet_NoDosis, _int_Carnet_CentroVacunacion);
			Vacuna1.CargarInfoComboBoxIds(hwnd, _int_Carnet_IdVacuna);
			Persona1.CargarInfoComboBoxCURP(hwnd, _int_Carnet_CURP);
			int id = atoi(String_Carnet_IdVacuna.c_str());
			EditarCarnet(id);
			MessageBox(hwnd, "Se ha Editado el Carnet Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
		}
		else {
			MessageBox(hwnd, "Verifique que los datos ingresados sean v�lidos!", "ERROR", MB_ICONERROR);
		}
	}

	void CargarInfoComboBoxCarnet(HWND hwnd,int _CB_CARNET_DOSIS,int _CB_CARNET_CENTROVACUNACION) {

		HWND hComboBox;
		hComboBox = GetDlgItem(hwnd, _CB_CARNET_DOSIS);
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
		hComboBox = GetDlgItem(hwnd, _CB_CARNET_CENTROVACUNACION);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"NORTE");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"CENTRO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"SUR");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"ESTE");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"OESTE");
	}

	void CargarInfoComboBoxIds(HWND hwnd, int _CB_CARNET_ID) {

		HWND hComboBox;
		hComboBox = GetDlgItem(hwnd, _CB_CARNET_ID);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		if (PtrOrigenCarnet != NULL) {
			PtrAuxiliarCarnet = PtrOrigenCarnet;
			while (PtrAuxiliarCarnet != NULL) {
				string id = PasarIdCarnet(PtrAuxiliarCarnet);
				if (id != "") {
					SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)id.c_str());
				}
				PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
			}
		}
		else {
			MessageBox(hwnd, "PRIMERO DEBE DE AGREGAR AL MENOS UN CARNET!", "PRECAUCI�N", MB_ICONWARNING);
		}
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

	void EditarCarnet(int _idCarnet) {

		while (PtrAuxiliarCarnet != NULL) {
			if (PtrAuxiliarCarnet->id==id) {
				PtrAuxiliarCarnet->Ptr_Carnet_siguiente->String_Carnet_CURP = String_Carnet_CURP;
				PtrAuxiliarCarnet->Ptr_Carnet_siguiente->String_Carnet_IdVacuna = String_Carnet_IdVacuna;
				PtrAuxiliarCarnet->Ptr_Carnet_siguiente->String_Carnet_Lote = String_Carnet_Lote;
				PtrAuxiliarCarnet->Ptr_Carnet_siguiente->String_Carnet_FechaDosis = String_Carnet_FechaDosis;
				PtrAuxiliarCarnet->Ptr_Carnet_siguiente->String_Carnet_NoDosis = String_Carnet_NoDosis;
				PtrAuxiliarCarnet->Ptr_Carnet_siguiente->String_Carnet_CentroVacunacion = String_Carnet_CentroVacunacion;
				PtrAuxiliarCarnet->Ptr_Carnet_siguiente->String_Carnet_FechaProximaDosis = String_Carnet_FechaProximaDosis;
			}
			else{
				PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
			}
			PtrAuxiliarCarnet = PtrOrigenCarnet;
			return;
		}
	}

	string PasarIdCarnet(Carnet * PtrAuxiliarCarnet) {
		if (!(PtrAuxiliarCarnet->borrado)) {
			char id[10] = "";
			_itoa_s(PtrAuxiliarCarnet->id, id, 10);
			return id;
		}
		else {
			return "";
		}
	}

}*PtrOrigenCarnet = NULL, * PtrAuxiliarCarnet = NULL;
Carnet Carnet1;
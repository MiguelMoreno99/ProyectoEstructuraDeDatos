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
	// 6 Variables
	string String_Carnet_CURP;
	string String_Carnet_IdVacuna;
	string String_Carnet_Lote;
	string String_Carnet_FechaDosis;
	string String_Carnet_NoDosis;
	string String_Carnet_CentroVacunacion;
	int id;
	bool err = false;
	Carnet* Ptr_Carnet_anterior = NULL;
	Carnet* Ptr_Carnet_siguiente = NULL;
public:
	//Funcciones
	void PasarInformacionCarnet(HWND hwnd, int _int_Carnet_CURP, int _int_Carnet_IdVacuna, int _int_Carnet_Lote, int _int_Carnet_FechaDosis, int _int_Carnet_NoDosis, int _int_Carnet_CentroVacunacion) {

		err = false;
		err = ValidacionLetraYNumeroSinEspacios(hwnd, _int_Carnet_CURP, err);
		err = ValidacionMayorACero(hwnd, _int_Carnet_IdVacuna, err);
		err = ValidacionLetraYNumeroSinEspacios(hwnd, _int_Carnet_Lote, err);
		err = ValidacionFechaMenorAActual(hwnd, _int_Carnet_FechaDosis, err);
		err = ValidacionMayorACero(hwnd, _int_Carnet_NoDosis, err);
		err = ValidacionLetraSinEspacios(hwnd, _int_Carnet_CentroVacunacion, err);

		if (!err) {
			String_Carnet_CURP = ValidacionCapturaTexto(hwnd, _int_Carnet_CURP);
			String_Carnet_IdVacuna = ValidacionCapturaTexto(hwnd, _int_Carnet_IdVacuna);
			String_Carnet_Lote = ValidacionCapturaTexto(hwnd, _int_Carnet_Lote);
			String_Carnet_FechaDosis = ValidacionCapturaTexto(hwnd, _int_Carnet_FechaDosis);
			String_Carnet_NoDosis = ValidacionCapturaTexto(hwnd, _int_Carnet_NoDosis);
			String_Carnet_CentroVacunacion = ValidacionCapturaTexto(hwnd, _int_Carnet_CentroVacunacion);
			SetDlgItemText(hwnd, _int_Carnet_CURP, "");
			SetDlgItemText(hwnd, _int_Carnet_IdVacuna, "");
			SetDlgItemText(hwnd, _int_Carnet_Lote, "");
			SetDlgItemText(hwnd, _int_Carnet_FechaDosis, "");
			SetDlgItemText(hwnd, _int_Carnet_NoDosis, "");
			SetDlgItemText(hwnd, _int_Carnet_CentroVacunacion, "");
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
		if (PtrOrigenVacuna!=NULL){
			PtrAuxiliarVacuna = PtrOrigenVacuna;
			int idVacuna = 1;
			while (PtrAuxiliarVacuna!=NULL){
				char cidVacuna[10] = "";
				_itoa_s(idVacuna, cidVacuna, 10);
				SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)cidVacuna);
				idVacuna++;
				PtrAuxiliarVacuna = PtrAuxiliarVacuna->Ptr_Vacuna_siguiente;
			}
		}else{
			MessageBox(hwnd, "PRIMERO DEBE DE AGREGAR AL MENOS UNA VACUNA!", "PRECAUCIÓN", MB_ICONWARNING);
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
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente->Ptr_Carnet_siguiente = NULL;
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente->Ptr_Carnet_anterior = PtrAuxiliarCarnet;
		}
		PtrAuxiliarCarnet = PtrOrigenCarnet;
		return;
	}

}*PtrOrigenCarnet = NULL, * PtrAuxiliarCarnet = NULL;
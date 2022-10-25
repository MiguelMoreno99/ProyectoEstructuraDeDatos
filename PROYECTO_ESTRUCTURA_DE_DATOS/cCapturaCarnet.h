#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string.h>
using namespace std;

class Carnet {

public:
	// 6 Variables
	string String_Carnet_CURP;
	string String_Carnet_IdVacuna;
	string String_Carnet_Lote;
	string String_Carnet_FechaDosis;
	string String_Carnet_NoDosis;
	string String_Carnet_CentroVacunacion;
	int id = 0;
	Carnet* Ptr_Carnet_anterior = NULL;
	Carnet* Ptr_Carnet_siguiente = NULL;

	//Funcciones
	void PasarInformacionCarnet(HWND hwnd, int _int_Carnet_CURP,
		int _int_Carnet_IdVacuna,
		int _int_Carnet_Lote,
		int _int_Carnet_FechaDosis,
		int _int_Carnet_NoDosis,
		int _int_Carnet_CentroVacunacion) {

		char DlgText[100] = "";
		HWND Hdlgitem;
		int Sizedlgitem;


		Hdlgitem = GetDlgItem(hwnd, _int_Carnet_CURP);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Carnet_CURP = DlgText;
		SetDlgItemText(hwnd, _int_Carnet_CURP, "");

		Hdlgitem = GetDlgItem(hwnd, _int_Carnet_IdVacuna);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Carnet_IdVacuna = DlgText;
		SetDlgItemText(hwnd, _int_Carnet_IdVacuna, "");

		Hdlgitem = GetDlgItem(hwnd, _int_Carnet_Lote);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Carnet_Lote = DlgText;
		SetDlgItemText(hwnd, _int_Carnet_Lote, "");

		Hdlgitem = GetDlgItem(hwnd, _int_Carnet_FechaDosis);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Carnet_FechaDosis = DlgText;
		SetDlgItemText(hwnd, _int_Carnet_FechaDosis, "");

		Hdlgitem = GetDlgItem(hwnd, _int_Carnet_NoDosis);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Carnet_NoDosis = DlgText;
		SetDlgItemText(hwnd, _int_Carnet_NoDosis, "");

		Hdlgitem = GetDlgItem(hwnd, _int_Carnet_CentroVacunacion);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Carnet_CentroVacunacion = DlgText;
		SetDlgItemText(hwnd, _int_Carnet_CentroVacunacion, "");

		GuardarCarnet();
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
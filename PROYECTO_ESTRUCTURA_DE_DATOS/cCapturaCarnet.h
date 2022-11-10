#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string.h>
#include "cValidadores.h"
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
	int id;
	bool err = false;
	Carnet* Ptr_Carnet_anterior = NULL;
	Carnet* Ptr_Carnet_siguiente = NULL;

	//Funcciones
	void PasarInformacionCarnet(HWND hwnd, int _int_Carnet_CURP,
		int _int_Carnet_IdVacuna,
		int _int_Carnet_Lote,
		int _int_Carnet_FechaDosis,
		int _int_Carnet_NoDosis,
		int _int_Carnet_CentroVacunacion) {

		err = false;
		err = ValidacionTexto(hwnd, _int_Carnet_CURP, err);
		err = ValidacionTexto(hwnd, _int_Carnet_IdVacuna, err);
		err = ValidacionTexto(hwnd, _int_Carnet_Lote, err);
		err = ValidacionTexto(hwnd, _int_Carnet_FechaDosis, err);
		err = ValidacionTexto(hwnd, _int_Carnet_NoDosis, err);
		err = ValidacionTexto(hwnd, _int_Carnet_CentroVacunacion, err);

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
			GuardarCarnet();
			MessageBox(hwnd, "Se ha registrado el Carnet Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
		}
		else {
			MessageBox(hwnd, "Verifique que los datos ingresados sean válidos!", "ERROR", MB_ICONERROR);
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
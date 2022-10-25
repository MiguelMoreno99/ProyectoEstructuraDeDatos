#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string.h>
using namespace std;

class Vacuna {

public:
	// 5 Variables
	string String_Vacuna_Tipo;
	string String_Vacuna_Marca;
	string String_Vacuna_NoDosis;
	string String_Vacuna_Precio;
	string String_Vacuna_Desc;
	int id = 0;
	Vacuna* Ptr_Vacuna_anterior = NULL;
	Vacuna* Ptr_Vacuna_siguiente = NULL;

	//Funcciones
	void PasarInformacionVacuna(HWND hwnd, int _int_Vacuna_Tipo,
		int _int_Vacuna_Marca,
		int _int_Vacuna_NoDosis,
		int _int_Vacuna_Precio,
		int _int_Vacuna_Desc) {

		char DlgText[100] = "";
		HWND Hdlgitem;
		int Sizedlgitem;


		Hdlgitem = GetDlgItem(hwnd, _int_Vacuna_Tipo);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Vacuna_Tipo = DlgText;
		SetDlgItemText(hwnd, _int_Vacuna_Tipo, "");

		Hdlgitem = GetDlgItem(hwnd, _int_Vacuna_Marca);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Vacuna_Marca = DlgText;
		SetDlgItemText(hwnd, _int_Vacuna_Marca, "");

		Hdlgitem = GetDlgItem(hwnd, _int_Vacuna_NoDosis);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Vacuna_NoDosis = DlgText;
		SetDlgItemText(hwnd, _int_Vacuna_NoDosis, "");

		Hdlgitem = GetDlgItem(hwnd, _int_Vacuna_Precio);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Vacuna_Precio = DlgText;
		SetDlgItemText(hwnd, _int_Vacuna_Precio, "");

		Hdlgitem = GetDlgItem(hwnd, _int_Vacuna_Desc);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Vacuna_Desc = DlgText;
		SetDlgItemText(hwnd, _int_Vacuna_Desc, "");

		GuardarVacuna();
	}

	void GuardarVacuna() {

		if (PtrOrigenVacuna == NULL) {
			PtrOrigenVacuna = new Vacuna;
			PtrOrigenVacuna->id++;
			PtrOrigenVacuna->String_Vacuna_Tipo = String_Vacuna_Tipo;
			PtrOrigenVacuna->String_Vacuna_Marca = String_Vacuna_Marca;
			PtrOrigenVacuna->String_Vacuna_NoDosis = String_Vacuna_NoDosis;
			PtrOrigenVacuna->String_Vacuna_Precio = String_Vacuna_Precio;
			PtrOrigenVacuna->String_Vacuna_Desc = String_Vacuna_Desc;
			PtrOrigenVacuna->Ptr_Vacuna_siguiente = NULL;
			PtrOrigenVacuna->Ptr_Vacuna_anterior = NULL;
		}
		else {
			PtrAuxiliarVacuna = PtrOrigenVacuna;
			while (PtrAuxiliarVacuna->Ptr_Vacuna_siguiente != NULL) {
				PtrAuxiliarVacuna = PtrAuxiliarVacuna->Ptr_Vacuna_siguiente;
			}
			PtrAuxiliarVacuna->Ptr_Vacuna_siguiente = new Vacuna;
			PtrAuxiliarVacuna->Ptr_Vacuna_siguiente->id = PtrAuxiliarVacuna->id + 1;
			PtrAuxiliarVacuna->Ptr_Vacuna_siguiente->String_Vacuna_Tipo = String_Vacuna_Tipo;
			PtrAuxiliarVacuna->Ptr_Vacuna_siguiente->String_Vacuna_Marca = String_Vacuna_Marca;
			PtrAuxiliarVacuna->Ptr_Vacuna_siguiente->String_Vacuna_NoDosis = String_Vacuna_NoDosis;
			PtrAuxiliarVacuna->Ptr_Vacuna_siguiente->String_Vacuna_Precio = String_Vacuna_Precio;
			PtrAuxiliarVacuna->Ptr_Vacuna_siguiente->String_Vacuna_Desc = String_Vacuna_Desc;
			PtrAuxiliarVacuna->Ptr_Vacuna_siguiente->Ptr_Vacuna_siguiente = NULL;
			PtrAuxiliarVacuna->Ptr_Vacuna_siguiente->Ptr_Vacuna_anterior = PtrAuxiliarVacuna;
		}
		PtrAuxiliarVacuna = PtrOrigenVacuna;
		return;
	}

}*PtrOrigenVacuna = NULL, * PtrAuxiliarVacuna = NULL;
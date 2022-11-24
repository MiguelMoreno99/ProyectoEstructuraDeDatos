#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string.h>
#include "cValidadores.h"
using namespace std;

class Vacuna {

private:
	// 5 Variables Privadas
	string String_Vacuna_Tipo;
	string String_Vacuna_Marca;
	string String_Vacuna_NoDosis;
	string String_Vacuna_Precio;
	string String_Vacuna_Desc;
	int id;
	bool err = false;

public:
	// 2 Variables Publicas
	Vacuna* Ptr_Vacuna_anterior = NULL;
	Vacuna* Ptr_Vacuna_siguiente = NULL;

	//Funcciones
	void PasarInformacionVacuna(HWND hwnd, int _int_Vacuna_Tipo, int _int_Vacuna_Marca, int _int_Vacuna_NoDosis, int _int_Vacuna_Precio, int _int_Vacuna_Desc) {

		err = false;
		err = ValidacionLetraConEspacios(hwnd, _int_Vacuna_Tipo, err);
		err = ValidacionLetraConEspacios(hwnd, _int_Vacuna_Marca, err);
		err = ValidacionMayorACero(hwnd, _int_Vacuna_NoDosis, err);
		err = ValidacionMayorACero(hwnd, _int_Vacuna_Precio, err);
		err = ValidacionLetraYNumeroConEspacios(hwnd, _int_Vacuna_Desc, err);

		if (!err) {
			String_Vacuna_Tipo = ValidacionCapturaTexto(hwnd, _int_Vacuna_Tipo);
			String_Vacuna_Marca = ValidacionCapturaTexto(hwnd, _int_Vacuna_Marca);
			String_Vacuna_NoDosis = ValidacionCapturaTexto(hwnd, _int_Vacuna_NoDosis);
			String_Vacuna_Precio = ValidacionANumero(hwnd, _int_Vacuna_Precio);
			String_Vacuna_Desc = ValidacionCapturaTexto(hwnd, _int_Vacuna_Desc);
			SetDlgItemText(hwnd, _int_Vacuna_Tipo, "");
			SetDlgItemText(hwnd, _int_Vacuna_Marca, "");
			SetDlgItemText(hwnd, _int_Vacuna_NoDosis, "");
			SetDlgItemText(hwnd, _int_Vacuna_Precio, "");
			SetDlgItemText(hwnd, _int_Vacuna_Desc, "");
			CargarInfoComboBoxVacuna(hwnd);
			GuardarVacuna();
			MessageBox(hwnd, "Se ha registrado la Vacuna Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
		}
		else {
			MessageBox(hwnd, "Verifique que los datos ingresados sean válidos!", "ERROR", MB_ICONERROR);
		}
	}

	void CargarInfoComboBoxVacuna(HWND hwnd) {

		HWND hComboBox;			
		hComboBox = GetDlgItem(hwnd, CB_VACUNA_MARCA);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"PFIZER BIONTECH");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"MODERNA");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"NOVAVAX");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"JANSSEN DE JOHNSON");
		hComboBox = GetDlgItem(hwnd, CB_VACUNA_DOSIS);
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
		hComboBox = GetDlgItem(hwnd, CB_VACUNA_TIPO);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"ARN MENSAJERO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"SUB UNIDADES PROTEICAS");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"VECTOR VIRAL");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"OTRO");
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

	string PasarIdVacunaCarnet(Vacuna* PtrAuxiliarVacuna) {

		char id[10] = "";
		_itoa_s(PtrAuxiliarVacuna->id, id, 10);
		return id;
	}

	string PasarDatosdelIdVacunaCarnet(string _String_Vacuna_id, int DatoSolicitado) {

		if (PtrOrigenVacuna!= NULL) {
			PtrAuxiliarVacuna = PtrOrigenVacuna;
			do {
				char id[10] = "";
				string sId = "";
				_itoa_s(PtrAuxiliarVacuna->id, id, 10);
				sId = id;
				if (sId == _String_Vacuna_id) {
					switch (DatoSolicitado) {
					case 1: {
						return PtrAuxiliarVacuna->String_Vacuna_Tipo;
						break;
					}
					case 2: {
						return PtrAuxiliarVacuna->String_Vacuna_Marca;
						break;
					}
					case 3: {
						return PtrAuxiliarVacuna->String_Vacuna_NoDosis;
						break;
					}
					case 4: {
						return PtrAuxiliarVacuna->String_Vacuna_Precio;
						break;
					}
					case 5: {
						return PtrAuxiliarVacuna->String_Vacuna_Desc;
						break;
					}
					default:
						break;
					}
				}
				else {
					PtrAuxiliarVacuna = PtrAuxiliarVacuna->Ptr_Vacuna_siguiente;
				}
			} while (PtrAuxiliarVacuna != NULL);
		}
		return "";
	}

}*PtrOrigenVacuna = NULL, * PtrAuxiliarVacuna = NULL;
Vacuna Vacuna1;
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
	bool borrado = false;

public:
	// 2 Variables Publicas
	Vacuna* Ptr_Vacuna_anterior = NULL;
	Vacuna* Ptr_Vacuna_siguiente = NULL;

	//Funcciones
	void GuardarInformacionVacuna(HWND hwnd, int _int_Vacuna_Tipo, int _int_Vacuna_Marca, int _int_Vacuna_NoDosis, int _int_Vacuna_Precio, int _int_Vacuna_Desc) {

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
			CargarInfoComboBoxVacuna(hwnd, _int_Vacuna_Marca, _int_Vacuna_NoDosis, _int_Vacuna_Tipo);
			GuardarVacuna();
			MessageBox(hwnd, "Se ha registrado la Vacuna Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
		}
		else {
			MessageBox(hwnd, "Verifique que los datos ingresados sean válidos!", "ERROR", MB_ICONERROR);
		}
	}

	void EditarInformacionVacuna(HWND hwnd, int _int_Vacuna_IdAEditar, int _int_Vacuna_Tipo, int _int_Vacuna_Marca, int _int_Vacuna_NoDosis, int _int_Vacuna_Precio, int _int_Vacuna_Desc) {

		err = false;
		err = ValidacionMayorACero(hwnd, _int_Vacuna_IdAEditar, err);
		err = ValidacionLetraConEspacios(hwnd, _int_Vacuna_Tipo, err);
		err = ValidacionLetraConEspacios(hwnd, _int_Vacuna_Marca, err);
		err = ValidacionMayorACero(hwnd, _int_Vacuna_NoDosis, err);
		err = ValidacionMayorACero(hwnd, _int_Vacuna_Precio, err);
		err = ValidacionLetraYNumeroConEspacios(hwnd, _int_Vacuna_Desc, err);

		if (!err) {
			id = atoi(ValidacionANumero(hwnd, _int_Vacuna_IdAEditar).c_str());
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
			CargarInfoComboBoxVacuna(hwnd, _int_Vacuna_Marca, _int_Vacuna_NoDosis, _int_Vacuna_Tipo);
			CargarInfoComboBoxIds(hwnd, _int_Vacuna_IdAEditar);
			EditarVacuna(id);
			MessageBox(hwnd, "Se ha Editado la Vacuna Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
		}
		else {
			MessageBox(hwnd, "Verifique que los datos ingresados sean válidos!", "ERROR", MB_ICONERROR);
		}
	}

	void BorrarInformacionVacuna(HWND hwnd, int _int_Vacuna_IdABorrar, int _int_Vacuna_Tipo, int _int_Vacuna_Marca, int _int_Vacuna_NoDosis, int _int_Vacuna_Precio, int _int_Vacuna_Desc) {

		err = false;
		err = ValidacionMayorACero(hwnd, _int_Vacuna_IdABorrar, err);

		if (!err) {
			id = atoi(ValidacionANumero(hwnd, _int_Vacuna_IdABorrar).c_str());
			SetDlgItemText(hwnd, _int_Vacuna_Tipo, "");
			SetDlgItemText(hwnd, _int_Vacuna_Marca, "");
			SetDlgItemText(hwnd, _int_Vacuna_NoDosis, "");
			SetDlgItemText(hwnd, _int_Vacuna_Precio, "");
			SetDlgItemText(hwnd, _int_Vacuna_Desc, "");
			BorrarVacuna(id);
			CargarInfoComboBoxVacuna(hwnd, _int_Vacuna_Marca, _int_Vacuna_NoDosis, _int_Vacuna_Tipo);
			CargarInfoComboBoxIds(hwnd, _int_Vacuna_IdABorrar);
			MessageBox(hwnd, "Se ha Borrado la Vacuna Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
		}
		else {
			MessageBox(hwnd, "Verifique que los datos ingresados sean válidos!", "ERROR", MB_ICONERROR);
		}
	}

	void CargarInfoComboBoxVacuna(HWND hwnd, int _CB_VACUNA_MARCA,int _CB_VACUNA_DOSIS, int _CB_VACUNA_TIPO) {

		HWND hComboBox;			
		hComboBox = GetDlgItem(hwnd, _CB_VACUNA_MARCA);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"PFIZER BIONTECH");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"MODERNA");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"NOVAVAX");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"JANSSEN DE JOHNSON");
		hComboBox = GetDlgItem(hwnd, _CB_VACUNA_DOSIS);
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
		hComboBox = GetDlgItem(hwnd, _CB_VACUNA_TIPO);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"ARN MENSAJERO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"SUB UNIDADES PROTEICAS");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"VECTOR VIRAL");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"OTRO");
	}

	void CargarInfoComboBoxIds(HWND hwnd, int _CB_VACUNA_ID) {

		HWND hComboBox;
		hComboBox = GetDlgItem(hwnd, _CB_VACUNA_ID);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		if (PtrOrigenVacuna != NULL) {
			PtrAuxiliarVacuna = PtrOrigenVacuna;
			while (PtrAuxiliarVacuna != NULL) {
				string id = PasarIdVacuna(PtrAuxiliarVacuna);
				if (id != "") {
					SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)id.c_str());
				}
				PtrAuxiliarVacuna = PtrAuxiliarVacuna->Ptr_Vacuna_siguiente;
			}
		}
		else {
			MessageBox(hwnd, "PRIMERO DEBE DE AGREGAR AL MENOS UNA VACUNA!", "PRECAUCIÓN", MB_ICONWARNING);
		}
	}

	void CargarInformacionVacuna(HWND hwnd, int _int_Vacuna_Id, int _int_Vacuna_Tipo, int _int_Vacuna_Marca, int _int_Vacuna_NoDosis, int _int_Vacuna_Precio, int _int_Vacuna_Desc) {

		string id = ValidacionCapturaTexto(hwnd, _int_Vacuna_Id);
		if (id != "") {
			HWND hComboBox;
			hComboBox = GetDlgItem(hwnd, _int_Vacuna_Tipo);
			SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelIdVacuna(id, 1).c_str());
			SetDlgItemText(hwnd, _int_Vacuna_Tipo, PasarDatosdelIdVacuna(id, 1).c_str());

			hComboBox = GetDlgItem(hwnd, _int_Vacuna_Marca);
			SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelIdVacuna(id, 2).c_str());
			SetDlgItemText(hwnd, _int_Vacuna_Marca, PasarDatosdelIdVacuna(id, 2).c_str());

			hComboBox = GetDlgItem(hwnd, _int_Vacuna_NoDosis);
			SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelIdVacuna(id, 3).c_str());
			SetDlgItemText(hwnd, _int_Vacuna_NoDosis, PasarDatosdelIdVacuna(id, 3).c_str());

			SetDlgItemText(hwnd, _int_Vacuna_Precio, PasarDatosdelIdVacuna(id, 4).c_str());
			SetDlgItemText(hwnd, _int_Vacuna_Desc, PasarDatosdelIdVacuna(id, 5).c_str());
		}
		else {
			MessageBox(hwnd, "Seleccione una Id de Vacuna primero!", "Advertencia", MB_ICONEXCLAMATION);
		}

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

	void EditarVacuna(int _id) {
		PtrAuxiliarVacuna = PtrOrigenVacuna;
		while (PtrAuxiliarVacuna != NULL) {
			if (PtrAuxiliarVacuna->id == id) {
				PtrAuxiliarVacuna->String_Vacuna_Tipo = String_Vacuna_Tipo;
				PtrAuxiliarVacuna->String_Vacuna_Marca = String_Vacuna_Marca;
				PtrAuxiliarVacuna->String_Vacuna_NoDosis = String_Vacuna_NoDosis;
				PtrAuxiliarVacuna->String_Vacuna_Precio = String_Vacuna_Precio;
				PtrAuxiliarVacuna->String_Vacuna_Desc = String_Vacuna_Desc;
				return;
			}
			else {
				PtrAuxiliarVacuna = PtrAuxiliarVacuna->Ptr_Vacuna_siguiente;
			}
		}
		return;
	}

	void BorrarVacuna(int _id) {
		PtrAuxiliarVacuna = PtrOrigenVacuna;
		while (PtrAuxiliarVacuna != NULL) {
			if (PtrAuxiliarVacuna->id == id) {
				PtrAuxiliarVacuna->borrado = true;
				return;
			}
			else {
				PtrAuxiliarVacuna = PtrAuxiliarVacuna->Ptr_Vacuna_siguiente;
			}
		}
		return;
	}

	string PasarIdVacuna(Vacuna* PtrAuxiliarVacuna) {
		if (!(PtrAuxiliarVacuna->borrado)){
			char id[10] = "";
			_itoa_s(PtrAuxiliarVacuna->id, id, 10);
			return id;
		}
		else {
			return "";
		}
	}

	string PasarDatosdelIdVacuna(string _String_Vacuna_id, int DatoSolicitado) {

		if (PtrOrigenVacuna!= NULL) {
			PtrAuxiliarVacuna = PtrOrigenVacuna;
			do {
				char id[10] = "";
				string sId = "";
				_itoa_s(PtrAuxiliarVacuna->id, id, 10);
				sId = id;
				if ((sId == _String_Vacuna_id) && !(PtrAuxiliarVacuna->borrado)) {
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
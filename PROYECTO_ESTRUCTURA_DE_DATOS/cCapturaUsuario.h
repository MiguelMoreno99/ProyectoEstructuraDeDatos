#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string.h>
using namespace std;

class Usuario {

public:
	// 4 Variables
	string String_Usuario_Usuario;
	string String_Usuario_Contraseña;
	string String_Usuario_Nombre;
	string String_Usuario_ApellidoPaterno;
	string String_Usuario_ApellidoMaterno;
	int id = 0;
	Usuario* Ptr_Usuario_anterior = NULL;
	Usuario* Ptr_Usuario_siguiente = NULL;

	//Funcciones
	void PasarInformacionUsuario(HWND hwnd, int _int_Usuario_Usuario, int _int_Usuario_Contraseña, int _int_Usuario_Nombre, int _int_Usuario_ApellidoPaterno, int _int_Usuario_ApellidoMaterno) {

		char DlgText[100] = "";
		HWND Hdlgitem;
		int Sizedlgitem;


		Hdlgitem = GetDlgItem(hwnd, _int_Usuario_Usuario);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Usuario_Usuario = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Usuario_Contraseña);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Usuario_Contraseña= DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Usuario_Nombre);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Usuario_Nombre = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Usuario_ApellidoPaterno);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Usuario_ApellidoPaterno = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Usuario_ApellidoMaterno);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Usuario_ApellidoMaterno = DlgText;
		GuardarUsuario();
	}

	void GuardarUsuario() {

		if (PtrOrigenUsuario == NULL) {
			PtrOrigenUsuario = new Usuario;
			PtrOrigenUsuario->id++;
			PtrOrigenUsuario->String_Usuario_Usuario = String_Usuario_Usuario;
			PtrOrigenUsuario->String_Usuario_Contraseña = String_Usuario_Contraseña;
			PtrOrigenUsuario->String_Usuario_Nombre = String_Usuario_Nombre;
			PtrOrigenUsuario->String_Usuario_ApellidoPaterno = String_Usuario_ApellidoPaterno;
			PtrOrigenUsuario->String_Usuario_ApellidoMaterno= String_Usuario_ApellidoMaterno;
			PtrOrigenUsuario->Ptr_Usuario_siguiente = NULL;
			PtrOrigenUsuario->Ptr_Usuario_anterior = NULL;
		}
		else {
			PtrAuxiliarUsuario = PtrOrigenUsuario;
			while (PtrAuxiliarUsuario->Ptr_Usuario_siguiente != NULL) {
				PtrAuxiliarUsuario = PtrAuxiliarUsuario->Ptr_Usuario_siguiente;
			}
			PtrAuxiliarUsuario->Ptr_Usuario_siguiente = new Usuario;
			PtrAuxiliarUsuario->Ptr_Usuario_siguiente->id = PtrAuxiliarUsuario->id + 1;
			PtrAuxiliarUsuario->Ptr_Usuario_siguiente->String_Usuario_Usuario = String_Usuario_Usuario;
			PtrAuxiliarUsuario->Ptr_Usuario_siguiente->String_Usuario_Contraseña = String_Usuario_Contraseña;
			PtrAuxiliarUsuario->Ptr_Usuario_siguiente->String_Usuario_Nombre = String_Usuario_Nombre;
			PtrAuxiliarUsuario->Ptr_Usuario_siguiente->String_Usuario_ApellidoPaterno = String_Usuario_ApellidoPaterno;
			PtrAuxiliarUsuario->Ptr_Usuario_siguiente->String_Usuario_ApellidoMaterno = String_Usuario_ApellidoMaterno;
			PtrAuxiliarUsuario->Ptr_Usuario_siguiente->Ptr_Usuario_siguiente = NULL;
			PtrAuxiliarUsuario->Ptr_Usuario_siguiente->Ptr_Usuario_anterior = PtrAuxiliarUsuario;
		}
		PtrAuxiliarUsuario = PtrOrigenUsuario;
		return;
	}

}*PtrOrigenUsuario=NULL, * PtrAuxiliarUsuario = NULL;
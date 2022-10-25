#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string.h>
#include "cValidadores.h"
using namespace std;

class Usuario {

private:
	// 5 Variables
	string String_Usuario_Usuario;
	string String_Usuario_Contraseña;
	string String_Usuario_Nombre;
	string String_Usuario_ApellidoPaterno;
	string String_Usuario_ApellidoMaterno;
	int id = 0;
	bool err = false;
	Usuario* Ptr_Usuario_anterior = NULL;
	Usuario* Ptr_Usuario_siguiente = NULL;

public:
	//Funcciones
	void PasarInformacionUsuario(HWND hwnd, int _int_Usuario_Usuario, int _int_Usuario_Contraseña, int _int_Usuario_Nombre,
		int _int_Usuario_ApellidoPaterno, int _int_Usuario_ApellidoMaterno) {

		err = ValidacionTexto(hwnd, _int_Usuario_Usuario);
		String_Usuario_Usuario = ValidacionCapturaTexto(hwnd, _int_Usuario_Usuario);
		SetDlgItemText(hwnd, _int_Usuario_Usuario, "");

		err = ValidacionTexto(hwnd, _int_Usuario_Contraseña);
		String_Usuario_Contraseña = ValidacionCapturaTexto(hwnd, _int_Usuario_Contraseña);
		SetDlgItemText(hwnd, _int_Usuario_Contraseña, "");

		err = ValidacionTexto(hwnd, _int_Usuario_Nombre);
		String_Usuario_Nombre = ValidacionCapturaTexto(hwnd, _int_Usuario_Nombre);
		SetDlgItemText(hwnd, _int_Usuario_Nombre, "");

		err = ValidacionTexto(hwnd, _int_Usuario_ApellidoPaterno);
		String_Usuario_ApellidoPaterno = ValidacionCapturaTexto(hwnd, _int_Usuario_ApellidoPaterno);
		SetDlgItemText(hwnd, _int_Usuario_ApellidoPaterno, "");

		err = ValidacionTexto(hwnd, _int_Usuario_ApellidoMaterno);
		String_Usuario_ApellidoMaterno = ValidacionCapturaTexto(hwnd, _int_Usuario_ApellidoMaterno);
		SetDlgItemText(hwnd, _int_Usuario_ApellidoMaterno, "");

		if (!err){
			GuardarUsuario();
			MessageBox(hwnd, "Se ha registrado el Usuario Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
		}
		else{
			MessageBox(hwnd, "Verifique que los datos ingresados sean válidos!", "ERROR", MB_ICONERROR);
		}

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
#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string.h>
#include "cValidadores.h"
#include <fstream>
using namespace std;

class Usuario {

private:
	// 5 Variables
	string String_Usuario_Usuario;
	string String_Usuario_Contraseña;
	string String_Usuario_Nombre;
	string String_Usuario_ApellidoPaterno;
	string String_Usuario_ApellidoMaterno;
	int id;
	bool err = false;
	Usuario* Ptr_Usuario_anterior = NULL;
	Usuario* Ptr_Usuario_siguiente = NULL;
public:
	//Funcciones
	void PasarInformacionUsuario(HWND hwnd, int _int_Usuario_Usuario, int _int_Usuario_Contraseña, int _int_Usuario_Nombre, int _int_Usuario_ApellidoPaterno, int _int_Usuario_ApellidoMaterno) {

		err = false;
		err = ValidacionTexto(hwnd, _int_Usuario_Usuario, err);
		err = ValidacionTexto(hwnd, _int_Usuario_Contraseña, err);
		err = ValidacionTexto(hwnd, _int_Usuario_Nombre, err);
		err = ValidacionTexto(hwnd, _int_Usuario_ApellidoPaterno, err);
		err = ValidacionTexto(hwnd, _int_Usuario_ApellidoMaterno, err);

		if (!err) {
			String_Usuario_Usuario = ValidacionCapturaTexto(hwnd, _int_Usuario_Usuario);
			String_Usuario_Contraseña = ValidacionCapturaTexto(hwnd, _int_Usuario_Contraseña);
			String_Usuario_Nombre = ValidacionCapturaTexto(hwnd, _int_Usuario_Nombre);
			String_Usuario_ApellidoPaterno = ValidacionCapturaTexto(hwnd, _int_Usuario_ApellidoPaterno);
			String_Usuario_ApellidoMaterno = ValidacionCapturaTexto(hwnd, _int_Usuario_ApellidoMaterno);
			if (BuscarUsuarioRepetido(hwnd, String_Usuario_Usuario)) {
				SetDlgItemText(hwnd, _int_Usuario_Usuario, "");
				SetDlgItemText(hwnd, _int_Usuario_Contraseña, "");
				SetDlgItemText(hwnd, _int_Usuario_Nombre, "");
				SetDlgItemText(hwnd, _int_Usuario_ApellidoPaterno, "");
				SetDlgItemText(hwnd, _int_Usuario_ApellidoMaterno, "");
				GuardarUsuario();
				MessageBox(hwnd, "Se ha registrado el Usuario Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
			}
		}
		else{
			MessageBox(hwnd, "Verifique que los datos ingresados sean válidos!", "ERROR", MB_ICONERROR);
		}
	}

	void GuardarUsuario() {

		if (PtrOrigenUsuario == NULL) {
			PtrOrigenUsuario = new Usuario;
			PtrOrigenUsuario->id++;
			id++;
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
			id++;
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

	void ValidarUsuario(HWND hInicioSesion, HWND hVentanaPrincipal, int _int_Usuario_Usuario, int _int_Usuario_Contraseña) {

		if (PtrOrigenUsuario == NULL) {
			MessageBox(hInicioSesion, "No hay nigun usuario registrado!", "ERROR", MB_ICONERROR);
		}

		else {
			err = false;
			err = ValidacionTexto(hInicioSesion, _int_Usuario_Usuario, err);
			err = ValidacionTexto(hInicioSesion, _int_Usuario_Contraseña, err);

			if (!err) {
				err = true;
				String_Usuario_Usuario = ValidacionCapturaTexto(hInicioSesion, _int_Usuario_Usuario);
				String_Usuario_Contraseña = ValidacionCapturaTexto(hInicioSesion, _int_Usuario_Contraseña);
				PtrAuxiliarUsuario = PtrOrigenUsuario;
				do{
					if (String_Usuario_Usuario == PtrAuxiliarUsuario->String_Usuario_Usuario && String_Usuario_Contraseña == PtrAuxiliarUsuario->String_Usuario_Contraseña){
						SetDlgItemText(hInicioSesion, _int_Usuario_Usuario, "");
						SetDlgItemText(hInicioSesion, _int_Usuario_Contraseña, "");
						MessageBox(hInicioSesion, "Ha Ingresado Correctamente!!", "Bienvenido!", MB_ICONINFORMATION);
						ShowWindow(hInicioSesion, SW_HIDE);
						ShowWindow(hVentanaPrincipal, SW_SHOW);
						err = false;
						break;
					}
					PtrAuxiliarUsuario = PtrAuxiliarUsuario->Ptr_Usuario_siguiente;
				} while (PtrAuxiliarUsuario != NULL);
				if (err){
					MessageBox(hVentanaPrincipal, "No se encontró ese Usuario y/o Contraseña!", "ERROR", MB_ICONERROR);
				}
			}
			else {
				MessageBox(hVentanaPrincipal, "Verifique los datos ingresados!", "ERROR", MB_ICONERROR);
			}

		}

	}

	void GuardarUsuariosTxt(HWND hwnd) {

		if (PtrOrigenUsuario != NULL) {
			ofstream OfGuardar("CapturaUsuario.txt");
			if (id == 1) {
				OfGuardar << PtrOrigenUsuario->String_Usuario_Usuario << "\n";
				OfGuardar << PtrOrigenUsuario->String_Usuario_Contraseña << "\n";
				OfGuardar << PtrOrigenUsuario->String_Usuario_Nombre << "\n";
				OfGuardar << PtrOrigenUsuario->String_Usuario_ApellidoPaterno << "\n";
				OfGuardar << PtrOrigenUsuario->String_Usuario_ApellidoMaterno << "\n";
				OfGuardar << PtrOrigenUsuario->id << "\n";
			}
			else {
				PtrAuxiliarUsuario = PtrOrigenUsuario;
				while (PtrAuxiliarUsuario != NULL) {
					OfGuardar << PtrAuxiliarUsuario->String_Usuario_Usuario << "\n";
					OfGuardar << PtrAuxiliarUsuario->String_Usuario_Contraseña << "\n";
					OfGuardar << PtrAuxiliarUsuario->String_Usuario_Nombre << "\n";
					OfGuardar << PtrAuxiliarUsuario->String_Usuario_ApellidoPaterno << "\n";
					OfGuardar << PtrAuxiliarUsuario->String_Usuario_ApellidoMaterno << "\n";
					OfGuardar << PtrAuxiliarUsuario->id << "\n";
					PtrAuxiliarUsuario = PtrAuxiliarUsuario->Ptr_Usuario_siguiente;
				}
			}
		OfGuardar.close();
		}
	}

	void CargarUsuariosTxt(HWND hwnd) {

			ifstream IfCargar("CapturaUsuario.txt", ios::app);
			while (!IfCargar.eof()) {
				IfCargar >> String_Usuario_Usuario;
				IfCargar >> String_Usuario_Contraseña;
				IfCargar >> String_Usuario_Nombre;
				IfCargar >> String_Usuario_ApellidoPaterno;
				IfCargar >> String_Usuario_ApellidoMaterno;
				IfCargar >> id;
				if (String_Usuario_ApellidoMaterno == "") {
					break;
				}
				else {
					GuardarUsuario();
					String_Usuario_Usuario = "";
					String_Usuario_Contraseña = "";
					String_Usuario_Nombre = "";
					String_Usuario_ApellidoPaterno = "";
					String_Usuario_ApellidoMaterno = "";
				}
			}
			IfCargar.close();
	}

	bool BuscarUsuarioRepetido(HWND hwnd, string _String_Usuario_Usuario) {

		if (PtrOrigenUsuario!=NULL){
			PtrAuxiliarUsuario = PtrOrigenUsuario;
			do{
				if (PtrAuxiliarUsuario->String_Usuario_Usuario == _String_Usuario_Usuario){
					MessageBox(hwnd,"Ya hay un Usuario registrado con ese Nombre! Intenta otro diferente.","ERROR",MB_ICONEXCLAMATION);
					return false;
				}
				else{
					PtrAuxiliarUsuario = PtrAuxiliarUsuario->Ptr_Usuario_siguiente;
				}
			} while (PtrAuxiliarUsuario!=NULL);
			return true;
		}
		else{
			return true;
		}
	}

}*PtrOrigenUsuario=NULL, * PtrAuxiliarUsuario = NULL;
#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string.h>
using namespace std;

class Persona {

public:
	// 16 Variables
	string String_Persona_ApellidoPaterno; 
	string String_Persona_ApellidoMaterno;
	string String_Persona_Nombre;
	string String_Persona_CURP;
	string String_Persona_RFC;
	string String_Persona_FechaNacimiento;
	string String_Persona_Calle;
	string String_Persona_Colonia;
	string String_Persona_Municipio;
	string String_Persona_Estado;
	string String_Persona_EstadoCivil;
	string String_Persona_Telefono;
	string String_Persona_Sexo;
	string String_Persona_GrupoOcupacional;
	string String_Persona_PerfilRiesgo;
	string String_Persona_PathDocumentoIdentidad;
	int id = 0;
	Persona* Ptr_Persona_anterior = NULL;
	Persona* Ptr_Persona_siguiente = NULL;

	//Funcciones
	void PasarInformacionPersona(HWND hwnd, int _int_Persona_ApellidoPaterno,
		int _int_Persona_ApellidoMaterno,
		int _int_Persona_Nombre,
		int _int_Persona_CURP,
		int _int_Persona_RFC,
		int _int_Persona_FechaNacimiento,
		int _int_Persona_Calle,
		int _int_Persona_Colonia,
		int _int_Persona_Municipio,
		int _int_Persona_Estado,
		int _int_Persona_EstadoCivil,
		int _int_Persona_Telefono,
		int _int_Persona_Sexo,
		int _int_Persona_GrupoOcupacional,
		int _int_Persona_PerfilRiesgo,
		int _int_Persona_PathDocumentoIdentidad) {

		char DlgText[100] = "";
		HWND Hdlgitem;
		int Sizedlgitem;


		Hdlgitem = GetDlgItem(hwnd, _int_Persona_ApellidoPaterno);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_ApellidoPaterno = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Persona_ApellidoMaterno);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_ApellidoMaterno = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Persona_Nombre);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_Nombre = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Persona_CURP);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_CURP = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Persona_RFC);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_RFC = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Persona_FechaNacimiento);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_FechaNacimiento = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Persona_Calle);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_Calle = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Persona_Colonia);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_Colonia = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Persona_Municipio);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_Municipio = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Persona_Estado);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_Estado = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Persona_EstadoCivil);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_EstadoCivil = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Persona_Telefono);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_Telefono = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Persona_Sexo);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_Sexo = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Persona_GrupoOcupacional);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_GrupoOcupacional = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Persona_PerfilRiesgo);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_PerfilRiesgo = DlgText;

		Hdlgitem = GetDlgItem(hwnd, _int_Persona_PathDocumentoIdentidad);
		Sizedlgitem = GetWindowTextLength(Hdlgitem);
		GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
		String_Persona_PathDocumentoIdentidad = DlgText;


		GuardarPersona();
	}

	void GuardarPersona() {

		if (PtrOrigenPersona == NULL) {
			PtrOrigenPersona = new Persona;
			PtrOrigenPersona->id++;
			PtrOrigenPersona->String_Persona_ApellidoPaterno = String_Persona_ApellidoPaterno;
			PtrOrigenPersona->String_Persona_ApellidoMaterno = String_Persona_ApellidoMaterno;
			PtrOrigenPersona->String_Persona_Nombre = String_Persona_Nombre;
			PtrOrigenPersona->String_Persona_CURP = String_Persona_CURP;
			PtrOrigenPersona->String_Persona_RFC = String_Persona_RFC;
			PtrOrigenPersona->String_Persona_FechaNacimiento = String_Persona_FechaNacimiento;
			PtrOrigenPersona->String_Persona_Calle = String_Persona_Calle;
			PtrOrigenPersona->String_Persona_Colonia = String_Persona_Colonia;
			PtrOrigenPersona->String_Persona_Municipio = String_Persona_Municipio;
			PtrOrigenPersona->String_Persona_Estado = String_Persona_Estado;
			PtrOrigenPersona->String_Persona_EstadoCivil = String_Persona_EstadoCivil;
			PtrOrigenPersona->String_Persona_Telefono = String_Persona_Telefono;
			PtrOrigenPersona->String_Persona_Sexo = String_Persona_Sexo;
			PtrOrigenPersona->String_Persona_GrupoOcupacional = String_Persona_GrupoOcupacional;
			PtrOrigenPersona->String_Persona_PerfilRiesgo = String_Persona_PerfilRiesgo;
			PtrOrigenPersona->String_Persona_PathDocumentoIdentidad = String_Persona_PathDocumentoIdentidad;
			PtrOrigenPersona->Ptr_Persona_siguiente = NULL;
			PtrOrigenPersona->Ptr_Persona_anterior = NULL;
		}
		else {
			PtrAuxiliarPersona = PtrOrigenPersona;
			while (PtrAuxiliarPersona->Ptr_Persona_siguiente != NULL) {
				PtrAuxiliarPersona = PtrAuxiliarPersona->Ptr_Persona_siguiente;
			}
			PtrAuxiliarPersona->Ptr_Persona_siguiente = new Persona;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->id = PtrAuxiliarPersona->id + 1;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_ApellidoPaterno = String_Persona_ApellidoPaterno;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_ApellidoMaterno = String_Persona_ApellidoMaterno;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_Nombre = String_Persona_Nombre;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_CURP = String_Persona_CURP;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_RFC = String_Persona_RFC;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_FechaNacimiento = String_Persona_FechaNacimiento;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_Calle = String_Persona_Calle;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_Colonia = String_Persona_Colonia;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_Municipio = String_Persona_Municipio;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_Estado = String_Persona_Estado;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_EstadoCivil = String_Persona_EstadoCivil;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_Telefono = String_Persona_Telefono;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_Sexo = String_Persona_Sexo;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_GrupoOcupacional = String_Persona_GrupoOcupacional;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_PerfilRiesgo = String_Persona_PerfilRiesgo;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->String_Persona_PathDocumentoIdentidad = String_Persona_PathDocumentoIdentidad;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->Ptr_Persona_siguiente = NULL;
			PtrAuxiliarPersona->Ptr_Persona_siguiente->Ptr_Persona_anterior = PtrAuxiliarPersona;
		}
		PtrAuxiliarPersona = PtrOrigenPersona;
		return;
	}

}*PtrOrigenPersona = NULL, * PtrAuxiliarPersona = NULL;
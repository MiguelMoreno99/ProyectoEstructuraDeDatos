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
	void PasarInformacion(HWND hwnd, int _int_Persona_ApellidoPaterno,
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

		if (PtrOrigen == NULL) {
			PtrOrigen = new Persona;
			PtrOrigen->id++;
			PtrOrigen->String_Persona_ApellidoPaterno = String_Persona_ApellidoPaterno;
			PtrOrigen->String_Persona_ApellidoMaterno = String_Persona_ApellidoMaterno;
			PtrOrigen->String_Persona_Nombre = String_Persona_Nombre;
			PtrOrigen->String_Persona_CURP = String_Persona_CURP;
			PtrOrigen->String_Persona_RFC = String_Persona_RFC;
			PtrOrigen->String_Persona_FechaNacimiento = String_Persona_FechaNacimiento;
			PtrOrigen->String_Persona_Calle = String_Persona_Calle;
			PtrOrigen->String_Persona_Colonia = String_Persona_Colonia;
			PtrOrigen->String_Persona_Municipio = String_Persona_Municipio;
			PtrOrigen->String_Persona_Estado = String_Persona_Estado;
			PtrOrigen->String_Persona_EstadoCivil = String_Persona_EstadoCivil;
			PtrOrigen->String_Persona_Telefono = String_Persona_Telefono;
			PtrOrigen->String_Persona_Sexo = String_Persona_Sexo;
			PtrOrigen->String_Persona_GrupoOcupacional = String_Persona_GrupoOcupacional;
			PtrOrigen->String_Persona_PerfilRiesgo = String_Persona_PerfilRiesgo;
			PtrOrigen->String_Persona_PathDocumentoIdentidad = String_Persona_PathDocumentoIdentidad;
			PtrOrigen->Ptr_Persona_siguiente = NULL;
			PtrOrigen->Ptr_Persona_anterior = NULL;
		}
		else {
			PtrAuxiliar = PtrOrigen;
			while (PtrAuxiliar->Ptr_Persona_siguiente != NULL) {
				PtrAuxiliar = PtrAuxiliar->Ptr_Persona_siguiente;
			}
			PtrAuxiliar->Ptr_Persona_siguiente = new Persona;
			PtrAuxiliar->Ptr_Persona_siguiente->id = PtrAuxiliar->id + 1;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_ApellidoPaterno = String_Persona_ApellidoPaterno;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_ApellidoMaterno = String_Persona_ApellidoMaterno;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_Nombre = String_Persona_Nombre;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_CURP = String_Persona_CURP;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_RFC = String_Persona_RFC;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_FechaNacimiento = String_Persona_FechaNacimiento;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_Calle = String_Persona_Calle;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_Colonia = String_Persona_Colonia;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_Municipio = String_Persona_Municipio;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_Estado = String_Persona_Estado;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_EstadoCivil = String_Persona_EstadoCivil;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_Telefono = String_Persona_Telefono;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_Sexo = String_Persona_Sexo;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_GrupoOcupacional = String_Persona_GrupoOcupacional;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_PerfilRiesgo = String_Persona_PerfilRiesgo;
			PtrAuxiliar->Ptr_Persona_siguiente->String_Persona_PathDocumentoIdentidad = String_Persona_PathDocumentoIdentidad;
			PtrAuxiliar->Ptr_Persona_siguiente->Ptr_Persona_siguiente = NULL;
			PtrAuxiliar->Ptr_Persona_siguiente->Ptr_Persona_anterior = PtrAuxiliar;
		}
		PtrAuxiliar = PtrOrigen;
		return;
	}

}*PtrOrigen, *PtrAuxiliar;
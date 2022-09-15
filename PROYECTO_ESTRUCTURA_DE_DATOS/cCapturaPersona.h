#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string.h>
using namespace std;

class Persona {

public:

	string String_Persona_ApellidoPaterno;
	string String_Persona_ApellidoMaterno;
	string String_Persona_Nombre;
	string String_Persona_CURP;
	string String_Persona_RFC;
	string String_Persona_FechaNacimiento;
	string String_Persona_Calle;
	string String_Persona_Colonia;
	string String_Persona_Ciudad;
	string String_Persona_Estado;
	string String_Persona_EstadoCivil;
	string String_Persona_Telefono;
	string String_Persona_Sexo;
	string String_Persona_GrupoOcupacional;
	string String_Persona_PerfilRiesgo;
	string String_Persona_PathDocumentoIdentidad;

		void GuardarPersona(string _String_Persona_ApellidoPaterno,
		string _String_Persona_ApellidoMaterno,
		string _String_Persona_Nombre,
		string _String_Persona_CURP,
		string _String_Persona_RFC,
		string _String_Persona_FechaNacimiento,
		string _String_Persona_Calle,
		string _String_Persona_Colonia,
		string _String_Persona_Ciudad,
		string _String_Persona_Estado,
		string _String_Persona_EstadoCivil,
		string _String_Persona_Telefono,
		string _String_Persona_Sexo,
		string _String_Persona_GrupoOcupacional,
		string _String_Persona_PerfilRiesgo,
		string _String_Persona_PathDocumentoIdentidad);

		void GuardarPersona() {}

private:
	int id = 1;
	Persona* Ptr_Persona_anterior = NULL;
	Persona* Ptr_Persona_siguiente = NULL;

}*PtrOrigen, *PtrAuxiliar;

void  Persona::GuardarPersona(string _String_Persona_ApellidoPaterno,
	string _String_Persona_ApellidoMaterno,
	string _String_Persona_Nombre,
	string _String_Persona_CURP,
	string _String_Persona_RFC,
	string _String_Persona_FechaNacimiento,
	string _String_Persona_Calle,
	string _String_Persona_Colonia,
	string _String_Persona_Ciudad,
	string _String_Persona_Estado,
	string _String_Persona_EstadoCivil,
	string _String_Persona_Telefono,
	string _String_Persona_Sexo,
	string _String_Persona_GrupoOcupacional,
	string _String_Persona_PerfilRiesgo,
	string _String_Persona_PathDocumentoIdentidad)
{
	 if (PtrOrigen == NULL) {
		 PtrOrigen = new Persona;
		 PtrOrigen->id++;
		 PtrOrigen->Ptr_Persona_siguiente = NULL;
		 PtrOrigen->Ptr_Persona_anterior = NULL;
	 }
	 else {
		 while (PtrAuxiliar->Ptr_Persona_siguiente != NULL) {
			 PtrAuxiliar = PtrAuxiliar->Ptr_Persona_siguiente;
		 }
		 PtrAuxiliar->Ptr_Persona_siguiente = new Persona;
		 PtrAuxiliar->Ptr_Persona_siguiente->Ptr_Persona_siguiente = NULL;
		 PtrAuxiliar->Ptr_Persona_siguiente->Ptr_Persona_anterior = PtrAuxiliar;
		 PtrAuxiliar->Ptr_Persona_siguiente->id = PtrAuxiliar->Ptr_Persona_siguiente->Ptr_Persona_anterior->id + 1;
	 }
	 PtrAuxiliar = PtrOrigen;
	 return;
}

 


#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string.h>
#include "cValidadores.h"
#include "cCapturaVacuna.h"
#include <fstream>
using namespace std;

class Carnet {

private:
	// 7 Variables Privadas
	string String_Carnet_CURP;
	string String_Carnet_IdVacuna;
	string String_Carnet_Lote;
	string String_Carnet_FechaDosis;
	string String_Carnet_NoDosis;
	string String_Carnet_CentroVacunacion;
	string String_Carnet_FechaProximaDosis;
	int id;
	bool err = false;
	bool borrado = false;

public:
	// 2 Variables Publicas
	Carnet* Ptr_Carnet_anterior = NULL;
	Carnet* Ptr_Carnet_siguiente = NULL;

	//Funciones Publicas
	void CapturarInformacionCarnet(HWND hwnd, int _int_Carnet_CURP, int _int_Carnet_IdVacuna, int _int_Carnet_Lote, int _int_Carnet_FechaDosis, int _int_Carnet_NoDosis, int _int_Carnet_CentroVacunacion, int _int_Carnet_FechaProximaDosis ,int _int_Persona_ApellidoPaterno, int _int_Persona_ApellidoMaterno, int _int_Persona_Nombre, int _int_Persona_CURP, int _int_Persona_RFC, int _int_Persona_FechaNacimiento, int _int_Persona_Calle, int _int_Persona_Colonia, int _int_Persona_Municipio, int _int_Persona_Estado, int _int_Persona_EstadoCivil, int _int_Persona_Telefono, int _int_Persona_Sexo, int _int_Persona_GrupoOcupacional, int _int_Persona_PerfilRiesgo, int _int_Vacuna_Tipo, int _int_Vacuna_Marca, int _int_Vacuna_NoDosis, int _int_Vacuna_Precio, int _int_Vacuna_Desc) {

		err = false;
		err = ValidacionLetraYNumeroSinEspacios(hwnd, _int_Carnet_CURP, err);
		err = ValidacionMayorACero(hwnd, _int_Carnet_IdVacuna, err);
		err = ValidacionLetraYNumeroSinEspacios(hwnd, _int_Carnet_Lote, err);
		err = ValidacionFechaMayorIgualAActual(hwnd, _int_Carnet_FechaDosis, err);
		err = ValidacionMayorACero(hwnd, _int_Carnet_NoDosis, err);
		err = ValidacionLetraSinEspacios(hwnd, _int_Carnet_CentroVacunacion, err);
		err = ValidacionFechaMayorACaptura(hwnd, _int_Carnet_FechaDosis, _int_Carnet_FechaProximaDosis, err);

		if (!err) {
			String_Carnet_CURP = ValidacionCapturaTexto(hwnd, _int_Carnet_CURP);
			String_Carnet_IdVacuna = ValidacionCapturaTexto(hwnd, _int_Carnet_IdVacuna);
			String_Carnet_Lote = ValidacionCapturaTexto(hwnd, _int_Carnet_Lote);
			String_Carnet_FechaDosis = ValidacionCapturaTexto(hwnd, _int_Carnet_FechaDosis);
			String_Carnet_NoDosis = ValidacionCapturaTexto(hwnd, _int_Carnet_NoDosis);
			String_Carnet_CentroVacunacion = ValidacionCapturaTexto(hwnd, _int_Carnet_CentroVacunacion);
			String_Carnet_FechaProximaDosis = ValidacionCapturaTexto(hwnd, _int_Carnet_FechaProximaDosis);
			SetDlgItemText(hwnd, _int_Carnet_CURP, "");
			SetDlgItemText(hwnd, _int_Carnet_IdVacuna, "");
			SetDlgItemText(hwnd, _int_Carnet_Lote, "");
			SetDlgItemText(hwnd, _int_Carnet_FechaDosis, "");
			SetDlgItemText(hwnd, _int_Carnet_NoDosis, "");
			SetDlgItemText(hwnd, _int_Carnet_CentroVacunacion, "");
			SetDlgItemText(hwnd, _int_Carnet_FechaProximaDosis, "");
			SetDlgItemText(hwnd, _int_Persona_ApellidoPaterno, "");
			SetDlgItemText(hwnd, _int_Persona_ApellidoMaterno, "");
			SetDlgItemText(hwnd, _int_Persona_Nombre, "");
			SetDlgItemText(hwnd, _int_Persona_CURP, "");
			SetDlgItemText(hwnd, _int_Persona_RFC, "");
			SetDlgItemText(hwnd, _int_Persona_FechaNacimiento, "");
			SetDlgItemText(hwnd, _int_Persona_Calle, "");
			SetDlgItemText(hwnd, _int_Persona_Colonia, "");
			SetDlgItemText(hwnd, _int_Persona_Municipio, "");
			SetDlgItemText(hwnd, _int_Persona_Estado, "");
			SetDlgItemText(hwnd, _int_Persona_EstadoCivil, "");
			SetDlgItemText(hwnd, _int_Persona_Telefono, "");
			SetDlgItemText(hwnd, _int_Persona_Sexo, "");
			SetDlgItemText(hwnd, _int_Persona_GrupoOcupacional, "");
			SetDlgItemText(hwnd, _int_Persona_PerfilRiesgo, "");
			SetDlgItemText(hwnd, _int_Vacuna_Tipo, "");
			SetDlgItemText(hwnd, _int_Vacuna_Marca, "");
			SetDlgItemText(hwnd, _int_Vacuna_NoDosis, "");
			SetDlgItemText(hwnd, _int_Vacuna_Precio, "");
			SetDlgItemText(hwnd, _int_Vacuna_Desc, "");
			CargarInfoComboBoxCarnet(hwnd, _int_Carnet_NoDosis, _int_Carnet_CentroVacunacion);
			Vacuna1.CargarInfoComboBoxIds(hwnd, _int_Carnet_IdVacuna);
			Persona1.CargarInfoComboBoxCURP(hwnd, _int_Carnet_CURP);
			GuardarCarnet();
			MessageBox(hwnd, "Se ha registrado el Carnet Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
		}
		else {
			MessageBox(hwnd, "Verifique que los datos ingresados sean válidos!", "ERROR", MB_ICONERROR);
		}
	}

	void EditarInformacionCarnet(HWND hwnd, int _int_Carnet_IdEditar, int _int_Carnet_IdVacuna, int _int_Carnet_CURP, int _int_Carnet_Lote, int _int_Carnet_FechaDosis, int _int_Carnet_NoDosis, int _int_Carnet_CentroVacunacion, int _int_Carnet_FechaProximaDosis) {

		err = false;
		err = ValidacionMayorACero(hwnd, _int_Carnet_IdEditar, err);
		err = ValidacionMayorACero(hwnd, _int_Carnet_IdVacuna, err);
		err = ValidacionLetraYNumeroSinEspacios(hwnd, _int_Carnet_Lote, err);
		err = ValidacionFechaMayorIgualAActual(hwnd, _int_Carnet_FechaDosis, err);
		err = ValidacionMayorACero(hwnd, _int_Carnet_NoDosis, err);
		err = ValidacionLetraSinEspacios(hwnd, _int_Carnet_CentroVacunacion, err);
		err = ValidacionFechaMayorACaptura(hwnd, _int_Carnet_FechaDosis, _int_Carnet_FechaProximaDosis, err);

		if (!err) {
			id = atoi(ValidacionANumero(hwnd, _int_Carnet_IdEditar).c_str());
			String_Carnet_IdVacuna = ValidacionCapturaTexto(hwnd, _int_Carnet_IdVacuna);
			String_Carnet_Lote = ValidacionCapturaTexto(hwnd, _int_Carnet_Lote);
			String_Carnet_FechaDosis = ValidacionCapturaTexto(hwnd, _int_Carnet_FechaDosis);
			String_Carnet_NoDosis = ValidacionCapturaTexto(hwnd, _int_Carnet_NoDosis);
			String_Carnet_CentroVacunacion = ValidacionCapturaTexto(hwnd, _int_Carnet_CentroVacunacion);
			String_Carnet_FechaProximaDosis = ValidacionCapturaTexto(hwnd, _int_Carnet_FechaProximaDosis);
			SetDlgItemText(hwnd, _int_Carnet_IdEditar, "");
			SetDlgItemText(hwnd, _int_Carnet_IdVacuna, "");
			SetDlgItemText(hwnd, _int_Carnet_CURP, "");
			SetDlgItemText(hwnd, _int_Carnet_Lote, "");
			SetDlgItemText(hwnd, _int_Carnet_FechaDosis, "");
			SetDlgItemText(hwnd, _int_Carnet_NoDosis, "");
			SetDlgItemText(hwnd, _int_Carnet_CentroVacunacion, "");
			SetDlgItemText(hwnd, _int_Carnet_FechaProximaDosis, "");
			CargarInfoComboBoxCarnet(hwnd, _int_Carnet_NoDosis, _int_Carnet_CentroVacunacion);
			CargarInfoComboBoxIds(hwnd, _int_Carnet_IdEditar);
			Vacuna1.CargarInfoComboBoxIds(hwnd, _int_Carnet_IdVacuna);
			EditarCarnet(id);
			MessageBox(hwnd, "Se ha Editado el Carnet Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
		}
		else {
			MessageBox(hwnd, "Verifique que los datos ingresados sean válidos!", "ERROR", MB_ICONERROR);
		}
	}

	void BorrarInformacionCarnet(HWND hwnd, int _int_Carnet_IdBorrar, int _int_Carnet_IdVacuna, int _int_Carnet_CURP, int _int_Carnet_Lote, int _int_Carnet_FechaDosis, int _int_Carnet_NoDosis, int _int_Carnet_CentroVacunacion, int _int_Carnet_FechaProximaDosis) {

		err = false;
		err = ValidacionMayorACero(hwnd, _int_Carnet_IdBorrar, err);

		if (!err) {
			id = atoi(ValidacionANumero(hwnd, _int_Carnet_IdBorrar).c_str());
			SetDlgItemText(hwnd, _int_Carnet_IdBorrar, "");
			SetDlgItemText(hwnd, _int_Carnet_IdVacuna, "");
			SetDlgItemText(hwnd, _int_Carnet_CURP, "");
			SetDlgItemText(hwnd, _int_Carnet_Lote, "");
			SetDlgItemText(hwnd, _int_Carnet_FechaDosis, "");
			SetDlgItemText(hwnd, _int_Carnet_NoDosis, "");
			SetDlgItemText(hwnd, _int_Carnet_CentroVacunacion, "");
			SetDlgItemText(hwnd, _int_Carnet_FechaProximaDosis, "");
			CargarInfoComboBoxCarnet(hwnd, _int_Carnet_NoDosis, _int_Carnet_CentroVacunacion);
			BorrarCarnet(id);
			CargarInfoComboBoxIds(hwnd, _int_Carnet_IdBorrar);
			Vacuna1.CargarInfoComboBoxIds(hwnd, _int_Carnet_IdVacuna);
			MessageBox(hwnd, "Se ha Borrado el Carnet Correctamente!!", "Felicidades!", MB_ICONINFORMATION);
		}
		else {
			MessageBox(hwnd, "Verifique que los datos ingresados sean válidos!", "ERROR", MB_ICONERROR);
		}
	}

	void CargarInfoComboBoxCarnet(HWND hwnd,int _CB_CARNET_DOSIS,int _CB_CARNET_CENTROVACUNACION) {

		HWND hComboBox;
		hComboBox = GetDlgItem(hwnd, _CB_CARNET_DOSIS);
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
		hComboBox = GetDlgItem(hwnd, _CB_CARNET_CENTROVACUNACION);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"NORTE");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"CENTRO");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"SUR");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"ESTE");
		SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)"OESTE");
	}

	void CargarInfoComboBoxIds(HWND hwnd, int _CB_CARNET_ID) {

		HWND hComboBox;
		hComboBox = GetDlgItem(hwnd, _CB_CARNET_ID);
		SendMessage(hComboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
		if (PtrOrigenCarnet != NULL) {
			PtrAuxiliarCarnet = PtrOrigenCarnet;
			while (PtrAuxiliarCarnet != NULL) {
				if (!(PtrAuxiliarCarnet->borrado)){
					char Cid[10] = "";
					_itoa_s(PtrAuxiliarCarnet->id, Cid, 10);
					string id = Cid;
					if (id != "") {
						SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)id.c_str());
					}
				}
				PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
			}
		}
		else {
			MessageBox(hwnd, "PRIMERO DEBE DE AGREGAR AL MENOS UN CARNET!", "PRECAUCIÓN", MB_ICONWARNING);
		}
	}

	void CargarInformacionCarnetConID(HWND hwnd, int _int_Carnet_Id, int _int_Carnet_ApellidoPaterno, int _int_Carnet_ApellidoMaterno, int _int_Carnet_Nombre, int _int_Carnet_IdVacuna, int _int_Carnet_CURP, int _int_Carnet_Lote, int _int_Carnet_FechaDosis, int _int_Carnet_NoDosis, int _int_Carnet_CentroVacunacion, int _int_Carnet_FechaProximaDosis) {
		OrdenarElementosPorId();
		string StringId = ValidacionCapturaTexto(hwnd, _int_Carnet_Id);
		if (StringId != "") {

			int id = atoi(StringId.c_str());
			HWND hComboBox;
			SetDlgItemText(hwnd, _int_Carnet_CURP, PasarDatosdelIdCarnet(id, 1).c_str());

			hComboBox = GetDlgItem(hwnd, _int_Carnet_IdVacuna);
			SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelIdCarnet(id, 2).c_str());
			SetDlgItemText(hwnd, _int_Carnet_IdVacuna, PasarDatosdelIdCarnet(id, 2).c_str());
			if (ValidacionCapturaTexto(hwnd, _int_Carnet_IdVacuna)=="") {
				SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)PasarDatosdelIdCarnet(id, 2).c_str());
				SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelIdCarnet(id, 2).c_str());
			}

			hComboBox = GetDlgItem(hwnd, _int_Carnet_Lote);
			SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelIdCarnet(id, 3).c_str());
			SetDlgItemText(hwnd, _int_Carnet_Lote, PasarDatosdelIdCarnet(id, 3).c_str());

			SetDlgItemText(hwnd, _int_Carnet_FechaDosis, PasarDatosdelIdCarnet(id, 4).c_str());

			hComboBox = GetDlgItem(hwnd, _int_Carnet_NoDosis);
			SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelIdCarnet(id, 5).c_str());
			SetDlgItemText(hwnd, _int_Carnet_NoDosis, PasarDatosdelIdCarnet(id, 5).c_str());

			hComboBox = GetDlgItem(hwnd, _int_Carnet_CentroVacunacion);
			SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelIdCarnet(id, 6).c_str());
			SetDlgItemText(hwnd, _int_Carnet_CentroVacunacion, PasarDatosdelIdCarnet(id, 6).c_str());

			SetDlgItemText(hwnd, _int_Carnet_FechaProximaDosis, PasarDatosdelIdCarnet(id, 7).c_str());
			SetDlgItemText(hwnd, _int_Carnet_ApellidoPaterno, "");
			SetDlgItemText(hwnd, _int_Carnet_ApellidoMaterno, "");
			SetDlgItemText(hwnd, _int_Carnet_Nombre, "");
		}
		else {
			MessageBox(hwnd, "Seleccione una Id de Carnet primero!", "Advertencia", MB_ICONEXCLAMATION);
		}

	}

	void CargarInformacionCarnetConNombre(HWND hwnd, int _int_Carnet_Id, int _int_Carnet_ApellidoPaterno, int _int_Carnet_ApellidoMaterno, int _int_Carnet_Nombre , int _int_Carnet_IdVacuna, int _int_Carnet_CURP, int _int_Carnet_Lote, int _int_Carnet_FechaDosis, int _int_Carnet_NoDosis, int _int_Carnet_CentroVacunacion, int _int_Carnet_FechaProximaDosis) {
		OrdenarElementosPorId();
		string StringApellidoPaterno = ValidacionCapturaTexto(hwnd, _int_Carnet_ApellidoPaterno);
		string StringApellidoMaterno = ValidacionCapturaTexto(hwnd, _int_Carnet_ApellidoMaterno);
		string StringApellidoNombre = ValidacionCapturaTexto(hwnd, _int_Carnet_Nombre);
		if (!(StringApellidoPaterno=="" || StringApellidoMaterno=="" || StringApellidoNombre=="")){
			string CURP = Persona1.PasarCURPsiIgualNombre(StringApellidoPaterno, StringApellidoMaterno, StringApellidoNombre);
			if (CURP!=""){
				string Id = PasarIdsiIgualCURP(CURP);
				if (Id != "") {
					int id = atoi(Id.c_str());
					HWND hComboBox;
					SetDlgItemText(hwnd, _int_Carnet_CURP, PasarDatosdelIdCarnet(id, 1).c_str());

					hComboBox = GetDlgItem(hwnd, _int_Carnet_IdVacuna);
					SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelIdCarnet(id, 2).c_str());
					SetDlgItemText(hwnd, _int_Carnet_IdVacuna, PasarDatosdelIdCarnet(id, 2).c_str());
					if (ValidacionCapturaTexto(hwnd, _int_Carnet_IdVacuna) == "") {
						SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)PasarDatosdelIdCarnet(id, 2).c_str());
						SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelIdCarnet(id, 2).c_str());
					}

					hComboBox = GetDlgItem(hwnd, _int_Carnet_Lote);
					SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelIdCarnet(id, 3).c_str());
					SetDlgItemText(hwnd, _int_Carnet_Lote, PasarDatosdelIdCarnet(id, 3).c_str());

					SetDlgItemText(hwnd, _int_Carnet_FechaDosis, PasarDatosdelIdCarnet(id, 4).c_str());

					hComboBox = GetDlgItem(hwnd, _int_Carnet_NoDosis);
					SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelIdCarnet(id, 5).c_str());
					SetDlgItemText(hwnd, _int_Carnet_NoDosis, PasarDatosdelIdCarnet(id, 5).c_str());

					hComboBox = GetDlgItem(hwnd, _int_Carnet_CentroVacunacion);
					SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelIdCarnet(id, 6).c_str());
					SetDlgItemText(hwnd, _int_Carnet_CentroVacunacion, PasarDatosdelIdCarnet(id, 6).c_str());

					SetDlgItemText(hwnd, _int_Carnet_FechaProximaDosis, PasarDatosdelIdCarnet(id, 7).c_str());

					hComboBox = GetDlgItem(hwnd, _int_Carnet_Id);
					SendMessage(hComboBox, CB_SELECTSTRING, NULL, (LPARAM)PasarDatosdelIdCarnet(id, 8).c_str());
					SetDlgItemText(hwnd, _int_Carnet_Id, PasarDatosdelIdCarnet(id, 8).c_str());
				}
				else {
					MessageBox(hwnd, "Ese Nombre No tiene Carnet Registrado!", "Advertencia", MB_ICONEXCLAMATION);
				}
			}
			else {
				MessageBox(hwnd, "No se encontró ningun Carnet con ese nombre!", "Advertencia", MB_ICONEXCLAMATION);
			}
		}
		else {
			MessageBox(hwnd, "Ingrese Apellido Paterno, Materno y Nombre primero!", "Advertencia", MB_ICONEXCLAMATION);
		}
	}

	void CargarInformacionListBoxPorCURP(HWND hwnd, int _LB_REPORTE_CARNET_LISTA) {
		OrdenarElementosAZ();
		PtrAuxiliarCarnet = PtrOrigenCarnet;
		HWND hListBox;
		hListBox = GetDlgItem(hwnd, _LB_REPORTE_CARNET_LISTA);
		SendMessage(hListBox, LB_RESETCONTENT, NULL, NULL);
		while (PtrAuxiliarCarnet!=NULL){
			char Cid[10] = "";
			_itoa(PtrAuxiliarCarnet->id, Cid, 10);
			string Sid = Cid;
			string DatosCarnet = PtrAuxiliarCarnet->String_Carnet_CURP + " // " + Sid + " // " + PtrAuxiliarCarnet->String_Carnet_IdVacuna + " // "  + PtrAuxiliarCarnet->String_Carnet_Lote + " // "  +
		    PtrAuxiliarCarnet->String_Carnet_FechaDosis + " // " + PtrAuxiliarCarnet->String_Carnet_NoDosis + " // " + PtrAuxiliarCarnet->String_Carnet_CentroVacunacion + " // " + 
			PtrAuxiliarCarnet->String_Carnet_FechaProximaDosis;
			SendMessage(hListBox, LB_ADDSTRING, NULL, (LPARAM)DatosCarnet.c_str());
			PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
		}
	}

	void CargarInformacionListBoxPorID(HWND hwnd, int _LB_REPORTE_CARNET_LISTA) {
		OrdenarElementosPorId();
		PtrAuxiliarCarnet = PtrOrigenCarnet;
		HWND hListBox;
		hListBox = GetDlgItem(hwnd, _LB_REPORTE_CARNET_LISTA);
		SendMessage(hListBox, LB_RESETCONTENT, NULL, NULL);
		while (PtrAuxiliarCarnet != NULL) {
			char Cid[10] = "";
			_itoa(PtrAuxiliarCarnet->id, Cid, 10);
			string Sid = Cid;
			string DatosCarnet = Sid + " // " + PtrAuxiliarCarnet->String_Carnet_CURP + " // " + PtrAuxiliarCarnet->String_Carnet_IdVacuna + " // " + PtrAuxiliarCarnet->String_Carnet_Lote + " // " +
			PtrAuxiliarCarnet->String_Carnet_FechaDosis + " // " + PtrAuxiliarCarnet->String_Carnet_NoDosis + " // " + PtrAuxiliarCarnet->String_Carnet_CentroVacunacion + " // " +
			PtrAuxiliarCarnet->String_Carnet_FechaProximaDosis;
			SendMessage(hListBox, LB_ADDSTRING, NULL, (LPARAM)DatosCarnet.c_str());
			PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
		}
	}

	void GuardarReportePersonasVacunadasTxtPorId(HWND hwnd) {

		if (PtrOrigenCarnet != NULL) {
			ofstream OfGuardar("ReportePersonasVacunadasPorId.txt");
			if (PtrOrigenCarnet->Ptr_Carnet_siguiente == NULL) {
				OfGuardar << PtrOrigenCarnet->String_Carnet_CURP << "\n";
				OfGuardar << PtrOrigenCarnet->String_Carnet_IdVacuna << "\n";
				OfGuardar << PtrOrigenCarnet->String_Carnet_Lote << "\n";
				OfGuardar << PtrOrigenCarnet->String_Carnet_FechaDosis << "\n";
				OfGuardar << PtrOrigenCarnet->String_Carnet_NoDosis << "\n";
				OfGuardar << PtrOrigenCarnet->String_Carnet_CentroVacunacion << "\n";
				OfGuardar << PtrOrigenCarnet->String_Carnet_FechaProximaDosis << "\n";
				OfGuardar << PtrOrigenCarnet->id << "\n";
				OfGuardar << PtrOrigenCarnet->borrado << "\n";
			}
			else {
				PtrAuxiliarCarnet = PtrOrigenCarnet;
				while (PtrAuxiliarCarnet != NULL) {
					OfGuardar << PtrAuxiliarCarnet->String_Carnet_CURP << "\n";
					OfGuardar << PtrAuxiliarCarnet->String_Carnet_IdVacuna << "\n";
					OfGuardar << PtrAuxiliarCarnet->String_Carnet_Lote << "\n";
					OfGuardar << PtrAuxiliarCarnet->String_Carnet_FechaDosis << "\n";
					OfGuardar << PtrAuxiliarCarnet->String_Carnet_NoDosis << "\n";
					OfGuardar << PtrAuxiliarCarnet->String_Carnet_CentroVacunacion << "\n";
					OfGuardar << PtrAuxiliarCarnet->String_Carnet_FechaProximaDosis << "\n";
					OfGuardar << PtrAuxiliarCarnet->id << "\n";
					OfGuardar << PtrAuxiliarCarnet->borrado << "\n";
					PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
				}
			}
			OfGuardar.close();
		}
	}

	void GuardarReportePersonasVacunadasTxtPorNombre(HWND hwnd) {

		if (PtrOrigenCarnet != NULL) {
			ofstream OfGuardar("ReportePersonasVacunadasPorNombre.txt");
			if (PtrOrigenCarnet->Ptr_Carnet_siguiente == NULL) {
				OfGuardar << PtrOrigenCarnet->String_Carnet_CURP << "\n";
				OfGuardar << PtrOrigenCarnet->String_Carnet_IdVacuna << "\n";
				OfGuardar << PtrOrigenCarnet->String_Carnet_Lote << "\n";
				OfGuardar << PtrOrigenCarnet->String_Carnet_FechaDosis << "\n";
				OfGuardar << PtrOrigenCarnet->String_Carnet_NoDosis << "\n";
				OfGuardar << PtrOrigenCarnet->String_Carnet_CentroVacunacion << "\n";
				OfGuardar << PtrOrigenCarnet->String_Carnet_FechaProximaDosis << "\n";
				OfGuardar << PtrOrigenCarnet->id << "\n";
				OfGuardar << PtrOrigenCarnet->borrado << "\n";
			}
			else {
				PtrAuxiliarCarnet = PtrOrigenCarnet;
				while (PtrAuxiliarCarnet != NULL) {
					OfGuardar << PtrAuxiliarCarnet->String_Carnet_CURP << "\n";
					OfGuardar << PtrAuxiliarCarnet->String_Carnet_IdVacuna << "\n";
					OfGuardar << PtrAuxiliarCarnet->String_Carnet_Lote << "\n";
					OfGuardar << PtrAuxiliarCarnet->String_Carnet_FechaDosis << "\n";
					OfGuardar << PtrAuxiliarCarnet->String_Carnet_NoDosis << "\n";
					OfGuardar << PtrAuxiliarCarnet->String_Carnet_CentroVacunacion << "\n";
					OfGuardar << PtrAuxiliarCarnet->String_Carnet_FechaProximaDosis << "\n";
					OfGuardar << PtrAuxiliarCarnet->id << "\n";
					OfGuardar << PtrAuxiliarCarnet->borrado << "\n";
					PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
				}
			}
			OfGuardar.close();
		}
	}


private:
	//Funciones Privadas
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
			PtrOrigenCarnet->String_Carnet_FechaProximaDosis = String_Carnet_FechaProximaDosis;
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
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente->String_Carnet_FechaProximaDosis = String_Carnet_FechaProximaDosis;
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente->Ptr_Carnet_siguiente = NULL;
			PtrAuxiliarCarnet->Ptr_Carnet_siguiente->Ptr_Carnet_anterior = PtrAuxiliarCarnet;
		}
		PtrAuxiliarCarnet = PtrOrigenCarnet;
		return;
	}

	void EditarCarnet(int _idCarnet) {

		int id = BusquedaIdCarnet(_idCarnet);
		if (id != -1) {
			PtrAuxiliarCarnet = PtrOrigenCarnet;
			for (int i = 1; i < id; i++) {
				PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
			}
			PtrAuxiliarCarnet->String_Carnet_IdVacuna = String_Carnet_IdVacuna;
			PtrAuxiliarCarnet->String_Carnet_Lote = String_Carnet_Lote;
			PtrAuxiliarCarnet->String_Carnet_FechaDosis = String_Carnet_FechaDosis;
			PtrAuxiliarCarnet->String_Carnet_NoDosis = String_Carnet_NoDosis;
			PtrAuxiliarCarnet->String_Carnet_CentroVacunacion = String_Carnet_CentroVacunacion;
			PtrAuxiliarCarnet->String_Carnet_FechaProximaDosis = String_Carnet_FechaProximaDosis;
		}
	}

	void BorrarCarnet(int _idCarnet) {

		int id = BusquedaIdCarnet(_idCarnet);
		if (id != -1) {
			PtrAuxiliarCarnet = PtrOrigenCarnet;
			for (int i = 1; i < id; i++) {
				PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
			}
			PtrAuxiliarCarnet->borrado = true;
		}
	}

	string PasarIdsiIgualCURP(string _CURP) {

		PtrAuxiliarCarnet= PtrOrigenCarnet;
		while (PtrAuxiliarCarnet != NULL) {
			if (PtrAuxiliarCarnet->String_Carnet_CURP == _CURP) {
				char Cid[10] = "";
				_itoa(PtrAuxiliarCarnet->id, Cid, 10);
				return Cid;
			}
			PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
		}
		return "";
	}

	string PasarDatosdelIdCarnet(int _Carnet_id, int DatoSolicitado) {

		int id = BusquedaIdCarnet(_Carnet_id);
		if (id != -1) {
			PtrAuxiliarCarnet = PtrOrigenCarnet;
			for (int i = 1; i < id; i++) {
				PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
			}
			switch (DatoSolicitado) {
			case 1: {
				return PtrAuxiliarCarnet->String_Carnet_CURP;
				break;
			}
			case 2: {
				return PtrAuxiliarCarnet->String_Carnet_IdVacuna;
				break;
			}
			case 3: {
				return PtrAuxiliarCarnet->String_Carnet_Lote;
				break;
			}
			case 4: {
				return PtrAuxiliarCarnet->String_Carnet_FechaDosis;
				break;
			}
			case 5: {
				return PtrAuxiliarCarnet->String_Carnet_NoDosis;
				break;
			}
			case 6: {
				return PtrAuxiliarCarnet->String_Carnet_CentroVacunacion;
				break;
			}
			case 7: {
				return PtrAuxiliarCarnet->String_Carnet_FechaProximaDosis;
				break;
			}
			case 8: {
				char id[10] = "";
				_itoa_s(PtrAuxiliarCarnet->id, id, 10);
				return id;
			}
			default:
				return "";
				break;
			}
		}
		return "";
	}

	int BusquedaIdCarnet(int _IdCarnetABuscar) {

		if (PtrOrigenCarnet != NULL) {
			int CantidadCarnets = 0;
			PtrAuxiliarCarnet = PtrOrigenCarnet;
			while (PtrAuxiliarCarnet != NULL) {
				CantidadCarnets++;
				PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
			}
			int CarnetId = BusquedaBinaria(0, CantidadCarnets, _IdCarnetABuscar);
			if (CarnetId == -1) {
				return-1;
			}
			else {
				return CarnetId;
			}
			PtrAuxiliarCarnet = PtrOrigenCarnet;
		}
		return-1;
	}

	int BusquedaBinaria(int ValorMinimo, int ValorMaximo, int ValorBuscado) {

		PtrAuxiliarCarnet = PtrOrigenCarnet;
		if (ValorMinimo <= ValorMaximo) {
			int ValorIntermedio = (ValorMinimo + ValorMaximo) / 2;
			for (int i = 1; i < ValorIntermedio; i++) {
				PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
			}
			if ((PtrAuxiliarCarnet->id == ValorBuscado)) {
				if (!PtrAuxiliarCarnet->borrado) {
					return PtrAuxiliarCarnet->id;
				}
				return -1;
			}
			if (PtrAuxiliarCarnet->id > ValorBuscado) {
				return BusquedaBinaria(ValorMinimo, PtrAuxiliarCarnet->Ptr_Carnet_anterior->id, ValorBuscado);
			}
			if (PtrAuxiliarCarnet->id < ValorBuscado) {
				return BusquedaBinaria(PtrAuxiliarCarnet->Ptr_Carnet_siguiente->id, ValorMaximo, ValorBuscado);
			}
		}
		return -1;
	}

	void OrdenarElementosPorId() {

		if (PtrOrigenCarnet != NULL) {
			int CantidadCarnets = 0;
			PtrAuxiliarCarnet = PtrOrigenCarnet;
			while (PtrAuxiliarCarnet != NULL) {
				CantidadCarnets++;
				PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
			}
			HeapShort(CantidadCarnets);
		}
	}

	void HeapShort(int _CantidadCarnets) {
		for (int i = _CantidadCarnets-1; i > 0; i--){
			Heapify(i);
			Intercambio(IrACarnetHeapShort(0), IrACarnetHeapShort(i));
		}
	}

	void Heapify(int size) {
		int mid, node;
		for (int i = 0; i <= size; i++){
			node = i;
			mid = (node == 0) ? 0 : (int)node / 2;
			while (mid >=0 && node != 0){
				if (IrACarnetHeapShort(mid)->id < IrACarnetHeapShort(node)->id){
					Intercambio(IrACarnetHeapShort(mid), IrACarnetHeapShort(node));
				}
				node = mid;
				mid = (node == 0) ? 0 : (int)node / 2;
			}
		}
	}

	void OrdenarElementosAZ() {

		if (PtrOrigenCarnet != NULL) {
			int CantidadCarnets = 0;
			PtrAuxiliarCarnet = PtrOrigenCarnet;
			while (PtrAuxiliarCarnet != NULL) {
				CantidadCarnets++;
				PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
			}
			QuickShort(1, CantidadCarnets);
		}
	}

	void QuickShort(int LowerIndex, int UpperIndex) {
		if (LowerIndex < UpperIndex) {
			int PivotIndex = CorrectPivot(LowerIndex, UpperIndex);
			QuickShort(LowerIndex, PivotIndex - 1);
			QuickShort(PivotIndex + 1, UpperIndex);
		}
	}

	int CorrectPivot(int LowerIndex, int UpperIndex) {
		Carnet* pivot = IrACarnetQuickShort(UpperIndex);
		int i = (LowerIndex - 1);
		for (int j = LowerIndex; j <= UpperIndex - 1; j++) {
			if (AZ(IrACarnetQuickShort(j), pivot)) {
				i++;
				Intercambio(IrACarnetQuickShort(i), IrACarnetQuickShort(j));
			}
		}
		i++;
		Intercambio(IrACarnetQuickShort(i), IrACarnetQuickShort(UpperIndex));
		return (i);
	}

	bool AZ(Carnet* Carnet1, Carnet* Carnet2) {
		if (strcmp(Carnet2->String_Carnet_CURP.c_str(), Carnet1->String_Carnet_CURP.c_str()) < 0) {
			return false;
		}
		return true;
	}

	Carnet* IrACarnetHeapShort(int _iteraciones) {

		PtrAuxiliarCarnet = PtrOrigenCarnet;
		for (int i = 0; i < _iteraciones; i++){
			PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
		}
		return PtrAuxiliarCarnet;
	}

	Carnet* IrACarnetQuickShort(int _iteraciones) {

		PtrAuxiliarCarnet = PtrOrigenCarnet;
		for (int i = 1; i < _iteraciones; i++) {
			PtrAuxiliarCarnet = PtrAuxiliarCarnet->Ptr_Carnet_siguiente;
		}
		return PtrAuxiliarCarnet;
	}

	void Intercambio(Carnet* Carnet1, Carnet* Carnet2) {
		Carnet* CarnetTemporal1Ant = NULL;
		Carnet* CarnetTemporal1Sig = NULL;
		Carnet* CarnetTemporal1 = NULL;
		CarnetTemporal1Ant = Carnet1->Ptr_Carnet_anterior;
		CarnetTemporal1Sig = Carnet1->Ptr_Carnet_siguiente;
		CarnetTemporal1 = Carnet1;
		if (CarnetTemporal1Sig == Carnet2) {
			Carnet1->Ptr_Carnet_siguiente = Carnet2->Ptr_Carnet_siguiente;
			if (Carnet1->Ptr_Carnet_siguiente != NULL) {
				Carnet1->Ptr_Carnet_siguiente->Ptr_Carnet_anterior = Carnet1;
			}
			Carnet1->Ptr_Carnet_anterior = Carnet2;
			Carnet2->Ptr_Carnet_siguiente = CarnetTemporal1;
			Carnet2->Ptr_Carnet_anterior = CarnetTemporal1Ant;
			if (Carnet2->Ptr_Carnet_anterior == NULL) {
				PtrOrigenCarnet = Carnet2;
			}
			else {
				Carnet2->Ptr_Carnet_anterior->Ptr_Carnet_siguiente = Carnet2;
			}
		}
		else {
			Carnet1->Ptr_Carnet_siguiente = Carnet2->Ptr_Carnet_siguiente;
			Carnet1->Ptr_Carnet_anterior = Carnet2->Ptr_Carnet_anterior;
			if (Carnet1->Ptr_Carnet_anterior != NULL) {
				Carnet1->Ptr_Carnet_anterior->Ptr_Carnet_siguiente = Carnet1;
			}
			if (Carnet1->Ptr_Carnet_siguiente != NULL) {
				Carnet1->Ptr_Carnet_siguiente->Ptr_Carnet_anterior = Carnet1;
			}
			Carnet2->Ptr_Carnet_siguiente = CarnetTemporal1Sig;
			Carnet2->Ptr_Carnet_anterior = CarnetTemporal1Ant;
			if (Carnet2->Ptr_Carnet_siguiente != NULL) {
				Carnet2->Ptr_Carnet_siguiente->Ptr_Carnet_anterior = Carnet2;
			}
			if (Carnet2->Ptr_Carnet_anterior == NULL) {
				PtrOrigenCarnet = Carnet2;
			}
			else {
				Carnet2->Ptr_Carnet_anterior->Ptr_Carnet_siguiente = Carnet2;
			}
		}
	}

}*PtrOrigenCarnet = NULL, * PtrAuxiliarCarnet = NULL;
Carnet Carnet1;
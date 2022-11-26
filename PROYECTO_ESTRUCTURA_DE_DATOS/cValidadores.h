#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

bool ValidacionContraseñaSinEspacios(HWND hwnd, int int_CampoParaValidar, bool flag) {

	char DlgText[100] = "";
	HWND Hdlgitem;
	int Sizedlgitem;
	Hdlgitem = GetDlgItem(hwnd, int_CampoParaValidar);
	Sizedlgitem = GetWindowTextLength(Hdlgitem);
	GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
	for (int i = 0; i < Sizedlgitem; i++) {
		if (flag || !((DlgText[i] >= 33) && (DlgText[i] <= 126))) {
			return true;
		}
	}
	if (Sizedlgitem == 0) {
		return true;
	}else {
		return false;
	}
}

bool ValidacionFechaMenorAActual(HWND hwnd, int int_CampoParaValidar, bool flag) {
	
	char FechaCapturada[12] = "";
	HWND Hdlgitem;
	int Sizedlgitem;
	Hdlgitem = GetDlgItem(hwnd, int_CampoParaValidar);
	Sizedlgitem = GetWindowTextLength(Hdlgitem);
	GetWindowText(Hdlgitem, FechaCapturada, Sizedlgitem + 1);
	if (Sizedlgitem !=0){
		time_t rawtime;
		tm* timeinfoFechaActual;
		tm timeinfoFechaCapturada;
		time(&rawtime);
		timeinfoFechaActual = localtime(&rawtime);
		string Fecha = FechaCapturada;
		timeinfoFechaCapturada.tm_year = atoi(Fecha.substr(6, 4).c_str()) - 1900;
		timeinfoFechaCapturada.tm_mon = atoi(Fecha.substr(3, 2).c_str()) - 1;
		timeinfoFechaCapturada.tm_mday = atoi(Fecha.substr(0, 2).c_str());
		if (!flag) {
			if (timeinfoFechaCapturada.tm_year < timeinfoFechaActual->tm_year) {
				return false;
			}
			else if (timeinfoFechaCapturada.tm_year == timeinfoFechaActual->tm_year && timeinfoFechaCapturada.tm_mon < timeinfoFechaActual->tm_mon) {
				return false;
			}
			else if ((timeinfoFechaCapturada.tm_year == timeinfoFechaActual->tm_year) && (timeinfoFechaCapturada.tm_mon == timeinfoFechaActual->tm_mon) && (timeinfoFechaCapturada.tm_mday < timeinfoFechaActual->tm_mday)) {
				return false;
			}
		}
	}
	return true;
}

bool ValidacionFechaMayorIgualAActual(HWND hwnd, int int_CampoParaValidar, bool flag) {

	char FechaCapturada[12] = "";
	HWND Hdlgitem;
	int Sizedlgitem;
	Hdlgitem = GetDlgItem(hwnd, int_CampoParaValidar);
	Sizedlgitem = GetWindowTextLength(Hdlgitem);
	GetWindowText(Hdlgitem, FechaCapturada, Sizedlgitem + 1);
	if (Sizedlgitem != 0){
		time_t rawtime;
		tm* timeinfoFechaActual;
		tm timeinfoFechaCapturada;
		time(&rawtime);
		timeinfoFechaActual = localtime(&rawtime);
		string Fecha = FechaCapturada;
		timeinfoFechaCapturada.tm_year = atoi(Fecha.substr(6, 4).c_str()) - 1900;
		timeinfoFechaCapturada.tm_mon = atoi(Fecha.substr(3, 2).c_str()) - 1;
		timeinfoFechaCapturada.tm_mday = atoi(Fecha.substr(0, 2).c_str());
		if (!flag) {
			if (timeinfoFechaCapturada.tm_year > timeinfoFechaActual->tm_year) {
				return false;
			}
			else if (timeinfoFechaCapturada.tm_year == timeinfoFechaActual->tm_year && timeinfoFechaCapturada.tm_mon > timeinfoFechaActual->tm_mon) {
				return false;
			}
			else if ((timeinfoFechaCapturada.tm_year == timeinfoFechaActual->tm_year) && (timeinfoFechaCapturada.tm_mon == timeinfoFechaActual->tm_mon) && (timeinfoFechaCapturada.tm_mday >= timeinfoFechaActual->tm_mday)) {
				return false;
			}
		}
	}
	return true;
}

bool ValidacionFechaMayorACaptura(HWND hwnd, int int_CampoFechaDosis, int _FechaProxDosis, bool flag) {

	HWND Hdlgitem;
	char FechaDosis[12] = "";
	int Sizedlgitem1;
	Hdlgitem = GetDlgItem(hwnd, int_CampoFechaDosis);
	Sizedlgitem1 = GetWindowTextLength(Hdlgitem);
	GetWindowText(Hdlgitem, FechaDosis, Sizedlgitem1 + 1);
	char FechaProxDosis[12] = "";
	int Sizedlgitem2;
	Hdlgitem = GetDlgItem(hwnd, _FechaProxDosis);
	Sizedlgitem2 = GetWindowTextLength(Hdlgitem);
	GetWindowText(Hdlgitem, FechaProxDosis, Sizedlgitem2 + 1);
	if (Sizedlgitem1 != 0 && Sizedlgitem2 != 0){
		tm timeinfoFechaDosis;
		tm timeinfoFechaProxDosis;
		string sFechaDosis = FechaDosis;
		string sFechaProxDosis = FechaProxDosis;
		timeinfoFechaDosis.tm_year = atoi(sFechaDosis.substr(6, 4).c_str()) - 1900;
		timeinfoFechaDosis.tm_mon = atoi(sFechaDosis.substr(3, 2).c_str()) - 1;
		timeinfoFechaDosis.tm_mday = atoi(sFechaDosis.substr(0, 2).c_str());
		timeinfoFechaProxDosis.tm_year = atoi(sFechaProxDosis.substr(6, 4).c_str()) - 1900;
		timeinfoFechaProxDosis.tm_mon = atoi(sFechaProxDosis.substr(3, 2).c_str()) - 1;
		timeinfoFechaProxDosis.tm_mday = atoi(sFechaProxDosis.substr(0, 2).c_str());
		if (!flag) {
			if (timeinfoFechaDosis.tm_year < timeinfoFechaProxDosis.tm_year) {
				return false;
			}
			else if (timeinfoFechaDosis.tm_year == timeinfoFechaProxDosis.tm_year && timeinfoFechaDosis.tm_mon < timeinfoFechaProxDosis.tm_mon) {
				return false;
			}
			else if ((timeinfoFechaDosis.tm_year == timeinfoFechaProxDosis.tm_year) && (timeinfoFechaDosis.tm_mon == timeinfoFechaProxDosis.tm_mon) && (timeinfoFechaDosis.tm_mday < timeinfoFechaProxDosis.tm_mday)) {
				return false;
			}
		}
	}
	return true;
}

bool ValidacionLetraYNumeroConEspacios(HWND hwnd, int int_CampoParaValidar, bool flag) {

	char DlgText[100] = "";
	HWND Hdlgitem;
	int Sizedlgitem;
	Hdlgitem = GetDlgItem(hwnd, int_CampoParaValidar);
	Sizedlgitem = GetWindowTextLength(Hdlgitem);
	GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
	for (int i = 0; i < Sizedlgitem; i++) {
		if (flag || !((DlgText[i]==32) || (DlgText[i] >= 48 && DlgText[i] <= 57) || (DlgText[i] >= 65 && DlgText[i] <= 90))) {
			return true;
		}
	}
	if (Sizedlgitem == 0) {
		return true;
	}else {
		return false;
	}
}

bool ValidacionLetraYNumeroSinEspacios(HWND hwnd, int int_CampoParaValidar, bool flag) {

	char DlgText[100] = "";
	HWND Hdlgitem;
	int Sizedlgitem;
	Hdlgitem = GetDlgItem(hwnd, int_CampoParaValidar);
	Sizedlgitem = GetWindowTextLength(Hdlgitem);
	GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
	for (int i = 0; i < Sizedlgitem; i++) {
		if (flag || !((DlgText[i] >= 48 && DlgText[i] <= 57) || (DlgText[i] >= 65 && DlgText[i] <= 90))) {
			return true;
		}
	}
	if (Sizedlgitem == 0) {
		return true;
	}else {
		return false;
	}
}

bool ValidacionLetraConEspacios(HWND hwnd, int int_CampoParaValidar, bool flag) {

	char DlgText[100] = "";
	HWND Hdlgitem;
	int Sizedlgitem;
	Hdlgitem = GetDlgItem(hwnd, int_CampoParaValidar);
	Sizedlgitem = GetWindowTextLength(Hdlgitem);
	GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
	for (int i = 0; i < Sizedlgitem; i++) {
		if (flag || !((DlgText[i] == 32) || (DlgText[i] >= 65 && DlgText[i] <= 90))) {
			return true;
		}
	}
	if (Sizedlgitem == 0) {
		return true;
	}else {
		return false;
	}
}

bool ValidacionLetraSinEspacios(HWND hwnd, int int_CampoParaValidar, bool flag) {

	char DlgText[100] = "";
	HWND Hdlgitem;
	int Sizedlgitem;
	Hdlgitem = GetDlgItem(hwnd, int_CampoParaValidar);
	Sizedlgitem = GetWindowTextLength(Hdlgitem);
	GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
	for (int i = 0; i < Sizedlgitem; i++) {
		if (flag || !(DlgText[i] >= 65 && DlgText[i] <= 90)) {
			return true;
		}
	}
	if (Sizedlgitem == 0) {
		return true;
	}else {
		return false;
	}
}

bool ValidacionMayorACero(HWND hwnd, int int_CampoParaValidar, bool flag) {

	char DlgText[150] = "";
	HWND Hdlgitem;
	int Sizedlgitem;
	Hdlgitem = GetDlgItem(hwnd, int_CampoParaValidar);
	Sizedlgitem = GetWindowTextLength(Hdlgitem);
	GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
	INT64 Number = _atoi64(DlgText);
	if (Number<=0 || flag) {
		return true;
	}else {
		return false;
	}
}

bool ValidacionNumeroTelefonico(HWND hwnd, int int_CampoParaValidar, bool flag) {

	char DlgText[150] = "";
	HWND Hdlgitem;
	int Sizedlgitem;
	Hdlgitem = GetDlgItem(hwnd, int_CampoParaValidar);
	Sizedlgitem = GetWindowTextLength(Hdlgitem);
	GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
	INT64 Number = _atoi64(DlgText);
	if (Sizedlgitem != 10 || flag) {
		return true;
	}
	else {
		return false;
	}
}

string ValidacionCapturaTexto(HWND hwnd, int int_CampoParaCapturar) {

	char DlgText[100] = "";
	HWND Hdlgitem;
	int Sizedlgitem;
	Hdlgitem = GetDlgItem(hwnd, int_CampoParaCapturar);
	Sizedlgitem = GetWindowTextLength(Hdlgitem);
	GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
	return DlgText;
}

string ValidacionANumero(HWND hwnd, int int_CampoParaCapturar) {

	char DlgText[100] = "";
	HWND Hdlgitem;
	int Sizedlgitem = 0;
	Hdlgitem = GetDlgItem(hwnd, int_CampoParaCapturar);
	Sizedlgitem = GetWindowTextLength(Hdlgitem);
	GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
	int Number = atoi(DlgText);
	ZeroMemory(DlgText, 100);
	_itoa_s(Number,DlgText,10);
	return DlgText;
}



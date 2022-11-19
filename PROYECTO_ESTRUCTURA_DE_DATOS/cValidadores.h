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
	time_t rawtime;
	tm* timeinfoFechaActual;
	tm timeinfoFechaCapturada;
	time(&rawtime);
	timeinfoFechaActual = localtime(&rawtime);
	string Fecha = FechaCapturada;
	timeinfoFechaCapturada.tm_year = atoi(Fecha.substr(6, 4).c_str()) - 1900;
	timeinfoFechaCapturada.tm_mon = atoi(Fecha.substr(3, 2).c_str()) - 1;
	timeinfoFechaCapturada.tm_mday = atoi(Fecha.substr(0, 2).c_str());
	if (!flag){
		if (timeinfoFechaCapturada.tm_year <= timeinfoFechaActual->tm_year) {
			if (timeinfoFechaCapturada.tm_mon <= timeinfoFechaActual->tm_mon) {
				if (timeinfoFechaCapturada.tm_mday < timeinfoFechaActual->tm_mday) {
					return false;
				}
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
	int Number = atoi(DlgText);
	if (Number<=0 || flag) {
		return true;
	}else {
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


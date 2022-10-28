#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string.h>
using namespace std;


bool ValidacionTexto(HWND hwnd, int int_CampoParaValidar, bool flag) {

	char DlgText[100] = "";
	string DlgTextS;
	HWND Hdlgitem;
	int Sizedlgitem;


	Hdlgitem = GetDlgItem(hwnd, int_CampoParaValidar);
	Sizedlgitem = GetWindowTextLength(Hdlgitem);
	GetWindowText(Hdlgitem, DlgText, Sizedlgitem + 1);
	DlgTextS = DlgText;

	if (DlgTextS == "HOLA" || DlgTextS == " " || DlgTextS == "" || flag){
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
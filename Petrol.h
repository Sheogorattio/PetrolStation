#pragma once
#include<windows.h>
#include<windowsx.h>
#include<tchar.h>
#include"resource.h"

const DOUBLE A92 = 49.77, A95 = 50.63, A95plus = 51.83;

class Petrol
{
public:
	static Petrol* ptr;
	static BOOL CALLBACK DlgProc(HWND hwnd, UINT id, WPARAM wp, LPARAM lp);
	BOOL Cls_OnInit(HWND hwnd, HWND hwndFocus, LPARAM lp);
	void Cls_OnClose(HWND hwnd);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtrl, UINT coseNotify);
	Petrol();
	HWND hPetrolTypeCombo, hPetrolPriceEdit, hPetrolValRadio, hPetrolSumRadio, hPetrolValEdit, hPetrolSumEdit, hPetrolTotalEdit;
	DOUBLE Total = 0, ActualPrice = 0;
};


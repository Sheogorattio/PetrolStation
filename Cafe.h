#pragma once
#include"Header.h"
class Cafe
{
public:
	static Cafe* ptr;
	static BOOL CALLBACK DlgProc(HWND hwnd, UINT id, WPARAM wp, LPARAM lp);
	Cafe();
	BOOL Cls_OnInit(HWND hwnd, HWND hwndFocus, LPARAM lp);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtrl, UINT codeNotify);
	void Cls_OnClose(HWND hwnd);
	HWND hHotDogCh, hColaCh, hBurgerCh, hPotatoCh, hPotatoNum, hBurgerNum, hColaNum, hHotDogNum, hHotDogPrice, hColaPrice, hBurgerPrice, hPotatoPrice, hTotalPrice;
	INT HotDogPrice = 40, PotatoPrice = 50, BurgerPrice = 120, ColaPrice = 60;
	DOUBLE TotalPrice = 0.0;
	TCHAR price[20];
};


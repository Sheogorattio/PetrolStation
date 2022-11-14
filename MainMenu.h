#pragma once
#include"Header.h"
#include"Cafe.h"
class MainMenu
{
public:
	HWND hPetrolButton, hCafeButton, hTotalPrice;
	DOUBLE nTotalPrice = 0;
	static MainMenu* ptr;
	static BOOL CALLBACK DlgProc(HWND hwnd, UINT message, WPARAM wp, LPARAM lp);
	BOOL Cls_OnInit(HWND hwnd, HWND hwndFocus, LPARAM lp);
	void Cls_OnClose(HWND hwnd);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtrl, UINT codeNotify);
	MainMenu();
};


#include "Cafe.h"
Cafe* Cafe::ptr = NULL;

BOOL Cafe::DlgProc(HWND hwnd, UINT id, WPARAM wParam, LPARAM lParam)
{
	switch (id) {
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInit);
	}
	return FALSE;
}

Cafe::Cafe()
{
	ptr = this;
}

BOOL Cafe::Cls_OnInit(HWND hwnd, HWND hwndFocus, LPARAM lp)
{

	hHotDogCh = GetDlgItem(hwnd, IDC_HotDogCheck);
	hHotDogNum = GetDlgItem(hwnd, IDC_HotDogNumberEdit);
	hHotDogPrice = GetDlgItem(hwnd, IDC_HotDogPrice);
	_stprintf_s(price, TEXT("%d"), HotDogPrice);
	SetWindowText(hHotDogPrice, price);
	hColaCh = GetDlgItem(hwnd, IDC_ColaCheck);
	hColaNum = GetDlgItem(hwnd, IDC_ColaNumberEdit);
	hColaPrice = GetDlgItem(hwnd, IDC_ColaPrice);
	_stprintf_s(price, TEXT("%d"), ColaPrice);
	SetWindowText(hColaPrice, price);
	hPotatoCh = GetDlgItem(hwnd, IDC_PotatoCheck);
	hPotatoNum = GetDlgItem(hwnd, IDC_PotatoNumberEdit);
	hPotatoPrice = GetDlgItem(hwnd, IDC_PotatoPrice);
	_stprintf_s(price, TEXT("%d"), PotatoPrice);
	SetWindowText(hPotatoPrice, price);
	hBurgerCh = GetDlgItem(hwnd, IDC_BurgerCheck);
	hBurgerNum = GetDlgItem(hwnd, IDC_BurherNumberEdit);
	hBurgerPrice = GetDlgItem(hwnd, IDC_BurgerPrice);
	_stprintf_s(price, TEXT("%d"), BurgerPrice);
	SetWindowText(hBurgerPrice, price);
	hTotalPrice = GetDlgItem(hwnd, IDC_CafeTotalPrice);
	SetWindowText(hTotalPrice, TEXT("0"));
	return TRUE;
}

void Cafe::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtrl, UINT codeNotify)
{
	if (id == IDOK) {
		TCHAR lpszHowMany[20];
		TotalPrice = 0;
		if (BST_CHECKED == SendMessage(hHotDogCh, BM_GETCHECK, 0, 0)) {
			GetWindowText(hHotDogNum, lpszHowMany, 20);
			TotalPrice += (HotDogPrice * atoi((char*)lpszHowMany));
		}
		if (BST_CHECKED == SendMessage(hBurgerCh, BM_GETCHECK, 0, 0)) {
			GetWindowText(hBurgerNum, lpszHowMany, 20);
			TotalPrice += (BurgerPrice * atoi((char*)lpszHowMany));
		}
		if (BST_CHECKED == SendMessage(hPotatoCh, BM_GETCHECK, 0, 0)) {
			GetWindowText(hPotatoNum, lpszHowMany, 20);
			TotalPrice += (PotatoPrice * atoi((char*)lpszHowMany));
		}
		if (BST_CHECKED == SendMessage(hColaCh, BM_GETCHECK, 0, 0)) {
			GetWindowText(hColaNum, lpszHowMany, 20);
			TotalPrice += (ColaPrice * atoi((char*)lpszHowMany));
		}
		TCHAR lpszTotalPrice[20];
		_stprintf_s(lpszTotalPrice, TEXT("%f"), TotalPrice);
		SetWindowText(hTotalPrice, lpszTotalPrice);
	}
	if (id == IDCANCEL) {
		EndDialog(hwnd, 0);
	}
}

void Cafe::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

#include "Petrol.h"

Petrol* Petrol::ptr = NULL;

BOOL Petrol::DlgProc(HWND hwnd, UINT id, WPARAM wParam, LPARAM lParam)
{
	switch (id) {
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInit);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
	}
	return FALSE;
}

BOOL Petrol::Cls_OnInit(HWND hwnd, HWND hwndFocus, LPARAM lp)
{

	hPetrolTypeCombo = GetDlgItem(hwnd, IDC_PetrolTypeCombo);
	hPetrolPriceEdit = GetDlgItem(hwnd, IDC_PetrolPrice1L);
	hPetrolValRadio = GetDlgItem(hwnd, IDC_PetrolVal);
	hPetrolSumRadio = GetDlgItem(hwnd, IDC_PetrolSum);
	hPetrolValEdit = GetDlgItem(hwnd, IDC_PetrolValEdit);
	hPetrolSumEdit = GetDlgItem(hwnd, IDC_PetrolSumEdit);
	hPetrolTotalEdit = GetDlgItem(hwnd, IDC_PetrolTotal);
	SendMessage(hPetrolTypeCombo, CB_ADDSTRING, 0, LPARAM(TEXT("A-92")));
	SendMessage(hPetrolTypeCombo, CB_ADDSTRING, 0, LPARAM(TEXT("A-95")));
	SendMessage(hPetrolTypeCombo, CB_ADDSTRING, 0, LPARAM(TEXT("A-92+")));
	EnableWindow(hPetrolTotalEdit, FALSE);
	return TRUE;
}

void Petrol::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

void Petrol::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtrl, UINT codeNotify)
{
	if (id == IDC_PetrolTypeCombo && codeNotify == CBN_SELCHANGE) {
		int index = SendMessage(hPetrolTypeCombo, CB_GETCURSEL, 0, 0);
		switch (index) {
			case 0:
			{
				SetWindowText(hPetrolPriceEdit, TEXT("49.77"));
				ActualPrice = A92;
				break;
			}
			case 1:
			{
				SetWindowText(hPetrolPriceEdit, TEXT("50.63"));
				ActualPrice = A95;
				break;
			}
			case 2:
			{
				SetWindowText(hPetrolPriceEdit, TEXT("51.83"));
				ActualPrice = A95plus;
				break;
			}
		}
	}
	if (id == IDC_PetrolVal) {
		EnableWindow(hPetrolValEdit, TRUE);
		EnableWindow(hPetrolSumEdit, FALSE);
		SetWindowText(hPetrolValEdit, TEXT("0"));
	}
	if (id == IDC_PetrolSum) {
		EnableWindow(hPetrolSumEdit, TRUE);
		EnableWindow(hPetrolValEdit, FALSE);
		SetWindowText(hPetrolSumEdit, TEXT("0"));
	}
	if (id == IDOK) {
		if (BST_CHECKED == SendMessage(hPetrolValRadio, BM_GETCHECK, 0, 0)) {
			TCHAR text[20];
			GetWindowText(hPetrolValEdit, text, 20);
			Total = ActualPrice * _wtof(text);
			_stprintf_s(text, TEXT("%f"), Total);
			SetWindowText(hPetrolSumEdit, text);
			SetWindowText(hPetrolTotalEdit, text);
		}
		if (BST_CHECKED == SendMessage(hPetrolSumRadio, BM_GETCHECK, 0, 0)) {
			TCHAR text[30];
			GetWindowText(hPetrolSumEdit, text, 20);
			SetWindowText(hPetrolTotalEdit, text);
			Total = _wtoi(text);
			_stprintf_s(text, TEXT("%f"), Total/ActualPrice);
			SetWindowText(hPetrolValEdit, text);
			
		}
	}
	if (id == IDCANCEL) {
		EndDialog(hwnd, 0);
	}
}

Petrol::Petrol()
{
	ptr = this;
}

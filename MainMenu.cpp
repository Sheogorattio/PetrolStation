#include "MainMenu.h"
MainMenu* MainMenu::ptr = NULL;

BOOL MainMenu::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInit);
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return FALSE;
}

BOOL MainMenu::Cls_OnInit(HWND hwnd, HWND hwndFocus, LPARAM lp)
{
	hPetrolButton = GetDlgItem(hwnd, IDC_PetrolButton);
	hCafeButton = GetDlgItem(hwnd, IDC_CafeButton);	
	hTotalPrice = GetDlgItem(hwnd, IDC_TotalPrice);

	return FALSE;
}

void MainMenu::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

void MainMenu::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtrl, UINT codeNotify)
{
		if (id ==  IDC_CafeButton) {
			Cafe cafe;
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG3), hwnd, (DLGPROC)Cafe::DlgProc);
			nTotalPrice += cafe.TotalPrice;
			TCHAR lpszTotalPrice[20];
			_stprintf_s(lpszTotalPrice, TEXT("%f"), nTotalPrice);
			SetWindowText(hTotalPrice, lpszTotalPrice);
		}
		if (id == IDC_PetrolButton) {
			Petrol petrol;
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG2), hwnd, (DLGPROC)Petrol::DlgProc);
			nTotalPrice += petrol.Total;
			TCHAR lpszTotalPrice[20];
			_stprintf_s(lpszTotalPrice, TEXT("%f"), nTotalPrice);
			SetWindowText(hTotalPrice, lpszTotalPrice);
		}
		if (id == IDOK) {
			TCHAR buff[50];
			_stprintf_s(buff, TEXT("Total price: %f"), nTotalPrice);
			MessageBox(hwnd, buff, TEXT("CHEQUE"), MB_OK | MB_ICONINFORMATION);
		}
		if(id == IDC_MMenuCancel) {
			EndDialog(hwnd, 0);
		}
}

MainMenu::MainMenu()
{
	ptr = this;
}

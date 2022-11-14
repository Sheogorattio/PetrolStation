#include"Header.h"
#include"MainMenu.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow) {
	MainMenu menu;
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)MainMenu::DlgProc);
}
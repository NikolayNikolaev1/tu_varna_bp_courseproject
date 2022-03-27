// ExerciseApplication.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "ExerciseApplication.h"
#include "stdio.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Dialog1(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    SendItemMessage(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Task1(HWND, UINT, WPARAM, LPARAM);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_EXERCISEAPPLICATION, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EXERCISEAPPLICATION));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EXERCISEAPPLICATION));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_EXERCISEAPPLICATION);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HMENU hMenu;
	switch (message)
	{
	case WM_COMMAND:
	{
		hMenu = GetMenu(hWnd);
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_A1:
			MessageBox(hWnd, "List A1", "A1", MB_OK);
			break;
		case IDM_A2:
			// Deletes Menu.
			DeleteMenu(hMenu, IDM_A8, MF_BYCOMMAND);
			break;
		case IDM_A3:
			// Check/Unchek menu.
			if (GetMenuState(hMenu, IDM_A4, MF_BYCOMMAND) == MF_CHECKED)
			{
				CheckMenuItem(hMenu, IDM_A4, MF_UNCHECKED);
				break;
			}

			CheckMenuItem(hMenu, IDM_A4, MF_CHECKED);
			break;
		case IDM_A4:
			// Enable/Disable menu.
			if (GetMenuState(hMenu, IDM_A7, MF_BYCOMMAND) == MF_ENABLED)
			{
				EnableMenuItem(hMenu, IDM_A7, MF_DISABLED);
				break;
			}

			EnableMenuItem(hMenu, IDM_A7, MF_ENABLED);
			break;
		case IDM_A9:
			// Insert new menu.
			if (GetMenuState(hMenu, IDM_A9 + 1, MF_BYCOMMAND) == -1)
			{
				MENUITEMINFO mii;
				ZeroMemory(&mii, sizeof(mii));
				mii.cbSize = sizeof(mii);
				mii.fMask = MIIM_ID | MIIM_TYPE | MIIM_STATE;
				mii.wID = IDM_A9 + 1;
				mii.fType = MFT_STRING;
				mii.dwTypeData = const_cast<char*>("A10");
				mii.fState = MFS_ENABLED;				InsertMenuItem(hMenu, IDM_A2, FALSE, &mii);
			}
			break;
		case IDM_A12:
			MessageBox(hWnd, "List A12", "A12", MB_OK);
			break;
		case IDM_T11:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_TASK1), hWnd, Task1);
			break;
		case IDM_T12:
			MessageBox(hWnd, "List T12", "T12", MB_OK);
			break;
		case IDM_DIALOG1:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Dialog1);
			break;
		case IDM_SENDITEMMESSAGE:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_SEND_ITEM_MSG), hWnd, SendItemMessage);
			break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_RBUTTONDOWN:
	{
		// Right mouse button context menu.
		hMenu = LoadMenu(hInst, MAKEINTRESOURCE(IDR_CONTEXT));
		HMENU hSubMenu = GetSubMenu(hMenu, 0);
		POINT pt = { LOWORD(lParam), HIWORD(lParam) };
		ClientToScreen(hWnd, &pt);
		TrackPopupMenu(hSubMenu, TPM_RIGHTBUTTON, pt.x, pt.y, 0, hWnd, NULL);
		DestroyMenu(hMenu);
		break;
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Dialog1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		SetDlgItemInt(hDlg, IDC_EDIT1, 16, true);
		SetDlgItemInt(hDlg, IDC_EDIT2, 8, true);
		CheckDlgButton(hDlg, IDC_RADIO1, BST_CHECKED);
		SetDlgItemText(hDlg, IDC_EDIT4, "1.333");
		SetDlgItemText(hDlg, IDC_EDIT5, "4.56");
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		char buf[100];
		float first_number, second_number, result;

		switch (LOWORD(wParam))
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		case IDC_EQUALS:
			first_number = GetDlgItemInt(hDlg, IDC_EDIT1, NULL, true);
			second_number = GetDlgItemInt(hDlg, IDC_EDIT2, NULL, true);

			if (IsDlgButtonChecked(hDlg, IDC_RADIO1))
			{
				// Substract numbers.
				result = first_number - second_number;
				SetDlgItemInt(hDlg, IDC_EDIT3, result, true);
				break;
			}
			// Multiply numbers.
			result = first_number * second_number;
			SetDlgItemInt(hDlg, IDC_EDIT3, result, true);
			break;
		case IDC_DIVIDE:
			// Divide numbers.
			GetDlgItemText(hDlg, IDC_EDIT4, buf, 100);
			first_number = atof(buf);
			GetDlgItemText(hDlg, IDC_EDIT5, buf, 100);
			second_number = atof(buf);

			result = first_number / second_number;
			sprintf_s(buf, "%10.2f", result);
			SetDlgItemText(hDlg, IDC_EDIT6, buf);
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK SendItemMessage(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		SendDlgItemMessage(hDlg, IDC_COMBO, CB_ADDSTRING, 100, (LPARAM)"First Message");
		SendDlgItemMessage(hDlg, IDC_COMBO, CB_ADDSTRING, 100, (LPARAM)"Second Message");
		SendDlgItemMessage(hDlg, IDC_COMBO, CB_ADDSTRING, 100, (LPARAM)"Third Message");
		SendDlgItemMessage(hDlg, IDC_COMBO, CB_ADDSTRING, 100, (LPARAM)"Fourth Message");
		CheckDlgButton(hDlg, IDC_CHECK_B, BST_CHECKED);
		CheckDlgButton(hDlg, IDC_CHECK_C, BST_CHECKED);
		return (INT_PTR)TRUE;
	case WM_COMMAND:
		char buf[100];

		switch (LOWORD(wParam))
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		case IDC_BTN_ENTER:
			// Save input text in Combo Box.
			GetDlgItemText(hDlg, IDC_EDIT, buf, 100);

			if (SendDlgItemMessage(hDlg, IDC_COMBO, CB_FINDSTRING, 100, (LPARAM)buf) == -1 || strlen(buf) > 0)
			{
				SendDlgItemMessage(hDlg, IDC_COMBO, CB_ADDSTRING, 100, (LPARAM)buf);
			}

			break;
		case IDC_BTN_SELECT:
		{
			// Output text from combo box based on checkbox.
			int combo_index = SendDlgItemMessage(hDlg, IDC_COMBO, CB_GETCURSEL, 0, 0);
			SendDlgItemMessage(hDlg, IDC_COMBO, CB_GETLBTEXT, combo_index, (LPARAM)buf);

			if (IsDlgButtonChecked(hDlg, IDC_CHECK_B))
			{
				SetDlgItemText(hDlg, IDC_EDIT_B, buf);
			}

			if (IsDlgButtonChecked(hDlg, IDC_CHECK_C))
			{
				SetDlgItemText(hDlg, IDC_EDIT_C, buf);
			}

			break;
		}
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Task1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
	{
		const char default_text[100] = "Sample edit box";
		SetDlgItemText(hDlg, IDC_EDIT1, default_text);
		SetDlgItemText(hDlg, IDC_EDIT2, default_text);
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:
		char buf[100];

		switch (LOWORD(wParam))
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		case IDC_BUTTON1:
			// Save message from first box to second box.
			GetDlgItemText(hDlg, IDC_EDIT1, buf, 100);
			SetDlgItemText(hDlg, IDC_EDIT2, buf);
			break;
		case IDC_BUTTON2:
			// Save message from second box to first box.
			GetDlgItemText(hDlg, IDC_EDIT2, buf, 100);
			SetDlgItemText(hDlg, IDC_EDIT1, buf);
			break;
		case IDC_MESSAGE_BOX:
			// Display Message box.
			MessageBox(hDlg, "Message box from\nDialog 1", "Message Box", MB_YESNOCANCEL);
			break;
		default:
			break;
		}
	}
	return (INT_PTR)FALSE;
}
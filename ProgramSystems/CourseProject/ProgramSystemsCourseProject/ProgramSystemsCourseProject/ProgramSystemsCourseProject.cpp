// ProgramSystemsCourseProject.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "ProgramSystemsCourseProject.h"
#include "stack"
#include "string"
#include <atlstr.h>
#include <stdexcept>

#define MAX_LOADSTRING 100

using namespace std;

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Arithmetic(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_PROGRAMSYSTEMSCOURSEPROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROGRAMSYSTEMSCOURSEPROJECT));

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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROGRAMSYSTEMSCOURSEPROJECT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PROGRAMSYSTEMSCOURSEPROJECT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_ARITHMETIC:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ARITHMETIC), hWnd, Arithmetic);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
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

void calc(stack<float> &operands, const char& operation);
void postfix(char* expression, char* postfixExpr, float& result);

// Message handler for about box.
INT_PTR CALLBACK Arithmetic(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDC_CALCULATE)
        {
            char expression[100];
            char postfixExpr[100] = "";
            float result = 0;
            try
            {
                GetDlgItemText(hDlg, IDC_EXPRESSION, expression, 100);

                reverse(expression, expression + strlen(expression));
                postfix(expression, postfixExpr, result);
                reverse(postfixExpr, postfixExpr + strlen(postfixExpr));

                SetDlgItemText(hDlg, IDC_PREFIX, postfixExpr);

                CString sTmp;
                sTmp.Format("%.2f", result);
                SetDlgItemText(hDlg, IDC_RESULT, sTmp);
            }
            catch (const invalid_argument& e)
            {
                MessageBox(hDlg, e.what(), "Invalid expression", MB_OK | MB_ICONERROR);
            }
        }
        
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

void postfix(char* expression, char* postfixExpr, float& result)
{
    stack<char> operators;
    stack<char> postfixExpression;
    stack<float> operands;
    bool operatorFlag = false;

    for (int i = 0; i < strlen(expression); i++)
    {
        switch (expression[i])
        {
        case ' ':
            continue;
        case '+':
        case '-':
            //operatorFlag = false;
        case '*':
        case '/':
            if (operatorFlag)
            {
                throw invalid_argument("Can not have 2 operators one after the other.");
            }

            operatorFlag = true;

            if (operators.empty())
            {
                operators.push(expression[i]);
                continue;
            }

            if ((expression[i] == '*' || expression[i] == '/')
                && (operators.top() == '-' || operators.top() == '+'))
            {
                operators.push(expression[i]);
                continue;
            }

            while (!operators.empty() && (operators.top() == '*' || operators.top() == '/'))
            {
                calc(operands, operators.top()); // Evaluating expresion.
                postfixExpression.push(operators.top());
                operators.pop();
            }

            operators.push(expression[i]);
            continue;
        case ')':
            operatorFlag = false;
            operators.push(expression[i]);
            continue;
        case '(':
            operatorFlag = false;
            while (operators.top() != ')')
            {
                calc(operands, operators.top()); // Evaluating expresion.
                postfixExpression.push(operators.top());
                operators.pop();
            }

            operators.pop(); // Remove the closing bracket.
            continue;
        default:
            operatorFlag = false;
            if (isdigit(expression[i]))
            {
                string number;
                bool decimalPointFlag = false;

                while (isdigit(expression[i]) || expression[i] == '.')
                {
                    number += expression[i];

                    if (expression[i] == '.')
                    {
                        if (decimalPointFlag)
                        {
                            break;
                        }

                        decimalPointFlag = true;
                    }

                    postfixExpression.push(expression[i]);
                    i++;
                }

                reverse(number.begin(), number.end());
                operands.push(stof(number)); // Save current number as a float.
                //postfixExpression.push(expression[i]);
                i--;
                continue;
            }

            throw invalid_argument("Invalid symbol in expression.");
        }
    }

    while (!operators.empty())
    {
        calc(operands, operators.top()); // Evaluating expresion.
        postfixExpression.push(operators.top());
        operators.pop();
    }

    result = operands.top();

    for (int i = postfixExpression.size() - 1; i >= 0; i--)
    {
        postfixExpr[i] = postfixExpression.top();
        postfixExpression.pop();
    }
}

void calc(stack<float> &operands, const char& operation)
{
    float firstOperand = operands.top();
    operands.pop();
    float secondOperand = operands.top();
    operands.pop();

    switch (operation)
    {
        case '+':
            operands.push(firstOperand + secondOperand);
            break;
        case '-':
            operands.push(firstOperand - secondOperand);
            break;
        case '*':
            operands.push(firstOperand * secondOperand);
            break;
        case '/':
            operands.push(firstOperand / secondOperand);
            break;
    }

}

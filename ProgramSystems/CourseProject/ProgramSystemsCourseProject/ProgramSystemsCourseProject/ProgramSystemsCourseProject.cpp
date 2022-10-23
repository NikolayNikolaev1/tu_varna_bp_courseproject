#include "atlstr.h"
#include "framework.h"
#include "ProgramSystemsCourseProject.h"
#include "string"
#include "stack"
#include "stdexcept"

#define MAX_LOADSTRING 100

using namespace std;

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

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


    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PROGRAMSYSTEMSCOURSEPROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);


    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROGRAMSYSTEMSCOURSEPROJECT));

    MSG msg;

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

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance;

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);

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
void prefix(char* expression, char* postfixExpr, float& result);

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
            char prefixExpr[100] = "";
            float result = 0;

            try
            {
                GetDlgItemText(hDlg, IDC_EXPRESSION, expression, 100);

                prefix(expression, prefixExpr, result);

                SetDlgItemText(hDlg, IDC_PREFIX, prefixExpr);

                CString sTmp;
                sTmp.Format("%.4f", result);
                SetDlgItemText(hDlg, IDC_RESULT, sTmp);
            }
            catch (const invalid_argument& e)
            {
                MessageBox(hDlg, e.what(), "Invalid expression", MB_OK | MB_ICONERROR);
            }
        }
        
        if (LOWORD(wParam) == IDCLOSE)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

void prefix(char* expression, char* prefixExpr, float& result)
{
    stack<char> operators; // stack for converting expression to prefix
    stack<char> output; // stack for converting expression to prefix
    stack<float> operands; // stack for calculating result of expression
    bool operatorFlag = false;

    reverse(expression, expression + strlen(expression));

    for (int i = 0; i < strlen(expression); i++)
    {
        switch (expression[i])
        {
        case ' ':
            continue;
        case '+':
        case '-':
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

            while (!operators.empty() &&
                (operators.top() == '*' || operators.top() == '/'))
            {
                calc(operands, operators.top()); // Evaluating expresion.
                output.push(operators.top());
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
                output.push(operators.top());
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

                    output.push(expression[i]);
                    i++;
                }

                reverse(number.begin(), number.end());
                operands.push(stof(number)); // save current number as a float
                i--; // prevents skipping next symbol
                continue;
            }

            throw invalid_argument("Invalid symbol in expression.");
        }
    }

    while (!operators.empty())
    {
        calc(operands, operators.top()); // Evaluating expresion.
        output.push(operators.top());
        operators.pop();
    }

    result = operands.top();

    for (int i = output.size() - 1; i >= 0; i--)
    {
        prefixExpr[i] = output.top();
        output.pop();
    }

    reverse(prefixExpr, prefixExpr + strlen(prefixExpr));
}

void calc(stack<float> &operands, const char& operation)
{
    if (operands.size() < 2)
    {
        throw invalid_argument("Expression can not start or end with an operator.");
    }
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

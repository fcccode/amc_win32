/*
 *  For AstroMediComp.org
 *  Assignment # 07 by Sachin Bhosale
 *  Color Window
 */

#include<windows.h>
#include"resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow)
{
  WNDCLASSEX wndclass;
  TCHAR szAppName[] = TEXT("ColorWindow");

  wndclass.cbClsExtra = 0;
  wndclass.cbWndExtra = 0;
  wndclass.cbSize = sizeof(WNDCLASSEX);
  wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
  wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
  wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
  wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
  wndclass.hInstance = hInstance;
  wndclass.lpfnWndProc = WndProc;
  wndclass.lpszClassName = szAppName;
  wndclass.lpszMenuName = NULL;
  wndclass.style = CS_VREDRAW | CS_HREDRAW;

  RegisterClassEx(&wndclass);

  HWND hwnd;
  hwnd = CreateWindow(szAppName
    , TEXT("Color Window")
    , WS_OVERLAPPEDWINDOW
    , CW_USEDEFAULT
    , CW_USEDEFAULT
    , CW_USEDEFAULT
    , CW_USEDEFAULT
    , NULL
    , NULL
    , hInstance
    , NULL);

  ShowWindow(hwnd, iCmdShow);
  UpdateWindow(hwnd);

  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return (int(msg.wParam));
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
  static int iKeyFlag;
  RECT rect;
  HDC hdc;
  HBRUSH hbr = NULL;
  PAINTSTRUCT ps;
  COLORREF color;
  switch (iMsg)
  {
  case WM_KEYDOWN:
    GetClientRect(hwnd, &rect);
    switch (wParam)
    {
    case VK_ESCAPE:
      PostQuitMessage(0);
      break;
    case 'O':
    case 'o':
    case '0':
      iKeyFlag = 0;
      InvalidateRect(hwnd, &rect, TRUE);
      break;
    case 'W':
    case 'w':
      iKeyFlag = 1;
      InvalidateRect(hwnd, &rect, TRUE);
      break;
    case 'Y':
    case 'y':
      iKeyFlag = 2;
      InvalidateRect(hwnd, &rect, TRUE);
      break;
    case 'A':
    case 'a':
      iKeyFlag = 3;
      InvalidateRect(hwnd, &rect, TRUE);
      break;
    case 'L':
    case 'l':
      iKeyFlag = 4;
      InvalidateRect(hwnd, &rect, TRUE);
      break;
    case 'M':
    case 'm':
      iKeyFlag = 5;
      InvalidateRect(hwnd, &rect, TRUE);
      break;
    case 'R':
    case 'r':
      iKeyFlag = 6;
      InvalidateRect(hwnd, &rect, TRUE);
      break;
    case 'B':
    case 'b':
      iKeyFlag = 7;
      InvalidateRect(hwnd, &rect, TRUE);
      break;
    }
    break;
  case WM_PAINT:
    GetClientRect(hwnd, &rect);
    hdc = BeginPaint(hwnd, &ps);
    SetTextColor(hdc, RGB(0, 0, 0));
    switch (iKeyFlag)
    {
    case 0:
      color = RGB(0, 0, 0);
      SetTextColor(hdc, RGB(255, 255, 255));
      break;
    case 1:
      color = RGB(255, 255, 255);
      break;
    case 2:
      color = RGB(255, 255, 0);
      break;
    case 3:
      color = RGB(0, 255, 255);
      break;
    case 4:
      color = RGB(0, 255, 0);
      break;
    case 5:
      color = RGB(255, 0, 255);
      break;
    case 6:
      color = RGB(255, 0, 0);
      break;
    case 7:
      color = RGB(0, 0, 255);
      break;
    }
    hbr = CreateSolidBrush(color);
    SetBkColor(hdc, color);
    FillRect(hdc, &rect, hbr);
    DrawText(hdc, TEXT("Use W Y A L M R B to change color"), -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    EndPaint(hwnd, &ps);
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  }
  return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

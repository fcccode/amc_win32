/*
 *  For AstroMediComp.org
 *  Assignment # 08 by Sachin Bhosale
 *  TV Screen Saver
 */

#include <windows.h>
#include"resource.h"

#define MYTIMER 101

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow)
{
  WNDCLASSEX wndclass;
  TCHAR szAppName[] = TEXT("TVScreenSaver");

  wndclass.cbClsExtra = 0;
  wndclass.cbSize = sizeof(WNDCLASSEX);
  wndclass.cbWndExtra = 0;
  wndclass.lpfnWndProc = WndProc;
  wndclass.lpszClassName = szAppName;
  wndclass.lpszMenuName = NULL;
  wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
  wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
  wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
  wndclass.hInstance = hInstance;
  wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
  wndclass.style = CS_HREDRAW | CS_VREDRAW;

  RegisterClassEx(&wndclass);

  HWND hwnd;
  hwnd = CreateWindow(szAppName
    , TEXT("TV Screen Saver")
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
  return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
  static int iTimerFlag = 0;
  RECT rect, subrect;
  COLORREF color = NULL;
  COLORREF colorarray[7] = { RGB(255, 255, 255)
  ,RGB(255, 255, 0)
  ,RGB(0, 255, 255)
  ,RGB(0, 255, 0)
  ,RGB(255, 0, 255)
  ,RGB(255, 0, 0)
  ,RGB(0, 0, 255) };

  HDC hdc;
  PAINTSTRUCT ps;
  HBRUSH hbr = NULL;
  int i, j, width;
  switch (iMsg)
  {
  case WM_KEYDOWN:
    switch (LOWORD(wParam))
    {
    case VK_ESCAPE:
      PostQuitMessage(0);
      break;
    }
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  case WM_CREATE:
    SetTimer(hwnd, MYTIMER, 200, NULL);
    break;
  case WM_TIMER:
    KillTimer(hwnd, MYTIMER);
    GetClientRect(hwnd, &rect);
    iTimerFlag++;
    InvalidateRect(hwnd, &rect, TRUE);
    SetTimer(hwnd, MYTIMER, 200, NULL);
    break;
  case WM_PAINT:
    KillTimer(hwnd, MYTIMER);
    if (iTimerFlag > 7 && iTimerFlag < 1)
      iTimerFlag = 1;
    GetClientRect(hwnd, &rect);
    hdc = BeginPaint(hwnd, &ps);
    width = (rect.right - rect.left);
    for (i = 0; i < 7; i++)
    {
      subrect.top = rect.top;
      subrect.bottom = rect.bottom;
      subrect.left = i * width / 7;
      subrect.right = subrect.left + width / 7;
      color = colorarray[(i + (iTimerFlag - 1))%7];
      hbr = CreateSolidBrush(color);
      SelectObject(hdc, hbr);
      FillRect(hdc, &subrect, hbr);
    }
    EndPaint(hwnd, &ps);
    SetTimer(hwnd, MYTIMER, 200, NULL);
    break;
  }
  return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}


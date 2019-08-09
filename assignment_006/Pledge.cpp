/*
 *  For AstroMediComp.org
 *  Assignment # 06 by Sachin Bhosale
 *  Pledge
 */

#include<windows.h>
#include"resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
  WNDCLASSEX wndclass;
  TCHAR szAppName[] = TEXT("Pledge");

  wndclass.cbClsExtra = 0;
  wndclass.cbWndExtra = 0;
  wndclass.cbSize = sizeof(WNDCLASSEX);
  wndclass.style = CS_VREDRAW | CS_HREDRAW;
  wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
  wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
  wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
  wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
  wndclass.hInstance = hInstance;
  wndclass.lpfnWndProc = WndProc;
  wndclass.lpszClassName = szAppName;
  wndclass.lpszMenuName = NULL;

  RegisterClassEx(&wndclass);

  HWND hwnd;
  hwnd = CreateWindow(szAppName
    , TEXT("Pledge")
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

  while (GetMessage(&msg,NULL,0,0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return (int(msg.wParam));
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
  static int cyChar;
  HDC hdc;
  PAINTSTRUCT ps;
  TEXTMETRIC tm;
  int i;
  switch (iMsg)
  {
  case WM_SIZE:

    break;
  case WM_CREATE:
    hdc = GetDC(hwnd);
    GetTextMetrics(hdc, &tm);
    cyChar = tm.tmHeight + tm.tmExternalLeading;
    DeleteDC(hdc);
    break;
  case WM_PAINT:
    hdc = BeginPaint(hwnd, &ps);
    SetBkColor(hdc, RGB(0, 0, 0));
    SetTextColor(hdc, RGB(155, 0, 255));
    i = 0;
    TextOut(hdc, 0, cyChar * ++i, TEXT("Pledge"), 8);
    TextOut(hdc, 0, cyChar * ++i, TEXT("- - - - - - - -"), 16);
    SetTextColor(hdc, RGB(255, 155, 0));
    TextOut(hdc, 0, cyChar * ++i, TEXT("India is my country."), 21);
    TextOut(hdc, 0, cyChar * ++i, TEXT("All Indians are my Brothers and Sisters. "), 42);
    TextOut(hdc, 0, cyChar * ++i, TEXT("I love my country "), 19);
    TextOut(hdc, 0, cyChar * ++i, TEXT("and I am proud of "), 19);
    SetTextColor(hdc, RGB(255, 255, 255));
    TextOut(hdc, 0, cyChar * ++i, TEXT("its rich and varied heritage. "), 31);
    TextOut(hdc, 0, cyChar * ++i, TEXT("I shall always strive "), 23);
    TextOut(hdc, 0, cyChar * ++i, TEXT("to be worthy of it. "), 21);
    TextOut(hdc, 0, cyChar * ++i, TEXT("I shall give my parents, teachers and all elders respect"), 57);
    SetTextColor(hdc, RGB(0, 155, 0));
    TextOut(hdc, 0, cyChar * ++i, TEXT("and treat everyone with courtesy. "), 35);
    TextOut(hdc, 0, cyChar * ++i, TEXT("To my country and my people, I pledge my devotion. "), 52);
    TextOut(hdc, 0, cyChar * ++i, TEXT("In their well being and prosperity alone, "), 43);
    TextOut(hdc, 0, cyChar * ++i, TEXT("lies my happiness. "), 20);
    EndPaint(hwnd, &ps);
    break;
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
  }
  return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}

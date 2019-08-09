/*
 *  For AstroMediComp.org
 *  Assignment # 05 by Sachin Bhosale
 *  Icon management and splash screen
 */

#include <windows.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
  WNDCLASSEX wndclass;
  TCHAR szAppName[] = TEXT("MyApp");

  wndclass.cbClsExtra = 0;
  wndclass.cbSize = sizeof(WNDCLASSEX);
  wndclass.cbWndExtra = 0;
  wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_PEN);
  wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
  wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
  wndclass.hIconSm = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON));
  wndclass.lpszClassName = szAppName;
  wndclass.lpfnWndProc = WndProc;
  wndclass.lpszMenuName = NULL;
  wndclass.hInstance = hInstance;
  wndclass.style = CS_HREDRAW | CS_VREDRAW;

  RegisterClassEx(&wndclass);

  HWND hwnd = CreateWindow(szAppName
    , TEXT("Sachin's Window")
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
  static HBITMAP hBitmap;
  BITMAP bitmap;
  static int widthClient, heightClient;
  static int widthBitmap, heightBitmap;
  HDC hdc;
  HDC hdcMem;
  HINSTANCE hInstance;
  PAINTSTRUCT ps;
  switch (iMsg)
  {
  case WM_CREATE:
    hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
    hBitmap = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP));
    GetObject(hBitmap, sizeof(BITMAP), &bitmap);
    widthBitmap = bitmap.bmWidth;
    heightBitmap = bitmap.bmHeight;
    break;
  case WM_SIZE:
    widthClient = LOWORD(lParam);
    heightClient = HIWORD(lParam);
    break;
  case WM_PAINT:
    hdc = BeginPaint(hwnd, &ps);
    hdcMem = CreateCompatibleDC(hdc);
    SelectObject(hdcMem, hBitmap);
    StretchBlt(hdc, 0, 0, widthClient, heightClient, hdcMem, 0, 0, widthBitmap, heightBitmap, MERGECOPY);
    DeleteDC(hdcMem);
    EndPaint(hwnd, &ps);
    break;
  case WM_DESTROY:
    DeleteObject(hBitmap);
    PostQuitMessage(0);
    break;
  case WM_KEYDOWN:
    switch (LOWORD(wParam))
    {
    case VK_ESCAPE:
      DeleteObject(hBitmap);
      PostQuitMessage(0);
      break;
    }
  }
  return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}


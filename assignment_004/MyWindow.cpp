/*
 *  For AstroMediComp.org
 *  Assignment # 04 by Sachin Bhosale
 *  Hello World in windows
 */

#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
  WNDCLASSEX wndclass;
  TCHAR szAppName[] = TEXT("MyApp");

  wndclass.cbClsExtra = 0;
  wndclass.cbSize = sizeof(WNDCLASSEX);
  wndclass.cbWndExtra = 0;
  wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
  wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
  wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
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

  TCHAR szMsg[255];
  TCHAR szCaption[] = TEXT("WndProc Message");
  RECT rect;
  HDC hdc;
  PAINTSTRUCT ps;
  switch (iMsg)
  {
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  case WM_PAINT:
    //Begin the painting i.e. get specialitst
    hdc = BeginPaint(hwnd, &ps);
    //Get rectangle locally
    GetClientRect(hwnd, &rect);
    //Set text color
    SetTextColor(hdc, RGB(0, 255, 0));
    //Set background color
    SetBkColor(hdc, RGB(0, 0, 0));
    //Write Hello World on screen
    DrawText(hdc, TEXT("Hello World!"), -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //Stop the painting i.e. remove the specialist
    EndPaint(hwnd, &ps);
    break;
  }
  return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}


/*
 *  For AstroMediComp.org
 *  Assignment # 03 by Sachin Bhosale
 *  Message Handling 
 */

#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
  MessageBox(NULL, TEXT("WinMain started!"), TEXT("WinMain Message"), MB_OK | MB_ICONINFORMATION);

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
  switch (iMsg)
  {
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  case WM_CREATE:
    wsprintf(szMsg, TEXT("WM_CREATE called!"));
    MessageBox(hwnd, szMsg, szCaption, MB_OK | MB_ICONWARNING);
    break;
  case WM_LBUTTONDOWN:
    wsprintf(szMsg, TEXT("WM_LBUTTONDOWN called!"));
    MessageBox(hwnd, szMsg, szCaption, MB_OK | MB_ICONQUESTION);
    break;
  case WM_KEYDOWN:
    wsprintf(szMsg, TEXT("WM_KEYDOWN called!"));
    MessageBox(hwnd, szMsg, szCaption, MB_OK | MB_ICONHAND);
    switch (LOWORD(wParam))
    {
    case VK_ESCAPE:
      MessageBox(hwnd, TEXT("Window will close now!"), szCaption, MB_OK | MB_ICONINFORMATION);
      DestroyWindow(hwnd);
      break;
    }
    break;
  }
  return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}


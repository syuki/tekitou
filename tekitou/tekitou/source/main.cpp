#include <stdio.h>
#include <Windows.h>

#include "SingleWindowCreator.h"
#include "WindowMessageLooper.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

  SingleWindowCreator window_creator;
  window_creator.EditCreateWindowExParameter([](CreateWindowExParameter& param) {
    // 非クライアント領域のサイズ計算
    RECT client_rect = { 0, 0, 800, 600 };
    AdjustWindowRect(&client_rect, param._window_style, false);
    param._window_width = client_rect.right - client_rect.left;
    param._window_height = client_rect.bottom - client_rect.top;
  });
  window_creator.Create(hInstance, nCmdShow);

  WindowMessageLooper::GetInstance()->MessageLoop([]() {});

  return 0;
}

//EOF
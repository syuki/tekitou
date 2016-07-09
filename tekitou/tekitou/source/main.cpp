#include <stdio.h>
#include <Windows.h>

#include "SingleWindowCreator.h"
#include "MessageLooper.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

  SingleWindowCreator window_creator;
  window_creator.Create(hInstance, nCmdShow);

  MessageLooper::GetInstance()->MessageLoop([]() {});

  return 0;
}

//EOF
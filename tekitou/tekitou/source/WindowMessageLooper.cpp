#include "WindowMessageLooper.h"
#include <Windows.h>

WindowMessageLooper* WindowMessageLooper::_instance = nullptr;

void WindowMessageLooper::MessageLoop(std::function<void()> func) {
  MSG message;
  while (_loop_frag) {
    if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {
      if (message.message == WM_QUIT) {
        break;
      }
      TranslateMessage(&message);
      DispatchMessage(&message);
    }
    else {
      func();
    }
  }
}

//EOF
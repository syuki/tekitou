#include "MessageLooper.h"
#include <Windows.h>

MessageLooper* MessageLooper::_instance = nullptr;

void MessageLooper::MessageLoop(std::function<void()> func) {
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
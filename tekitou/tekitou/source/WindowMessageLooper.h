#pragma once
#ifndef SN_WINDOW_MESSAGE_LOOPER_H_
#define SN_WINDOW_MESSAGE_LOOPER_H_

#include <functional>

class WindowMessageLooper {
public:

  static WindowMessageLooper* GetInstance() {
    if (!_instance) { _instance = new WindowMessageLooper(); }
    return _instance;
  }

  void MessageLoop(std::function<void()> func);

  void SetLoopFlag(bool flag) {
    _loop_frag = flag;
  }

protected:
private:

  static WindowMessageLooper* _instance;

  bool _loop_frag;

  // @brief Constructor
  WindowMessageLooper() : _loop_frag(true) {
  }
};

#endif SN_WINDOW_MESSAGE_LOOPER_H_
//EOF
#pragma once
#ifndef SN_MESSAGE_LOOPER_H_
#define SN_MESSAGE_LOOPER_H_

#include <functional>

class MessageLooper {
public:

  static MessageLooper* GetInstance() {
    if (!_instance) { _instance = new MessageLooper(); }
    return _instance;
  }

  void MessageLoop(std::function<void()> func);

  void SetLoopFlag(bool flag) {
    _loop_frag = flag;
  }

protected:
private:

  static MessageLooper* _instance;

  bool _loop_frag;

  // @brief Constructor
  MessageLooper() : _loop_frag(true) {
  }
};

#endif SN_MESSAGE_LOOPER_H_
//EOF
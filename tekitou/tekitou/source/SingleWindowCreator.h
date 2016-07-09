#pragma once
#ifndef SN_SINGLE_WINDOW_CREATOR_H_
#define SN_SINGLE_WINDOW_CREATOR_H_

#include <Windows.h>
#include <string>
#include <functional>
#include "CreateWindowExParameter.h"

// @class SingleWindowManager
class SingleWindowCreator {
public:

  // @brief Constructor
  SingleWindowCreator();

  void EditWindowClassExParameter(std::function<void(WNDCLASSEX&)> func) {
    func(_window_class_ex);
  }

  void EditCreateWindowExParameter(std::function<void(CreateWindowExParameter&)> func) {
    func(_create_window_ex_parameter);
  }

  void Create(HINSTANCE instance_handle, int show_param);

  HWND GetWindowHandle() { return _window_handle; }
  
protected:
private:

  // Shared parameter
  HINSTANCE    _instance_handle;
  std::wstring _window_class_name;

  WNDCLASSEX _window_class_ex;
  CreateWindowExParameter _create_window_ex_parameter;

  HWND _window_handle;
};

#endif // SN_SINGLE_WINDOW_CREATOR_H_
//EOF
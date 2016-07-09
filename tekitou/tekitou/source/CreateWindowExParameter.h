#pragma once
#ifndef SN_CREATE_WINDOW_EX_PARAMETER_H_
#define SN_CREATE_WINDOW_EX_PARAMETER_H_

#include <Windows.h>
#include <string>

struct CreateWindowExParameter {
public:
  CreateWindowExParameter() :
    _window_ex_style(0),
    _window_class_name(L"DefaultClassName"),
    _window_caption(L"Window"),
    _window_style(WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX ^ WS_THICKFRAME),
    _window_position_x(CW_USEDEFAULT),
    _window_position_y(CW_USEDEFAULT),
    _window_width(800),
    _window_height(600),
    _parent_window(nullptr),
    _menu_handle(nullptr),
    _instance_handle(nullptr),
    _window_parameter(nullptr) {
  }

  DWORD        _window_ex_style;
  std::wstring _window_class_name;
  std::wstring _window_caption;
  DWORD        _window_style;
  int          _window_position_x;
  int          _window_position_y;
  int          _window_width;
  int          _window_height;
  HWND         _parent_window;
  HMENU        _menu_handle;
  HINSTANCE    _instance_handle;
  LPVOID       _window_parameter;
protected:
private:
};

#endif // SN_CREATE_WINDOW_EX_PARAMETER_H_
//EOF
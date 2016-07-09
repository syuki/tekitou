#include "SingleWindowCreator.h"
#include "CreateWindowExParameter.h"

SingleWindowCreator::SingleWindowCreator() :
  _window_class_name(L"DefaultClassName"),
  _instance_handle(nullptr),
  _window_handle(nullptr) {
  ZeroMemory(&_window_class_ex, sizeof(WNDCLASSEX));  
}

void SingleWindowCreator::Create(HINSTANCE instance_handle, int show_param) {
  _instance_handle = instance_handle;

  _create_window_ex_parameter._window_class_name = _window_class_name;
  _create_window_ex_parameter._instance_handle = _instance_handle;
  _window_class_ex.hInstance = _instance_handle;
  _window_class_ex.lpszClassName = _window_class_name.c_str();

  _window_class_ex.cbSize = sizeof(WNDCLASSEX);
  _window_class_ex.lpfnWndProc = [](HWND h, UINT m, WPARAM w, LPARAM l)->LRESULT {
    switch (m) {
    case WM_CLOSE:
      DestroyWindow(h);
      return 0;
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    default:
      break;
    }
    return DefWindowProc(h, m, w, l);
  };

  RegisterClassEx(&_window_class_ex);

  _window_handle = CreateWindowEx(
    _create_window_ex_parameter._window_ex_style,
    _create_window_ex_parameter._window_class_name.c_str(),
    _create_window_ex_parameter._window_caption.c_str(),
    _create_window_ex_parameter._window_style,
    _create_window_ex_parameter._window_position_x,
    _create_window_ex_parameter._window_position_y,
    _create_window_ex_parameter._window_width,
    _create_window_ex_parameter._window_height,
    _create_window_ex_parameter._parent_window,
    _create_window_ex_parameter._menu_handle,
    _create_window_ex_parameter._instance_handle,
    _create_window_ex_parameter._window_parameter
    );

  ShowWindow(_window_handle, show_param);
  UpdateWindow(_window_handle);
}

//EOF
#pragma once
#include "imgui.h"
#include <qglobal.h>
ImGuiKey VirtualKeyToImGuiKey(unsigned int wParam);

//Most of the key mapping were copied from ImGUI backends implem see https://github.com/ocornut/imgui/tree/master/backends
#ifdef Q_OS_WINDOWS
    #include "platform/windows_key_mappings.cpp"
#endif

#ifdef Q_OS_ANDROID
    #include "platform/android_key_mappings.cpp"
#endif

#ifdef Q_OS_MACOS
    #include "platform/macosx_key_mappings.cpp"
#endif

#ifdef Q_OS_LINUX
    #include "platform/linux_key_mappings.cpp"
#endif




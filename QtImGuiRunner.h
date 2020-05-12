#pragma once
#include "imgui.h"

#include <functional>
#include <string>

namespace QtImGuiRunner {

// ImGuiRunner::run() can call this type of function
typedef std::function<void(void)> GuiLoopFunction;

// ImGuiRunner::run_with_quit() can call this type of function
// it shall return true when exit is required
typedef std::function<bool(void)> GuiLoopWithExitFunction;


// Display parameters
struct AppWindowParams
{
    AppWindowParams(
            std::string windowTitle = "",
            int windowWidth = 800, int windowHeight = 600,
            bool provideFullBackgroundWindow = true
            )
        : window_title(windowTitle)
        , window_width(windowWidth)
        , window_height(windowHeight)
        , provide_full_background_window(provideFullBackgroundWindow)
    {
    }

    std::string window_title = "";
    int window_width = 800;
    int window_height = 600;
    bool show_maximized = false;
    bool show_fullscreen = false;

    bool provide_full_background_window = true;
    ImVec4 clear_color = ImColor(114, 144, 154);
};

int Run(
    GuiLoopFunction guiLoopFunction,
    const AppWindowParams &params,
    int argc = 0,
    char **argv = nullptr
    );

int RunWithQuit(
    GuiLoopWithExitFunction guiLoopFunction,
    const AppWindowParams &params,
    int argc = 0,
    char **argv = nullptr
    );

// void BringMainWindowToTop();

} // namespace QtImGuiRunner

#include <QtImGuiRunner.h>

struct ApplicationState
{
    double f =  0.5;
    bool show_another_window = false;
    bool show_test_window = false;
};

bool GuiLoop(ApplicationState &state)
{
    // 1. Show a simple window
    // Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets appears in a window automatically called "Debug"
    {
        static float f = 0.0f;
        ImGui::Text("Hello, world!");
        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
        if (ImGui::Button("Test Window")) state.show_test_window ^= 1;
        if (ImGui::Button("Another Window")) state.show_another_window ^= 1;
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    }

    // 2. Show another simple window, this time using an explicit Begin/End pair
    if (state.show_another_window)
    {
        ImGui::SetNextWindowSize(ImVec2(200,100), ImGuiCond_FirstUseEver);
        ImGui::Begin("Another Window", &state.show_another_window);
        ImGui::Text("Hello");
        ImGui::End();
    }

    // 3. Show the ImGui test window. Most of the sample code is in ImGui::ShowTestWindow()
    if (state.show_test_window)
    {
        ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
        ImGui::ShowDemoWindow();
    }

    // 4. Quit by returning true
    if (ImGui::Button("Quit"))
        return true;

    return false;
}


int main()
{
    //
    // First example:
    // - We create a lambda that capture an application context
    // - By default a full background window will be provided
    //
    // Since we are calling QtImGuiRunner::RunWithQuit, we can add a "Quit" button
    // To cause the application to quit, simply return true at the end of the GuiLoop function or lambda
    QtImGuiRunner::AppWindowParams params;
    params.window_title = "Hello";
    params.show_maximized = true;
    params.provide_full_background_window = false;
    ApplicationState state;
    auto gui_loop_lambda = [&state]() {
        return GuiLoop(state);
    };
    QtImGuiRunner::RunWithQuit(gui_loop_lambda, params);
}

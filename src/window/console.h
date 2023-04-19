//
// Created by Dmitry Savosh on 19.04.2023.
//

#ifndef IMGUI_GLFW_CONSOLE_H
#define IMGUI_GLFW_CONSOLE_H

#include "imgui/imgui.h"

struct AppConsole
{
    char InputBuf[256];
    ImVector<char*> Items;
    ImVector<const char*> Commands;
    ImVector<char*> History;
    int HistoryPos; // -1: new line, 0..History.Size-1 browsing history.
    ImGuiTextFilter Filter;
    bool AutoScroll;
    bool ScrollToBottom;

    AppConsole();
    ~AppConsole();
    void ClearLog();
    void AddLog( const char* fmt, ... ) IM_FMTARGS(2);
    void Draw( const char* title, bool* p_open );
    void ExecCommand( const char* command_line );
    int TextEditCallback( ImGuiInputTextCallbackData* data );
};

void ShowAppConsole( bool* p_open );

#endif // IMGUI_GLFW_CONSOLE_H

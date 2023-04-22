//
// Created by Dmitry Savosh on 19.04.2023.
//

#ifndef IMGUI_GLFW_CONSOLE_H
#define IMGUI_GLFW_CONSOLE_H

#include "imgui/imgui.h"

struct AppConsoleColors
{
    ImVec4 ErrorColor   = ImVec4( 1.0f, 0.3f, 0.3f, 1.0f );
    ImVec4 WarningColor = ImVec4( 1.0f, 0.8f, 0.6f, 1.0f );
};

struct AppConsoleWindow
{
    AppConsoleColors ConsoleColors;

    char InputBuf[256]{};
    ImVector<char*> Items;
    ImVector<const char*> Commands;
    ImVector<char*> History;
    int HistoryPos = -1; // -1: new line, 0..History.Size-1 browsing history.
    ImGuiTextFilter Filter;
    bool AutoScroll     = true;
    bool ScrollToBottom = false;

    AppConsoleWindow();
    ~AppConsoleWindow();
    void ClearLog();
    void Add( const char* fmt, ... ) IM_FMTARGS( 2 );
    void Draw( const char* title, bool* p_open );
    void ExecCommand( const char* command_line );
    int TextEditCallback( ImGuiInputTextCallbackData* data );
    void Help();
};

#endif // IMGUI_GLFW_CONSOLE_H

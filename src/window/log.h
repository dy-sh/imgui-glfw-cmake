//
// Created by Dmitry Savosh on 19.04.2023.
//

//-----------------------------------------------------------------------------
// Debug log
//-----------------------------------------------------------------------------
// Usage:
//  include "log.h;
//
//  LOG("Hello %d world\n", 123);
//  or:
//  AppLog::Add("Hello %d world\n", 123);

#ifndef IMGUI_GLFW_LOG_H
#define IMGUI_GLFW_LOG_H

#include "imgui/imgui.h"

#define LOG(fmt, ...) AppLog::Add(fmt, ##__VA_ARGS__)

struct AppLog
{
private:
    AppLog(){};
    AppLog(const AppLog&) = delete;
    AppLog& operator=(const AppLog&) = delete;

public:
    static AppLog* get();

    ImGuiTextBuffer Buf;
    ImGuiTextFilter Filter;
    ImVector<int> LineOffsets; // Index to lines offset. We maintain this with AddLog() calls.
    bool AutoScroll;           // Keep scrolling if already at the bottom.

    void Clear();
    void AddLog( const char* fmt, ... )  IM_FMTARGS( 2 );
    void Draw( const char* title, bool* p_open = NULL );

    static void Add( const char* fmt, ... ) ;
};

void ShowAppLog( bool* p_open );

#endif // IMGUI_GLFW_LOG_H

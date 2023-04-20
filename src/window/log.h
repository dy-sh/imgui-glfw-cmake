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

#include "../utils.h"
#include "imgui/imgui.h"
#include <sstream>
#include <string>
#include <vector>

#define LOG( fmt, ... ) AppLog::Add( fmt, ##__VA_ARGS__ )

enum class LogLevel
{
    Info,
    Warn,
    Error
};

ENUM_TO_STRING( LogLevel, "Info", "Warn", "Error" )

struct AppLog
{
private:
    AppLog(){};
    AppLog( const AppLog& )            = delete;
    AppLog& operator=( const AppLog& ) = delete;

public:
    static AppLog* get();

    ImGuiTextBuffer Buf;
    ImGuiTextFilter Filter;
    ImVector<int> LineOffsets; // Index to lines offset. We maintain this with AddLog() calls.
    bool AutoScroll;           // Keep scrolling if already at the bottom.

    void Clear();
    void AddLog( LogLevel level, const char* fmt, ... ) IM_FMTARGS( 3 );
    void Draw( bool* p_open = NULL );

    static void Add( const char* fmt, ... );
    static void Add( LogLevel level, const char* fmt, ... );
    static void Show( bool* p_open = NULL );
};



#endif // IMGUI_GLFW_LOG_H

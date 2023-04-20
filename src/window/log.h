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
//  AppLog::Add(LogLevel::War, "Hello %d world\n", 123);

#ifndef IMGUI_GLFW_LOG_H
#define IMGUI_GLFW_LOG_H

#include "../utils.h"
#include "imgui/imgui.h"
#include <sstream>
#include <string>

#define LOG( fmt, ... ) AppLog::Add( fmt, ##__VA_ARGS__ )

enum class LogLevel
{
    Inf,
    War,
    Err
};

ENUM_TO_STRING( LogLevel, "Inf", "War", "Err" )

struct AppLogColors
{
    ImVec4 ErrorColor   = ImVec4( 1.0f, 0.3f, 0.3f, 1.0f );
    ImVec4 WarningColor = ImVec4( 1.0f, 0.8f, 0.6f, 1.0f );
};

struct AppLogWindow
{
    AppLogColors LogColors;

    ImGuiTextBuffer Buf;
    ImGuiTextFilter Filter;
    ImVector<int> LineOffsets; // Index to lines offset. We maintain this with AddMessage() calls.
    bool AutoScroll;           // Keep scrolling if already at the bottom.

    void Clear();
    void Add( LogLevel level, const char* fmt, ... ) IM_FMTARGS( 3 );
    void Draw( const char* title, bool* p_open = NULL );
    void DrawColorizedLine( const char* line_start, const char* line_end ) const;
};

// Singleton
struct AppLog
{
private:
    AppLog(){};
    AppLog( const AppLogWindow& )            = delete;
    AppLog& operator=( const AppLogWindow& ) = delete;

public:
    static AppLogWindow* get();

    static void Add( const char* fmt, ... );
    static void Add( LogLevel level, const char* fmt, ... );
    static void Draw( bool* p_open = NULL );
};

#endif // IMGUI_GLFW_LOG_H

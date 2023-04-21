//
// Created by Dmitry Savosh on 21.04.2023.
//

#ifndef IMGUI_APP_DEBUG_H
#define IMGUI_APP_DEBUG_H

#include "debug/log.h"
#include <iomanip>

#define LOG( fmt, ... ) AppLog::Add( fmt, ##__VA_ARGS__ )

enum class LogLevel
{
    inf,
    wrn,
    err
};

ENUM_TO_STRING( LogLevel, "inf", "wrn", "err" )


//-----------------------------------------------------------------------------
// Debug log
//-----------------------------------------------------------------------------
// Usage:
//  include "debug.h;
//
//  LOG("Hello %d world\n", 123);
//  AppLog::Add(LogLevel::wrn, "Hello %d world\n", 123);

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






#endif // IMGUI_APP_DEBUG_H

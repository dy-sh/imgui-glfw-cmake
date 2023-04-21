//
// Created by Dmitry Savosh on 21.04.2023.
//

#include "debug.h"
AppLogWindow* AppLog::get()
{
    static AppLogWindow* instance;

    if( !instance )
        instance = new AppLogWindow();

    return instance;
}

void AppLog::Add( const char* fmt, ... )
{
    auto log = AppLog::get();

    va_list args;
    va_start( args, fmt );

    int length = vsnprintf( nullptr, 0, fmt, args ); // Determine the length of the formatted string
    std::string buffer( length, '\0' );              // Allocate a buffer to store the formatted string
    vsnprintf( &buffer[0], length + 1, fmt, args );  // Format the string into the buffer
    Add( LogLevel::inf, "%s", buffer.c_str() ); // Add the formatted string to the log

    va_end( args );
}

void AppLog::Add( LogLevel level, const char* fmt, ... )
{
    auto log = AppLog::get();

    std::ostringstream oss;

    // append LogLevel
    oss << "[" << ToString( level ) << "] ";
    // append current time
    oss << "[" << std::fixed << std::setprecision( 2 ) << ImGui::GetTime() << "] ";
    // append message
    oss << fmt << "\n";

    std::string s = oss.str();
    fmt           = s.c_str();

    va_list args;
    va_start( args, fmt );

    int length = vsnprintf( nullptr, 0, fmt, args ); // Determine the length of the formatted string
    std::string buffer( length, '\0' );              // Allocate a buffer to store the formatted string
    vsnprintf( &buffer[0], length + 1, fmt, args );  // Format the string into the buffer
    log->Add( "%s", buffer.c_str() );                // Add the formatted string to the log

    va_end( args );
}

void AppLog::Draw( bool* p_open )
{
    auto log = AppLog::get();
    log->Draw( "Log", p_open );
}


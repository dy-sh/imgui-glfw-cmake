//
// Created by Dmitry Savosh on 20.04.2023.
//

#ifndef IMGUI_APP_UTILS_H
#define IMGUI_APP_UTILS_H

/*  -------- enum to string ---------
Usage:

enum class LogLevel
{
    Info,
    Warn,
    Error
};

ENUM_TO_STRING( LogLevel, "Info", "Warn", "Error" )


*/

#define ENUM_TO_STRING(EnumType, ...) \
    inline std::string ToString(EnumType value) \
    { \
        static const char* const values[] = { __VA_ARGS__ }; \
        return values[static_cast<int>(value)]; \
    }

#endif // IMGUI_APP_UTILS_H

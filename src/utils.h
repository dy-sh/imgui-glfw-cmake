//
// Created by Dmitry Savosh on 20.04.2023.
//

#ifndef IMGUI_APP_UTILS_H
#define IMGUI_APP_UTILS_H

/*  -------- enum to string ---------
Usage:

enum class LogLevel
{
    Inf,
    War,
    Err
};

ENUM_TO_STRING( LogLevel, "Inf", "War", "Err" )


*/

#define ENUM_TO_STRING(EnumType, ...) \
    inline const char* ToString(EnumType value) \
    { \
        static const char* const values[] = { __VA_ARGS__ }; \
        return values[static_cast<int>(value)]; \
    }

#endif // IMGUI_APP_UTILS_H

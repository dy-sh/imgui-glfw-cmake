//
// Created by Dmitry Savosh on 19.04.2023.
//

#ifndef IMGUI_GLFW_LOG_H
#define IMGUI_GLFW_LOG_H

#include "imgui/imgui.h"

//-----------------------------------------------------------------------------
// [SECTION] Example App: Debug Log / ShowExampleAppLog()
//-----------------------------------------------------------------------------

// Usage:
//  static AppLog my_log;
//  my_log.AddLog("Hello %d world\n", 123);
//  my_log.Draw("title");
struct AppLog
{
private:
    AppLog(){};
    AppLog(const AppLog&) = delete;
    AppLog& operator=(const AppLog&) = delete;

public:
    static AppLog* get() {
        static AppLog* instance;

        if (!instance) {
            instance = new AppLog();
            instance->AutoScroll = true;
            instance->Clear();
        }
        return instance;
    }

    ImGuiTextBuffer Buf;
    ImGuiTextFilter Filter;
    ImVector<int> LineOffsets; // Index to lines offset. We maintain this with AddLog() calls.
    bool AutoScroll;           // Keep scrolling if already at the bottom.

    void Clear();
    void AddLog( const char* fmt, ... ) ;//IM_FMTARGS( 2 );
    void Draw( const char* title, bool* p_open = NULL );

};

void ShowAppLog( bool* p_open );

#endif // IMGUI_GLFW_LOG_H

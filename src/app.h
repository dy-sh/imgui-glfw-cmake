//
// Created by Dmitry Savosh on 19.04.2023.
//

#ifndef IMGUI_GLFW_APP_H
#define IMGUI_GLFW_APP_H

#include "imgui/imgui.h"
#include "window/console.h"
#include "window/log.h"
#include "window/login_window.h"
#include "window/main_window.h"

bool show_debug_toolbar = true;

bool show_login_window = false;
bool show_main_window  = true;

bool show_app_console      = false;
bool show_app_log          = false;
bool show_app_metrics      = false;
bool show_app_debug_log    = false;
bool show_app_stack_tool   = false;
bool show_app_about        = false;
bool show_app_style_editor = false;
bool show_demo_window      = false;

extern GLFWwindow* g_window;

static void ShowDebugToolbar();

static void ShowWindows()
{
    if( ImGui::IsKeyPressed( ImGuiKey::ImGuiKey_Escape ) )
    {
        glfwSetWindowShouldClose( g_window, true );
    }

    if( show_debug_toolbar )
        ShowDebugToolbar();

    if( show_login_window )
    {
        ShowLoginWindow();
    }

    if( show_main_window && !show_login_window )
        ShowMainWindow();

    if( show_demo_window )
        ImGui::ShowDemoWindow( &show_demo_window );

    if( show_app_console )
        ShowAppConsole( &show_app_console );
    if( show_app_log )
        AppLog::Draw( &show_app_log );
    if( show_app_metrics )
        ImGui::ShowMetricsWindow( &show_app_metrics );
    if( show_app_debug_log )
        ImGui::ShowDebugLogWindow( &show_app_debug_log );
    if( show_app_stack_tool )
        ImGui::ShowStackToolWindow( &show_app_stack_tool );
    if( show_app_about )
        ImGui::ShowAboutWindow( &show_app_about );
    if( show_app_style_editor )
    {
        ImGui::Begin( "Dear ImGui Style Editor", &show_app_style_editor );
        ImGui::ShowStyleEditor();
        ImGui::End();
    }
}

static void ShowDebugToolbar()
{
    if( ImGui::BeginMainMenuBar() )
    {
        if( ImGui::BeginMenu( "Debug" ) )
        {
            ImGui::MenuItem( "Console", NULL, &show_app_console );
            ImGui::MenuItem( "Log", NULL, &show_app_log );
            ImGui::MenuItem( "Metrics/Debugger", NULL, &show_app_metrics );
            ImGui::MenuItem( "Debug Log", NULL, &show_app_debug_log );
            ImGui::MenuItem( "Stack Tool", NULL, &show_app_stack_tool );
            ImGui::MenuItem( "Style Editor", NULL, &show_app_style_editor );
            ImGui::MenuItem( "About Dear ImGui", NULL, &show_app_about );
            ImGui::MenuItem( "Demo Window", NULL, &show_demo_window );
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

#endif // IMGUI_GLFW_APP_H

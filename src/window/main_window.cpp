//
// Created by Dmitry Savosh on 18.04.2023.
//

#include "main_window.h"
#include "imgui/imgui.h"
#include "log.h"

bool maximize_main_window = false;

extern bool show_login_window;
extern bool show_main_window;
extern bool show_app_log;

static float OriginalWindowRounding;

void MaximizeMainWindow()
{
#ifdef IMGUI_HAS_VIEWPORT
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos( viewport->WorkPos );
    ImGui::SetNextWindowSize( viewport->WorkSize );
    ImGui::SetNextWindowViewport( viewport->ID );
#else
    ImGui::SetNextWindowPos( ImVec2( 0.0f, 0.0f ) );
    ImGui::SetNextWindowSize( ImGui::GetIO().DisplaySize );
#endif

    ImGuiStyle* style      = &ImGui::GetStyle();
    OriginalWindowRounding = style->WindowRounding;
    style->WindowRounding  = 0.0;
}

void FinishMaximizeMainWindow()
{
    ImGuiStyle* style     = &ImGui::GetStyle();
    style->WindowRounding = OriginalWindowRounding;
}

void ShowMainWindow()
{
    if( maximize_main_window )
    {
        MaximizeMainWindow();
        ImGui::Begin(
            "Main", &show_main_window,
            ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus );
    }
    else
    {
        ImGui::Begin( "Main", NULL, ImGuiWindowFlags_NoBringToFrontOnFocus );
    }

    static int counter = 0;
    ImGui::Text( "Hello, world!" );

    if( ImGui::Button( "Authorization" ) )
    {
        show_login_window = true;
    }

    if( ImGui::Button( "Simple Button" ) )
    {
        counter++;
    }
    ImGui::SameLine();
    ImGui::Text( "counter = %d", counter );

    if( ImGui::Button( "Test Log" ) )
    {
        LOG( "Hello %d world\n", 123 );
        show_app_log = true;
    }

    ImGui::End();

    if( maximize_main_window )
        FinishMaximizeMainWindow();
}

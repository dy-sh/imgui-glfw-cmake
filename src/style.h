//
// Created by Dmitry Savosh on 19.04.2023.
//

#ifndef IMGUI_GLFW_STYLE_H
#define IMGUI_GLFW_STYLE_H
#include "imgui/imgui.h"

void apply_custom_style( ImVec4& bg_color, ImGuiStyle* dst = NULL )
{
    ImGuiStyle* style = dst ? dst : &ImGui::GetStyle();
    ImVec4* colors    = style->Colors;

    style->WindowPadding     = ImVec2( 15, 15 );
    style->WindowRounding    = 10.0;
    style->FramePadding      = ImVec2( 5, 5 );
    style->ItemSpacing       = ImVec2( 12, 8 );
    style->ItemInnerSpacing  = ImVec2( 8, 6 );
    style->IndentSpacing     = 25.0;
    style->ScrollbarSize     = 15.0;
    style->ScrollbarRounding = 15.0;
    style->GrabMinSize       = 15.0;
    style->GrabRounding      = 7.0;
    style->FrameRounding     = 6.0;

    colors[ImGuiCol_Text]                 = ImVec4( 0.95, 0.96, 0.98, 1.00 );
    colors[ImGuiCol_TextDisabled]         = ImVec4( 0.36, 0.42, 0.47, 1.00 );
    colors[ImGuiCol_WindowBg]             = ImVec4( 43.f / 256, 45.f / 256, 48.f / 256, 1.f );
    colors[ImGuiCol_ChildBg]              = ImVec4( 43.f / 256, 45.f / 256, 48.f / 256, 1.f );
    colors[ImGuiCol_MenuBarBg]            = ImVec4( 0.30, 0.31, 0.32, 1.00 );
    colors[ImGuiCol_PopupBg]              = ImVec4( 0.30, 0.31, 0.32, 1.00 );
    colors[ImGuiCol_Border]               = ImVec4( 0.05, 0.05, 0.05, 1.00 );
    colors[ImGuiCol_BorderShadow]         = ImVec4( 0.50, 0.50, 0.50, 0.50 );
    colors[ImGuiCol_FrameBg]              = ImVec4( 60.f / 256, 62.f / 256, 66.f / 256, 1.f );
    colors[ImGuiCol_FrameBgHovered]       = ImVec4( 68.f / 256, 71.f / 256, 77.f / 256, 1.f );
    colors[ImGuiCol_FrameBgActive]        = ImVec4( 78.f / 256, 81.f / 256, 87.f / 256, 1.f );
    colors[ImGuiCol_TitleBg]              = ImVec4( 33.f / 256, 35.f / 256, 38.f / 256, 1.f );
    colors[ImGuiCol_TitleBgCollapsed]     = ImVec4( 33.f / 256, 35.f / 256, 38.f / 256, 1.f );
    colors[ImGuiCol_TitleBgActive]        = ImVec4( 63.f / 256, 65.f / 256, 68.f / 256, 1.f );
    colors[ImGuiCol_ScrollbarBg]          = ImVec4( 0.02, 0.02, 0.02, 0.39 );
    colors[ImGuiCol_ScrollbarGrab]        = ImVec4( 0.30, 0.31, 0.32, 1.00 );
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4( 0.40, 0.41, 0.42, 1.00 );
    colors[ImGuiCol_ScrollbarGrabActive]  = ImVec4( 0.06, 0.53, 0.98, 1.00 );
    colors[ImGuiCol_CheckMark]            = ImVec4( 0.06, 0.53, 0.98, 1.00 );
    colors[ImGuiCol_SliderGrab]           = ImVec4( 0.28, 0.56, 1.00, 1.00 );
    colors[ImGuiCol_SliderGrabActive]     = ImVec4( 0.37, 0.61, 1.00, 1.00 );
    colors[ImGuiCol_Button]               = ImVec4( 78.f / 256, 81.f / 256, 87.f / 256, 1.f );
    colors[ImGuiCol_ButtonHovered]        = ImVec4( 0.28, 0.56, 1.00, 1.00 );
    colors[ImGuiCol_ButtonActive]         = ImVec4( 0.06, 0.53, 0.98, 1.00 );
    colors[ImGuiCol_Header]               = ImVec4( 0.20, 0.25, 0.29, 0.55 );
    colors[ImGuiCol_HeaderHovered]        = ImVec4( 0.26, 0.59, 0.98, 0.80 );
    colors[ImGuiCol_HeaderActive]         = ImVec4( 0.26, 0.59, 0.98, 1.00 );
    colors[ImGuiCol_ResizeGrip]           = ImVec4( 43.f / 256, 45.f / 256, 48.f / 256, 1.f );
    colors[ImGuiCol_ResizeGripHovered]    = ImVec4( 43.f / 256, 45.f / 256, 48.f / 256, 1.f );
    colors[ImGuiCol_ResizeGripActive]     = ImVec4( 0.06, 0.53, 0.98, 1.00 );
    colors[ImGuiCol_PlotLines]            = ImVec4( 0.61, 0.61, 0.61, 1.00 );
    colors[ImGuiCol_PlotLinesHovered]     = ImVec4( 1.00, 0.43, 0.35, 1.00 );
    colors[ImGuiCol_PlotHistogram]        = ImVec4( 0.90, 0.70, 0.00, 1.00 );
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4( 1.00, 0.60, 0.00, 1.00 );
    colors[ImGuiCol_TextSelectedBg]       = ImVec4( 0.25, 1.00, 0.00, 0.43 );

    bg_color = ImVec4( 29.f / 256, 31.f / 256, 33.f / 256, 1.f );

    ImGuiIO& io      = ImGui::GetIO();
    ImFont* mainfont = io.Fonts->AddFontFromFileTTF(
        "C:\\Windows\\Fonts\\JetBrainsMono[wght].ttf", 20.f, nullptr, io.Fonts->GetGlyphRangesCyrillic() );
    IM_ASSERT( mainfont != NULL );
}

#endif // IMGUI_GLFW_STYLE_H

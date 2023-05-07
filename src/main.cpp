//
// Created by Dmitry Savosh on 19.04.2023.
//

#include <imgui/imgui.h>
#include <imgui_impl/glfw.h>
#include <imgui_impl/opengl3.h>
#include <imgui_impl/fonts.hpp>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <glad/glad.h> // order is important!

#include <GLFW/glfw3.h> // order is important!

#include <fmt/format.h>

#include <stdio.h>
#include <cmath>

#include "AppGUI.h"

GLFWwindow* g_window;
static ImVec4 bg_color;

#ifdef __EMSCRIPTEN__
EM_JS( int, canvas_get_width, (), { return Module.canvas.width; } );
EM_JS( int, canvas_get_height, (), { return Module.canvas.height; } );
EM_JS( void, resizeCanvas, (), { js_resizeCanvas(); } );
#endif

AppGUI app;

static void glfw_error_callback( int error, const char* description )
{
    fmt::print( "Glfw Error {}: {}\n", error, description );
}

static void draw_gl( int display_w, int display_h )
{
    glViewport( 0, 0, display_w, display_h );
    glClearColor( bg_color.x, bg_color.y, bg_color.z, bg_color.w );
    glClear( GL_COLOR_BUFFER_BIT );
}

// Helper to display a little (?) mark which shows a tooltip when hovered.
// In your own code you may want to display an actual icon if you are using a merged icon fonts (see docs/FONTS.txt)

void loop()
{
#ifdef __EMSCRIPTEN__
    int width  = canvas_get_width();
    int height = canvas_get_height();

    glfwSetWindowSize( g_window, width, height );
#endif

    glfwPollEvents();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    app.Render();

    ImGui::Render();

    int display_w, display_h;
    glfwMakeContextCurrent( g_window );
    glfwGetFramebufferSize( g_window, &display_w, &display_h );

    draw_gl( display_w, display_h );

    ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );

    glfwSwapBuffers( g_window );
}

int init()
{
    glfwSetErrorCallback( glfw_error_callback );

    if( !glfwInit() )
    {
        fmt::print( "Failed to initialize GLFW\n" );
        return 1;
    }

    glfwWindowHint( GLFW_SAMPLES, 4 ); // 4x antialiasing
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 2 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE ); // We don't want the old OpenGL
//     glfwWindowHint( GLFW_DECORATED, false );
//     glfwWindowHint( GLFW_RESIZABLE, true );
#if __APPLE__
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
#endif

    // Open a window and create its OpenGL context
    int canvasWidth  = 1280;
    int canvasHeight = 720;
    g_window         = glfwCreateWindow( canvasWidth, canvasHeight, "ImGui App", NULL, NULL );
    glfwMakeContextCurrent( g_window );
    glfwSwapInterval( 1 ); // Enable vsync

    if( g_window == NULL )
    {
        fmt::print( "Failed to open GLFW window.\n" );
        glfwTerminate();
        return -1;
    }

    gladLoadGL( (GLADloadfunc)glfwGetProcAddress ); // Initialize GLAD

    // Setup Dear ImGui binding
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io    = ImGui::GetIO();
    io.IniFilename = "imgui_state.ini";

    ImGui_ImplGlfw_InitForOpenGL( g_window, false );
    ImGui_ImplOpenGL3_Init();

    app.ApplyStyle( bg_color );

    // Cursor callbacks
    glfwSetMouseButtonCallback( g_window, ImGui_ImplGlfw_MouseButtonCallback );
    glfwSetScrollCallback( g_window, ImGui_ImplGlfw_ScrollCallback );
    glfwSetKeyCallback( g_window, ImGui_ImplGlfw_KeyCallback );
    glfwSetCharCallback( g_window, ImGui_ImplGlfw_CharCallback );

#ifdef __EMSCRIPTEN__
    resizeCanvas();
#endif

    return 0;
}

void quit()
{
    // Stop the ImGui rendering loop
    glfwSetWindowShouldClose( g_window, true );

    // Free up resources used by ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // Destroy the GLFW window
    glfwDestroyWindow( g_window );

    // Terminate GLFW
    glfwTerminate();
}

extern "C" int main( int argc, char** argv )
{
    if( init() != 0 )
        return 1;

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop( loop, 0, 1 );
#else
    while( !app.should_close && !glfwWindowShouldClose( g_window ) )
    {
        loop();
    }
#endif

    quit();

    return 0;
}

extern "C" int WinMain( int argc, char** argv )
{
    return main( argc, argv );
}
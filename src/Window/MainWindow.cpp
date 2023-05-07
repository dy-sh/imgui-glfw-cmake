//
// Created by Dmitry Savosh on 18.04.2023.
//

#include "MainWindow.h"
#include "../Tools/Debug.h"
#include "imgui/imgui.h"
#include "WindowManager.h"
#include "../Tools/Console.h"
#include "../Tools/Log.h"

using namespace std;


void MainWindow::RenderContent()
{
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    
    static int counter = 0;
    ImGui::Text("Alt + C - Console");
    ImGui::Text("Alt + X - Log");
    ImGui::Text("Esc - Quit");

    if (ImGui::Button("Simple Button"))
    {
        counter++;
    }
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);

    if (ImGui::Button("Authorization"))
    {
        if (windowManager)
        {
            if (Window* loginWindow = windowManager->GetWindowByTitle("Login"))
            {
                loginWindow->ToggleVisible();
            }
        }
    }

    if (ImGui::Button("Add Log message"))
    {
        LOG("Simple %d message example", 123);
        LOG(LogLevel::wrn, "wrn message example");
        LogWindow::Add(LogLevel::err, "err message example");
       
        if (Window* log = static_cast<LogWindow*>(windowManager->GetWindowByTitle("Log")))
        {
            log->SetVisible(true);
        }
    }

    if (ImGui::Button("Add Console message"))
    {
        CONSOLE("Simple %d message example", 123);
        CONSOLE(LogLevel::wrn, "wrn message example");
        ConsoleWindow::Add(LogLevel::err, "err message example");

        if (Window* log = static_cast<LogWindow*>(windowManager->GetWindowByTitle("Console")))
        {
            log->SetVisible(true);
        }
    }
}

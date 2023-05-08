//
// Created by Dmitry Savosh on 18.04.2023.
//

#pragma once

#include "imgui/imgui.h"
#include "Window.h"


class LoginWindow : public ModalWindow
{
public:
    static constexpr int LOGIN_LENGTH = 24;
    static constexpr int PASS_LENGTH = 24;

    std::string correct_login = "1";
    std::string correct_password = "";

    LoginWindow(const std::string& title, bool visible)
        : ModalWindow(title, visible, {400,230})
    {
    }


    void SetLoginWindowPos();


    void RenderContent() override;

private:
    bool CheckCredentials(char login[LOGIN_LENGTH], char password[PASS_LENGTH]);
};
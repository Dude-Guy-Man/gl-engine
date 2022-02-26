#pragma once
#include <GLFW/glfw3.h>
#ifndef _MAINGAME_H
#define _MAINGAME_H

class MainGame
{
    public:
    MainGame(const char* name, int p_w, int p_h)
    {
        success = InitGLFW(name, p_w, p_h);
        if(success)
            success = InitGl();
    }

    int Success()
    {
        return success;
    }

    void Run();

    private:
    GLFWwindow* window;

    void Logic(float elapsedTime, bool* finished);

    int InitGLFW(const char* name, int p_w, int p_h);
    int InitGl();

    int success;
    int width;
    int height;

};

#endif
#include <iostream>
#include <GLFW/glfw3.h>
#include <ctime>
#include <thread>
#include "MainGame.h"

void MainGame::Run()
{
    clock_t begin;
    clock_t end;

    bool threadFinished = false;
    float oneFrame = CLOCKS_PER_SEC / 60;
    oneFrame = 1 / oneFrame;
    std::thread gameThread(Logic, 1.0f, &threadFinished);
    begin = clock();

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        if(threadFinished)
        {
            end = clock();
            threadFinished = 0;
            float elapsedTime = (end - begin) * oneFrame;
            gameThread = std::thread(Logic, elapsedTime, &threadFinished);
            begin = clock();
        }

        glfwSwapBuffers(window);
    }
}

void MainGame::Logic(float elapsedTime, bool* finished)
{
    finished = true;
}

int MainGame::InitGLFW(const char* name, int p_w, int p_h)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(p_w, p_h, name, 0, 0);
    if(!window)
    {
        std::cout << "Your computer doesn't support OpenGL" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    width = p_w;
    height = p_h;

    return 1;
}

int MainGame::InitGl()
{
    return 1;
}
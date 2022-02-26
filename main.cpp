#include <iostream>
#define GLFW_DLL
#include <GLFW/glfw3.h>
#include "MainGame.h"

int main()
{
    if(!glfwInit())
    {
        std::cout << "Couldn't init GLFW\n";
    }
    
    MainGame game("Lol", 500, 500);
    if(!game.Success())
    {
        return -1;
    }
    game.Run(); //lol good luck

    glfwTerminate();
    return 0;
}
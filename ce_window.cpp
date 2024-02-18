#include "ce_window.h"

#include <stdexcept>

namespace ce{

    CeWindow::CeWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
        initWindow();
    }


    CeWindow::~CeWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void CeWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr); 
        
    }

    void CeWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create windows surface");
        }
    }
}
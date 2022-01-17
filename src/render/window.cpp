#include "window.hpp"

#include <exception>
#include <iostream>
#include <optional>
#include <string>

namespace myra{
// public:
    std::optional<Window> Window::create(int width, int height, const std::string& title) {
        if (!glfwInit()) {
            std::cout << "Failed to initialize GLFW" << std::endl;
            return {};
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        GLFWwindow* windowHandle = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        if (windowHandle == NULL) {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return {};
        }
        glfwMakeContextCurrent(windowHandle);
        Window* window = new Window(windowHandle, width, height);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return {};
        }
        glViewport(0, 0, width, height);
        glfwSetWindowUserPointer(windowHandle, (void*) &window);
        glfwSetFramebufferSizeCallback(windowHandle, onFramebufferResize);

        return *window;
    }

    Window::~Window() {
        glfwTerminate();
    }

    const void Window::clear() {
        glClearColor(m_r, m_g, m_b, m_a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    const void Window::endFrame() {
        glfwSwapBuffers(m_windowHandle);
        glfwPollEvents();
    }
// private:
    Window::Window(GLFWwindow* window, int width, int height) {
        m_windowHandle = window;
        m_width = width;
        m_height = height;
    }

    void Window::onFramebufferResize(GLFWwindow* windowHandle, int width, int height) {
        Window* window = (Window*) glfwGetWindowUserPointer(windowHandle);

        glViewport(0, 0, width, height);
        window->m_width = width;
        window->m_height = height;
    }
// public:
    const int Window::getWidth() {
        return m_width;
    }

    const int Window::getHeight() {
        return m_height;
    }

    void Window::setClearColor(int r, int g, int b, int a) {
        m_r = r;
        m_g = g;
        m_b = b;
        m_a = a;
    }

    const bool Window::shouldWindowClose() {
        return glfwWindowShouldClose(m_windowHandle);
    }
}

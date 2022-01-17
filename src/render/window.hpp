#pragma once

#include <optional>
#include <string>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace myra {
    class Window {
    private:
        GLFWwindow* m_windowHandle;
        int m_width, m_height;
        int m_r, m_g, m_b, m_a;
    public:
        static std::optional<Window> create(int width, int height, const std::string& title);
        ~Window();
        const void clear();
        const void endFrame();
    private:
        Window(GLFWwindow* window, int width, int height);
        static void onFramebufferResize(GLFWwindow* windowHandle, int width, int height);
    public:
        const int getWidth();
        const int getHeight();
        void setClearColor(int r, int g, int b, int a);
        const bool shouldWindowClose();
    };
}

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Window.hpp"
#include "Log.hpp"

namespace Graphics
{
    static bool GLFWIsInitialized = false;

    Window::Window(std::string title, unsigned int width, unsigned int height)
        :_title(std::move(title))
        ,_width(width)
        ,_height(height)
    {
        int resultCode = init();
    }

    Window::~Window()
    {
        shutDown();
    }

    void Window::onUpdate()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glfwSwapBuffers(_pWindow);
        glfwPollEvents();
    }

    unsigned int Window::getWidth() const noexcept
    {
        return _width;
    }

    unsigned int Window::getHeight() const noexcept
    {
        return _height;
    }

    int Window::init()
    {
        LOG_INFO("Creating Window: '{0}' with size {1}x{2}.", _title, _width, _height);

        if (!GLFWIsInitialized)
        {
            if (!glfwInit())
            {
                LOG_CRITICAL("Can't Initialize GLFW.");
                return -1;
            }
            GLFWIsInitialized = true;
        }

        _pWindow = glfwCreateWindow(_width, _height, _title.c_str(), nullptr, nullptr);

        if (!_pWindow)
        {
            LOG_CRITICAL("Can't Create Window: '{0}'.", _title);
            glfwTerminate();
            return -2;
        }

        glfwMakeContextCurrent(_pWindow);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LOG_CRITICAL("Can't Initialize glad.");
            glfwTerminate();
            return -3;
        };
    }

    void Window::shutDown()
    {
        glfwDestroyWindow(_pWindow);
        glfwTerminate();
    }
}
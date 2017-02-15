#include "window.h"
#include <stdio.h>

namespace ObjView
{

Window::Window() :
	Window(1, 1)
{
}

Window::Window(int width, int height, const char* title, bool fullscreen) :
	m_title((char*)title)
{
	if(!glfwInit())
	{
		fprintf(stderr, "Error: Unable to initialize GLFW\n");
		return;
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	
	GLFWmonitor* monitor = NULL;
	if (fullscreen)
	{
		monitor = glfwGetPrimaryMonitor();
	}
	
	createWindow(width, height, monitor);
}

void Window::setWidth(int width)
{
	setResolution(width, getHeight());
}

int Window::getWidth() const
{
	int width;
	glfwGetWindowSize(m_glfw_window, &width, NULL);
	return width;
}

void Window::setHeight(int height)
{
	setResolution(getWidth(), height);
}

int Window::getHeight() const
{
	int height;
	glfwGetWindowSize(m_glfw_window, NULL, &height);
	return height;
}

void Window::setResolution(int width, int height)
{
	glfwSetWindowSize(m_glfw_window, width, height);
}

void Window::getResolution(int* width, int* height) const
{
	glfwGetWindowSize(m_glfw_window, width, height);
}

void Window::setFullscreen(bool state)
{
	int width, height;
	getResolution(&width, &height);
	
	GLFWmonitor* monitor = NULL;
	if (state)
	{
		monitor = glfwGetPrimaryMonitor();
	}
	
	glfwSetWindowMonitor(m_glfw_window, monitor, GLFW_DONT_CARE, GLFW_DONT_CARE, width,
						 height, GLFW_DONT_CARE);
}

bool Window::isFullscreen() const
{
	GLFWmonitor* monitor = glfwGetWindowMonitor(m_glfw_window);
	return (bool)monitor;
}

void Window::setTitle(const char* title)
{
	m_title = (char*)title;
	glfwSetWindowTitle(m_glfw_window, title);
}

const char* Window::getTitle() const
{
	return m_title;
}

void Window::setVSync(bool state)
{
	glfwSwapInterval((int)state);
}

void Window::setAntiAliasingSamples(int samples)
{
	glfwWindowHint(GLFW_SAMPLES, samples);
	recreateWindow();
}

void Window::swapBuffers()
{	
	glfwSwapBuffers(m_glfw_window);
}

void Window::pollEvents()
{
	glfwPollEvents();
}

bool Window::shouldClose() const
{
	return glfwWindowShouldClose(m_glfw_window);
}

void Window::close()
{
	glfwDestroyWindow(m_glfw_window);
	m_glfw_window = NULL;
}

// Precondition: There's no existing window.
bool Window::createWindow(int width, int height, GLFWmonitor* monitor)
{
	m_glfw_window = glfwCreateWindow(width, height, m_title, monitor, NULL);
	
	if (!m_glfw_window)
	{
		glfwTerminate();
		fprintf(stderr, "Error: Unable to create window.\n");
		return false;
	}
	
	glfwSetFramebufferSizeCallback(m_glfw_window, framebufferSizeCallback);
	glfwMakeContextCurrent(m_glfw_window);
	
	return true;
}

bool Window::recreateWindow()
{
	int width = 1;
	int height = 1;
	GLFWmonitor* monitor = NULL;
	
	if (m_glfw_window)
	{
		// Get window info
		getResolution(&width, &height);
		monitor = glfwGetWindowMonitor(m_glfw_window);
		// Destroy existing window
		glfwDestroyWindow(m_glfw_window);
	}
	
	return createWindow(width, height, monitor);
}

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

GLFWwindow* Window::m_glfw_window = NULL;

}

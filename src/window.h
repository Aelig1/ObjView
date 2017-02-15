#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

namespace ObjView
{

class Window
{
public:
	Window();
	Window(int width, int height, const char* title = "Window", bool fullscreen = false);

	virtual void setWidth(int width);
	int getWidth() const;
	void setHeight(int height);
	int getHeight() const;
	void setResolution(int width, int height);
	void getResolution(int* width, int* height) const;
	void setFullscreen(bool state);
	bool isFullscreen() const;
	void setTitle(const char* title);
	const char* getTitle() const;
	void setVSync(bool state);
	void setAntiAliasingSamples(int samples);
	void swapBuffers();
	void pollEvents();
	bool shouldClose() const;
	void close();

private:
	bool createWindow(int width, int height, GLFWmonitor* monitor);
	bool recreateWindow();
	static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

	static GLFWwindow* m_glfw_window;
	char* m_title;
};

}

#endif // WINDOW_H
#include "window.hpp"
#include <stdexcept>

Window::Window(int width, int height, const std::string& title) {
	// initialise GLFW
	if (!glfwInit()) {
		throw std::runtime_error("ERROR: failed to initialise GLFW");
	}

	// initialise GLFW window
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	p_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (p_window == NULL) {
		throw std::runtime_error("ERROR: failed to initialise GLFW window");
		glfwTerminate();
	}
	glfwMakeContextCurrent(p_window);

	// initialise GLEW
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		throw std::runtime_error("ERROR: Failed to initialise GLEW");
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	p_isOpen = true;
}

Window::~Window() {
	glfwTerminate();
}

void Window::clear(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update() {
	glfwSetInputMode(p_window, GLFW_STICKY_KEYS, GL_TRUE);

	glfwSwapBuffers(p_window);
	glfwPollEvents();
	if (glfwGetKey(p_window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(p_window) != 0) {
		p_isOpen = false;
	}
}

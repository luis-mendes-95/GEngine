#include "AppWindow.h"
#include "GraphicsEngine.h"

AppWindow::AppWindow()
{
}

AppWindow::~AppWindow()
{
}

void AppWindow::onCreate()
{
	Window::onCreate(); /*CALL THE BASE CLASS ON CREATE FUNCTION*/
	GraphicsEngine::get()->init(); /*INITIALIZE THE GRAPHICS ENGINE*/
}

void AppWindow::onUpdate()
{
}

void AppWindow::onDestroy()
{
	Window::onDestroy(); /*CALL THE BASE CLASS ON DESTROY FUNCTION*/
	
	//RELEASE THE GRAPHICS ENGINE
	GraphicsEngine::get()->release();
}

void Window::onCreate()
{
	// IMPLEMENTATION OF THE BASE CLASS ON CREATE FUNCTION
}



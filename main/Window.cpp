#include "Window.h"



Window* window = nullptr; /*WINDOW OBJECT*/

Window::Window() /*CONSTRUCTOR ->  This constructor is responsible for initializing a Window object.*/
{
	
} 

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) /*WINDOW PROCEDURE*/
{
	switch (msg) /*SWITCH STATEMENT FOR MESSAGES*/
	{
	case WM_CREATE:
	{
		/*EVENT FIRED WHEN THE WINDOW WILL BE CREATED*/
		window->onCreate(); /*CALL ON CREATE FUNCTION*/
		break;
	}

	case WM_DESTROY:
	{
		/*EVENT FIRED WHEN THE WINDOW WILL BE DESTROYED*/
		window->onDestroy(); /*CALL ON DESTROY FUNCTION*/
		::PostQuitMessage(0); /*POST QUIT MESSAGE*/
		break;
	}

	default:
		return ::DefWindowProc(hwnd, msg, wparam, lparam); /*DEFAULT CASE*/
	}

	return NULL;
}

/*INITIALIZATION FUNCTION*/
bool Window::init() 
{
	WNDCLASSEX wc; /*WINDOW CLASS STRUCTURE*/
	wc.cbClsExtra = NULL; /*EXTRA BYTES*/
	wc.cbSize = sizeof(WNDCLASSEX); /*SIZE OF STRUCTURE*/
	wc.cbWndExtra = NULL; /*EXTRA BYTES*/
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW; /*BACKGROUND COLOR*/
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); /*CURSOR*/
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); /*ICON*/
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION); /*SMALL ICON*/
	wc.hInstance = NULL; /*INSTANCE HANDLE*/
	wc.lpszClassName = L"WindowClass"; /*CLASS NAME*/
	wc.lpszMenuName = NULL; /*MENU NAME*/
	wc.style = NULL;
	wc.lpfnWndProc = DefWindowProc; /*WINDOW PROCEDURE*/
	 
	if (!::RegisterClassEx(&wc)) /*REGISTER WINDOW CLASS*/
		return false;

	if (!window) /*CHECK IF WINDOW OBJECT IS CREATED*/
		window = this; /*ASSIGN WINDOW OBJECT TO THIS POINTER*/

	m_hwnd=::CreateWindowEx( /*CREATE WINDOW AND ATTRIBUTE IT TO AN EXISTING VARIABLE*/
		WS_EX_OVERLAPPEDWINDOW, // Extended window style that provides a window with a title bar, a system menu, a maximize button, a minimize button, and a close button.
		L"WindowClass", // The name of the window class to which the window belongs.
		L"DirectX Application", // The title of the window.
		WS_OVERLAPPEDWINDOW, // Window style that creates a window that is initially visible and has a title bar, a system menu, a maximize button, a minimize button, and a close button.
		CW_USEDEFAULT, //Constant used to specify that the window should use the default position or size.
		CW_USEDEFAULT, //Constant used to specify that the window should use the default position or size.
		1024, //The width of the window in pixels.
		768, //The height of the window in pixels.
		NULL, //The parent window handle.
		NULL, //The menu handle.
		NULL, //The instance handle.
		NULL //A pointer to the Window object that will be associated with the window.
		);

	if (!m_hwnd) /*CHECK IF WINDOW IS CREATED*/
		return false;

	::ShowWindow(m_hwnd, SW_SHOW); /*SHOW WINDOW*/
	::UpdateWindow(m_hwnd); /*UPDATE WINDOW*/



	m_is_run = true; /*SET IS RUN TO TRUE*/
	return true;
}

/*BROADCAST FUNCTION*/
bool Window::broadcast() 
{
	MSG msg; /*MESSAGE STRUCTURE*/

	while (::PeekMessage(&msg, NULL, 0, 0,PM_REMOVE) > 0) /*GET MESSAGE*/
	{
		::TranslateMessage(&msg); /*TRANSLATE MESSAGE*/
		::DispatchMessage(&msg); /*DISPATCH MESSAGE*/
	}

	window->onUpdate(); /*CALL ON UPDATE FUNCTION*/

	Sleep(0); /*SLEEP*/

	return true;
}

/*RELEASE FUNCTION*/
bool Window::release() 
{

	if (!::DestroyWindow(m_hwnd)) /*CHECK IF WINDOW IS CREATED*/
		return false;  

	return true;
}

/*CHECK IF WINDOW IS RUNNING*/
bool Window::isRun() 
{
	return m_is_run; /*RETURN IS RUN*/
}

/*EVENT FIRED WHEN THE WINDOW WILL BE DESTROYED*/
void Window::onDestroy() 
{
	m_is_run = false; /*SET IS RUN TO FALSE*/
}

/*DESTRUCTOR*/
Window::~Window()
{
}

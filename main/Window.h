#pragma once /*HEADER GUARD*/
#include <Windows.h> /*INCLUDE WINDOWS HEADER FILE*/

class Window
{

public: /*IT MEANS THAT THESE FOLLOWING MEMBERS OF THE CLASS CAN BE USED AND ACCESSED OUTSIDE THE CLASS.*/

	Window(); /*CONSTRUCTOR*/
	bool init(); /*INITIALIZATION FUNCTION*/
	bool broadcast(); /*BROADCAST FUNCTION*/
	bool release(); /*RELEASE FUNCTION*/
	bool isRun(); /*CHECK IF WINDOW IS RUNNING*/

	/*EVENTS*/
	virtual void onCreate() = 0; /*EVENT FIRED WHEN THE WINDOW WILL BE CREATED*/
	virtual void onUpdate() = 0; /*EVENT FIRED WHEN THE WINDOW WILL BE UPDATED*/
	virtual void onDestroy(); /*EVENT FIRED WHEN THE WINDOW WILL BE DESTROYED*/

	~Window();  /*DESTRUCTOR*/

protected:/*IT MEANS THAT IT CAN ONLY BE ACCESSED WITHIN THE CLASS ITSELF AND ITS CHILD CLASSES.*/

	HWND m_hwnd; /*HANDLE TO THE WINDOW -> KEEP IT PROTECTED*/
	bool m_is_run; /*CHECK IF WINDOW IS RUNNING -> KEEP IT PROTECTED -> YOU CAN CALL THIS "A FLAG"*/

};


#pragma once /*HEADER GUARD*/
#include "Window.h" /*INCLUDE WINDOW HEADER FILE*/



class AppWindow: public Window /*INHERITANCE ->  AppWindow class inherits from the Window class*/
{
public:
	AppWindow(); /*CONSTRUCTOR*/
	~AppWindow(); /*DESTRUCTOR*/

	/*INHERITED VIA WINDOW*/
	virtual void onCreate() override; /*OVERRIDE ON CREATE FUNCTION*/
	virtual void onUpdate() override; /*OVERRIDE ON UPDATE FUNCTION*/
	virtual void onDestroy() override; /*OVERRIDE ON DESTROY FUNCTION*/
};


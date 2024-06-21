
#include "AppWindow.h"

/*MAIN FUNCTION -> EVERYTHING IS CENTRALIZED HERE*/
int main() 
{
	AppWindow app; /*CREATE AN INSTANCE OF THE APPWINDOW CLASS*/

	if (app.init())
	{

		while (app.isRun()) /*WHILE THE WINDOW IS RUNNING*/
		{
			if (app.broadcast() == false) /*IF BROADCAST FUNCTION RETURNS FALSE*/
				break; /*BREAK THE LOOP*/

			app.broadcast(); /*BROADCAST FUNCTION*/

			/*PRINT A MESSAGE IN POWERSHELL LOG SAYING: "HELLO WORLD!"*/

			
		}
		
	}
	return 0;
}
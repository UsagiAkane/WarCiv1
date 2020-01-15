#include "WindowManager.h"


int main(void) {
	std::srand(static_cast<unsigned int>(time(NULL)));
	WindowManager WM;
	//WM.mainMenu(WM.getWindow());
	WM.newGameWindow();
	return WN_SUCCESS;
}
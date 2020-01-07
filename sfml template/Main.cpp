#include "WindowManager.h"
#define SUCCESS_EXIT 1

int main(void) {
	std::srand(static_cast<unsigned int>(time(NULL)));
	WindowManager WM;
	//WM.mainMenu(WM.getWindow());
	WM.newGameWindow();
	return SUCCESS_EXIT;
}
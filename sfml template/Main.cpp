#include "WindowManager.h"
#define SUCCESS_EXIT 1

int main(void) {
	std::srand(time(NULL));
	WindowManager::mainWindow();
	return SUCCESS_EXIT;
}
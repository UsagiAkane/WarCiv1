#include "WindowManager.h"

int main(void) {
	std::srand(static_cast<unsigned int>(time(NULL)));
	WindowManager wm;
	wm.main_menu(wm.get_window());

	return WN_SUCCESS;
}
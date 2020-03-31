#include "locker_module/keypad.h"
#include "locker_module/putty.h"
#include "locker.h"
#include "messages.h"
#include "user_manager.h"
#include "admin_manager.h"
#include "access_manager.h"

int main(void)
{
	keypad_t* keypad = get_keypad();
	putty_t* putty = get_putty();
	locker_t* locker_1 = get_locker(1);
	locker_t* locker_2 = get_locker(2);
	locker_t* admin = get_locker(0);

	while(1) {
		putty -> print_line(welcomeMsg);

		char keyPressed = keypad -> get_debounced_key();
		if (keyPressed == '1') {
			handle_user(locker_1);
		} else if (keyPressed == '2') {
			handle_user(locker_2);
		} else if (keyPressed == 'A') {
			handle_admin(admin);
		} else if (keyPressed == 'B') {
			handle_password_change(-1);
		}
		putty -> print_line(clearDisplay);
	}

    return 0;
}

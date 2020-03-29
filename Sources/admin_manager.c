#include "locker_module/display_timer.h"
#include "locker_module/solenoid_lock.h"
#include "locker_module/keypad.h"
#include "locker_module/lcd.h"
#include "messages.h"
#include "user_manager.h"
#include "access_manager.h"

void handle_admin(locker_t* admin) {
	lcd_t* lcd = get_lcd();
	timer_t* timer = get_timer();
	int isAuthenticated = authenticate_user(admin);
	if (isAuthenticated == 0) {
		keypad_t* keypad = get_keypad();
		while(1) {
			lcd -> print_line(adminAccess);
			char keyPressed = keypad -> get_debounced_key();
			if (keyPressed == '1') {
				lcd -> print_line(openMsg);
				lock_t* lock = get_solenoid_lock(1);
				lock -> open();
				timer -> delay(5000);
				lock -> close();
			} else if (keyPressed == '2') {
				lcd -> print_line(openMsg);
				lock_t* lock = get_solenoid_lock(2);
				lock -> open();
				timer -> delay(5000);
				lock -> close();
			} else if (keyPressed == 'A') {
				lcd -> print_line(adminLogoutMsg);
				timer -> delay(2000);
				return;
			} else if (keyPressed == 'B') {

			}
			lcd -> print_line(clearDisplay);
		}
	}
}

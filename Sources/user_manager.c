/* 
	File: user_manager.c
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	Implementation of the user_manager.h header file
*/
#include "locker_module/display_timer.h"
#include "locker_module/solenoid_lock.h"
#include "locker_module/putty.h"
#include "user_manager.h"
#include "messages.h"
#include "access_manager.h"

void handle_user(locker_t* locker) {
	putty_t* putty = get_putty();
	int isAuthenticated = authenticate_user(locker);
	if (isAuthenticated == 0) {
		putty -> print_line(openMsg);
		lock_t* lock = get_solenoid_lock(locker -> number);
		lock -> open();
		timer_t* timer = get_timer();
		timer -> delay(10000);
		lock -> close();
	}
}

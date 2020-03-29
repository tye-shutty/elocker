#ifndef SOURCES_ACCESS_MANAGER_H_
#define SOURCES_ACCESS_MANAGER_H_

#include "locker_module/lcd.h"
#include "locker.h"

int check_password(locker_t* locker, lcd_t* lcd);
int authenticate_user(locker_t* locker);
void change_password(locker_t* locker, lcd_t* lcd);
void handle_password_change();

#endif /* SOURCES_ACCESS_MANAGER_H_ */

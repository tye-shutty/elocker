/* 
	File: access_manager.h
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
  The access manager module is responsible for getting 
  the combination from the user or admin and verifying 
  if the combination is correct. The module dispatches 
  commands to the speaker, and putty to provide feedback 
  to the user. The module also implements the logic to 
  change the password. 
*/

#ifndef SOURCES_ACCESS_MANAGER_H_
#define SOURCES_ACCESS_MANAGER_H_

#include "locker_module/putty.h"
#include "locker.h"

int check_password(locker_t* locker, putty_t* putty);
int authenticate_user(locker_t* locker);
void change_password(locker_t* locker, putty_t* putty);
void handle_password_change();

#endif /* SOURCES_ACCESS_MANAGER_H_ */

/* 
	File: user_manager.h
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	The user manager module is responsible for getting
  authorization to unlock a locker and give the correct
  feedback to the user. 
*/

#ifndef SOURCES_USER_MANAGER_H_
#define SOURCES_USER_MANAGER_H_
#include "locker.h"

void handle_user(locker_t* locker);

#endif /* SOURCES_USER_MANAGER_H_ */


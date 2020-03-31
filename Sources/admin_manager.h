/* 
	File: admin_manager.h
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
  The admin manager module handles the instructions in 
  admin mode. The module dispatches the commands for
  opening a locker or changing a password providing
  the administrator previleges.
*/

#ifndef SOURCES_ADMIN_MANAGER_H_
#define SOURCES_ADMIN_MANAGER_H_

void handle_admin(locker_t* admin);

#endif /* SOURCES_ADMIN_MANAGER_H_ */

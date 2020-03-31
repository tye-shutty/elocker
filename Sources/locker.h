/* 
	File: admin_manager.h
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	The locker module is a data structure that represent each
	locker. The structure holds the reference for the password
	and locker number. The administrator is also implemented
	as a locker, but it is not assigned any specific locker
	number. 
*/

#ifndef SOURCES_LOCKER_H_
#define SOURCES_LOCKER_H_

typedef struct locker_struct {
	int number;
	int* password;
} locker_t;

locker_t* get_locker(int number);

#endif /* SOURCES_LOCKER_H_ */

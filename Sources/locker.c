/* 
	File: locker.c
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	Implementation of the locker.h header file
*/

#include "locker.h"
#include <stdlib.h>

static locker_t* locker1 = 0;
static locker_t* locker2 = 0;
static locker_t* admin = 0;

static int password1[3] = {10, 20, 30};
static int password2[3] = {5, 15, 25};
static int passworda[3] = {7, 18, 26};

int* get_password(int number) {
	if (number == 1) {
		return password1;
	} else if (number == 2) {
		return password2;
	} else {
		return passworda;
	}
}

locker_t* get_locker(int number) {
	if (number == 1) {
		if(locker1 == 0) {
			locker1 = (locker_t*) malloc(sizeof(locker_t));
			locker1 -> number = number;
			locker1 -> password = get_password(number);
		}
		return locker1;
   } else if (number == 2){
		if(locker2 == 0) {
			locker2 = (locker_t*) malloc(sizeof(locker_t));
			locker2 -> number = number;
			locker2 -> password = get_password(number);
		}
		return locker2;
   } else {
		if(admin == 0) {
			admin = (locker_t*) malloc(sizeof(locker_t));
			admin -> number = number;
			admin -> password = get_password(number);
		}
		return admin;
   }
}

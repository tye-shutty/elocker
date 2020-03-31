/* 
	File: access_manager.c
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	Implementation of the access_manager.h header file
*/

#include "locker_module/potentiometer.h"
#include "locker_module/speaker.h"
#include "locker_module/keypad.h"
#include "locker_module/display_timer.h"
#include "messages.h"
#include "access_manager.h"

int check_password(locker_t* locker, putty_t* putty) {
	pot_t* potentiometer = get_pot();
	int* combination = (int*) malloc(sizeof(int) * 3);
	combination[0] = 0;
	combination[1] = 0;
	combination[2] = 0;

	timer_t* timer = get_timer();

	putty -> print_line(enterPasswordMsg);
	putty -> print_string(centralize);
	for (int i = 0; i < 3; i++) {
		int elapsedTime = 0;
		while(elapsedTime < 4000){
			if ((potentiometer -> read_value()) / 8 == combination[i]) {
				timer -> delay(1);
				elapsedTime++;
			} else {
				combination[i] = (potentiometer -> read_value()) / 8;
				char digit1 = (combination[i] / 10) + '0';
				char digit2 = (combination[i] % 10) + '0';
				putty -> put_char(digit1);
				putty -> put_char(digit2);
				putty -> put_char(8);
				putty -> put_char(8);
				elapsedTime = 0;
			}
		}
		char digit1 = (combination[i] / 10) + '0';
		char digit2 = (combination[i] % 10) + '0';
		putty -> put_char(digit1);
		putty -> put_char(digit2);
		putty -> put_char(' ');
	}

	int check = 3;
	for (int i = 0; i < 3; i++) {
		if(combination[i] == locker -> password[i]) {
			check--;
		}
	}

	putty -> print_line(clearDisplay);
	return check;
}

int authenticate_user(locker_t* locker) {
	putty_t* putty = get_lcd();
	speaker_t* speaker = get_speaker();
	timer_t* timer = get_timer();

	int isPassWrong = check_password(locker, putty);
	if (isPassWrong) {
		speaker -> play(FAIL);
		putty -> print_line(invalidMsg);
		timer -> delay(2000);
		return -1;
	} else {
		speaker -> play(SUCCESS);
		putty -> print_line(validMsg);
		timer -> delay(2000);
		return 0;
	}
}

void change_password(locker_t* locker, putty_t* putty, int isAdmin) {
	int isAuthenticated = authenticate_user(locker);
	if (isAuthenticated == 0 || isAdmin == 0) {
		pot_t* potentiometer = get_pot();
		int* combination = (int*) malloc(sizeof(int) * 3);
		combination[0] = 0;
		combination[1] = 0;
		combination[2] = 0;

		timer_t* timer = get_timer();

		putty -> print_line(enterNewPasswordMsg);
		putty -> print_string(centralize);

		for (int i = 0; i < 3; i++) {
			int elapsedTime = 0;
			while(elapsedTime < 4000){
				if ((potentiometer -> read_value()) / 8 == combination[i]) {
					timer -> delay(1);
					elapsedTime++;
				} else {
					combination[i] = (potentiometer -> read_value()) / 8;
					char digit1 = (combination[i] / 10) + '0';
					char digit2 = (combination[i] % 10) + '0';
					putty -> put_char(digit1);
					putty -> put_char(digit2);
					putty -> put_char(8);
					putty -> put_char(8);
					elapsedTime = 0;
				}
			}
			char digit1 = (combination[i] / 10) + '0';
			char digit2 = (combination[i] % 10) + '0';
			putty -> put_char(digit1);
			putty -> put_char(digit2);
			putty -> put_char(' ');
		}

		locker -> password = combination;
		putty -> print_line(clearDisplay);
	}
}

void handle_password_change(int isAdmin) {
	locker_t* locker_1 = get_locker(1);
	locker_t* locker_2 = get_locker(2);
	locker_t* admin = get_locker(0);
	putty_t* putty = get_lcd();
	putty -> print_line(changeTargetMsg1);
	putty -> print_string(changeTargetMsg2);
	timer_t* timer = get_timer();
	timer -> delay(2000);

	keypad_t* keypad = get_keypad();
	char keyPressed = keypad -> get_debounced_key();
	if (keyPressed == '1') {
		change_password(locker_1, putty, isAdmin);
		putty -> print_string(passChangedMsg);
	} else if (keyPressed == '2') {
		change_password(locker_2, putty, isAdmin);
		putty -> print_string(passChangedMsg);
	} else if (keyPressed == 'A') {
		change_password(admin, putty, isAdmin);
		putty -> print_string(passChangedMsg);
	}

	timer -> delay(2000);
}

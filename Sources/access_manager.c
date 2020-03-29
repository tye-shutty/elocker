#include "locker_module/potentiometer.h"
#include "locker_module/speaker.h"
#include "locker_module/keypad.h"
#include "locker_module/display_timer.h"
#include "messages.h"
#include "access_manager.h"

int check_password(locker_t* locker, lcd_t* lcd) {
	pot_t* potentiometer = get_pot();
	int* combination = (int*) malloc(sizeof(int) * 3);
	combination[0] = 0;
	combination[1] = 0;
	combination[2] = 0;

	timer_t* timer = get_timer();

	lcd -> print_line(enterPasswordMsg);
	lcd -> print_string(centralize);
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
				lcd -> put_char(digit1);
				lcd -> put_char(digit2);
				lcd -> put_char(8);
				lcd -> put_char(8);
				elapsedTime = 0;
			}
		}
		char digit1 = (combination[i] / 10) + '0';
		char digit2 = (combination[i] % 10) + '0';
		lcd -> put_char(digit1);
		lcd -> put_char(digit2);
		lcd -> put_char(' ');
	}

	int check = 3;
	for (int i = 0; i < 3; i++) {
		if(combination[i] == locker -> password[i]) {
			check--;
		}
	}

	lcd -> print_line(clearDisplay);
	return check;
}

int authenticate_user(locker_t* locker) {
	lcd_t* lcd = get_lcd();
	speaker_t* speaker = get_speaker();
	timer_t* timer = get_timer();

	int isPassWrong = check_password(locker, lcd);
	if (isPassWrong) {
		speaker -> play(FAIL);
		lcd -> print_line(invalidMsg);
		timer -> delay(2000);
		return -1;
	} else {
		speaker -> play(SUCCESS);
		lcd -> print_line(validMsg);
		timer -> delay(2000);
		return 0;
	}
}

void change_password(locker_t* locker, lcd_t* lcd) {
	int isAuthenticated = authenticate_user(locker);
	if (isAuthenticated == 0) {
		pot_t* potentiometer = get_pot();
		int* combination = (int*) malloc(sizeof(int) * 3);
		combination[0] = 0;
		combination[1] = 0;
		combination[2] = 0;

		timer_t* timer = get_timer();

		lcd -> print_line(enterNewPasswordMsg);
		lcd -> print_string(centralize);

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
					lcd -> put_char(digit1);
					lcd -> put_char(digit2);
					lcd -> put_char(8);
					lcd -> put_char(8);
					elapsedTime = 0;
				}
			}
			char digit1 = (combination[i] / 10) + '0';
			char digit2 = (combination[i] % 10) + '0';
			lcd -> put_char(digit1);
			lcd -> put_char(digit2);
			lcd -> put_char(' ');
		}

		locker -> password = combination;
		lcd -> print_line(clearDisplay);
	}
}

void handle_password_change() {
	locker_t* locker_1 = get_locker(1);
	locker_t* locker_2 = get_locker(2);
	locker_t* admin = get_locker(0);
	lcd_t* lcd = get_lcd();
	lcd -> print_line(changeTargetMsg1);
	lcd -> print_string(changeTargetMsg2);
	timer_t* timer = get_timer();
	timer -> delay(2000);

	keypad_t* keypad = get_keypad();
	char keyPressed = keypad -> get_debounced_key();
	if (keyPressed == '1') {
		change_password(locker_1, lcd);
	} else if (keyPressed == '2') {
		change_password(locker_2, lcd);
	} else if (keyPressed == 'A') {
		change_password(admin, lcd);
	}
}

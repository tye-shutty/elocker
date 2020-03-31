/* 
	File: keypad.c
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	Implementation of the keypad.h header file
*/

#include "keypad.h"

static keypad_t* this = 0;

void init_keypad() {
	gpio_init();

	int row[] = {5, 7, 0, 9};
    for(int i = 0; i < 4; i++) {
    	set_portc_output(row[i]);
    }
}

char get_char(int row, int col) {
	switch(row) {
		case 0:
			if (col == 0) {
				return '1';
			} else if (col == 1) {
				return '2';
			} else if (col == 2) {
				return '3';
			} else if (col == 3) {
				return 'A';
			} else {
				return 0;
			}
		case 1:
			if (col == 0) {
				return '4';
			} else if (col == 1) {
				return '5';
			} else if (col == 2) {
				return '6';
			} else if (col == 3) {
				return 'B';
			} else {
				return 0;
			}
		case 2:
			if (col == 0) {
				return '7';
			} else if (col == 1) {
				return '8';
			} else if (col == 2) {
				return '9';
			} else if (col == 3) {
				return 'C';
			} else {
				return 0;
			}
		case 3:
			if (col == 0) {
				return '0';
			} else if (col == 1) {
				return 'F';
			} else if (col == 2) {
				return 'E';
			} else if (col == 3) {
				return 'D';
			} else {
				return 0;
			}
		default:
			return 0;
	}
}

char get_key() {
    int row[] = {5, 7, 0, 9};
    int col[] = {10, 11, 11, 10};

    for(int i = 0; i < 4; i++) {
    	set_portc_output(row[i]);
    }

    int selCol = -1;
    int selRow = -1;

    for(int i = 0; i < 4; i++) {
    	clear_portc_output(row[i]);
    	for(int j = 0; j < 4; j++) {
    		int input;
    		if (j < 2) {
    			input = get_portb_input(col[j]);
    		} else {
    			input = get_portc_input(col[j]);
    		}
    		if (!input) {
    			selRow = i;
    			selCol = j;
    		}
    	}
    	set_portc_output(row[i]);
    }

    return get_char(selRow, selCol);
}

char get_debounced_key() {
	char input = get_key();
	// wait for key press
	while (input == 0) {
		input = get_key();
	};

	// key press detected
	int counter = 500;
	int temp = input;
	while(counter) {
		temp = input;
		input = get_key();
		if (temp == input) {
			counter--;
		}
	}

	return input;
}

keypad_t* get_keypad() {
   if(this == 0) {
	   init_keypad();

    	this = (keypad_t*) malloc(sizeof(keypad_t));
        this -> get_key = &get_key;
        this -> get_debounced_key = &get_debounced_key;
    }
    return this;
}

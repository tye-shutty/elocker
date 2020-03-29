#ifndef SOURCES_LOCKER_H_
#define SOURCES_LOCKER_H_

typedef struct locker_struct {
	int number;
	int* password;
} locker_t;

locker_t* get_locker(int number);

#endif /* SOURCES_LOCKER_H_ */

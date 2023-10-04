#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"



int main(int argc, char *argv[]) {
	if (argc < 2){
		fprintf(2, "Expected sleep duration in seconds\n");
		exit(1);
	}

	int duration  = atoi(argv[1]);
	if (duration < 0){
	      fprintf(2,"Invalid sleep duration interval\n");
              exit(1);
	} else {
		sleep(duration);
	}
	exit(0);
}

/* 1. int xxx(int); ->  user/user.h
 * 2. entry("xxx"); -> user/usys.pl
 * 3. #define SYS_xxx 22 -> kernel/syscall.h
 * 4. extern uint64 sys_xxx(void); && static uint64  -> [SYS_xxx] sys_xxx,    --> kernel syscall.c
 * 5. uint64 
 *    sys_xxx(void){}
 *
 *  6.  implement somewhere in kernel e.g. kernel/defs.h */



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

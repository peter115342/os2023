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
 *  6.  implement somewhere in kernel e.g. kernel/defs.h
 *  -----------------------------------------------------------------------------------------------
 *
 *int fork() Create a process, return child’s PID.
*int exit(int status) Terminate the current process; status reported to wait(). No return.
*int wait(int *status) Wait for a child to exit; exit status in *status; returns child PID.
*int kill(int pid) Terminate process PID. Returns 0, or -1 for error.
*int getpid() Return the current process’s PID.
*int sleep(int n) Pause for n clock ticks.
*int exec(char *file, char *argv[]) Load a file and execute it with arguments; only returns if error.
*char *sbrk(int n) Grow process’s memory by n bytes. Returns start of new memory.
*int open(char *file,int flags)Open a file;flags indicate read/write;returns an fd (file descriptor).
*int write(int fd, char *buf, int n) Write n bytes from buf to file descriptor fd; returns n.
*int read(int fd, char *buf, int n) Read n bytes into buf; returns number read; or 0 if end of file.
*int close(int fd) Release open file fd.
*int dup(int fd) Return a new file descriptor referring to the same file as fd.
*int pipe(int p[]) Create a pipe, put read/write file descriptors in p[0] and p[1].
*int chdir(char *dir) Change the current directory.
*int mkdir(char *dir) Create a new directory.
*int mknod(char *file, int, int) Create a device file.
*int fstat(int fd, struct stat *st) Place info about an open file into *st.
*int stat(char *file, struct stat *st) Place info about a named file into *st.
*int link(char *file1, char *file2) Create another name (file2) for the file file1.
*int unlink(char *file) Remove a file.
   */



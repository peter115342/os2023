#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(){
int p[2];
char recv_buf[32];

pipe(p);

int pid  = fork();
if(pid==0){
write(p[1],"Ping",5);
fprintf(1,"Thread id %d  received Ping\n",getpid());
}
else{
  wait(0);
read(p[0],recv_buf,5);
fprintf(1,"Thread id %d received Pong\n", getpid());
}
exit(0);
}

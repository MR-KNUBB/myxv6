#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/uproc.h"
#include "user/user.h"

int main(int argc, char **argv){
  int start = uptime();
  int fk = fork();
  struct rusage ru;

  if(fk == 0) // child
    exec(argv[1],argv);
  wait2(0,&ru); // parent
  int elapsed = uptime() - start;

  printf("elapsed time: %d ticks, cpu time: %d ticks, %d% CPU\n", elapsed, ru.cputime, (ru.cputime*100)/elapsed);


  exit(0);
}

#include "kernel/param.h"
#include "kernel/types.h"
#include "user/uproc.h"
#include "user/user.h"

int main(int argc, char **argv)

{
  struct uproc uproc[NPROC];
  int nprocs;
  int i;
  char *state;
  static char *states[] = {
    [SLEEPING] "sleeping",
    [RUNNABLE] "runnable",
    [RUNNING]   "running",
    [ZOMBIE]     "zombie",
  };

  nprocs = getprocs(uproc); //will return # of active processes
  if (nprocs < 0)
    exit(-1);

  printf("pid\tstate\t\tsize\tcputime\tppid\tname\n");
  for(i=0; i < nprocs; i++){
    state = states[uproc[i].state];
    printf("%d\t %s\t %l\t %d\t %d\t %s\n", uproc[i].pid, state, uproc[i].cputime, 
       uproc[i].size, uproc[i].ppid, uproc[i].name);
  }

  exit(0);

}

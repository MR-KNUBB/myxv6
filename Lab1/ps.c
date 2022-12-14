#include "kernel/param.h"
#include "kernel/types.h"
#include "user/uproc.h"
#include "user/user.h"

int main(int argc, char **argv)

{
  struct uproc uproc[NPROC];
  int nprocs;
  nprocs = getprocs(uproc); //will return # of active processes

  if (nprocs < 0)
    exit(-1);

    // You can remove the following print statement
 // printf("\n---------%d processes active------------\n", nprocs);

  printf("pid\tppid\tsize\tname\n");
  struct uproc *u;
  for(u = uproc; u < &uproc[nprocs]; u++){
    printf("%d\t%d\t%d\t%s\n", u->pid, u->ppid,u->size, u->name);
  }

  exit(0);

}

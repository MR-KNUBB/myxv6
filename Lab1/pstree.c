#include "kernel/param.h"
#include "kernel/types.h"
#include "user/uproc.h"
#include "user/user.h"

void mktree(struct uproc *uproc,int nprocs, int indent, int pid){

  struct uproc *p;

  for(p = uproc; p < &uproc[nprocs]; p++){
    if(p->pid == pid){
      for(int i = 0; i < indent; i++){
        printf("\t");
      }
      printf("%s(%d)\n", p->name, p->pid);
    }
    if(p->ppid == pid){
      mktree(uproc,nprocs,indent+1, p->pid);

    }
  }
}

int main(int argc, char **argv)

{
  struct uproc uproc[NPROC];
  int nprocs;
  nprocs = getprocs(uproc); //will return # of active processes

  if (nprocs < 0)
    exit(-1);

  // You can remove the following print statement
  printf("\n--------------------------\n", nprocs);
  mktree(uproc,nprocs, 0, 1); //starts with looking for init and indentation 0
  exit(0);
}

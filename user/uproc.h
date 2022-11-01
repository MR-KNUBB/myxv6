/*

* file uproc.h with definition of user process structure

*/

enum uprocstate { UNUSED, USED, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

struct rusage {
  uint64 cputime;
};

struct uproc {

  int pid; // Process ID

  enum uprocstate state; // Process state

  uint64 cputime;

  uint64 size; // Size of process memory (bytes)

  int ppid; // Parent ID

  char name[16]; // Process command name


};

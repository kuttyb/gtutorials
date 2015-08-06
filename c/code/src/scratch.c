#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <spawn.h>

int main(void) 
{
  for (int i = 0; i < 100000; ++i)
    {
      pid_t pid;
      int status = posix_spawn(&pid, "/bin/sh", NULL, NULL, "", environ);
    }
  return 0;
}

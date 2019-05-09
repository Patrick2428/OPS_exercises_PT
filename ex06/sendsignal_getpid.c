#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  if(argc < 2)
    {
      perror("Argument pid missing");
      exit(1);
    }
  pid_t Sigpid = atoi(argv[1]);

  while(1)
    {
      kill(Sigpid, 25);
      sleep(3);
    }
}

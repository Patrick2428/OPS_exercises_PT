#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
  int fd, pid;

  fd = open("PIDpipe", O_RDONLY);
  read(fd, &pid, sizeof(pid));
  close(fd);

  while(1)
    {
      kill(pid, 25);
      sleep(3);
    }
}

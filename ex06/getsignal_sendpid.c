#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


volatile char digits = '0';
void newHandler(int sig);

int main(void)
{
  struct sigaction act;
  int pid, fd;

  memset(&act, '\0', sizeof(act)); //Set the memory to Null zero
  act.sa_handler = newHandler;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask); //No masking

  sigaction(25, &act, NULL); //installs signal handler
  //printf("PID = %d\n",getpid());
  pid = getpid();
  fd = open ("PIDpipe", O_WRONLY);
  write(fd, &pid, sizeof(pid));
  close(fd);
  
  while(1)
    {
      write(1,&digits,1);
      sleep(1);  
    }
  return 0;
}

void newHandler(int sig)
{
  if(++digits > '9')
     digits = '0';
}

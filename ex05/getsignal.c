#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>

volatile char digits = '0';
void newHandler(int sig);

int main(void)
{
  struct sigaction act;

  memset(&act, '\0', sizeof(act));
  act.sa_handler = newHandler;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);

  sigaction(25, &act, NULL);
  printf("PID = %d\n",getpid());
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

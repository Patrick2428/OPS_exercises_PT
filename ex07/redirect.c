#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <ctype.h>

#define ESC 0x1B

int main(void)
{
  int pipeFD1[2],pipeFD2[2]; // 2 pipes since they can only be one direction
  char buf;

  if(pipe(pipeFD1) == -1)
    {
      perror("pipe");
      exit(1);
    }
  if(pipe(pipeFD2) == -1)
    {
      perror("pipe");
      exit(1);
    }

  switch(fork())
    {
    case -1:
      perror("fork");
      exit(1);

    case 0:      
      //child
      close(pipeFD1[0]); //Close read side of pipe1
      close(pipeFD2[1]); //close write side of the pipe2
      
      
      dup2(pipeFD1[1], 1); //dub  write of pipe1 to stdout file descriptor
      dup2(pipeFD2[0], 0); //dub read of pipe2 to stdin file descriptor
      close(pipeFD1[1]);
      close(pipeFD2[0]);

      execlp("./filter", "filter", (char *) NULL);
      perror("execlp"); //If returns error occurs;
      exit(1);
      break;
      
    default:
      //parent

      close(pipeFD1[1]);//close write side of pipe1
      close(pipeFD2[0]);//close read side of pipe2

      while(buf != ESC)
	{
	  read(0, &buf, 1);
	  write(pipeFD2[1], &buf, 1);
	  read(pipeFD1[0], &buf, 1);
	  write(1, &buf, 1);
	}
      wait(NULL);
      close(pipeFD1[0]);
      close(pipeFD2[1]);
      break;
    }

  return 0;
}

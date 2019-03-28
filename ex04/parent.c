/******************************************************************************
 * File:         display.c
 * Version:      1.4
 * Date:         2018-02-20
 * Author:       M. van der Sluys, J.H.L. Onokiewicz, R.B.A. Elsinghorst, J.G. Rouland
 * Description:  OPS exercise 2: syntax check
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "displayFunctions.h"
#include "unistd.h"
#include "sys/wait.h"
#include <sys/resource.h>
#include <sys/time.h>


int main(int argc, char *argv[]) {
  int  niceIncr,numofChar;
  pid_t Child;
  
  ErrCode err;

  numofChar = (argc -4);
  
  err = SyntaxCheck(argc, argv, numofChar);  // Check the command-line parameters
  if(err != NO_ERR) {
    DisplayError(err);        // Print an error message
  } else {
    
    niceIncr = strtoul(argv[3], NULL, 10); //String to unsigned long int

  
  printf("Num of characters: %d\n",numofChar);

  for(int iChild = 0; iChild < numofChar; iChild++)
    {
      Child  = fork();

      switch(Child){

      case -1:
	  perror("forking has failed,no child process created");
	  exit(1);
	  break;
	  
      case 0:
	  //Child process
        
        setpriority(PRIO_PROCESS,getpid(),(niceIncr*iChild));
	printf("The priority of Child%d: %d\n",iChild, getpriority(PRIO_PROCESS,getpid()));

	execl("../ex02/./display","display",argv[1],argv[2],argv[4+iChild],(char*)NULL );
	
	perror("Starting child failed\n");	
	break;
	
      default:
	  //parent process
	break;
      }
      if(Child == 0)
	{
	  break;
	}
    }

  for(int x = 0; x < numofChar; x ++)
    {
      wait(NULL);
    }

  printf("All the children have finished\n");

  }
  
  printf("\n");  // Newline at end
  return 0;
}

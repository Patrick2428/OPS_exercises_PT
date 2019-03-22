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

int main(int argc, char *argv[]) {
  unsigned long int numOfTimes;
  char printMethod;
  char printChar;
  int  niceIncr,numofChar;
  pid_t Child;
  
  ErrCode err;

  numofChar = (argc -4);
  
  err = SyntaxCheck(argc, argv, numofChar);  // Check the command-line parameters
  if(err != NO_ERR) {
    DisplayError(err);        // Print an error message
  } else {
    printMethod = argv[1][0];
    numOfTimes = strtoul(argv[2], NULL, 10);  // String to unsigned long
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
	printChar = argv[iChild + 4][0];
	/*printf("The pid of child%d is: %d\nThe character: %c\nThe nice increment: %d\n",iChild+1,getpid(), printChar, iChild*niceIncr);*/
    
	if(nice(iChild * niceIncr) == -1)
	  {
	    perror("The nice() failed\n");
	  }
	   
	   PrintCharacters(printMethod, numOfTimes, printChar);  // Print character printChar numOfTimes times using method printMethod*/

  printf("\nThe priority of child %d is: %d\n",iChild, getpriority(PRIO_PROCESS, getpid()));  	
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
  

  }
  
  printf("\n");  // Newline at end
  return 0;
}

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

int main(int argc, char *argv[]) {
  unsigned long int numOfTimes, numofChar;
  char printMethod;
  char printChar;
  int counter, niceIncr;
  pid_t iChild;
  
  ErrCode err;
  
  err = SyntaxCheck(argc, argv);  // Check the command-line parameters
  if(err != NO_ERR) {
    DisplayError(err);        // Print an error message
  } else {
    printMethod = argv[1][0];
    numOfTimes = strtoul(argv[2], NULL, 10);  // String to unsigned long
    niceIncr = strtoul(argv[3], NULL, 10); //String to unsigned long int

  numofChar = (argc -4);
  printf("Num of characters: %ld\n",numofChar);

  for(counter = 0; counter < numofChar; counter++)
    {
      iChild  = fork();

      switch(iChild){

      case -1:
	  perror("forking has failed,no child process created");
	  exit(1);

      case 0:
	  //Child process
	printChar = argv[counter + 4][0];
	printf("The pid of child%d is: %d\nThe character: %c\nThe nice increment: %d\n",counter+1,getpid(), printChar, iChild*niceIncr);
	//execl("./display", printChar, (char*) NULL);

      default:
	  //Mother process
	  wait(NULL);
	
      }
      
    }
    
  
  /* PrintCharacters(printMethod, numOfTimes, printChar);  // Print character printChar numOfTimes times using method printMethod*/
  }
  
  printf("\n");  // Newline at end
  return 0;
}

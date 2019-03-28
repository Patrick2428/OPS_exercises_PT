/******************************************************************************
 * File:         displayFunctions.c
 * Version:      1.4
 * Date:         2018-02-20
 * Author:       M. van der Sluys, J.H.L. Onokiewicz, R.B.A. Elsinghorst, J.G. Rouland
 * Description:  OPS exercise 2:  function definitions for display.c
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "displayFunctions.h"
#include "syntaxCheck.h"

// Check the command-line parameters:
ErrCode SyntaxCheck(int argc, char **argv, int characters) {
  ErrCode errCode = NO_ERR;
  if(argc != (characters + 4)) {
    errCode = ERR_PARS;
  } else {
     if(errCode == NO_ERR) errCode = TestNr(argv[3]);  // Test whether argument 3 (NiceValue) is a positive value
    
  }
  return errCode;
}

// Print an error message:
void DisplayError(ErrCode errCode) {
  switch(errCode) {
  case ERR_PARS:
    printf("\nNumber of command-line parameters is incorrect.\n");
    break;
  case ERR_NR:
    printf("\nThe nice value is not a positive integer.\n");
    break;
  default:
    printf("\nUnknown error code!\n");
  }
  
  printf("\nCorrect syntax:\n");
  printf("  ./display <print type> <number of times> <print character>\n\n");
  printf("  first parameter: <print type>: e, p or w\n");
  printf("  second parameter: <number of times>: positive integer\n");
  printf("  third parameter: <print character>: a single character\n");
  printf("\n");  // Newline at end
}


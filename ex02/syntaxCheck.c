/******************************************************************************
 * File:         syntaxCheck.c
 * Version:      1.4
 * Datum:        2018-02-20
 * Author:       M. van der Sluys, J.H.L. Onokiewicz, R.B.A. Elsinghorst, J.G. Rouland
 * Description:  OPS exercise 2:  definitions of test functions for display.c
 ******************************************************************************/

#include <stdlib.h>
#include "syntaxCheck.h"
#include <string.h>



// Test whether an argument is one character long and has the correct value (e,p,w):
ErrCode TestType(char *printMethod) {
  ErrCode fout = NO_ERR;
  if(*printMethod == 'e' || *printMethod == 'p' || *printMethod == 'w')
    {
       fout = NO_ERR;
    }
  else
    {
       fout = ERR_TYPE;
       
    }
   
  return fout;
}

// Test whether an argument contains a non-negative number:
ErrCode TestNr(char *numberOfTimes) {
  ErrCode fout = NO_ERR;
  
  if(*numberOfTimes == '-')
    {
      fout = ERR_NR;
    }
  else
    {
      fout = NO_ERR;
    }
  
  return fout;
}


// Test whether an argument contains only one character:
ErrCode TestChar(char *printChar) {
  ErrCode fout = NO_ERR;
  
  if(strlen(printChar) >= 2)
    {
      fout = ERR_CHAR;
    }

  else
    {
      fout = NO_ERR;
      }
  return fout;
}

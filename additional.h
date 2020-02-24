// Author: Walerij Hrul
//
// Own functions used often
//

#ifndef ADDITIONAL_H
#define ADDITIONAL_H

#define FORMAT(S) "%" #S "s"
#define S_FORMAT(S) FORMAT(S)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structs.h"

void* checkMemoryAlloc( void* wsk, bool* badAlloc );
// clear user input stream
void clearBuf( void );
// return 0 if error
unsigned long long readInputPositiveNumber( void );
// return NULL if error
char* readInputWord( bool* badAlloc );
// read from user input stream char which differs from ' ' and '\n'
char mygetchar( void );

#endif
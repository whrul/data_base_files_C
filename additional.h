#ifndef ADDITIONAL_H
#define ADDITIONAL_H

#define FORMAT(S) "%" #S "s"
#define S_FORMAT(S) FORMAT(S)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structs.h"

void* checkMemoryAlloc( void* wsk );
void clearBuf( void );
unsigned long long readInputPositiveNumber( void );
char* readInputWord( void );
char mygetchar( void );

#endif
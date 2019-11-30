#ifndef FILES_H
#define FILES_H

#define MAX_KEY_SIZE 50
#define MAX_VALUE_SIZE 50
#define MAX_LINE_LENGTH 120
#define FOR_CHAR 5

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "structs.h"

unsigned long long maxFileId( CopyFile* copyFileHead );
void clearCopyFiles( CopyFile** copyFileHead );
void showCopies( CopyFile* copyFileHead );
CopyFile* searchFileById( CopyFile* copyFileHead, int id );
bool dropCopy( CopyFile** copyFileHead, int id );

#endif
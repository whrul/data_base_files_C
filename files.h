// Author: Walerij Hrul
//
// Imitation of file class implementation
// used for uploading-saving data from-into txt-files 
//

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

// return the highest id among files, 0 if empty
unsigned long long maxFileId( CopyFile* copyFileHead );
// free allocated memory; set copyFileHead as NULL
void clearCopyFiles( CopyFile** copyFileHead );
// display list of files (id & name & data) / empty line if head is empty
void showCopies( CopyFile* copyFileHead );
// NULL is returned if none
CopyFile* searchFileById( CopyFile* copyFileHead, int id );
// info there is non which such id; also delete file txt from machine
bool dropCopy( CopyFile** copyFileHead, int id );

#endif
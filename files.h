// Author: Walerij Hrul
//
// Imitation of file class implementation
// used for uploading-saving data from-into txt-files 
//

#ifndef FILES_H
#define FILES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ownConsts.h"
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
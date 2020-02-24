// Author: Walerij Hrul
//
// Responsible for reading data from files and fill files-structre 
//

#ifndef FILE_READ_H
#define FILE_READ_H

#include <stdio.h>
#include <stdbool.h>
#include "structs.h"
#include "projects.h"
#include "managers.h"
#include "workers.h"
#include "project_worker.h"
#include "fileCheck.h"

// create list structure of existed files
bool readCopies( FILE* f, CopyFile** copyFileHead );
// wrapper for readCopies
bool loadCopies( CopyFile** copyFileHead );

// the second file used for preventing errors when load data from file after aborting the program while program was writing data into file 
bool readSecondFileWithCopies( CopyFile** copyFileHead );
bool readFirstFileWithCopies( CopyFile** copyFileHead );


bool takeDataFromCopy( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead, CopyFile** copyFileHead, int id_file );

#endif
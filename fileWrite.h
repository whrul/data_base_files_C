// Author: Walerij Hrul
//
// Responsible for writing data into txt-files
//

#ifndef FILE_WRITE_H
#define FILE_WRITE_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "files.h"
#include "additional.h"

// write data from structures into txt-file in data/copies/{input name}
// write new file into file with name of files for loading data from
// remove the file with data in case of error
bool createCopy( Project* projectHead, Manager* managerHead, Worker* workerHead, 
        Project_Worker* project_workerHead, CopyFile** copyFileHead, char** name, bool* badAlloc );
bool writeProjects( FILE* f, Project* projectHead );
bool writeProject( FILE* f, Project* project );
bool writeManagers( FILE* f, Manager* managerHead );
bool writeManager( FILE* f, Manager* manager );
bool writeWorkers( FILE* f, Worker* workerHead );
bool writeWorker( FILE* f, Worker* worker );
bool writeProjectWorkers( FILE* f, Project_Worker* project_workerHead );
bool writeProjectWorker( FILE* f, Project_Worker* project_worker );
// add prefix and postfix to name inputed by user
char* makeTrueNameOfFile( char* name, bool* badAlloc );

#endif
#ifndef FILE_WRITE_H
#define FILE_WRITE_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "files.h"
#include "additional.h"

bool createCopy( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, CopyFile** copyFileHead, char** name );
bool writeProjects( FILE* f, Project* projectHead );
bool writeProject( FILE* f, Project* project );
bool writeManagers( FILE* f, Manager* managerHead );
bool writeManager( FILE* f, Manager* manager );
bool writeWorkers( FILE* f, Worker* workerHead );
bool writeWorker( FILE* f, Worker* worker );
bool writeProjectWorkers( FILE* f, Project_Worker* project_workerHead );
bool writeProjectWorker( FILE* f, Project_Worker* project_worker );
char* makeTrueNameOfFile( char* name );

#endif
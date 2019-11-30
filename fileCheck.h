#ifndef FILE_CHECK_H
#define FILE_CHECK_H

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <limits.h>
#include "structs.h"
#include "projects.h"
#include "managers.h"
#include "workers.h"
#include "project_worker.h"

bool readChar( FILE* const temp, char symbol );
bool checkKey( char* const key, char* const buf );
bool writeTextValueOfKeyInVariable( FILE* const temp, char* key, char* variableForWriting );
bool writeNumberValueOfKeyInVariable( FILE* const temp, char* key, unsigned long long* variableForWriting );
bool readValueOfKey( FILE* const temp, char* key, char* readWord );
char checkForHash( FILE* temp );

bool checkFileForCorrect( FILE* f, Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead );
bool checkProject( FILE* f, Project** projectHead );
bool checkManager( FILE* f, Manager** managerHead );
bool checkWorker( FILE* f, Worker** workerHead );
bool checkProject_Worker( FILE* f, Project_Worker** project_workerHead );

bool checkForEndOfFile( FILE* f );

#endif
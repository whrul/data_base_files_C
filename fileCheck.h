// Author: Walerij Hrul
//
// Implementation of own json
// check file for correct format and create "database tables/objects"

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

// check if next readed char is equal to char arg
bool readChar( FILE* const temp, char symbol );
// check if buf starts with  \" + key + \" + :
bool checkKey( char* const key, char* const buf );
// check format of readed lines from file; return value of key in 2nd char* arg, false otherwise
bool writeTextValueOfKeyInVariable( FILE* const temp, char* key, char* variableForWriting );
// check format of readed lines from file; return value of key in 2nd char* arg, false otherwise
bool writeNumberValueOfKeyInVariable( FILE* const temp, char* key, unsigned long long* variableForWriting );
// if readed line contains \" + key + \" + ":" + value + , than write key in the 2nd char* arg; return false otherwise
bool readValueOfKey( FILE* const temp, char* key, char* readWord );
// check if next symbol is equal to #; # means end of each kind of "object" writed in file.txt
char checkForHash( FILE* temp );
// check format of file; create all lists from file; do not check date at the end of file
bool checkFileForCorrect( FILE* f, Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead, bool* badAlloc );
// create and add to list structure Project if readed lines have correct format
bool checkProject( FILE* f, Project** projectHead, bool* badAlloc );
// create and add to list structure Manager if readed lines have correct format
bool checkManager( FILE* f, Manager** managerHead, bool* badAlloc );
// create and add to list structure Worker if readed lines have correct format
bool checkWorker( FILE* f, Worker** workerHead, bool* badAlloc );
// create and add to list structure Project_Worker if readed lines have correct format
bool checkProject_Worker( FILE* f, Project_Worker** project_workerHead, bool* badAlloc );

// with saving actual position if not end
bool checkForEndOfFile( FILE* f );

#endif
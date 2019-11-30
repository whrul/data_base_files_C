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

bool readCopies( FILE* f, CopyFile** copyFileHead );
bool loadCopies( CopyFile** copyFileHead );
bool readSecondFileWithCopies( CopyFile** copyFileHead );
bool readFirstFileWithCopies( CopyFile** copyFileHead );
bool takeDataFromCopy( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead, CopyFile** copyFileHead, int id_file );

#endif
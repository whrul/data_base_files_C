#ifndef PROJECT_WORKER_H
#define PROJECT_WORKER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "structs.h"
#include "additional.h"

Project_Worker* addWorkerToProject( Project_Worker* project_workerHead, int id_worker, int id_project, int id );
unsigned long long maxProjectWorkerId( Project_Worker* project_workerHead );
void clearProjectWorker( Project_Worker** project_workerHead );
Project_Worker* searchProjectWorkerById( Project_Worker* project_workerHead, int id );
Project_Worker* dropProjectWorkerRow( Project_Worker* project_workerHead, int id );

#endif
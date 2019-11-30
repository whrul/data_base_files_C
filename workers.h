#ifndef WORKERS_H
#define WORKERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "structs.h"
#include "projects.h"
#include "menu.h"
#include "additional.h"

Worker* addWorker( Worker* workerHead, char surname[],  char name[], int id );
unsigned long long maxWorkerId( Worker* workerHead );
Worker* searchWorkerById( Worker* workerHead, int id );
Worker* dropWorker( Worker* workerHead, int id, Project_Worker** project_workerHead );
void showWorkers( Worker* workerHead );
void showFullWorkers( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, char id );
void clearWorkers( Worker** workerHead );

#endif
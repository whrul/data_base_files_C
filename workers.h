// Author: Walerij Hrul
//
// Imitation of worker class implementation 
//

#ifndef WORKERS_H
#define WORKERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include "sort.h"
#include "projects.h"
#include "project_worker.h"
#include "managers.h"

// return workerHead
Worker* addWorker( Worker* workerHead, char surname[],  char name[], int id, bool* badAlloc );
// return the highest id among workers, 0 if empty
unsigned long long maxWorkerId( Worker* workerHead );
// return NULL if there is non
Worker* searchWorkerById( Worker* workerHead, int id );
// return wokerHead; show info in output stream if there is no one with such id
Worker* dropWorker( Worker* workerHead, int id, Project_Worker** project_workerHead );
// display list of workers (id & surname & name) / info that it is empty
void showWorkers( Worker* workerHead );
// display list of workers (id & surname & name & projects) / info that it is empty
void showFullWorkers( Project* projectHead, Worker* workerHead, Project_Worker* project_workerHead, char id );
// free allocated memory; set workerHead as NULL
void clearWorkers( Worker** workerHead );

#endif

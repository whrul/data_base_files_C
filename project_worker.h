// Author: Walerij Hrul
//
// Control dependencies between projects-workers 
//

#ifndef PROJECT_WORKER_H
#define PROJECT_WORKER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "structs.h"
#include "projects.h"
#include "workers.h"
#include "managers.h"


// create "line" in "datatable id-id_project-id_worker" if line with such id_worker & id_project does not exist
Project_Worker* addWorkerToProject( Project_Worker* project_workerHead, int id_worker, int id_project, int id, bool* badAlloc );
// return the highest id in "datatable id-id_project-id_worker", 0 if empty
unsigned long long maxProjectWorkerId( Project_Worker* project_workerHead );
// free allocated memory; set project_workerHead as NULL
void clearProjectWorker( Project_Worker** project_workerHead );
// return NULL if there is non
Project_Worker* searchProjectWorkerById( Project_Worker* project_workerHead, int id );
// remove "line" from "datatable id-id_project-id_worker" if line with such id exist
Project_Worker* dropProjectWorkerRow( Project_Worker* project_workerHead, int id );

#endif
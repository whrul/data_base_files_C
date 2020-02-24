// Author: Walerij Hrul
//
// Imitation of project class implementation 
//

#ifndef PROJECTS_H
#define PROJECTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include "ownConsts.h"
#include "workers.h"
#include "managers.h"

// return projectHead
Project* addProject( Project* projectHead, char name[], int id_manager, int id, bool* badAlloc );
// return the highest id among projects, 0 if empty
unsigned long long maxProjectId( Project* projectHead );
// return NULL if there is non
Project* searchProjectById( Project* projectHead, int id );
// return projectHead; show info in output stream if there is no one with such id
Project* dropProject( Project* projectHead, int id, Project_Worker** project_workerHead );
// display list of projects (id & name) / info that it is empty
void showProjects( Project* projectHead );
// display list of projects (id & name & manager & workers) / info that it is empty
void showFullProjects( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, char id );
// free allocated memory; set projectHead as NULL
void clearProjects( Project** projectHead );
// only if project with such id exist; do not check if manager exist 
void addManagerToProject( Project* projectHead, int id_manager, int id_project );

#endif

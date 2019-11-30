#ifndef PROJECTS_H
#define PROJECTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include "structs.h"
#include "managers.h"
#include "workers.h"
#include "menu.h"
#include "additional.h"

Project* addProject( Project* projectHead, char name[], int id_manager, int id );
unsigned long long maxProjectId( Project* projectHead );
Project* searchProjectById( Project* projectHead, int id );
Project* dropProject( Project* projectHead, int id, Project_Worker** project_workerHead );
void showProjects( Project* projectHead );
void showFullProjects( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, char id );
void clearProjects( Project** projectHead );
void addManagerToProject( Project* projectHead, int id_manager, int id_project );

#endif
#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdbool.h>
#include "structs.h"
#include "projects.h"
#include "managers.h"
#include "workers.h"
#include "project_worker.h"
#include "sort.h"
#include "additional.h"
#include "fileRead.h"
#include "fileWrite.h"
#include "files.h"

void start( void );
void menu( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead, SortW** sortHeadW, SortN** sortHeadN, CopyFile** copyFileHead );
void show( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, SortW** sortHeadW, SortN** sortHeadN );
void askForFullList( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, SortW** sortHeadW, SortN** sortHeadN, char table );
void drop( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead );
void add( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead );
void addProjectMenu( Project** projectHead, char** name);
void addManagerMenu( Manager** managerHead, char** name, char** surname );
void addWorkerMenu( Worker** workerHead, char** name, char** surname );
bool addWorkerToProjectMenu( Project** projectHead, Worker** workerHead, Project_Worker** project_workerHead );
bool addManagerToProjectMenu( Project** projectHead, Manager** managerHead );
void dropProjectMenu( Project** projectHead, Project_Worker** project_workerHead );
void dropManagerMenu( Project** projectHead, Manager** managerHead );
void dropWorkerMenu( Worker** workerHead, Project_Worker** project_workerHead );
bool dropWorkerFromProjectMenu( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead );

void copies( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead, CopyFile** copyFileHead );

#endif

// Author: Walerij Hrul
//
// 
//

#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdbool.h>
#include "structs.h"
#include "projects.h"
#include "managers.h"
#include "workers.h"
#include "project_worker.h"
#include "files.h"
#include "ownConsts.h"
#include "additional.h"
#include "fileWrite.h"
#include "fileRead.h"

// show start info
void start( void );
// show main menu
void menu( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead, SortW** sortHeadW, SortN** sortHeadN, CopyFile** copyFileHead, bool* badAlloc );

// show separate parts of menu 
void show( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, SortW** sortHeadW, SortN** sortHeadN, bool* badAlloc );
void askForFullList( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, SortW** sortHeadW, SortN** sortHeadN, char table, bool* badAlloc );
void drop( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead );
void add( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead, bool* badAlloc );
void addProjectMenu( Project** projectHead, char** name, bool* badAlloc);
void addManagerMenu( Manager** managerHead, char** name, char** surname, bool* badAlloc );
void addWorkerMenu( Worker** workerHead, char** name, char** surname, bool* badAlloc );
bool addWorkerToProjectMenu( Project** projectHead, Worker** workerHead, Project_Worker** project_workerHead, bool* badAlloc );
bool addManagerToProjectMenu( Project** projectHead, Manager** managerHead );
void dropProjectMenu( Project** projectHead, Project_Worker** project_workerHead );
void dropManagerMenu( Project** projectHead, Manager** managerHead );
void dropWorkerMenu( Worker** workerHead, Project_Worker** project_workerHead );
bool dropWorkerFromProjectMenu( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead );
void copies( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead, CopyFile** copyFileHead, bool* badAlloc );

#endif

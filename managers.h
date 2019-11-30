#ifndef MANAGERS_H
#define MANAGERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "structs.h"
#include "workers.h"
#include "menu.h"
#include "additional.h"

Manager* addManager( Manager* managerHead, char surname[],  char name[], int id );
unsigned long long maxManagerId( Manager* managerHead );
Manager* searchManagerById( Manager* managerHead, int id );
Manager* dropManager( Manager* managerHead, int id, Project* projectHead );
void showManagers( Manager* managerHead );
void showFullManagers( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, char id );
void clearManagers( Manager** managerHead );

#endif
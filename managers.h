// Author: Walerij Hrul
//
// Imitation of manager class implementation 
//

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

// return managerHead
Manager* addManager( Manager* managerHead, char surname[],  char name[], int id, bool* badAlloc );
// return the highest id among managers, 0 if empty
unsigned long long maxManagerId( Manager* managerHead );
// return NULL if there is non
Manager* searchManagerById( Manager* managerHead, int id );
// return managerHead; show info in output stream if there is no one with such id
Manager* dropManager( Manager* managerHead, int id, Project* projectHead );
// display list of managers (id & surname & name) / info that it is empty
void showManagers( Manager* managerHead );
// display list of managers (id & surname & name & projects with workers) / info that it is empty
void showFullManagers( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, char id );
// free allocated memory; set managerHead as NULL
void clearManagers( Manager** managerHead );

#endif

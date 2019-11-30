#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "structs.h"
#include "managers.h"
#include "workers.h"
#include "additional.h"

SortW* copyProjectW( Project* projectHead, SortW** sortHead );
SortN* copyProjectN( Project* projectHead, SortN** sortHead, Project_Worker* project_workerHead );
SortW* copyManagerW( Manager* managerHead, SortW** sortHead );
SortW* copyWorkerW( Worker* workerHead, SortW** sortHead );
SortW* sortByWord(  SortW** sortHead );
SortN* sortByNumber( SortN** sortHead );
void showProjectsSortW( SortW* sortHead );
void showProjectsSortN( SortN* sortHead, Project* projectHead );
void showManagersSortW( SortW* sortHead, Manager* managerHead );
void showWorkersSortW( SortW* sortHead, Worker* workerHead );
void clearSortW( SortW** sortHead );
void clearSortN( SortN** sortHead );

#endif
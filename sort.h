// Author: Walerij Hrul
//
// Sorting by making copies lists of data
//

#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "structs.h"
#include "additional.h"
#include "projects.h"
#include "managers.h"
#include "workers.h"

// create copy of list of projects for sorting by name
SortW* copyProjectW( Project* projectHead, SortW** sortHead, bool* badAlloc );
// create copy of list of projects for sorting by number of workers
SortN* copyProjectN( Project* projectHead, SortN** sortHead, Project_Worker* project_workerHead, bool* badAlloc );
// create copy of list of managers for sorting by surname
SortW* copyManagerW( Manager* managerHead, SortW** sortHead, bool* badAlloc );
// create copy of list of workers for sorting by surname
SortW* copyWorkerW( Worker* workerHead, SortW** sortHead, bool* badAlloc );
// sort created copy by comparing char[]; in alphabetic order; bubble sort
SortW* sortByWord(  SortW** sortHead );
// sort created copy by comparing int; asc order; bubble sort
SortN* sortByNumber( SortN** sortHead );

// just show list (id & sorted value) / info that empty; without sorting
void showProjectsSortW( SortW* sortHead );
void showProjectsSortN( SortN* sortHead, Project* projectHead );
void showManagersSortW( SortW* sortHead, Manager* managerHead );
void showWorkersSortW( SortW* sortHead, Worker* workerHead );

// free allocated memory; set sortHead as NULL
void clearSortW( SortW** sortHead );
void clearSortN( SortN** sortHead );

#endif
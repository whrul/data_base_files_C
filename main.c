#include <stdbool.h>
#include "structs.h"
#include "projects.h"
#include "managers.h"
#include "workers.h"
#include "project_worker.h"
#include "files.h"
#include "fileRead.h"
#include "menu.h"

void ownClearMemory( Project* projectHead, Manager* managerHead, Worker* workerHead, 
        Project_Worker* project_workerHead, CopyFile* copyFileHead );

int main( void ){ 
	Project* projectHead = NULL;
	Manager* managerHead = NULL;
	Worker* workerHead = NULL;
	Project_Worker* project_workerHead = NULL;
	SortW* sortHeadW = NULL;
	SortN* sortHeadN = NULL;	
	CopyFile* copyFileHead = NULL; 
	bool badAlloc = false;

	start();
	if( !loadCopies( &copyFileHead, &badAlloc ) ){
		puts("Load files of copies: unsuccessfully.");
		if ( badAlloc ) {
			puts("Bad alloc error");
			ownClearMemory( projectHead, managerHead, workerHead, project_workerHead, copyFileHead );
			return 1;
		}
	}
	else{
		puts("Load files of copies: successfully.");
	}
	menu( &projectHead, &managerHead, &workerHead, &project_workerHead, &sortHeadW, &sortHeadN, &copyFileHead, &badAlloc );
	if ( badAlloc ) {
		puts("Bad alloc error");
		ownClearMemory( projectHead, managerHead, workerHead, project_workerHead, copyFileHead );
		return 1;
	}
	ownClearMemory( projectHead, managerHead, workerHead, project_workerHead, copyFileHead );

	return 0;
}

void ownClearMemory( Project* projectHead, Manager* managerHead, Worker* workerHead, 
        Project_Worker* project_workerHead, CopyFile* copyFileHead ) {
			clearProjects( &projectHead ); 
			clearManagers( &managerHead );
			clearWorkers( &workerHead );
			clearProjectWorker( &project_workerHead );
			clearCopyFiles( &copyFileHead );
}

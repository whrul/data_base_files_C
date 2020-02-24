#include "structs.h"
#include "projects.h"
#include "managers.h"
#include "workers.h"
#include "project_worker.h"
#include "sort.h"
#include "menu.h"
#include "additional.h"
#include "fileRead.h"

int main( void )
{      // '\0'   ferror->fclose? 
	Project* projectHead = NULL;
	Manager* managerHead = NULL;
	Worker* workerHead = NULL;
	Project_Worker* project_workerHead = NULL;
	SortW* sortHeadW = NULL;
	SortN* sortHeadN = NULL;	
	CopyFile* copyFileHead = NULL; 


	start();
	
	bool badAlloc = false;

	if( !loadCopies( &copyFileHead, &badAlloc ) ){
		puts("Load files of copies: unsuccessfully.");
		if ( badAlloc ) {
			puts("Bad alloc error");
			clearProjects( &projectHead ); 
			clearManagers( &managerHead );
			clearWorkers( &workerHead );
			clearProjectWorker( &project_workerHead );
			clearCopyFiles( &copyFileHead );
			return 1;
		}
	}
	else{
		puts("Load files of copies: successfully.");
	}
	
	menu( &projectHead, &managerHead, &workerHead, &project_workerHead, &sortHeadW, &sortHeadN, &copyFileHead, &badAlloc );
	if ( badAlloc ) {
		puts("Bad alloc error");
		clearProjects( &projectHead ); 
		clearManagers( &managerHead );
		clearWorkers( &workerHead );
		clearProjectWorker( &project_workerHead );
		clearCopyFiles( &copyFileHead );
		return 1;
	}

	clearProjects( &projectHead ); 
	clearManagers( &managerHead );
	clearWorkers( &workerHead );
	clearProjectWorker( &project_workerHead );
	clearCopyFiles( &copyFileHead );

	return 0;
}
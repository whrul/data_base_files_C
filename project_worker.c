#include "project_worker.h"

Project_Worker* addWorkerToProject( Project_Worker* project_workerHead, int id_worker, int id_project, int id, bool* badAlloc ){

	Project_Worker* test = project_workerHead;
	while( test ){
		if( test->id_worker == id_worker && test->id_project == id_project){
			return project_workerHead;
		}
		test = test->next;
	}

	Project_Worker* pw1 = checkMemoryAlloc( malloc( sizeof( Project_Worker ) ), badAlloc );
	if( *badAlloc ) {
		return project_workerHead;
	}
	pw1->id_worker = id_worker;
	pw1->id_project = id_project;
	pw1->id = id;
	pw1->next = NULL;

	Project_Worker* temp = project_workerHead;
	if( !temp ){
		return pw1;
	}
	else{
		while( temp->next != NULL){
			temp = temp->next;
		}
		temp->next = pw1;
		return project_workerHead;
	}
}

unsigned long long maxProjectWorkerId( Project_Worker* project_workerHead )
{
	unsigned long long id = 0;
	Project_Worker* temp = project_workerHead;
	if( temp ){
		while( temp->next != NULL ){
			temp = temp -> next;
		}
		id = temp->id;
	}
	return id;
}

void clearProjectWorker( Project_Worker** project_workerHead ){
	Project_Worker* prev = NULL;
	while( *project_workerHead ){
		prev = *project_workerHead;
		*project_workerHead = (*project_workerHead)->next;
		free(prev);
	}

}

Project_Worker* dropProjectWorkerRow( Project_Worker* project_workerHead, int id ){
	Project_Worker* elementForDrop = searchProjectWorkerById( project_workerHead, id );
	if( !elementForDrop ){
		return project_workerHead;
	}
	if ( elementForDrop != project_workerHead ){
		Project_Worker* temp = project_workerHead;
		while( temp->next != elementForDrop){
			temp = temp->next;
		}
		temp->next = elementForDrop->next;
		free( elementForDrop );
		elementForDrop = NULL;
	}
	else{
		project_workerHead = elementForDrop->next;
		free( elementForDrop );	
		elementForDrop = NULL;
	}
	return project_workerHead;
}

Project_Worker* searchProjectWorkerById( Project_Worker* project_workerHead, int id ){
	Project_Worker* temp = project_workerHead;
	while( temp != NULL ){
		if( temp->id == id){
			return temp;
		}
		temp = temp -> next;
	}
	return NULL;
}
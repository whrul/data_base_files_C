#include "workers.h"

Worker* addWorker( Worker* workerHead, char surname[], char name[], int id, bool* badAlloc ){
	Worker* w1 = checkMemoryAlloc( malloc( sizeof( Worker ) ), badAlloc );
	if( *badAlloc ){
		return workerHead;
	}
	strcpy(w1->name, name);
	strcpy(w1->surname, surname);
	w1->id = id;
	w1->next = NULL;

	Worker* temp = workerHead;
	if( !temp ){
		return w1;
	}
	else{
		while( temp->next != NULL ){
			temp = temp -> next;
		}
		temp->next = w1;
		return workerHead;
	}
}

unsigned long long maxWorkerId( Worker* workerHead )
{
	unsigned long long id = 0;
	Worker* temp = workerHead;
	if( temp ){
		while( temp->next != NULL ){
			temp = temp -> next;
		}
		id = temp->id;
	}
	return id;
}

Worker* searchWorkerById( Worker* workerHead, int id ){
	Worker* temp = workerHead;
	while( temp != NULL ){
		if( temp->id == id){
			return temp;
		}
		temp = temp -> next;
	}
	return NULL;
}

Worker* dropWorker( Worker* workerHead, int id, Project_Worker** project_workerHead )
{
	Worker* elementForDrop = searchWorkerById( workerHead, id );
	if( !elementForDrop ){
		puts("Incorrect id.");
		return workerHead;
	}
	if ( elementForDrop != workerHead ){
		Worker* temp = workerHead;
		while( temp->next != elementForDrop){
			temp = temp->next;
		}
		temp->next = elementForDrop->next;
		free( elementForDrop );
		elementForDrop = NULL;
	}
	else{
		workerHead = elementForDrop->next;
		free( elementForDrop );	
		elementForDrop = NULL;
	}

	Project_Worker* temp = *project_workerHead;
	while( temp ){
		if( temp->id_worker == id){
			int id_row_for_deleting = temp->id;
			temp = temp->next;
			*project_workerHead = dropProjectWorkerRow( *project_workerHead, id_row_for_deleting );
		}
		else{
			temp=temp->next;
		}		
	}

	return workerHead;
}

void showWorkers( Worker* workerHead ){
	Worker* temp = workerHead;
	if( temp ){
		printf(" id | %*s | %*s |\n", MAX_LENGTH, "surname", MAX_LENGTH, "name");
		while( temp ){		
			printf("| %llu | %*s | %*s | \n", temp->id, MAX_LENGTH, temp->surname, MAX_LENGTH, temp->name);
			temp = temp->next;
		}
	}
	else{
		puts("Empty");
	}
	
}

void showFullWorkers( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, char id ){
	Project* project = projectHead;
	Manager* manager = managerHead;
	Worker* worker = workerHead;
	Project_Worker* project_worker;
	if( worker ){

		puts("Workers:");
		while( worker ){
			puts("");
			if( worker->id == id - '0' || '*' == id )
			{
			printf("Id: %llu,\n", worker->id);
			printf("Surname & Name: %s %s,\n", worker->surname, worker->name);	
			printf("Projects:");
			project_worker = project_workerHead;
			while( project_worker ){
				if( project_worker->id_worker == worker->id){
					printf("  %s,", searchProjectById( project, project_worker->id_project )->name );
				}
				project_worker = project_worker->next;
			}
			puts("");	

			}
			worker = worker->next;
		}

	}
	else{
		puts("Empty");
	}
}

void clearWorkers( Worker** workerHead ){
	Worker* prev = NULL;
	while( *workerHead ){
		prev = *workerHead;
		*workerHead = (*workerHead)->next;
		free( prev );
	}
}
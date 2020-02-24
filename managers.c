#include "managers.h"

Manager* addManager( Manager* managerHead, char surname[], char name[], int id, bool* badAlloc ){
	Manager* m1 = checkMemoryAlloc( malloc( sizeof( Manager ) ), badAlloc );
	if( *badAlloc ){
		return managerHead;
	}
	strcpy(m1->name, name);
	strcpy(m1->surname, surname);
	m1->id = id;
	m1->next = NULL;

	Manager* temp = managerHead;
	if( !temp ){
		return m1;
	}
	else{
		while( temp->next != NULL ){
			temp = temp -> next;
		}
		temp->next = m1;
		return managerHead;
	}
}

unsigned long long maxManagerId( Manager* managerHead )
{
	unsigned long long id = 0;
	Manager* temp = managerHead;
	if( temp ){
		while( temp->next != NULL ){
			temp = temp -> next;
		}
		id = temp->id;
	}
	return id;
}

Manager* searchManagerById( Manager* managerHead, int id ){
	Manager* temp = managerHead;
	while( temp != NULL ){
		if( temp->id == id){
			return temp;
		}
		temp = temp -> next;
	}
	return NULL;
}

Manager* dropManager( Manager* managerHead, int id, Project* projectHead )
{
	Manager* elementForDrop = searchManagerById( managerHead, id );
	if( !elementForDrop ){
		puts("Incorrect id.");
		return managerHead;
	}
	if ( elementForDrop != managerHead){
		Manager* temp = managerHead;
		while( temp->next != elementForDrop)
		{
			temp = temp->next;
		}
		temp->next = elementForDrop->next;
		free( elementForDrop );
		elementForDrop = NULL;
	}
	else{
		managerHead = elementForDrop->next;
		free( elementForDrop );	
		elementForDrop = NULL;
	}

	Project* temp = projectHead;
	while( temp ){
		if( temp->id_manager == id){
			temp->id_manager == 0;
		}		
		temp=temp->next;	
	}
	return managerHead;
}

void showManagers( Manager* managerHead ){
	Manager* temp = managerHead;
	if( temp ){
		puts("\nMangers:");
		printf(" id | %*s | %*s | \n", MAX_LENGTH, "surname", MAX_LENGTH, "name" );
		while( temp ){		
			printf("| %llu | %15s | %15s | \n", temp->id, temp->surname, temp->name);
			temp = temp->next;
		}
	}
	else{
		puts("Empty");
	}
	
}

void showFullManagers( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, char id ){
	Project* project;
	Manager* manager = managerHead;
	Worker* worker = NULL;
	Project_Worker* project_worker;
	if( manager )
	{
		puts("\nMangers:");
		while( manager ){
			
			if( manager->id == id - '0' || '*' == id ){
				printf("\nId: %llu,\n", manager->id);	
				printf("Surname & Name: %s %s,\n", manager->surname, manager->name );	

				project = projectHead;	
				while( project ){
					if( project->id_manager == manager->id){
						printf("Project: %s,\n", project->name);
						project_worker = project_workerHead;
						printf("Workers:");
						while( project_worker ){
							if( project_worker->id_project == project->id ){
								worker = searchWorkerById( workerHead, project_worker->id_worker );
								printf(" %s %s,", worker->surname, worker->name);
							}
							project_worker = project_worker->next;
						}
						puts("");
					}
					project = project->next;
				}
			}
			manager = manager->next;
		}
	}
	else{
		puts("Empty");
	}
	
}


void clearManagers( Manager** managerHead ){
	Manager* prev = NULL;
	while( *managerHead )
	{
		prev = *managerHead;
		*managerHead = (*managerHead)->next;
		free( prev );
	}
}
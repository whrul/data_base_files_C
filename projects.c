#include "projects.h"

Project* addProject( Project* projectHead, char name[], int id_manager, int id ){
	Project* p1 = checkMemoryAlloc( malloc( sizeof( Project ) ) );
	strcpy(p1->name, name);
	p1->id = id;
	p1->id_manager = id_manager;
	p1->next = NULL;

	Project* temp = projectHead;
	if( !temp ){
		return p1;
	}
	else{
		while( temp->next != NULL ){
			temp = temp -> next;
		}
		temp->next = p1;
		return projectHead;
	}
}

unsigned long long maxProjectId( Project* projectHead )
{
	unsigned long long id = 0;
	Project* temp = projectHead;
	if( temp ){
		while( temp->next != NULL ){
			temp = temp -> next;
		}
		id = temp->id;
	}
	return id;
}

Project* searchProjectById( Project* projectHead, int id ){
	Project* temp = projectHead;
	while( temp != NULL ){
		if( temp->id == id){
			return temp;
		}
		temp = temp -> next;
	}
	return NULL;
}


void addManagerToProject( Project* projectHead, int id_manager, int id_project ){
	Project* temp = searchProjectById( projectHead, id_project );
	if( temp ){
		temp->id_manager = id_manager;
	}
}

Project* dropProject( Project* projectHead, int id, Project_Worker** project_workerHead )
{
	Project* elementForDrop = searchProjectById( projectHead, id );
	if( !elementForDrop ){
		puts("Incorrect id.");
		return projectHead;
	}
	if ( elementForDrop != projectHead ){
		Project* temp = projectHead;
		while( temp->next != elementForDrop){
			temp = temp->next;
		}
		temp->next = elementForDrop->next;
		free( elementForDrop );
		elementForDrop = NULL;
	}
	else{
		projectHead = elementForDrop->next;
		free( elementForDrop );	
		elementForDrop = NULL;
	}

	Project_Worker* temp = *project_workerHead;
	while( temp ){
		if( temp->id_project == id){
			int id_row_for_deleting = temp->id;
			temp = temp->next;
			*project_workerHead = dropProjectWorkerRow( *project_workerHead, id_row_for_deleting );
		}
		else{
			temp=temp->next;
		}		
	}
	return projectHead;
}

void clearProjects( Project** projectHead ){
	Project* prev = NULL;
	while( *projectHead ){
		prev = *projectHead;
		*projectHead = (*projectHead)->next;
		free( prev );
	}
}

void showProjects( Project* projectHead ){
	Project* temp = projectHead;
	if( temp ){
		printf(" id | %*s |\n", MAX_LENGTH, "name");
		while( temp ){		
			printf("| %llu | %*s |\n", temp->id, MAX_LENGTH, temp->name);
			temp = temp->next;
		}
	}
	else{
		puts("Empty");
	}
	
}

void showFullProjects( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, char id ){
	Project* project = projectHead;
	Manager* manager = NULL;
	Worker* worker = NULL;
	Project_Worker* project_worker;
	if( project ){
		puts("\nProjects:");
		while( project ){	
			if( project->id == id - '0' || '*' == id )
			{
				printf("\nId: %llu,\n", project->id);	
				printf("Name: %s,\n", project->name);	
				manager = searchManagerById( managerHead, project->id_manager );
				printf("Manager:");
				if( manager ){
					printf(" %s %s,", manager->surname, manager->name);
				}	
				printf("\n");
				printf("Workers:");		
				project_worker = project_workerHead;
				while( project_worker ){
					if( project_worker->id_project == project->id){
						worker = searchWorkerById( workerHead, project_worker->id_worker );
						printf(" %s %s,", worker->surname, worker->name );
					}
					project_worker = project_worker->next;
				}
				printf("\n");
			}
			project = project->next;
		}
	}
	else{
		puts("Empty");
	}
	
}
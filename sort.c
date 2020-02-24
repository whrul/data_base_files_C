#include "sort.h"

void clearSortW( SortW** sortHead ){
	SortW* prev = NULL;
	while( *sortHead ){
		prev = *sortHead;
		*sortHead = (*sortHead)->next;
		free( prev );
	}
}

void clearSortN( SortN** sortHead ){
	SortN* prev = NULL;
	while( *sortHead ){
		prev = *sortHead;
		*sortHead = (*sortHead)->next;
		free( prev );
	}
}

SortW* copyProjectW( Project* projectHead, SortW** sortHead, bool* badAlloc )
{
	Project* copyProject = projectHead;
	if( !copyProject ){
		return NULL;
	}
	while( copyProject )
	{
		SortW* s1 = checkMemoryAlloc( malloc( sizeof( SortW ) ), badAlloc );
		if( *badAlloc ){
			return *sortHead;
		}
		s1->id = copyProject->id;
		strcpy(s1->sortWord, copyProject->name);
		s1->next = NULL;

		SortW* temp = *sortHead;
		if( !temp ){
			*sortHead = s1;
		}
		else{
			while( temp->next != NULL ){
				temp = temp -> next;
			}
			temp->next = s1;
		}
		copyProject = copyProject->next;
	}
	return *sortHead;
}

SortN* copyProjectN( Project* projectHead, SortN** sortHead, Project_Worker* project_workerHead, bool* badAlloc )
{
	Project* copyProject = projectHead;
	if( !copyProject ){
		return NULL;
	}
	while( copyProject )
	{
		SortN* s1 = checkMemoryAlloc( malloc( sizeof( SortN ) ), badAlloc );
		if( *badAlloc ){
			return *sortHead;
		}
		s1->id = copyProject->id;
		s1->next = NULL;

		int numberOfWorkers = 0;
		Project_Worker* projectworker = project_workerHead;
		while( projectworker ){
			if( projectworker->id_project == copyProject->id ){
				++numberOfWorkers;
			}
			projectworker = projectworker->next;
		}

		s1->sortNumber = numberOfWorkers;

		SortN* temp = *sortHead;
		if( !temp ){
			*sortHead = s1;
		}
		else{
			while( temp->next != NULL ){
				temp = temp -> next;
			}
			temp->next = s1;
		}
		copyProject = copyProject->next;
	}
	return *sortHead;
}

SortW* copyManagerW( Manager* managerHead, SortW** sortHead, bool* badAlloc )
{
	Manager* copyManager = managerHead;
	if( !copyManager ){
		return NULL;
	}
	while( copyManager )
	{
		SortW* s1 = checkMemoryAlloc( malloc( sizeof( SortW ) ), badAlloc );
		if( *badAlloc ){
			return *sortHead;
		}
		s1->id = copyManager->id;
		strcpy(s1->sortWord, copyManager->surname);
		s1->next = NULL;

		SortW* temp = *sortHead;
		if( !temp ){
			*sortHead = s1;
		}
		else{
			while( temp->next != NULL ){
				temp = temp -> next;
			}
			temp->next = s1;
		}
		copyManager = copyManager->next;
	}
	return *sortHead;
}

SortW* copyWorkerW( Worker* workerHead, SortW** sortHead, bool* badAlloc )
{
	Worker* copyWorker = workerHead;
	if( !copyWorker ){
		return NULL;
	}
	while( copyWorker )
	{
		SortW* s1 = checkMemoryAlloc( malloc( sizeof( SortW ) ), badAlloc );
		if( *badAlloc ){
			return *sortHead;
		}
		s1->id = copyWorker->id;
		strcpy(s1->sortWord, copyWorker->surname);
		s1->next = NULL;

		SortW* temp = *sortHead;
		if( !temp ){
			*sortHead = s1;
		}
		else
		{
			while( temp->next != NULL ){
				temp = temp -> next;
			}
			temp->next = s1;
		}
		copyWorker = copyWorker->next;
	}
	return *sortHead;
}

SortW* sortByWord( SortW** sortHead ){
	SortW* temp = *sortHead;
	if( !temp ){
		return NULL;
	}

	SortW* prev = NULL;
	bool swap = true;

	int i = 0;
	bool needforswap = false;
	while( swap ){
		swap = false;		
		while( temp->next )
		{
			i = 0;
			needforswap = false;
			while( i <= MAX_LENGTH ){
				if(	temp->sortWord[i] == '\0' ){
					break;
				}
				if(	temp->next->sortWord[i] == '\0' ){
					needforswap = true;
					break;
				}

				if( temp->sortWord[i]  > temp->next->sortWord[i] ){
					needforswap = true;
					break;
				}
				else if( temp->sortWord[i]  < temp->next->sortWord[i] ){
					break;
				}
				++i;
			}
			if( needforswap ){
				SortW* help = temp->next;
				temp->next = temp->next->next;
				help->next = temp;
			
				if( temp == *sortHead){
					*sortHead = help;
				}
				else{
					prev->next = help; 
				}
				prev = help;
				swap = true;
			}
			else{
				prev = temp;
				temp = temp->next;
			}		
		}
		temp = *sortHead;
	}
	
	return *sortHead;
}

SortN* sortByNumber( SortN** sortHead ){
	SortN* temp = *sortHead;
	if( !temp ){
		return NULL;
	}

	SortN* prev = NULL;
	bool swap = true;

	bool needforswap = false;
	while( swap ){
		swap = false;		
		while( temp->next ){
			needforswap = false;
			if( temp->sortNumber > temp->next->sortNumber ){
				needforswap = true;
			}
			if( needforswap ){
				SortN* help = temp->next;
				temp->next = temp->next->next;
				help->next = temp;
			
				if( temp == *sortHead){
					*sortHead = help;
				}
				else{
					prev->next = help; 
				}
				prev = help;
				swap = true;
			}
			else{
				prev = temp;
				temp = temp->next;
			}		
		}
		temp = *sortHead;
	}
	
	return *sortHead;
}

void showProjectsSortW( SortW* sortHead ){
	SortW* temp = sortHead;
	if( temp ){
		puts("Sort by name of project:");
		puts(" - - - - - - - - - - - ");
		printf(" id | %*s |\n", MAX_LENGTH, "name");
		while( temp ){		
			printf("| %llu | %*s |\n", temp->id, MAX_LENGTH, temp->sortWord);
			temp = temp->next;
		}
	}
	else{
		puts("Empty");
	}
	
}

void showManagersSortW( SortW* sortHead, Manager* managerHead ){
	SortW* temp = sortHead;
	if( temp ){
		printf(" id | surname & name |\n");
		while( temp ){		
			Manager* manager = searchManagerById( managerHead, temp->id );
			printf("| %llu | %s %s |\n", temp->id, manager->surname, manager->name);
			temp = temp->next;
		}
	}
	else{
		puts("Empty");
	}
	
}

void showWorkersSortW( SortW* sortHead, Worker* workerHead ){
	SortW* temp = sortHead;
	if( temp ){
		printf(" id | surname & name |\n");
		while( temp ){		
			Worker* worker = searchWorkerById( workerHead, temp->id );
			printf("| %llu | %s %s |\n", temp->id, worker->surname, worker->name);
			temp = temp->next;
		}
	}
	else{
		puts("Empty");
	}
	
}

void showProjectsSortN( SortN* sortHead, Project* projectHead ){
	SortN* temp = sortHead;
	if( temp ){
		puts("\nSort by ammount of workers in the projects:");
		puts(" - - - - - - - - - - - - - -  - - - - - - ");
		printf(" id | %*s | ammount of workers \n", MAX_LENGTH, "name");
		while( temp ){		
			Project* project = searchProjectById( projectHead, temp->id );
			printf("| %llu | %*s | %d \n", temp->id, MAX_LENGTH, project->name, temp->sortNumber);
			temp = temp->next;
		}
	}
	else{
		puts("Empty");
	}	
}
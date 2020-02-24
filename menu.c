#include "menu.h"

void start()
{
    puts("-----------------");
    puts("Welcome to the DataBase powered by Walerij Hrul.");
    puts("-----------------");
}

void menu( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead, SortW** sortHeadW, SortN** sortHeadN, CopyFile** copyFileHead, bool* badAlloc )
{
	char choice = '&';
	while( 'q' != choice){
		puts("\n| Please, choose type of action:");
    	puts("| 1 - for DISPLAYing smth");
    	puts("| 2 - for CREATing/ADDing");
    	puts("| 3 - for DELETing smth");
    	puts("| 4 - for work with COPIES");
    	puts("| q - for exit the program\n");

		choice = mygetchar();
		clearBuf();

		switch( choice ){
			case '1':
				show( *projectHead, *managerHead, *workerHead, *project_workerHead, sortHeadW, sortHeadN, badAlloc );
				if( *badAlloc ){
					return;
				}
				break;
			case '2':
				add( projectHead, managerHead, workerHead, project_workerHead, badAlloc );
				if( *badAlloc ){
					return;
				}
				break;
			case '3':
				drop( projectHead, managerHead, workerHead, project_workerHead );
				break;
			case '4':
				copies( projectHead, managerHead, workerHead, project_workerHead, copyFileHead, badAlloc );
				if( *badAlloc ){
					return;
				}
				break;
		}
	}
}

void show( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, SortW** sortHeadW, SortN** sortHeadN, bool* badAlloc ){

    char choice = '&';
	while( '0' != choice){
		puts("\n| 1 - show Projects");
    	puts("| 2 - show Managers");
    	puts("| 3 - show Workers");
    	puts("| 0 - for return to main menu\n");

		choice = mygetchar();
		clearBuf();

		switch( choice ){
			case '1':
				puts("");
				showProjects( projectHead );
				if( projectHead )
				{
					askForFullList( projectHead, managerHead, workerHead, project_workerHead, sortHeadW, sortHeadN, 'p', badAlloc );
					if( *badAlloc ){
						return;
					}
				}				
				break;
			case '2':
				puts("");
				showManagers( managerHead );
				if( managerHead )
				{
					askForFullList( projectHead, managerHead, workerHead, project_workerHead, sortHeadW, sortHeadN, 'm', badAlloc );
					if( *badAlloc ){
						return;
					}
				}				
				break;
			case '3':
				puts("");
				showWorkers( workerHead );
				if( workerHead )
				{
					askForFullList( projectHead, managerHead, workerHead, project_workerHead, sortHeadW, sortHeadN, 'w', badAlloc );
					if( *badAlloc ){
						return;
					}
				}	
				break;
		}
	}

}

void askForFullList( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, SortW** sortHeadW, SortN** sortHeadN, char table, bool* badAlloc )
{
	char id = '&';
	while( 's' != id){
		puts("\n| If you want to watch more about some object input its id ('*' - for showing more information about all objects) ");
		puts("| If you want to watch the ordered list input o");
		puts("| s - for skip\n");

		id = mygetchar();
		clearBuf();

		if( isdigit( id ) || '*' == id ){
			switch ( table ){
				case 'p':
					showFullProjects( projectHead, managerHead, workerHead, project_workerHead, id );
					break;
				case 'm':
					showFullManagers( projectHead, managerHead, workerHead, project_workerHead, id );
					break;
				case 'w':
					showFullWorkers( projectHead, workerHead, project_workerHead, id );			
					break;
			}
			
		}
		if( 'o' == id ){
			switch ( table ){
				case 'p':
					*sortHeadW = copyProjectW( projectHead, sortHeadW, badAlloc );
					if( *badAlloc ){
						return;
					}
					*sortHeadW = sortByWord( sortHeadW );
					showProjectsSortW( *sortHeadW );
					clearSortW( sortHeadW );
					*sortHeadW = NULL;

					*sortHeadN = copyProjectN( projectHead, sortHeadN, project_workerHead, badAlloc );
					if( *badAlloc ){
						return;
					}
					*sortHeadN = sortByNumber( sortHeadN );
					showProjectsSortN( *sortHeadN, projectHead );
					clearSortN( sortHeadN );
					*sortHeadN = NULL;

					break;
				case 'm':
					*sortHeadW = copyManagerW( managerHead, sortHeadW, badAlloc );
					if( *badAlloc ){
						return;
					}
					*sortHeadW = sortByWord( sortHeadW );
					showManagersSortW( *sortHeadW, managerHead );
					clearSortW( sortHeadW );
					*sortHeadW = NULL;
					break;
				case 'w':
					*sortHeadW = copyWorkerW( workerHead, sortHeadW, badAlloc );
					if( *badAlloc ){
						return;
					}
					*sortHeadW = sortByWord( sortHeadW );
					showWorkersSortW( *sortHeadW, workerHead );
					clearSortW( sortHeadW );
					*sortHeadW = NULL;
					break;
			}
		}
	}
}

void add( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead, bool* badAlloc ){

    char choice = '&';
	while( '0' != choice){
		puts("\n| 1 - add project");
    	puts("| 2 - add manager");
    	puts("| 3 - add worker");
    	puts("| 4 - involve worker in project");
    	puts("| 5 - involve/change manager in project");
    	puts("| 0 - return to main menu\n");

		choice = mygetchar();
		clearBuf();

		char* name = NULL;
		char* surname = NULL;
		switch( choice ){
			case '1':
				addProjectMenu( projectHead, &name, badAlloc );
				if (badAlloc) {
					free( name );
					free( surname );
					return;
				}
				break;
			case '2':
				addManagerMenu( managerHead, &name, &surname, badAlloc );
				if (badAlloc) {
					free( name );
					free( surname );
					return;
				}
				break;
			case '3':
				addWorkerMenu( workerHead, &name, &surname, badAlloc );
				if (badAlloc) {
					free( name );
					free( surname );
					return;
				}
				break;
			case '4':
				if( !addWorkerToProjectMenu( projectHead, workerHead, project_workerHead, badAlloc ) ){
					puts("0 changed rows");
					if (badAlloc) {
						free( name );
						free( surname );
						return;
					}
				}
				else{
					puts("Done");
				}				
				break;
			case '5':
				if( !addManagerToProjectMenu( projectHead, managerHead ) ){
					puts("0 changed rows");
				}
				else{
					puts("Added");
				}				
				break;
		}

		free( name );
		free( surname );
	}
}

void addProjectMenu( Project** projectHead, char** name, bool* badAlloc ){
	printf("\nInput name of project: ");
	*name = readInputWord( badAlloc );
	if( *badAlloc ){
		return;
	}
	if( *name )
	{
		*projectHead = addProject( *projectHead, *name, 0, maxProjectId( *projectHead ) + 1, badAlloc );
		if( *badAlloc ){
			return;
		}
		puts("Added");
	}
	else
	{
		puts("Some problems");
	}
}


void addManagerMenu( Manager** managerHead, char** name, char** surname, bool* badAlloc){
	printf("\nInput surname of manager: ");
	*surname = readInputWord( badAlloc );
	if( *badAlloc ){
		return;
	}
	printf("Input name of manager: ");
	*name = readInputWord( badAlloc );
	if( *badAlloc ){
		return;
	}
	if( *name && *surname ){
		*managerHead = addManager( *managerHead, *surname, *name, maxManagerId( *managerHead ) + 1, badAlloc );
		if( *badAlloc ){
			return;
		}
		puts("Added");
	}
	else{
		puts("Some problems");
	}
}

void addWorkerMenu( Worker** workerHead, char** name, char** surname, bool* badAlloc){
		printf("\nInput surname of worker: ");
		*surname = readInputWord( badAlloc );
		if( *badAlloc ){
			return;
		}
		printf("Input name of worker: ");
		*name = readInputWord( badAlloc );
		if( *badAlloc ){
			return;
		}
		if( *name && *surname ){
			*workerHead = addWorker( *workerHead, *surname, *name, maxWorkerId( *workerHead ) + 1, badAlloc );
			if( *badAlloc ){
				return;
			}
			puts("Added");
		}
		else{
			puts("Some problems");
		}
}

bool addWorkerToProjectMenu( Project** projectHead, Worker** workerHead, Project_Worker** project_workerHead, bool* badAlloc ){
	showProjects( *projectHead );
	if( !*projectHead ){
		return false;
	}
	printf("\nInput id of project: ");
	unsigned long long id_project = readInputPositiveNumber();
	Project* test1 = searchProjectById( *projectHead, id_project );
	if( !test1 ){
		return false;
	}

	showWorkers( *workerHead );
	if( !*workerHead ){
		return false;
	}
	printf("\nInput id of worker: ");
	unsigned long long id_worker = readInputPositiveNumber();
	Worker* test2 = searchWorkerById( *workerHead, id_worker );
	if( !test2 ){
		return false;
	}

	*project_workerHead = addWorkerToProject( *project_workerHead, id_worker, id_project, maxProjectWorkerId( *project_workerHead ) + 1, badAlloc );
	return !badAlloc;
}

bool addManagerToProjectMenu( Project** projectHead, Manager** managerHead ){
	showProjects( *projectHead );
	if( !*projectHead ){
		return false;
	}
	printf("\nInput id of project: ");
	unsigned long long id_project = readInputPositiveNumber();
	Project* test1 = searchProjectById( *projectHead, id_project );
	if( !test1 ){
		return false;
	}

	showManagers(  *managerHead );
	if( !*managerHead ){
		return false;
	}
	printf("\nInput id of manager: ");
	unsigned long long id_manager = readInputPositiveNumber();
	Manager* test2 = searchManagerById( *managerHead, id_manager );
	if( !test2 ){
		return false;
	}

	addManagerToProject( *projectHead, id_manager, id_project );
	return true;
}

void drop( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead ){

    char choice = '&';
	while( '0' != choice){
		puts("\n| 1 - delete Project");
    	puts("| 2 - delete Manager");
    	puts("| 3 - delete Worker");
    	puts("| 4 - delete Worker from project");
    	puts("| 0 - return to main menu\n");

		choice = mygetchar();
		clearBuf();

		switch( choice ){
			case '1':
				dropProjectMenu( projectHead, project_workerHead );
				break;
			case '2':
				dropManagerMenu( projectHead, managerHead );	
				break;
			case '3':
				dropWorkerMenu( workerHead, project_workerHead );
				break;
			case '4':
				if( !dropWorkerFromProjectMenu( projectHead, managerHead, workerHead, project_workerHead ) ){
					puts("Nothing was deleted");
				}
				else{
					puts("Done");
				}				
				break;
		}
	}
}

void dropProjectMenu( Project** projectHead, Project_Worker** project_workerHead ){
	showProjects( *projectHead );
	if( *projectHead ){
		printf("\nInput id of project for deleting: ");
		unsigned long long id_project = readInputPositiveNumber();
		*projectHead = dropProject( *projectHead, id_project, project_workerHead );
	}		
}

void dropManagerMenu( Project** projectHead, Manager** managerHead ){
	showManagers( *managerHead );
	if( *managerHead ){
		printf("\nInput id of manager for deleting: ");
		unsigned long long id_manager = readInputPositiveNumber();
		*managerHead = dropManager( *managerHead, id_manager, *projectHead );
	}
}

void dropWorkerMenu( Worker** workerHead, Project_Worker** project_workerHead ){
	showWorkers( *workerHead );
	if( *workerHead ){
		printf("\nInput id of worker for deleting: ");
		unsigned long long id_worker = readInputPositiveNumber();
		*workerHead = dropWorker( *workerHead, id_worker, project_workerHead );	
	}	
}

bool dropWorkerFromProjectMenu( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead )
{
	showFullProjects( *projectHead, *managerHead, *workerHead, *project_workerHead, '*' );
	if( !*projectHead ){
		return false;
	}
	printf("\nInput id of project: ");
	unsigned long long id_project = readInputPositiveNumber();
	Project* test1 = searchProjectById( *projectHead, id_project );
	if( !test1 ){
		puts("Incorrect id.");
		return false;
	}

	Project_Worker* temp = *project_workerHead;
	if( temp ){
		puts("Workers:");
		printf(" id  surname  name \n");
		while( temp ){
			if( temp->id_project == id_project ){
				Worker* worker1 = searchWorkerById( *workerHead, temp->id_worker );
				printf("| %llu | %*s | %*s | \n", worker1->id, MAX_LENGTH, worker1->surname, MAX_LENGTH, worker1->name); 
			}					
			temp = temp->next;
		}
	}
	else{
		puts("Empty");
		return false;
	}

	printf("\nInput id of worker for deleting from project: ");
	unsigned long long id_worker = readInputPositiveNumber();
	Project_Worker* test2 = *project_workerHead;
	while( test2 ){
		if( test2->id_project == id_project && test2->id_worker == id_worker){
			*project_workerHead = dropProjectWorkerRow( *project_workerHead, test2->id );
			return true;
		}
		test2 = test2->next;
	}
	puts("Incorrect id.");
	return false;
}

void copies( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead, CopyFile** copyFileHead, bool* badAlloc ){

    char choice = '&';
	while( '0' != choice){
		puts("\n| 1 - CREATE copy");
    	puts("| 2 - LOAD copy");
    	puts("| 3 - DELETE copy");
    	puts("| 0 - return to main menu\n");

		choice = mygetchar();
		clearBuf();

		switch( choice ){
			case '1':
				printf("Input name of file: ");
				char* name = NULL;
				name = readInputWord( badAlloc );
				if( *badAlloc ){
					return;
				}
				char* forFree = name;
				if( createCopy( *projectHead, *managerHead, *workerHead, *project_workerHead, copyFileHead, &name, badAlloc ) ){
					puts("Successfully");
				}
				else{
					if( *badAlloc ){
						free( name );
						free( forFree );
						return;
					}
					puts("Some errors =(");
				}	
				free( name );
				free( forFree );
				break;
			case '2':
				showCopies( *copyFileHead );
				if( *copyFileHead ){
					printf("\nInput id of copy file for UPLOADing: ");
					unsigned long long id_file = readInputPositiveNumber();
					if( takeDataFromCopy( projectHead, managerHead, workerHead, project_workerHead, copyFileHead, id_file, badAlloc ) ){
						puts("Uploading copy: successfully.");
					}
					else{
						if( *badAlloc ){
							return;
						}
						clearProjects( projectHead ); 
						clearManagers( managerHead );
						clearWorkers( workerHead );
						clearProjectWorker( project_workerHead );
						puts("Uploading copy: unsuccessfully.");
					}
				}
				else{
					puts("Empty");
				}				
				break;
			case '3':
				showCopies( *copyFileHead );
				if( *copyFileHead ){
					printf("\nInput id of copy file for DELETing: ");
					unsigned long long id_file = readInputPositiveNumber();
					if( dropCopy( copyFileHead, id_file ) ){
						puts("Deleting copy: successfully.");
					}
					else{
						puts("Deleting copy: unsuccessfully.");
					}
				}
				else{
					puts("Empty");
				}				
		}
	}
}


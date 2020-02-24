#include "fileWrite.h"

bool createCopy( Project* projectHead, Manager* managerHead, Worker* workerHead, Project_Worker* project_workerHead, CopyFile** copyFileHead, char** name ){
	*name = makeTrueNameOfFile( *name );
	FILE* f = fopen( *name, "a+" ); 
	if( !f ){
		return false;
	}
	if( !( writeProjects( f , projectHead ) && writeManagers( f, managerHead ) && writeWorkers( f, workerHead ) && writeProjectWorkers( f, project_workerHead ) ) ){
		fclose( f );
		remove( *name );
		return false;
	}
	char buf[ 50 ] = {0};
	time_t t = time(NULL);
	struct tm* time = localtime( &t );
	strftime( buf, 50, "%FT%T%z", time );;
	fprintf( f, "#\n%s\n", buf );
	if( ferror(f) ){
		fclose( f );
		remove( *name );
		return false;
	}
	fclose( f );

	CopyFile* copyFile = checkMemoryAlloc( malloc( sizeof( CopyFile ) ) ); //x2
	copyFile->id = maxFileId( *copyFileHead ) + 1;
	strcpy( copyFile->name, *name );
	strcpy( copyFile->date, buf );
	copyFile->next = NULL;
	if( !*copyFileHead ){
		*copyFileHead = copyFile;
	}
	else{
		CopyFile* temp = *copyFileHead;
		while( temp->next ){
			temp = temp->next;
		}
		temp->next = copyFile;
	}
	FILE* f2 = fopen( "data/files.txt", "a+" );
	if( !f2 ){

		fclose( f );
		remove( *name );
		return false;
	} 
	fprintf( f2, "{\n\"id\":%llu,\n", (unsigned long long)copyFile->id );
	fprintf( f2, "\"name\":\"%s\",\n", copyFile->name );
	fprintf( f2, "\"date\":\"%s\",\n}\n", buf );
	if( ferror( f2 ) ){
		fclose( f );
		remove( *name );
		fclose( f2 );
		return false;
	}
	fclose( f2 );
	return true;
}

bool writeProjects( FILE* f, Project* projectHead ){
	fprintf( f, "\"Projects\":\n" );
	if( ferror(f) ){
		return false;
	}
	Project* tempHead = projectHead;	
	while( tempHead && writeProject( f, tempHead ) ){
		tempHead = tempHead->next;
	}
	if( tempHead ){
		return false;
	}
	return true;
}

bool writeProject( FILE* f, Project* project ){
	fseek( f, 0, SEEK_END );
	fprintf( f, "{\n\"id\":%llu,\n", (unsigned long long)project->id );
	fprintf( f, "\"name\":\"%s\",\n", project->name );
	fprintf( f, "\"id_manager\":%llu,\n}\n", (unsigned long long)project->id_manager );
	if( ferror(f) )
	{
		return false;
	}
	return true;
}

bool writeManagers( FILE* f, Manager* managerHead ){
	fprintf( f, "#\n\"Managers\":\n" );
	if( ferror(f) ){
		return false;
	}
	Manager* tempHead = managerHead;	
	while( tempHead && writeManager( f, tempHead ) ){
		tempHead = tempHead->next;
	}
	if( tempHead ){
		return false;
	}
	return true;
}

bool writeManager( FILE* f, Manager* manager ){
	fseek( f, 0, SEEK_END );
	fprintf( f, "{\n\"id\":%llu,\n", (unsigned long long)manager->id );
	fprintf( f, "\"name\":\"%s\",\n", manager->name );
	fprintf( f, "\"surname\":\"%s\",\n}\n", manager->surname );
	if( ferror(f) )
	{
		return false;
	}
	return true;
}

bool writeWorkers( FILE* f, Worker* workerHead ){
	fprintf( f, "#\n\"Workers\":\n" );
	if( ferror(f) ){
		return false;
	}
	Worker* tempHead = workerHead;	
	while( tempHead && writeWorker( f, tempHead ) ){
		tempHead = tempHead->next;
	}
	if( tempHead ){
		return false;
	}
	return true;
}

bool writeWorker( FILE* f, Worker* worker ){
	fseek( f, 0, SEEK_END );
	fprintf( f, "{\n\"id\":%llu,\n", (unsigned long long)worker->id );
	fprintf( f, "\"name\":\"%s\",\n", worker->name );
	fprintf( f, "\"surname\":\"%s\",\n}\n", worker->surname );
	if( ferror(f) )
	{
		return false;
	}
	return true;
}

bool writeProjectWorkers( FILE* f, Project_Worker* project_workerHead ){
	fprintf( f, "#\n\"Project_Workers\":\n" );
	if( ferror(f) ){
		return false;
	}
	Project_Worker* tempHead = project_workerHead;	
	while( tempHead && writeProjectWorker( f, tempHead ) ){
		tempHead = tempHead->next;
	}
	if( tempHead ){
		return false;
	}
	return true;
}
bool writeProjectWorker( FILE* f, Project_Worker* project_worker ){
	fseek( f, 0, SEEK_END );
	fprintf( f, "{\n\"id\":%llu,\n", (unsigned long long)project_worker->id );
	fprintf( f, "\"id_project\":%llu,\n", (unsigned long long)project_worker->id );
	fprintf( f, "\"id_worker\":%llu,\n}\n", (unsigned long long)project_worker->id );
	if( ferror(f) )
	{
		return false;
	}
	return true;
}

char* makeTrueNameOfFile( char* name ){
	const char* pre = "data/copies/";
	const char* post = ".txt";
	char* result = checkMemoryAlloc( malloc(  strlen( pre ) + strlen( name ) + strlen( post ) + 1 ) );
	strcpy( result, pre );
	strcat( result, name );
	strcat( result, post );
	result[ strlen( result ) ] = '\0';
	return result;
}
#include "fileRead.h"

bool readCopies( FILE* f, CopyFile** copyFileHead, bool* badAlloc ){
	char name[ MAX_KEY_SIZE ] = {0};
	char date[ MAX_KEY_SIZE ] = {0};
	unsigned long long id = 0;
	bool checking = false;
	
		checking = readChar( f, '{' ) && writeNumberValueOfKeyInVariable( f, "id", &id ) && writeTextValueOfKeyInVariable( f, "name", name ) && writeTextValueOfKeyInVariable( f, "date", date ) && readChar( f, '}' );
		if( checking ){
			CopyFile* copyFile = checkMemoryAlloc( malloc( sizeof( CopyFile ) ), badAlloc );
			if( *badAlloc ){
				return false;
			}
			if( id<0 ){
				id = (-1)*id;
			}
			copyFile->id = id;
			strcpy( copyFile->name, name );
			strcpy( copyFile->date, date );
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
		}

	return checking;
}

bool loadCopies( CopyFile** copyFileHead, bool* badAlloc ){
	return readSecondFileWithCopies( copyFileHead, badAlloc );
}

bool readSecondFileWithCopies( CopyFile** copyFileHead, bool* badAlloc ){
	FILE* f2 = fopen( "data/files2.txt", "a+" );
	if( !f2 ){
		return false;
	}	
	if( checkForEndOfFile( f2 ) ){
		fclose( f2 );
		return readFirstFileWithCopies( copyFileHead, badAlloc );
	}
	else{
		while( !(ferror( f2 ) || feof( f2 )) ){
			if( !checkForEndOfFile( f2 ) ){
				if( !readCopies( f2, copyFileHead, badAlloc ) ){
					fclose( f2 );
					remove( "data/files2.txt" );
					return readFirstFileWithCopies( copyFileHead, badAlloc );
				}
			}
		}
		FILE* forDeleting = fopen( "data/files.txt", "r+" );
		if( forDeleting ){
			fclose( forDeleting );
			remove( "data/files.txt" );
		}	
		rename( "data/files2.txt", "data/files.txt" );
		return true;
	}
}

bool readFirstFileWithCopies( CopyFile** copyFileHead, bool* badAlloc ){
	FILE* f = fopen( "data/files.txt", "a+" ); //check for "r"  and check for empty
	if( !f ){
		return false;
	}	
	while( !(ferror( f ) || feof( f )) ){
		if( !checkForEndOfFile( f ) ){
			if( !readCopies( f, copyFileHead, badAlloc ) ){
				fclose( f );
				return false;
			}
		}
	}
	fclose( f );
	return true;
}

bool readFileWithCopies( CopyFile** copyFileHead, char* nameOfFile ){
	FILE* f = fopen( nameOfFile, "a+" );
	if( !f ){
		return false;
	}

} 

bool takeDataFromCopy( Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead, CopyFile** copyFileHead, int id_file, bool* badAlloc ){
	CopyFile* fileForOpen = searchFileById( *copyFileHead, id_file );
	if( !fileForOpen ){
		puts("Incorrect id.");
		return false;
	}
	FILE* f = fopen( fileForOpen->name, "a+" );
	if( !f ){
		return false;
	}

	clearProjects( projectHead ); 
	clearManagers( managerHead );
	clearWorkers( workerHead );
	clearProjectWorker( project_workerHead );

	bool checking = true;
	if( !checkForEndOfFile( f ) ){
		checking = checkFileForCorrect( f, projectHead, managerHead, workerHead, project_workerHead, badAlloc );
	}
	fclose( f );
	return checking && badAlloc;
}

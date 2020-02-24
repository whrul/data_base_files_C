#include "fileCheck.h"


bool readChar( FILE* const temp, char symbol )
{
	char buf[ FOR_CHAR ] = {0};
	char* result = fgets( buf, FOR_CHAR, temp );
	if( result ){
		if( symbol == buf[0] ){
			return true;
		}
	}
	return false;
}

bool checkKey( char* const key, char* const buf )
{
	size_t keyLength = strlen( key );
	if( buf[0] == '"' && buf[ keyLength+1 ] == '"' && buf[ keyLength+2 ] == ':')
	{
		if( strncmp( key, buf+1, keyLength ) == 0 )
		{
			return true;
		}
	}
	return false;
}

bool checkFileForCorrect( FILE* temp, Project** projectHead, Manager** managerHead, Worker** workerHead, Project_Worker** project_workerHead ){
	char buf[ MAX_LINE_LENGTH ] = {0};
	char nextSymbol = ' ';
	char* result = fgets( buf, MAX_LINE_LENGTH, temp);
	if( result && checkKey( "Projects", buf ) ){
		nextSymbol = checkForHash( temp );
		while( !(ferror( temp ) || feof( temp )) && nextSymbol!='#'){
			if( !checkProject( temp, projectHead ) ){
				return false;
			}
			nextSymbol = checkForHash( temp );
		}		
	}
	else{
		return false;
	}
	result = fgets( buf, MAX_LINE_LENGTH, temp);
	if( result && checkKey( "Managers", buf ) ){
		nextSymbol = checkForHash( temp );
		while( !(ferror( temp ) || feof( temp )) && nextSymbol!='#'){
			if( !checkManager( temp, managerHead ) ){
				return false;
			}
			nextSymbol = checkForHash( temp );
		}
		
	}
	else{
		return false;
	}
	result = fgets( buf, MAX_LINE_LENGTH, temp);
	if( result && checkKey( "Workers", buf ) ){
		nextSymbol = checkForHash( temp );
		while( !(ferror( temp ) || feof( temp )) && nextSymbol!='#'){
			if( !checkWorker( temp, workerHead ) ){
				return false;
			}
			nextSymbol = checkForHash( temp );
		}
		
	}
	else{
		return false;
	}
	result = fgets( buf, MAX_LINE_LENGTH, temp);
	if( result && checkKey( "Project_Workers", buf ) ){
		nextSymbol = checkForHash( temp );
		while( !(ferror( temp ) || feof( temp )) && nextSymbol!='#' ){
			if( !checkProject_Worker( temp, project_workerHead ) ){
				return false;
			}
			nextSymbol = checkForHash( temp );
		}		
	}
	else{
		return false;
	}
	return true;
	
}

bool checkProject( FILE* f, Project** projectHead ){
	bool checking = false;
	char name[ MAX_KEY_SIZE ] = {0};
	unsigned long long id;
	unsigned long long id_manager;
		checking = readChar( f, '{' ) && writeNumberValueOfKeyInVariable( f, "id", &id ) && writeTextValueOfKeyInVariable( f, "name", name ) && writeNumberValueOfKeyInVariable( f, "id_manager", &id_manager ) && readChar( f, '}' );
	if( checking ){
		*projectHead = addProject( *projectHead, name, id_manager, id );
	}
	return checking;
}

bool checkManager( FILE* f, Manager** managerHead ){
	bool checking = false;
	char name[ MAX_KEY_SIZE ] = {0};
	char surname[ MAX_KEY_SIZE ] = {0};
	unsigned long long id;
		checking = readChar( f, '{' ) && writeNumberValueOfKeyInVariable( f, "id", &id ) && writeTextValueOfKeyInVariable( f, "name", name ) && writeTextValueOfKeyInVariable( f, "surname", surname ) && readChar( f, '}' );
	if( checking ){
		*managerHead = addManager( *managerHead, surname, name, id );
	}
	return checking;
}

bool checkWorker( FILE* f, Worker** workerHead ){
	bool checking = false;
	char name[ MAX_KEY_SIZE ] = {0};
	char surname[ MAX_KEY_SIZE ] = {0};
	unsigned long long id;
		checking = readChar( f, '{' ) && writeNumberValueOfKeyInVariable( f, "id", &id ) && writeTextValueOfKeyInVariable( f, "name", name ) && writeTextValueOfKeyInVariable( f, "surname", surname ) && readChar( f, '}' );
	if( checking ){
		*workerHead = addWorker( *workerHead, surname, name, id );
	}
	return checking;
}

bool checkProject_Worker( FILE* f, Project_Worker** project_workerHead ){
	bool checking = false;
	unsigned long long id_project;
	unsigned long long id_worker;
	unsigned long long id;
		checking = readChar( f, '{' ) && writeNumberValueOfKeyInVariable( f, "id", &id ) && writeNumberValueOfKeyInVariable( f, "id_project", &id_project ) && writeNumberValueOfKeyInVariable( f, "id_worker", &id_worker ) && readChar( f, '}' );
	if( checking ){
		*project_workerHead = addWorkerToProject( *project_workerHead, id_worker, id_project, id );
	}
	return checking;
}

bool writeTextValueOfKeyInVariable( FILE* const temp, char* key, char* variableForWriting )
{
	char buf[ MAX_LINE_LENGTH ] = {0};
	if( readValueOfKey( temp, key, buf ) )
	{
		size_t valueLength = strlen( buf );
		if( buf[0] == '"' && buf[valueLength - 1] == '"' && valueLength-2<MAX_VALUE_SIZE )
		{
			strncpy( variableForWriting, buf+1, valueLength-2 );
			variableForWriting[valueLength-2];
			return true;
		}
	}
	return false;
}

bool writeNumberValueOfKeyInVariable( FILE* const temp, char* key, unsigned long long* variableForWriting )
{
	char buf[ MAX_LINE_LENGTH ] = {0};
	if( readValueOfKey( temp, key, buf ) )
	{
		char* numberPointer = NULL;
		unsigned long long result = strtoull( buf, &numberPointer, 10 );
		if( numberPointer - buf > 0 && result < ULLONG_MAX )
		{
			*variableForWriting = result;
			return true;
		}
	}
	return false;
}

bool checkForEndOfFile( FILE* f ){
	fpos_t position;
	fgetpos(f, &position);
	char c = fgetc( f );
    if( feof( f ) ){
    	return true;
    }
    else{
    	fsetpos(f, &position);
    	return false;
    }
}

bool readValueOfKey( FILE* const temp, char* key, char* readWord )
{
	char buf[ MAX_LINE_LENGTH ] = {0};
	char* result = fgets( buf, MAX_LINE_LENGTH, temp);
	bool checkForComa = false;
	for( unsigned char i = 0; i < strlen( result ); ++i ){
		if( result[i] == ',' ){
			checkForComa = true;
			break;
		}
	}
	if( !checkForComa ){
		return false;
	}
	if( result && checkKey( key, buf ) ){
		char* beginOfValue = buf + strlen( key ) +  3;
		char* endOfValue = strrchr( beginOfValue, ',' );
		ptrdiff_t diff = endOfValue - beginOfValue;
		if( diff )
		{
			strncpy( readWord, beginOfValue, diff );
			readWord[ diff ] = '\0';
			return true;
		}
	}
	return false;
}

char checkForHash( FILE* temp ){
	fpos_t position;
	fgetpos(temp, &position);
	if( readChar( temp, '#' ) ){
		return '#';
	}
	else{
		fsetpos(temp, &position);
		return ' ';
	}
}
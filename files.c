#include "files.h"

unsigned long long maxFileId( CopyFile* copyFileHead )
{
	unsigned long long id = 0;
	CopyFile* temp = copyFileHead;
	if( temp )
	{
		while( temp->next != NULL )
		{
			temp = temp -> next;
		}
		id = temp->id;
	}
	return id;
}


void clearCopyFiles( CopyFile** copyFileHead ){
	CopyFile* temp = *copyFileHead;
	while( *copyFileHead ){
		temp = *copyFileHead;
		*copyFileHead = (*copyFileHead)->next;
		free(temp);
	}
}

void showCopies( CopyFile* copyFileHead ){
	CopyFile* temp = copyFileHead;
	if( temp ){
		puts("\nCopies:");
	}
	while( temp ){
		printf("%llu. %*s | %s\n", temp->id, MAX_LENGTH_FOR_FILE, temp->name, temp->date);
		temp = temp->next;
	}
}


CopyFile* searchFileById( CopyFile* copyFileHead, int id ){
	CopyFile* temp = copyFileHead;
	while( temp != NULL )
	{
		if( temp->id == id)
		{
			return temp;
		}
		temp = temp -> next;
	}
	return NULL;
}



bool dropCopy( CopyFile** copyFileHead, int id ){
	CopyFile* elementForDrop = searchFileById( *copyFileHead, id );
	if( !elementForDrop )
	{
		puts("Incorrect id.");
		return false;
	}
	char nameOfDropingFile[ MAX_LENGTH_FOR_FILE ];
	strcpy( nameOfDropingFile, elementForDrop->name );
	if ( elementForDrop != *copyFileHead )
	{
		CopyFile* temp = *copyFileHead;
		while( temp->next != elementForDrop)
		{
			temp = temp->next;
		}
		temp->next = elementForDrop->next;
		free( elementForDrop );
		elementForDrop = NULL;
	}
	else
	{
		*copyFileHead = elementForDrop->next;
		free( elementForDrop );	
		elementForDrop = NULL;
	}

	FILE* f2 = fopen( "data/files2.txt", "w+" );
	if( !f2 ){
		return false;
	} 
	CopyFile* temp = *copyFileHead;
	while( temp ){
		fprintf( f2, "{\n\"id\":%llu,\n", (unsigned long long)temp->id );
		fprintf( f2, "\"name\":\"%s\",\n", temp->name );
		fprintf( f2, "\"date\":\"%s\",\n}\n", temp->date );
		if( ferror( f2 ) ){
			return false;
		}
		temp=temp->next;
	}
	fclose( f2 );

	FILE* forDeleting = fopen( "data/files.txt", "r+" );
	if( forDeleting ){
		fclose( forDeleting );
		remove( "data/files.txt" );
	}
	rename( "data/files2.txt", "data/files.txt" );
	remove( nameOfDropingFile );
	printf("Name: %s\n", nameOfDropingFile);
	return true;
}
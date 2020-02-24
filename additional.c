#include "additional.h"

void* checkMemoryAlloc( void* wsk ){
	if( !wsk ){
		puts("No memory");
		exit( 0 );
	}
	return wsk;
}

void clearBuf( void ){
    char clear = ' ';
    while(clear!='\n' && clear!=EOF){
        clear = getchar();
    }    
}

unsigned long long readInputPositiveNumber( void ){
	unsigned long long number = 0;
	if( 1 != scanf("%llu", &number) ){
		clearBuf();
	}
	return number;
}

char* readInputWord( void ){
	char* word = checkMemoryAlloc( calloc( MAX_LENGTH+1, sizeof( char ) ) );
	if( 1!= scanf( S_FORMAT( MAX_LENGTH ), word ) ){
		clearBuf();
		free( word );
		return NULL;
	}
	clearBuf();
	return word;
}

char mygetchar( void )
{
	while( true ){
		char symbol = getchar();
		if (symbol != ' ' && symbol != '\n'){
			return symbol;
		}
	}	
}
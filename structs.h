// Author: Walerij Hrul
//
// Structurs for "objects"(project, manager, worker, worker-project), sorts, working with files 
//

#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_LENGTH 15
#define MAX_LENGTH_FOR_FILE 30
#define MAX_LENGTH_FOR_DATE 20

struct Project{
	unsigned long long id;
	char name[ MAX_LENGTH+1 ];
	int id_manager;
	struct Project* next;
};
typedef struct Project Project;

struct Manager{
	unsigned long long id;
	char name[ MAX_LENGTH+1 ];
	char surname[ MAX_LENGTH+1 ];
	struct Manager* next;
};
typedef struct Manager Manager;

struct Worker{
	unsigned long long id;
	char name[ MAX_LENGTH+1 ];
	char surname[ MAX_LENGTH+1 ];
	struct Worker* next;
};
typedef struct Worker Worker;

struct Project_Worker{
	unsigned long long id;
	int id_project;
	int id_worker;
	struct Project_Worker* next;
};
typedef struct Project_Worker Project_Worker;

struct SortW{
	unsigned long long id;
	char sortWord[ MAX_LENGTH+1 ];
	struct SortW* next;
};
typedef struct SortW SortW; 

struct SortN{
	unsigned long long id;
	int sortNumber;
	struct SortN* next;
};
typedef struct SortN SortN; 

struct CopyFile{
	unsigned long long id;
	char name[ MAX_LENGTH_FOR_FILE+1 ];
	char date[ MAX_LENGTH_FOR_DATE+1 ];
	struct CopyFile* next;
};
typedef struct CopyFile CopyFile;

#endif
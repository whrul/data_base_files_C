CC = gcc
CCFALGS = -Wall
TARGET = db.out

$(TARGET): additional.o fileCheck.o fileRead.o files.o fileWrite.o main.o managers.o menu.o project_worker.o projects.o sort.o workers.o
	$(CC) additional.o fileCheck.o fileRead.o files.o fileWrite.o main.o managers.o menu.o project_worker.o projects.o sort.o workers.o -o $(TARGET)

additional.o: additional.c additional.h ownConsts.h
	$(CC) $(CCFALGS) -c additional.c
fileCheck.o: fileCheck.c fileCheck.h ownConsts.h structs.h projects.h managers.h workers.h project_worker.h
	$(CC) $(CCFALGS) -c fileCheck.c
fileRead.o: fileRead.c fileRead.h ownConsts.h additional.h fileCheck.h files.h structs.h
	$(CC) $(CCFALGS) -c fileRead.c
files.o: files.c files.h ownConsts.h structs.h
	$(CC) $(CCFALGS) -c files.c
fileWrite.o: fileWrite.c fileWrite.h additional.h structs.h files.h
	$(CC) $(CCFALGS) -c fileWrite.c
main.o: main.c structs.h projects.h managers.h workers.h project_worker.h files.h fileRead.h menu.h
	$(CC) $(CCFALGS) -c main.c
managers.o: managers.c managers.h structs.h ownConsts.h additional.h workers.h
	$(CC) $(CCFALGS) -c managers.c
menu.o: menu.c menu.h ownConsts.h structs.h projects.h managers.h workers.h project_worker.h files.h additional.h fileWrite.h fileRead.h
	$(CC) $(CCFALGS) -c menu.c
project_worker.o: project_worker.c project_worker.h structs.h projects.h workers.h managers.h
	$(CC) $(CCFALGS) -c project_worker.c
projects.o: projects.c projects.h ownConsts.h workers.h managers.h
	$(CC) $(CCFALGS) -c projects.c
sort.o: sort.c sort.h structs.h additional.h projects.h managers.h workers.h
	$(CC) $(CCFALGS) -c sort.c
workers.o: workers.c workers.h sort.h projects.h project_worker.h managers.h
	$(CC) $(CCFALGS) -c workers.c

.PHONY: run, clean, valgrind

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o
	rm -f *.out

valgrind: $(TARGET)
	valgrind --leak-check=yes --track-origins=yes --show-reachable=yes ./$(TARGET)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char fName[20];
	char lName[20];
}studName;

typedef struct {
	int month;
	int year;
}bday;

typedef struct {
	studName name;
	bday birthdate;
	int age;
	int idNum;
}studentInfo;

typedef struct{
	studentInfo studList[20];
	int studCount;
}classRecord;


void initList(classRecord* CR){
	CR->studCount = 0;	
}


void displayRec(classRecord CR){
	int i;
	
	for(i=0; i<CR.studCount; i++){
		printf("[%d] ID: %d - Age: %d \n", i, CR.studList[i].idNum, CR.studList[i].age);
	}
	
	printf("\nTotal: %d\n", CR.studCount);
}

void insertFirst(classRecord* CR, studentInfo stud){
	int i;
	for(i=CR->studCount; i > 0; i--){
		CR->studList[i] = CR->studList[i-1];
	}
	CR->studList[0] = stud;
	CR->studCount++;
}

void insertLast(classRecord* CR, studentInfo stud){
	
	CR->studList[CR->studCount] = stud;
	CR->studCount++;
}

void insertatIndex(classRecord* CR, studentInfo stud, int num){
	int i;
	for(i=CR->studCount; i > num ; i--){
		CR->studList[i] = CR->studList[i-1];
	}
	CR->studList[num] = stud;
	CR->studCount++;
}

void insertSorted(classRecord* CR, studentInfo stud){
	int i;
	for(i=CR->studCount; i > 0 && CR->studList[i-1].age >= stud.age; i--){
		CR->studList[i] = CR->studList[i-1];
	}
	CR->studList[i] = stud;
	CR->studCount++;
}

void deleteFirst(classRecord* CR){
	int i;
	for(i=0; i<CR->studCount - 1; i++){
		CR->studList[i] = CR->studList[i+1];
	}
	CR->studCount--;
}

void deleteLast(classRecord* CR){
	CR->studCount--;
}

void deleteatIndex(classRecord* CR, int num){
	int i;
	for(i=num; i<CR->studCount - 1; i++){
		CR->studList[i] = CR->studList[i+1];
	}
	CR->studCount--;
}


int main(void) {
	
	classRecord classRec;
	
	initList(&classRec);
	
	studentInfo students[] = {{{"Joseph", "Parchaso"}, {8, 1999}, 24, 18100807},
							  {{"Rix", "Potot"}, {4, 2000}, 23, 18102727},
							  {{"Gab", "Achas"}, {12, 1991}, 31, 18101111},
							  {{"Andy", "Menano"}, {5, 1993}, 25, 18102222},
							  {{"Bakol", "Collado"}, {5, 1997}, 15, 18103333},
							  {{"Pilep", "Tan"}, {3, 1998}, 28, 18104444},
							  {{"Maya", "Potot"}, {9, 2014}, 100, 18100000},
							 };
	
	
	
	insertFirst(&classRec, students[5]);
	insertFirst(&classRec, students[3]);
	insertLast(&classRec, students[0]);
	insertFirst(&classRec, students[1]);
	insertatIndex(&classRec, students[4], 2);
	insertSorted(&classRec, students[6]);
	
	displayRec(classRec);
	
	printf("\n\n");
	
	deleteFirst(&classRec);
	deleteLast(&classRec);
	deleteLast(&classRec);
	deleteatIndex(&classRec, 1);
	displayRec(classRec);
	
}

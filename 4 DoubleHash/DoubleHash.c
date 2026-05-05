#include <stdio.h>
#include <stdlib.h>
#include "DoubleHash.h"

void initHash(closedHash* CH) {
	int i;
    for (i = 0; i < MAX; i++) {
        CH->arr[i].status = EMPTY;
    }
}

int hash1(int key) {
    return key % MAX;
}

int hash2(int key) {
    return 7 - (key % 7);
}

void insert(closedHash* CH, studentInfo student) {
    int h1 = hash1(student.idNum);
    int h2 = hash2(student.idNum);
    int i = 0;

    while (CH->arr[h1].status == OCCUPIED) {
        h1 = (h1 + i * h2) % MAX;
        i++;
        if (i == MAX) {
            printf("Hash table is full\n");
        }
    }

    CH->arr[h1] = student;
    CH->arr[h1].status = OCCUPIED;
}

void delete(closedHash* CH, int idNum) {
    int h1 = hash1(idNum);
    int h2 = hash2(idNum);
    int i = 0;

    while (CH->arr[h1].status != EMPTY) {
        if (CH->arr[h1].status == OCCUPIED && CH->arr[h1].idNum == idNum) {
            CH->arr[h1].status = DELETED;
        }
        h1 = (h1 + i * h2) % MAX;
        i++;
        if (i == MAX) {
            printf("Element not found\n");
        }
    }
}

void display(closedHash CH) {
	int i;
    for (i = 0; i < MAX; i++) {
        printf("%d: ", i);
        if (CH.arr[i].status == OCCUPIED) {
            printf("(%s %s, %d, %02d/%04d, %d)",
                CH.arr[i].name.fName, CH.arr[i].name.lName, 
                CH.arr[i].idNum,
                CH.arr[i].birthdate.month, CH.arr[i].birthdate.year,
                CH.arr[i].age);
        } else if (CH.arr[i].status == DELETED) {
            printf("DELETED");
        } else {
            printf("EMPTY");
        }
        printf("\n");
    }
}


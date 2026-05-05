#include <stdio.h>
#include <stdlib.h>
#include "QuadraticProbing.h"
#define MAX 10

void initHash(closedHash* CH) {
    int i;
    for (i = 0; i < MAX; i++) {
        CH->arr[i].status = EMPTY;
    }
}

int hash(int key) {
    return key % MAX;
}

void insert(closedHash* CH, studentInfo student) {
    int index = hash(student.idNum);
    int originalIndex = index;
    int i = 1;

    while (CH->arr[index].status == OCCUPIED) {
        index = (originalIndex + i * i) % MAX;
        i++;
        if (i == MAX) {
            printf("Hash table is full\n");
        }
    }
    CH->arr[index] = student;
    CH->arr[index].status = OCCUPIED;
}

void delete(closedHash* CH, int idNum) {
    int index = hash(idNum);
    int originalIndex = index;
    int i = 1;

    while (CH->arr[index].status != EMPTY) {
        if (CH->arr[index].status == OCCUPIED && CH->arr[index].idNum == idNum) {
            CH->arr[index].status = DELETED;
        }
        index = (originalIndex + i * i) % MAX;
        i++;
        if (i == MAX) {
            printf("Element not found\n");
        }
    }
    printf("Element not found\n");
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


#include <stdio.h>
#include <stdlib.h>
#include "LinearProbing.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    closedHash table;
    initHash(&table);

    studentInfo students[] = {
					        {{"Joseph", "Parchaso"}, {8, 1999}, 24, 18100807, OCCUPIED},
					        {{"Rix", "Potot"}, {4, 2000}, 23, 18102727, OCCUPIED},
					        {{"Gab", "Achas"}, {12, 1991}, 31, 18101111, OCCUPIED},
					        {{"Andy", "Menano"}, {5, 1993}, 25, 18102222, OCCUPIED},
					        {{"Bakol", "Collado"}, {5, 1997}, 15, 18103333, OCCUPIED},
					        {{"Pilep", "Tan"}, {3, 1998}, 28, 18104444, OCCUPIED},
					        {{"Maya", "Potot"}, {9, 2014}, 100, 18100000, OCCUPIED}
    };

    insert(&table, students[0]);
    insert(&table, students[1]);
    insert(&table, students[2]);
    insert(&table, students[3]);
    insert(&table, students[4]);
    insert(&table, students[5]);
    insert(&table, students[6]);

    display(table);
    
    printf("\n====\n\n");
    
    delete(&table, 18100807);

    display(table);

    return 0;
}

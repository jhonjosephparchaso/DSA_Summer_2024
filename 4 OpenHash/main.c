#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OpenHash.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    openHash table;
    initHashTable(&table);

	studentInfo students[] = {{{"Joseph", "Parchaso"}, {8, 1999}, 24, 18100807},
							  {{"Rix", "Potot"}, {4, 2000}, 23, 18102727},
							  {{"Gab", "Achas"}, {12, 1991}, 31, 18101111},
							  {{"Andy", "Menano"}, {5, 1993}, 25, 18102222},
							  {{"Bakol", "Collado"}, {5, 1997}, 15, 18103333},
							  {{"Pilep", "Tan"}, {3, 1998}, 28, 18104444},
							  {{"Maya", "Potot"}, {9, 2014}, 100, 18100000},
							 };

	insert(&table, students[0], 5);
	insert(&table, students[1], 25);
	insert(&table, students[2], 100);
	insert(&table, students[3], 7);
	insert(&table, students[4], 55);
	insert(&table, students[5], 17);
	insert(&table, students[6], 18);

    display(table);
    
    printf("\n====\n\n");
    
	delete(&table, 18100807, 5);

    display(table);

    return 0;
}

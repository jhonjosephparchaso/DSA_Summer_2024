#include <stdio.h>
#include <stdlib.h>
#include "UnionIntersection.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	SET set1, set2, unionSetRes, intersectSetRes;
	
	initSet(&set1);
	initSet(&set2);
	
    insertinSet(&set1, 10);
    insertinSet(&set1, 20);
    insertinSet(&set1, 30);

    insertinSet(&set2, 20);
    insertinSet(&set2, 30);
    insertinSet(&set2, 40);

    printf("Set 1: ");
    printSet(set1);
    printf("Set 2: ");
    printSet(set2);
    
    deleteinSet(&set2, 40);

    printf("Set 2 after deletion: ");
    printSet(set2);

    unionSetRes = unionSet(&set1, &set2);
    intersectSetRes = intersectSet(&set1, &set2);

    printf("Union of Set 1 and Set 2: ");
    printSet(unionSetRes);
    printf("Intersection of Set 1 and Set 2: ");
    printSet(intersectSetRes);
    
	return 0;
}

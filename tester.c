//
// Created by user on 4/16/21.
//

#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    struct vector vector;

    create(&vector);

    printVector(vector);

    add(&vector, 6);
    add(&vector, 7);
    add(&vector, 9);

    printVector(vector);

    printf("\nPrinting all elements: \n");
    for (int i = 0; i < vector.size; ++i) {
        printf("Element at %d: %d \n", i, elementAt(&vector, i));
    }

    add(&vector, 6);
    add(&vector, 6);

    printVector(vector);

    removeElements(&vector, 6);

    printVector(vector);

    trimToSize(&vector);

    printVector(vector);

    return 0;
}
/**
 * Testing vector implementation
 * Part 2 - Assignment 1 - CLA
 *
 * Created by Tom Grozev.
 */

#include "vector.h"
#include <stdio.h>

/**
 * Main testing function
 *
 * @return
 */
int main() {
    // Create vector var
    Vector vector;

    // Initialise an empty vector
    create(&vector);

    // Show the vector is empty
    printf("\nEmpty Vector: \n");
    printVector(vector);

    // Add integers to the vector
    add(&vector, 6);
    add(&vector, 7);
    add(&vector, 9);

    // Show the integers in the vector
    printf("\nAdded elements: \n");
    printVector(vector);

    // Print all elements in vector using elementAt function
    printf("\nPrinting all elements using elementAt(): \n");
    for (int i = 0; i < vector.size; ++i) {
        printf("Element at %d: %d \n", i, elementAt(&vector, i));
    }

    // Add two duplicate integers
    add(&vector, 6);
    add(&vector, 6);

    // Show the integers in the vector
    printf("\nAdded more elements: \n");
    printVector(vector);

    // Remove all 6 integers from the vector
    removeElements(&vector, 6);

    // Show the 6 elements have been removed
    printf("\nRemoved all 6 values: \n");
    printVector(vector);

    // Trim the vector capacity to match the size
    trimToSize(&vector);

    // Show the trimmed vector
    printf("\nTrimmed vector: \n");
    printVector(vector);

    return 0;
}
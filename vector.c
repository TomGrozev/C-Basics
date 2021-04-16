//
// Created by user on 4/16/21.
//
#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

void create(Vector *vector) {
    // Create a new vector with two elements

    vector->size = 0;
    vector->capacity = 2;
    vector->list = malloc(vector->capacity * sizeof(int));
}

void printVector(Vector vector) {
    // Prints the vector

    printf("Size: %d \n", vector.size);
    printf("Capacity: %d \n", vector.capacity);
    printf("List: ");
    for (int i = 0; i < vector.capacity; ++i) {
        printf("%d", vector.list[i]);
        if (i != vector.capacity - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

void add(Vector *vector, int integer) {
    // Adds an element to the end of the vector

    if (vector->size >= vector->capacity) {
        // If capacity needs to be increased

        // Create temp list with twice the size of the current vector
        int *tmp = malloc(2 * vector->capacity * sizeof(int));

        // Copy the current elements
        for (int i = 0; i < vector->size; ++i) {
            tmp[i] = vector->list[i];
        }

        // Free the old list and set the new one
        free(vector->list);
        vector->list = tmp;

        // Set the new capacity
        vector->capacity *= 2;
    }

    // Add the new element
    vector->list[vector->size] = integer;
    vector->size++;
}

void removeElements(Vector *vector, int integer) {
    // Removes all elements in the vector with value

    int removed = 0;
    for (int i = 0; i < vector->size; ++i) {
        if (vector->list[i] == integer) {
            // If element is integer value, remove
            vector->list[i] = 0;
            removed++;
        }
    }

    // Set new vector size
    vector->size -= removed;
}

int elementAt(Vector *vector, int index) {
    // Gets an element at an index

    if (index >= vector->size) {
        // If index is out of bounds exit with an error
        printf("Index %d out of bounds.", index);
        exit(0);
    } else {
        return vector->list[index];
    }
}

void trimToSize(Vector *vector) {
    // Trims vector capacity to vector size

    // Create new list of the vector size
    int *tmp = malloc(vector->size * sizeof(int));
    int tmpI = 0;

    // Iterate over the entire vector capacity
    for (int i = 0; i < vector->capacity; ++i) {
        if (vector->list[i] != 0 && tmpI <= vector->size) {
            // If element has value and the temp list size is within bounds
            tmp[tmpI] = vector->list[i];
            // Goto next element
            tmpI++;
        }
        // Otherwise goto next element in vector but not temp list
    }

    // Free the old list and set the new one
    free(vector->list);
    vector->list = tmp;

    // Set the new capacity
    vector->capacity = vector->size;
}
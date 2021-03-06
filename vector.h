/**
 * Implementing a vector in C
 * Part 2 - Assignment 1 - CLA
 *
 * Created by Tom Grozev.
 */

#ifndef ASSIGNMENT1_VECTOR_H
#define ASSIGNMENT1_VECTOR_H

struct vector {
    int size;
    int capacity;
    int *list;
};
typedef struct vector Vector;

void create(struct vector *vector);

void printVector(struct vector vector);

void add(struct vector *vector, int integer);

void removeElements(struct vector *vector, int integer);

int elementAt(struct vector *vector, int index);

void trimToSize(struct vector *vector);

#endif //ASSIGNMENT1_VECTOR_H

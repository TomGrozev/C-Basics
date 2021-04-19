//
// Created by user on 4/16/21.
//

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist_sorted.h"

Node *newNode(int data) {
    // Creates a new node with data

    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->nextNode = NULL;
    return node;
}

List *create() {
    // Creates an empty list with no head

    List *list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    return list;
}

int isEmpty(List *list) {
    // Checks if a list is empty

    return list->head == NULL;
}

/**
 * Insert in ascending order
 *
 * @param [in,out] list The list to add an element to
 * @param [in] data The element to add
 */
void insert(List *list, int data) {
    Node *dataNode = newNode(data);
    if (isEmpty(list)) {
        // If empty set head to new node

        list->head = dataNode;
    } else {
        // Otherwise find location to add new data

        Node *current = list->head;
        Node *previous = NULL;

        // Iterate until a node is found that is greater than or equal to the data
        while (current != NULL && current->data < data) {
            previous = current;
            current = current->nextNode;
        }

        // Set the data node to point to the bigger node and the smaller to point to the data node
        dataNode->nextNode = current;
        if (previous == NULL) {
            list->head = dataNode;
        } else {
            previous->nextNode = dataNode;
        }
    }
}

void traverse(List *list) {
    // Prints the list's values

    if (isEmpty(list)) {
        printf("List is empty");
    } else {
        Node *current = list->head;
        printf("List: ");
        // Iterates over all until the node is NULL
        while (current != NULL) {
            printf("%d", current->data);
            current = current->nextNode;

            if (current != NULL) {
                // Add comma if not last
                printf(", ");
            }
        }
    }
    printf("\n");
}

void delete(List *list, int data) {
    if (!isEmpty(list)) {
        Node *current = list->head;
        Node *previous;
        // Iterate until a node is found that is greater than or equal to the data
        while (current != NULL) {
            Node *next = current->nextNode;
            if (current->data == data) {
                previous->nextNode = next;
                free(current);
            } else {
                previous = current;
            }

            current = next;
        }
    }
}
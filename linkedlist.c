//
// Created by user on 4/16/21.
//

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

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

void insertAtHead(List *list, int data) {
    // Insert a node at the head

    Node *newHead = newNode(data);
    if (isEmpty(list)) {
        // If empty set head to head

        list->head = newHead;
    } else {
        // Otherwise set new head's next to current head and set new head

        newHead->nextNode = list->head;
        list->head = newHead;
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
void insertAtTail(List *list, int data) {
    // Insert a node at the end of the list

    if (isEmpty(list)) {
        list->head = newNode(data);
    } else {
        Node *current = list->head;

        // Iterates over until at end node
        while (current->nextNode != NULL) {
            current = current->nextNode;
        }

        // Sets the next node to a new node
        current->nextNode = newNode(data);
    }
}

void deleteHead(List *list) {
    // Deletes the head node

    if (!isEmpty(list)) {
        // Create temp reference to head
        Node *tmp = list->head;

        // Set new head
        Node *newHead = list->head->nextNode;
        list->head = newHead;

        // Clear old head from memory
        free(tmp);
    }
}

void deleteTail(List *list) {
    // Deletes the tail node

    if (!isEmpty(list)) {
        Node *current = list->head;
        Node *previous;

        // Get the last node and node before last
        while (current->nextNode != NULL) {
            previous = current;
            current = current->nextNode;
        }

        // Remove last node from the second last (making it last)
        previous->nextNode = NULL;

        // Clear old tail from memory
        free(current);
    }
}

/**
 * Sorted Linked List Implementation
 * Part 3 - Assignment 1 - CLA
 *
 * Created by Tom Grozev.
 */

#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *nextNode;
};
typedef struct node Node;

struct list {
    Node *head;
};
typedef struct list List;

/**
 * Creates a new node with data
 *
 * @param [in] data The integer data to create a node for
 * @return A new Node with `data` value and no next node
 */
Node *newNode(int data) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->nextNode = NULL;
    return node;
}

/**
 * Creates an empty list with no head
 *
 * @return An empty List
 */
List *create() {
    List *list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    return list;
}

/**
 * Checks if a list is empty
 *
 * @param [in] list The list to check
 * @return True if is empty or false if not
 */
int isEmpty(List *list) {
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

/**
 * Print out the values of the list
 *
 * @param [in] list The list to print
 */
void traverse(List *list) {
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

/**
 * Deletes all instances of `data` from list
 *
 * @param [in,out] list The list to delete elements in
 * @param [in] data The element value to delete
 */
void delete(List *list, int data) {
    if (!isEmpty(list)) {
        Node *current = list->head;
        Node *previous;

        // Iterate over all nodes
        while (current != NULL) {
            Node *next = current->nextNode;

            // If it matches skip the node and free it from memory
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
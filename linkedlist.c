/**
 * Linked List Implementation
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
 * Insert a node at the start of the list
 *
 * @param [in,out] list The list to insert the data in
 * @param [in] data The data to insert
 */
void insertAtHead(List *list, int data) {
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
 * Insert a node at the end of the list
 *
 * @param [in,out] list The list to insert the data in
 * @param [in] data The data to insert
 */
void insertAtTail(List *list, int data) {
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

/**
 * Deletes the head node
 *
 * @param [in,out] list The list to delete the head Node on
 */
void deleteHead(List *list) {
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

/**
 * Deletes the tail node
 *
 * @param [in,out] list The list to delete the tail Node on
 */
void deleteTail(List *list) {
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

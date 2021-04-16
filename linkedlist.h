//
// Created by user on 4/16/21.
//

#ifndef ASSIGNMENT1_LINKEDLIST_H
#define ASSIGNMENT1_LINKEDLIST_H

struct node {
    int data;
    struct node *nextNode;
};
typedef struct node Node;

struct list {
    Node *head;
};
typedef struct list List;

List *create();
int isEmpty(List *list);
void insertAtHead(List *list, int data);
void traverse(List *list);
void insertAtTail(List *list, int data);
void deleteHead(List *list);
void deleteTail(List *list);

#endif //ASSIGNMENT1_LINKEDLIST_H

//
// Created by user on 4/16/21.
//

#ifndef ASSIGNMENT1_LINKEDLIST_SORTED_H
#define ASSIGNMENT1_LINKEDLIST_SORTED_H

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
void insert(List *list, int data);
void traverse(List *list);
void delete(List *list, int data);

#endif //ASSIGNMENT1_LINKEDLIST_SORTED_H

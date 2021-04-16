#include <stdio.h>
#include "linkedlist.h"

int main() {
    // Run part 1
//    runPart1();

    // Run part 3
    List *list = create();
    if (isEmpty(list)) {
        printf("List is empty\n");
    }

    insertAtHead(list, 4);
    insertAtHead(list, 3);
    insertAtHead(list, 2);
    insertAtHead(list, 1);
    traverse(list);
    printf("%d", list->head->data);

    insertAtTail(list, 5);
    insertAtHead(list, 0);
    traverse(list);

    deleteTail(list);
    traverse(list);
    deleteHead(list);
    traverse(list);
    deleteTail(list);
    traverse(list);

    return 0;
}

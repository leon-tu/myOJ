#ifndef LINKED_H
#define LINKED_H

typedef struct single_linked_node {
    int value;
    struct single_linked_node *pNext;
} SingleLinkedNode;

typedef SingleLinkedNode SingleLinkedList;

void LinkList_Display(SingleLinkedList *pList);
int CreateList(SingleLinkedList **pList, int n);
SingleLinkedList *SingleLinkRev(SingleLinkedList *pLink);

#endif

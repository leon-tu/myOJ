#include "stdio.h"
#include "stdlib.h"
#include "../include/linked.h"
#include "../../utils/util.h"

SingleLinkedList *SingleLinkRev(SingleLinkedList *pLink)
{
    if (NULL == pLink) {
        printf("Null link\n");
        return NULL;
    }

    SingleLinkedNode *pNewHead = NULL, *pLinkedNode = NULL;
    pLinkedNode = pLink;

    while(pLinkedNode->pNext != NULL) {
        SingleLinkedNode *pNext = pLinkedNode->pNext;
        pLinkedNode->pNext = pNewHead;
        pNewHead = pLinkedNode;
        pLinkedNode = pNext;
    }
    
    pLinkedNode->pNext = pNewHead;
    return pLinkedNode;
}

int CreateList(SingleLinkedList **pList, int n)
{
    if (NULL == pList) {
        printf("Null pointer\n");
        return -1;
    }   

    SingleLinkedList *pHead = NULL, *pNode = NULL, *pPre = NULL;
    int i = 0;
    for (i = 0; i < n; i++) {
        pNode = (SingleLinkedList *) malloc(sizeof(SingleLinkedList));
        if (NULL == pNode) {
            printf("Fail to malloc link list node\n");
            return -1;
        }
        pNode->value = i;
        pNode->pNext = NULL;
        if (0 == i) {
            pHead = pNode;
        }
        
        if (pPre) {
            pPre->pNext = pNode;
        }
        
        LOG_PRI("Index: %d, vlaue: %d\n", i, pNode->value);
        pPre = pNode;
    }    

    *pList = pHead;
    return 0;
}

int FreeList(SingleLinkedList *pList)
{
    if (NULL == pList) {
        LOG_PRI("NULL pointer\n");
        return -1;
    }

    SingleLinkedNode *pNode = NULL, *pNext = NULL;
    pNode = pList;
    while (pNode != NULL) {
        pNext = pNode->pNext;
        free(pNode);
        pNode = pNext;
    }
    
    return 0;
}

void LinkList_Display(SingleLinkedList *pList)
{
    if (NULL == pList) {
        LOG_PRI("NULL pointer\n");
        return -1;
    }

    SingleLinkedNode *pNode = NULL;
    pNode = pList;
    while(pNode != NULL) {
        printf("%d->", pNode->value);
        pNode = pNode->pNext;
    }    
    printf("NULL\n");

    return;
}

int LinkList_Insert(SingleLinkedList *pList, int index, int value)
{
    if (NULL == pList) {
        LOG_PRI("NULL pointer\n");
        return -1;
    }

    SingleLinkedNode *pPre = NULL, *pNode = NULL;
    int i = 0;
    pPre = pList;
    
    for (i = 1; i < index; i++) {
        pPre = pPre->pNext;
    }    

    pNode = (SingleLinkedNode *)malloc(sizeof(SingleLinkedNode));
    if (NULL == pNode) {
        LOG_PRI("Fail to malloc node\n");
        return -1;
    }
    pNode->value = value;
    pNode->pNext = pPre->pNext;
    pPre->pNext = pNode;    

    return 0;
}

int LinkList_Del(SingleLinkedList *pList, int index)
{
    if (NULL == pList) {
        LOG_PRI("NULL pointer\n");
        return -1;
    } 

    SingleLinkedNode *pPre = NULL, *pNode = NULL;
    pPre = pList;

}




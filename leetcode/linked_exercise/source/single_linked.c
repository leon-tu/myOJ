#include "stdio.h"
#include "../include/linked.h"

SingleLinkedNode *SingleLinkRev(SingleLinkedNode *pLink)
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

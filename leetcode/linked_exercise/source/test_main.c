#include "../include/linked.h"
#include "stdlib.h"

void main()
{
    int ret = 0;
    SingleLinkedList *pList = NULL, *pListRev = NULL;
    ret = CreateList(&pList, 10);
    if(ret) {
        printf("Create list fail\n");
        return;
    } 
    LinkList_Display(pList);
    
    pListRev = SingleLinkRev(pList);
    if (pListRev) {
        LinkList_Display(pListRev);
    }

    return;
}

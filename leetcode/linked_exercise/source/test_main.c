#include "../include/linked.h"
#include "stdlib.h"
#include "../../utils/util.h"

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

    ret = LinkList_Insert(pListRev, 5, 20);
    if (ret) {
        LOG_PRI("Fail to insert\n");
    }
    if (pListRev) {
        LinkList_Display(pListRev);
    }

    FreeList(pListRev);
    return;
}


typedef struct {
    int key;
    int value;
    struct LRUCache *pNext;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *pHead = NULL, *pPre = NULL, *pCur = NULL;
    int i = 0;
    printf("capacity %d\n", capacity);
    pHead = (LRUCache *)malloc(sizeof(LRUCache));
    if (NULL == pHead) {
        printf("malloc fail\n");
        return NULL;
    }

    pHead->key = -1;
    pHead->value = -1;
    pHead->pNext = NULL;

    pPre = pHead;

    for (i = 0; i < capacity; i++) {
        pCur = (LRUCache *)malloc(sizeof(LRUCache));
        if (NULL == pCur) {
            printf("malloc fail\n");
        }

        pCur->key = -1;
        pCur->value = -1;
        pCur->pNext = NULL;

        if (pPre) {
            pPre->pNext = pCur;
        }

        pPre = pCur;
    }

    return pHead;
}

// the new added cache and accessed cache would be moved to the beginning
int lRUCacheGet(LRUCache* obj, int key) {
    LRUCache *pCur = NULL, *pPre = NULL;
    int value = -1;
    pPre = obj;
    for (pCur = pPre->pNext; pCur != NULL; pCur = pCur->pNext) {
        if (pCur->key == key) {
            value = pCur->value;
            //move the cache to the beginning
            pPre->pNext = pCur->pNext;
            pCur->pNext = obj->pNext;
            obj->pNext = pCur;
            break;
        }
        pPre = pCur;
    }

    printf("get: %d, %d\n", key, value);
    return value;    
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    LRUCache *pCur = NULL, *pPre = NULL;

    printf("put: %d, %d\n", key, value);
    pPre = obj;
    for (pCur = pPre->pNext; pCur != NULL; pCur = pCur->pNext) {
    /*     
        if (-1 == pCur->key) {
            pCur->key = key;
            pCur->value = value;
            return;
        }

        if (key == pCur->key) {
            // cache reassign, need to assign new value and move it to the begining
            if (value != pCur->value) {
                printf("key[%d] is equal, values are %d, %d\n",
                        key, value, pCur->value);
                pCur->value = value;
                
                pPre->pNext = pCur->pNext;
                pCur->pNext = obj->pNext;
                obj->pNext = pCur;
            }
            return;
        }
    */
        
        if ((-1 == pCur->key) || (key == pCur->key)) {
            // cache assign and move it to the beginning
            pCur->key = key;
            pCur->value = value;
            pPre->pNext = pCur->pNext;
            pCur->pNext = obj->pNext;
            obj->pNext = pCur;
            return;
        }
        
        if (NULL == pCur->pNext) {
            // cache is full, move the last one with the key to the beginning of chain
            pPre->pNext = NULL;
            pCur->key = key;
            pCur->value = value;
            pCur->pNext = obj->pNext;
            obj->pNext = pCur;
            return;
        } 

        pPre = pCur;
    }

    return;  
}

void lRUCacheFree(LRUCache* obj) {
    LRUCache *pCur = NULL, *pNext = NULL;
    pCur = obj;
    while(pCur) {
        free(pCur);
        pCur = pCur->pNext;
    }

    return;    
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * struct LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 * lRUCachePut(obj, key, value);
 * lRUCacheFree(obj);
 */

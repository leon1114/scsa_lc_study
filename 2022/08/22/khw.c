/*
Runtime: 691 ms, faster than 37.19% of C online submissions for LRU Cache.
Memory Usage: 110.1 MB, less than 53.72% of C online submissions for LRU Cache.

아 어제 풀어놓고 깃에 올리는거 깜빡했네...
*/



#define HASH_SIZE 10001

//실제로 데이터를 저장하는 캐시
typedef struct cache {
    struct cache *prev;
    struct cache *next;
    int key;
    int data;
} Cache;

//LRUCache
typedef struct {
    int capacity;
    int count;
    Cache * head;
    Cache * tail;
    Cache **hash;
} LRUCache;

Cache *createNewNode(int key, int data)
{
    Cache *temp = (Cache *)malloc(sizeof(Cache));
    temp->prev = NULL;
    temp->next = NULL;
    temp->key = key;
    temp->data = data;
    return temp;
}

Cache ** createHash(int hashSize)
{
    Cache **hash = (Cache **)malloc(hashSize * sizeof(Cache *));
    memset(hash, 0, hashSize *sizeof(Cache *));
    return hash;
}

//LRU 생성
LRUCache* lRUCacheCreate(int capacity) {
    
    LRUCache *lru = (LRUCache *)malloc(sizeof(LRUCache));
    lru->capacity = capacity;
    lru->count = 0;
    lru->head = createNewNode(-1,0);
    lru->tail = createNewNode(-1,0);
    lru->head->next = lru->tail;
    lru->tail->prev = lru->head;
    lru->hash = createHash(HASH_SIZE);
    
    return lru;
}


void addNode(LRUCache * lru, Cache *node)
{
    node->prev = lru->head;
    node->next = lru->head->next;
    
    lru->head->next->prev = node;
    lru->head->next = node;  
}

void removeNode(Cache *node)
{
    Cache *prev = node->prev;
    Cache *next = node->next;
    
    prev->next = next;
    next->prev = prev;
}

Cache* popTail(LRUCache * lru)
{
    Cache *node = lru->tail->prev;
    removeNode(node);
    return node;
}

void movetohead(LRUCache *cache, Cache *node)
{
    removeNode(node);
    addNode(cache,node);    
}

////////////////////
void lRUCachePut(LRUCache* obj, int key, int value) {
    //신규 노드 만들어서 앞에 넣어준다.
    Cache *node = obj->hash[key];    
    
    //해당 key가 없는 경우
    if(node==NULL) {
        node = createNewNode(key,value);
        obj->hash[key] = node;
        addNode(obj,node);
        obj->count++;
        
        if(obj->count > obj->capacity)
        {
            Cache *tail = popTail(obj);
            obj->hash[tail->key] = NULL;
            obj->count--;
        }        
    }
    else {
        //이미 있는 경우, 값 변경 및 앞으로 이동
        node->data = value;
        movetohead(obj,node);
    }
}

int lRUCacheGet(LRUCache* obj, int key) {
    //value값 리턴하고 앞으로 이동
    Cache *node = obj->hash[key];
    if(node != NULL)
    {
        int data = node->data;
        movetohead(obj,node);
        return data;
    }
    return -1;
}

void lRUCacheFree(LRUCache* obj) {
    
    while(obj->head)
    {
        Cache * temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }
    free(obj->hash);
    free(obj);
    
}


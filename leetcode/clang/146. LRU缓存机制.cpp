#ifndef HLIST_H
#define HLIST_H

//#include <stddef.h>
//#include <stdbool.h>

/* 
 * �ýṹ������Ƕ�뵽ҵ�����ݽṹ����(entry)������ʵ������
 * ����
 *     struct Entry {           // ���ҵ�����ݽṹ��
 *         ...
 *         struct Node node;    // Ƕ�����У�λ������
 *         ...
 *     };
 */
struct Node {
    struct Node *next, *prev;
};

/* 
 * �ɳ�Ա���� node ��ַ��ȡ�ṹ�� entry ��ַ
 * ����
 *     struct Entry entry;
 *     struct Node *n = &entry.node;
 *     struct Entry *p = NODE_ENTRY(n, struct Entry, node);
 *     ��ʱ p ָ�� entry
 */
#define NODE_ENTRY(node, type, member) \
    ((type*)((char*)(node) - (size_t)&((type*)0)->member))

/* 
 * �û����壬��� node �ڵ�Ĵ�����
 * ע��: ����� node ָ�룡
 * �������Ҫʹ�� NODE_ENTRY ����ȡ������ entry
 */
typedef void (*NodeFunc)(struct Node *node);

/* 
 * �û����壬��� node �ڵ�Ĵ�����������ѡ����
 * ע��: ����� node ָ�룡
 * �������Ҫʹ�� NODE_ENTRY ����ȡ������ entry
 */
typedef void (*NodeFuncX)(struct Node *node, void *arg);


/* ���ڱ��ڵ��˫������ */
struct List {
    struct Node base;
};

static inline void ListInit(struct List *list)
{
    list->base.next = &list->base;
    list->base.prev = &list->base;
}

static inline bool ListEmpty(const struct List *list)
{
    return list->base.next == &list->base;
}

static inline bool ListIsHead(const struct List *list, const struct Node *node)
{
    return list->base.next == node;
}

static inline bool ListIsTail(const struct List *list, const struct Node *node)
{
    return list->base.prev == node;
}

/* node ���뵽 pos ǰ�� */
static inline void ListInsert(struct Node *pos, struct Node *node)
{
    node->prev = pos->prev;
    node->next = pos;
    node->prev->next = node;
    node->next->prev = node;
}

static inline void ListAddTail(struct List *list, struct Node *node)
{
    ListInsert(&list->base, node);
}

static inline void ListAddHead(struct List *list, struct Node *node)
{
    ListInsert(list->base.next, node);
}

static inline void ListRemove(struct Node *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

static inline void ListRemoveTail(struct List *list)
{
    ListRemove(list->base.prev);
}

static inline void ListRemoveHead(struct List *list)
{
    ListRemove(list->base.next);
}

static inline void ListReplace(struct Node *old, struct Node *node)
{
    node->next = old->next;
    node->next->prev = node;
    node->prev = old->prev;
    node->prev->next = node;
}

#define LIST_FOR_EACH(node, list) \
    for (node = (list)->base.next; \
         node != &(list)->base; \
         node = (node)->next)

#define LIST_FOR_EACH_SAFE(node, tmp, list) \
    for (node = (list)->base.next, tmp = (node)->next; \
         node != &(list)->base; \
         node = tmp, tmp = (node)->next)

/* 
 * ������������ڵ�
 * ע��: nodeProc ��������� node ָ�룡
 *       ����ʱ��Ҫ�ı�����ṹ��
 */
static inline void ListIterate(struct List *list,
                               NodeFuncX nodeProc,
                               void *arg)
{
    struct Node *node;
    LIST_FOR_EACH(node, list) {
        nodeProc(node, arg);
    }
}

/* ע�⣺NodeFunc ��������� node ���� entry! */
static inline void ListDeinit(struct List *list, NodeFunc nodeDeinit)
{
    if (nodeDeinit == NULL) {
        return;
    }

    struct Node *node, *tmp;
    LIST_FOR_EACH_SAFE(node, tmp, list) {
        nodeDeinit(node);
    }
}

/* ��ȡͷ��㣬��� */
#define LIST_HEAD_ENTRY(list, type, member) \
    (ListEmpty(list) ? NULL : NODE_ENTRY((list)->base.next, type, member))

/* ��ȡβ��㣬��� */
#define LIST_TAIL_ENTRY(list, type, member) \
    (ListEmpty(list) ? NULL : NODE_ENTRY((list)->base.prev, type, member))

/* ��ȡ��һ��㣬��� */
#define LIST_NEXT_ENTRY(entry, list, type, member) \
    (ListIsTail(list, &(entry)->member) ? \
        NULL : \
        NODE_ENTRY((entry)->member.next, type, member))

/* ��ȡ��һ��㣬��� */
#define LIST_PREV_ENTRY(entry, list, type, member) \
    (ListIsHead(list, &(entry)->member) ? \
        NULL : \
        NODE_ENTRY((entry)->member.prev, type, member))

/* ���������������������������ʹ�� _SAFE �汾 */
#define LIST_FOR_EACH_ENTRY(entry, list, type, member) \
    for (entry = NODE_ENTRY((list)->base.next, type, member); \
         &(entry)->member != &(list)->base; \
         entry = NODE_ENTRY((entry)->member.next, type, member))

#define LIST_FOR_EACH_ENTRY_SAFE(entry, tmp, list, type, member) \
    for (entry = NODE_ENTRY((list)->base.next, type, member), \
         tmp = NODE_ENTRY((entry)->member.next, type, member); \
         &(entry)->member != &(list)->base; \
         entry = tmp, tmp = NODE_ENTRY((entry)->member.next, type, member))

/* ������������������������������ʹ�� _SAFE �汾 */
#define LIST_FOR_EACH_ENTRY_REVERSE(entry, list, type, member) \
    for (entry = NODE_ENTRY((list)->base.prev, type, member); \
         &(entry)->member != &(list)->base; \
         entry = NODE_ENTRY((entry)->member.prev, type, member))

#define LIST_FOR_EACH_ENTRY_REVERSE_SAFE(entry, tmp, list, type, member) \
    for (entry = NODE_ENTRY((list)->base.prev, type, member), \
         tmp = NODE_ENTRY((entry)->member.prev, type, member); \
         &(entry)->member != &(list)->base; \
         entry = tmp, tmp = NODE_ENTRY((entry)->member.prev, type, member))

#endif /* HLIST_H */


#ifndef HHASH_H
#define HHASH_H

#include <stdbool.h>
#include <stdlib.h>

/* 
 * �û����壬�ж������ڵ��Ƿ���ͬ
 * ����� node ָ�룡��ʹ�� NODE_ENTRY ��ȡ��Ӧ entry
 */
typedef bool (*HashEqualFunc)(const struct Node *a, const struct Node *b);

/*
 * �û����壬hash key ���ɺ������������� hash Ͱ
 * ����ֵ��Ӧ���� hash Ͱ��С���ƣ�
 * ����� node ָ�룡��ʹ�� NODE_ENTRY ��ȡ��Ӧ entry
 */
typedef size_t (*HashKeyFunc)(const struct Node *node, size_t bktSize);

/* 
 * Thomas Wong ����ɢ�к���
 * ����԰���ʹ�ã���ʵ����� HashKeyFunc
 * ע�⣺����ֵ�򳬹���ϣͰ��С����Ҫ��һ������
 */
static inline size_t TwIntHash(unsigned int key)
{
    key = ~key + (key << 15);
    key = key ^ (key >> 12);
    key = key + (key << 2);
    key = key ^ (key >> 4);
    key = (key + (key << 3)) + (key << 11);
    key = key ^ (key >> 16);
    return (size_t)key;
}

/* 
 * BKDR �ַ���ɢ�к���
 * ����԰���ʹ�ã���ʵ����� HashKeyFunc
 * ע�⣺����ֵ�򳬹���ϣͰ��С����Ҫ��һ������
 */
static inline size_t BkdrHash(const char *str)
{
    size_t hash = 0;
    register size_t ch = 0;
    while ((ch = (size_t)(*str++)) != '\0') {
        // hash = hash * 131 + ch;
        hash = (hash << 7) + (hash << 1) + hash + ch;
    }
    return hash;
}

struct HashTable {
    size_t bktSize;
    HashEqualFunc equal;
    HashKeyFunc key;
    struct List *bkts;
};

/* �ɹ����� 0��ʧ�ܷ��� -1 */
static inline int HashInit(struct HashTable *ht, 
                           size_t bktSize, 
                           HashEqualFunc equal, 
                           HashKeyFunc key)
{
    ht->bktSize = bktSize;
    ht->equal = equal;
    ht->key = key;
    ht->bkts = (struct List*)malloc(sizeof(struct List) * bktSize);
    if (ht->bkts == NULL) {
        return -1;
    }

    size_t i;
    for (i = 0; i < bktSize; i++) {
        ListInit(&ht->bkts[i]);
    }
    return 0;
}

/* ע�⣺NodeFunc ��������� node ���� entry! */
static inline void HashDeinit(struct HashTable *ht, NodeFunc nodeDeinit)
{
    if (nodeDeinit != NULL) {
        size_t i;
        for (i = 0; i < ht->bktSize; i++) {
            ListDeinit(&ht->bkts[i], nodeDeinit);
        }
    }
    free(ht->bkts);
}

static inline void HashAdd(struct HashTable *ht, struct Node *node)
{
    size_t k = ht->key(node, ht->bktSize);
    struct List *list = &ht->bkts[k];
    ListAddTail(list, node);
}

static inline void HashRemove(struct Node *node)
{
    ListRemove(node);
}

static inline struct Node *HashFind(const struct HashTable *ht, 
                                    const struct Node *cmpNode)
{
    size_t k = ht->key(cmpNode, ht->bktSize);
    struct List *list = &ht->bkts[k];
    struct Node *node;
    LIST_FOR_EACH(node, list) {
        if (ht->equal(cmpNode, node)) {
            return node;
        }
    }
    return NULL;
}

/* 
 * ���������ϣ�ڵ�
 * ע��: nodeProc ��������� node ָ�룡
 *       ����ʱ��Ҫ�ı� key ֵ������ṹ��
 */
static inline void HashIterate(struct HashTable *ht,
                               NodeFuncX nodeProc,
                               void *arg)
{
    size_t i;
    for (i = 0; i < ht->bktSize; i++) {
        struct Node *node;
        LIST_FOR_EACH(node, &ht->bkts[i]) {
            nodeProc(node, arg);
        }
    }
}

/* 
 * ���ù�ϣ����������� rehash
 * ������ֵ�����ɱ���ԭֵ����
 * �ɹ����� 0��ʧ�ܷ��� -1��ʧ��ʱ��ԭ��ϣ���Կ�ʹ��
 */
static inline int HashReset(struct HashTable *ht, 
                            size_t bktSize, 
                            HashEqualFunc equal, 
                            HashKeyFunc key)
{
    bktSize = bktSize != 0 ? bktSize : ht->bktSize;
    equal = equal != NULL ? equal : ht->equal;
    key = key != NULL ? key : ht->key;

    struct HashTable newHt;
    int ret = HashInit(&newHt, bktSize, equal, key);
    if (ret != 0) {
        return -1;
    }

    size_t i;
    for (i = 0; i < ht->bktSize; i++) {
        struct List *list = &ht->bkts[i];
        struct Node *node, *tmp;
        LIST_FOR_EACH_SAFE(node, tmp, list) {
            HashAdd(&newHt, node);
        }
    }

    free(ht->bkts);
    *ht = newHt;
    return 0;
}


#endif /* HHASH_H */


typedef struct {
    int capacity;
    int curCnt;
    struct List recent;     // �������¼"���ʹ��"˳��tail ���
    struct HashTable ht;    // �� HASH ʵ�ֿ��ٲ���
} LRUCache;

typedef struct {
    struct Node nodeInList;
    struct Node nodeInHash;
    int key;
    int value;
} LRUNode;

static size_t HashBktSize(int capacity)
{
    size_t bktSize = capacity / 4;     // ���ܲ���������ѣ�δ����
    bktSize = bktSize < 4 ? 4 : bktSize;
    return bktSize;
}

static bool HashEqual(const struct Node *a, const struct Node *b)
{
    LRUNode *na = NODE_ENTRY(a, LRUNode, nodeInHash);
    LRUNode *nb = NODE_ENTRY(b, LRUNode, nodeInHash);
    return na->key == nb->key;
}

static size_t HashKey(const struct Node *node, size_t bktSize)
{
    LRUNode *n = NODE_ENTRY(node, LRUNode, nodeInHash);
    size_t k = TwIntHash((unsigned int)n->key);
    return k % bktSize;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *cache = (LRUCache*)malloc(sizeof(LRUCache));
    if (cache == NULL) { return NULL; }
    cache->capacity = capacity;
    cache->curCnt = 0;
    ListInit(&cache->recent);

    size_t bktSize = HashBktSize(capacity);
    int ret = HashInit(&cache->ht, bktSize, HashEqual, HashKey);
    if (ret != 0) {
        free(cache);
        return NULL;
    }
    return cache;
}

int lRUCacheGet(LRUCache* lru, int key) {
    LRUNode cmpNode = { .key = key };
    struct Node *node = HashFind(&lru->ht, &cmpNode.nodeInHash);
    if (node == NULL) { return -1; }

    // �����⣬get ����Ҳ����"ʹ��"
    LRUNode *entry = NODE_ENTRY(node, LRUNode, nodeInHash);
    ListRemove(&entry->nodeInList);
    ListAddTail(&lru->recent, &entry->nodeInList);
    return entry->value;
}

void lRUCachePut(LRUCache* lru, int key, int value) {
    LRUNode *entry;
    LRUNode cmpNode = { .key = key };
    struct Node *node = HashFind(&lru->ht, &cmpNode.nodeInHash);
    if (node != NULL) {
        entry = NODE_ENTRY(node, LRUNode, nodeInHash);
        ListRemove(&entry->nodeInList);
    } else {
        if (lru->curCnt < lru->capacity) {
            entry = (LRUNode*)malloc(sizeof(LRUNode));
            if (entry == NULL) { return; }
            lru->curCnt++;
        } else {
            // �ظ����ñ���Ҫ�������Ľڵ�
            entry = LIST_HEAD_ENTRY(&lru->recent, LRUNode, nodeInList);
            if (entry == NULL) { return; }
            ListRemove(&entry->nodeInList);
            HashRemove(&entry->nodeInHash);
        }
        entry->key = key;
        HashAdd(&lru->ht, &entry->nodeInHash);
    }
    entry->value = value;
    ListAddTail(&lru->recent, &entry->nodeInList);
}

static void FreeListNode(struct Node *node)
{
    LRUNode *entry = NODE_ENTRY(node, LRUNode, nodeInList);
    free(entry);
}

void lRUCacheFree(LRUCache* lru) {
    HashDeinit(&lru->ht, NULL); // LRUNode ֻ���ͷ�һ��
    ListDeinit(&lru->recent, FreeListNode);
    free(lru);
}

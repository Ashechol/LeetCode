#include <unordered_map>
#include <iostream>

using namespace std;

class LRUCache {

    struct DualListNode
    {
        int key;
        int val;
        DualListNode* pre;
        DualListNode* next;
        DualListNode(int key=0, int val=0) : key(key), val(val), pre(nullptr), next(nullptr) {}
    };

    unordered_map<int, DualListNode*> lruHash;
    DualListNode* dummyHead;
    DualListNode* dummyTail;

    void Update(DualListNode* tmp)
    {
        tmp->pre->next = tmp->next;
        tmp->next->pre = tmp->pre;
        tmp->pre = dummyHead;
        tmp->next = dummyHead->next;
        dummyHead->next->pre = tmp;
        dummyHead->next = tmp;
    }

public:
    int capacity;

    LRUCache(int capacity) : capacity(capacity),
                             dummyHead(new DualListNode()), dummyTail(new DualListNode())
    {
        dummyHead->next = dummyTail;
        dummyTail->pre = dummyHead;
    }


    int get(int key)
    {
        if (lruHash.find(key) == lruHash.end())
            return -1;
        else
        {
            Update(lruHash[key]);
            return lruHash[key]->val;
        }
    }

    void put(int key, int value)
    {
        if (lruHash.find(key) != lruHash.end())
        {
            lruHash[key]->val = value;
            Update(lruHash[key]);
            return;
        }

        DualListNode* newNode = new DualListNode(key, value);

        if (lruHash.size() == capacity)
        {
            DualListNode* tmp = dummyTail->pre;
            dummyTail->pre = tmp->pre;
            tmp->pre->next = dummyTail;

            cout << tmp->key << endl;
            lruHash.erase(tmp->key);
            delete tmp;
        }

        lruHash[key] = newNode;
        dummyHead->next->pre = newNode;
        newNode->next = dummyHead->next;
        newNode->pre = dummyHead;
        dummyHead->next = newNode;
    }
};

int main()
{
    LRUCache lr(2);
    lr.put(1, 1); // 缓存是 {1=1}
    lr.put(2, 2); // 缓存是 {1=1, 2=2}
    lr.get(1);    // 返回 1
    lr.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lr.get(2);    // 返回 -1 (未找到)
    lr.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lr.get(1);    // 返回 -1 (未找到)
    lr.get(3);    // 返回 3
    lr.get(4);    // 返回 4

    return 0;
}
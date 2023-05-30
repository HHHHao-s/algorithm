#include "s.h"
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache
{
public:
    struct Node
    {
        int pre, succ, value;
    };

    int head, end, size, capacity;

    unordered_map<int, Node> cache;

    LRUCache(int _capacity)
    {
        size = 0;
        head = -1;
        end = -1;
        capacity = _capacity;
    }

    int get(int key)
    {
        if(capacity==1) {
            if(cache.count(key)) return cache[key].value;
            else return -1;
        }

        if (cache.count(key))
        { // have
            if(capacity==1) return cache[key].value;

            if (!(head == key))
            {
                if (key == end)
                {
                    Node *self = &cache[key], *heads = &cache[head], *self_succ = &cache[self->succ];
                    
                    end = self->succ;
                    self_succ->pre = -1;

                    self->pre = head;
                    self->succ = -1;
                    heads->succ = key;

                    head = key;
                    
                    return self->value;
                }
                else
                {
                    Node *self = &cache[key], *heads = &cache[head], *self_pre = &cache[self->pre], *self_succ = &cache[self->succ];
                    self_pre->succ = self->succ;
                    self_succ->pre = self->pre;

                    self->pre = head;
                    self->succ = -1;
                    heads->succ = key;

                    head = key;

                    return self->value;
                }
            }
            else
            {
                return cache[head].value;
            }
        }
        else
            return -1;
    }

    void put(int key, int value)
    {

        if(capacity==1) {
            cache.clear();
            cache[key].value=value;
            return ;
        }
        if (cache.count(key))
        { // have
            cache[key].value = value;
            get(key);
        }else
        {
            
            if (size < capacity)
            {
                if (head != -1)
                {
                    Node *heads = &cache[head];
                    cache[key] = {head, -1, value};
                    heads->succ = key;
               
                }
                else
                {
                    end = key;
                    cache[key] = {-1, -1, value};
                    
                }
                head = key;
                size++;
            }
            else
            { // sacrifice
                Node *ends = &cache[end], *ends_succ = &cache[ends->succ], *heads = &cache[head];

                ends_succ->pre = -1;
                int temp = ends->succ;
                cache.erase(end);
                end = temp;
                
                
                cache[key] = {head, -1, value};
                heads->succ = key;
                head = key;
            }
        }
    }
};

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache2 {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache2(int _capacity): capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main(){

    LRUCache c = LRUCache(2);

    c.put(1,1);
    c.put(2,2);
    cout << c.get(1) << " ";
    c.put(3,3);
    cout << c.get(2) << " ";
    c.put(4,4);
    cout << c.get(1) << " ";
    cout << c.get(3) << " ";
    cout << c.get(4) << " ";
    return 0;
}

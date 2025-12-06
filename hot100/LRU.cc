/**
 * xiebaoma
 * 2025-12-05
 */
#include <unordered_map>
using namespace std;

class LRUNode
{
public:
    LRUNode* pre;
    LRUNode* next;
    int key;
    int val;
    LRUNode()
    {
        pre = nullptr;
        next = nullptr;
        key = 0;
        val = 0;
    }
    LRUNode(int key, int val)
    {
        this->key = key;
        this->val = val;
        pre = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity= capacity;
        count=0;
        start = new LRUNode();
        end = new LRUNode();
        start->next = end;
        end->pre= start;
    }

    void removeend()
    {
        LRUNode* node = end->pre;
        nodes.erase(node->key);
        node->pre->next = end;
        end->pre = node->pre;
        delete node;
    }

    void movetohead(LRUNode* node)
    {
        node->next->pre=node->pre;
        node->pre->next=node->next;

        LRUNode* cur= start->next;
        start->next=node;
        node->next= cur;
        cur->pre=node;
        node->pre=start;
    }
    void addtohead(LRUNode* node)
    {
        LRUNode* cur= start->next;
        start->next = node;
        node->next= cur;
        node->pre=start;
        cur->pre=node;
    }
    int get(int key) {
        if (nodes.find(key)==nodes.end())
        {
            return -1;
        }
        LRUNode* node = nodes[key];
        movetohead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (nodes.find(key)!=nodes.end())
        {
            // 更新已存在节点的值并移动到头部
            nodes[key]->val = value;
            movetohead(nodes[key]);
            return;
        }
        LRUNode* newnode = new LRUNode(key, value);
        nodes[key] = newnode;
        addtohead(newnode);
        count++;
        if (count > capacity)
        {
            removeend();
            count--;
        }
    }

    ~LRUCache() {
        // 清理所有节点
        LRUNode* cur = start;
        while (cur != nullptr) {
            LRUNode* next = cur->next;
            delete cur;
            cur = next;
        }
    }
private:
    LRUNode* start;
    LRUNode* end;
    int capacity;
    int count;
    unordered_map<int , LRUNode*> nodes;
};

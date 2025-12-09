#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
public:
    struct Node {
        int key;
        int value;
        int freq;
        Node(int k, int v, int f) : key(k), value(v), freq(f) {}
    };

    int capacity;
    int minFreq;

    // key -> 节点迭代器
    unordered_map<int, list<Node>::iterator> keyNode;

    // freq -> 双向链表，存放所有该频率的节点
    unordered_map<int, list<Node>> freqList;

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0) return 0;

        auto it = keyNode.find(key);
        if (it == keyNode.end()) return -1;

        auto nodeIt = it->second;
        int val = nodeIt->value;
        int freq = nodeIt->freq;

        // 从旧 freq 列表中删除
        freqList[freq].erase(nodeIt);
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        // 插入到新 freq 列表中
        freqList[freq + 1].push_front(Node(key, val, freq + 1));
        keyNode[key] = freqList[freq + 1].begin();

        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // key 已存在：更新值 + freq++
        if (keyNode.count(key)) {
            keyNode[key]->value = value;
            get(key);      // 复用 get 的逻辑提升频率
            return;
        }

        // 缓存满了：删掉 minFreq 频率下最旧的节点（链表尾）
        if (keyNode.size() >= capacity) {
            auto &lst = freqList[minFreq];
            auto delIt = lst.back();
            int delKey = delIt.key;
            lst.pop_back();
            if (lst.empty()) {
                freqList.erase(minFreq);
            }
            keyNode.erase(delKey);
        }

        // 插入新节点，freq = 1
        freqList[1].push_front(Node(key, value, 1));
        keyNode[key] = freqList[1].begin();
        minFreq = 1;
    }
};

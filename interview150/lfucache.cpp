/**
 * xiebaoma
 * 2025-07-26
 */

#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
private:
    int capacity;
    int minFreq;

    unordered_map<int, int> keyToVal;
    unordered_map<int, int> keyToFreq;
    unordered_map<int, list<int>> freqToKeys;
    unordered_map<int, list<int>::iterator> keyToIter;

    void increaseFreq(int key) {
        int freq = keyToFreq[key];
        keyToFreq[key] = freq + 1;

        // 从旧频率列表中删除
        freqToKeys[freq].erase(keyToIter[key]);
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (freq == minFreq)
                minFreq++;
        }

        // 加入新频率列表
        freqToKeys[freq + 1].push_front(key);
        keyToIter[key] = freqToKeys[freq + 1].begin();
    }

    void removeMinFreqKey() {
        // 找到最小频率对应的 key 列表
        auto& keyList = freqToKeys[minFreq];
        int keyToRemove = keyList.back();
        keyList.pop_back();
        if (keyList.empty()) {
            freqToKeys.erase(minFreq);
        }

        // 删除相关数据
        keyToVal.erase(keyToRemove);
        keyToFreq.erase(keyToRemove);
        keyToIter.erase(keyToRemove);
    }

public:
    LFUCache(int capacity): capacity(capacity), minFreq(0) {}

    int get(int key) {
        if (keyToVal.count(key) == 0)
            return -1;
        increaseFreq(key);
        return keyToVal[key];
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyToVal.count(key)) {
            keyToVal[key] = value;
            increaseFreq(key);
            return;
        }

        if (keyToVal.size() == capacity) {
            removeMinFreqKey();
        }

        // 插入新 key
        keyToVal[key] = value;
        keyToFreq[key] = 1;
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }
};

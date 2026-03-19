#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

struct Node {
    int key;
    int value;
    int freq;
};

class LFUCache {
private:
    int capacity;
    int minFreq;

    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (key_table.find(key) == key_table.end())
            return -1;

        auto it = key_table[key];
        Node node = *it;
        int freq = node.freq;

        freq_table[freq].erase(it);
        if (freq_table[freq].empty()) {
            freq_table.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        node.freq++;
        freq_table[node.freq].push_front(node);
        key_table[key] = freq_table[node.freq].begin();

        return node.value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (key_table.find(key) != key_table.end()) {
            key_table[key]->value = value;
            get(key);  
            return;
        }

        if (key_table.size() == capacity) {
            auto &list = freq_table[minFreq];
            auto node = list.back();
            key_table.erase(node.key);
            list.pop_back();

            if (list.empty())
                freq_table.erase(minFreq);
        }

        Node node = {key, value, 1};
        freq_table[1].push_front(node);
        key_table[key] = freq_table[1].begin();
        minFreq = 1;
    }
};
/**
 * xiebaoma
 * 2025-12-11
 */

#include <unordered_map>
#include <list>
using namespace std;

class LFUCache
{
public:
    struct Node
    {
        int key;
        int value;
        int freq;
        Node(int k,int v,int f):key(k),value(v),freq(f){}
    };

    int capacity;
    int minFreq;

    unordered_map<int,list<Node>::iterator> keyNode;
    unordered_map<int,list<Node>> freqList;

    LFUCache(int capacity):capacity(capacity),minFreq(0){}

    int get(int key)
    {
        if (capacity==0) return -1;
        if (keyNode.find(key)==keyNode.end()) return -1;

        auto it =keyNode[key];
        int val = it->value;
        int freq=it->freq;

        freqList[freq].erase(it);
        if (freqList[freq].empty())
        {
            freqList.erase(freq);
            if (freq==minFreq) minFreq++;
        }

        freqList[freq+1].push_front(Node(key,val,freq+1));
        keyNode[key]=freqList[freq+1].begin();

        return val;
    }

    void put(int key,int value)
    {
        if (capacity==0) return;
        if (keyNode.find(key)!=keyNode.end())
        {
            keyNode[key]->value=value;
            get(key);
            return;
        }
        if (keyNode.size()>=capacity)
        {
            auto &lst= freqList[minFreq];
            auto it = prev(lst.end());
            int delkey=it->key;
            lst.erase(it);
            if (lst.empty())
            {
                freqList.erase(minFreq);
            }
            keyNode.erase(delkey);
        }

        freqList[1].push_front(Node(key,value,1));
        keyNode[key]=freqList[1].begin();
        minFreq=1;
    }
};
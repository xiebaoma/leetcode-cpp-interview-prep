/**
 * xiebaoma
 * 2025-06-30
 */

#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomizedSet
{
public:
    RandomizedSet() { srand(time(0)); }

    bool insert(int val)
    {
        if (valToIndex.count(val))
            return false;
        valToIndex[val] = data.size();
        data.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (!valToIndex.count(val))
            return false;
        int idx = valToIndex[val];
        int last = data.back();
        data[idx] = last;
        valToIndex[last] = idx;
        data.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom()
    {
        int randIdx = rand() % data.size();
        return data[randIdx];
    }

private:
    vector<int> data;
    unordered_map<int, int> valToIndex;
};

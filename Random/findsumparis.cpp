/**
 * xiebaoma
 * 2025-07-06
 */

#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs
{
public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        mnums2 = nums2;
        for (int val : nums1)
        {
            map[val]++;
        }
    }

    void add(int index, int val)
    {
        mnums2[index] += val;
    }

    int count(int tot)
    {
        int count = 0;
        for (int val : mnums2)
        {
            if (map.find(tot - val) != map.end())
            {
                count += map[tot - val];
            }
        }
        return count;
    }

private:
    vector<int> mnums2;
    unordered_map<int, int> map;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
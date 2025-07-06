/**
 * xiebaoma
 * 2025-07-06
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> map;
        vector<int> ret;
        int len = numbers.size();
        for (int i = 0; i < len; i++)
        {
            int val = numbers[i];
            if (map.find(target - val) != map.end())
            {
                ret.push_back(map[target - val] + 1);
                ret.push_back(i + 1);
                break;
            }
            else
            {
                map[val] = i;
            }
        }
        return ret;
    }
};
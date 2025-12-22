/**
 * 2025-06-19
 * xiebaoma
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++)
    {
        int key = nums[i];
        int val = i;
        if (map.find(target - key) != map.end())
        {
            ret.push_back(map[target - key]);
            ret.push_back(i);
            return ret;
        }
        map[key] = val;
    }
    return ret;
}

int main()
{
}
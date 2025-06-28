/**
 * xiebaoma
 * 2025-06-28
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    set<string> generate(vector<char> &vec)
    {
        set<string> result;

        // 排序是关键，确保 next_permutation 从最小排列开始
        sort(vec.begin(), vec.end());

        do
        {
            string s(vec.begin(), vec.end()); // 将字符组合成字符串
            result.insert(s);                 // set 自动去重
        } while (next_permutation(vec.begin(), vec.end()));

        return result;
    }

    vector<string> getpalind(set<string> &strings, char mid, bool checksingle)
    {
        vector<string> ret;
        for (string s : strings)
        {
            string s2 = s;
            reverse(s2.begin(), s2.end());
            if (checksingle)
            {
                s += mid;
            }
            s += s2;
            ret.push_back(s);
        }
        return ret;
    }

    vector<string> generatePalindromes(string s)
    {
        char mid = '0';
        unordered_map<char, int> map;
        vector<string> ret;
        vector<char> chars;
        for (char c : s)
        {
            map[c]++;
        }
        bool checksingle = true;
        int count = 0;
        for (auto it : map)
        {
            if (it.second % 2 == 1)
            {
                mid = it.first;
                count++;
            }
            chars.insert(chars.end(), it.second / 2, it.first);
            if (count > 1)
            {
                return ret;
            }
        }
        if (count == 0)
            checksingle = false;
        set<string> strings = generate(chars);
        ret = getpalind(strings, mid, checksingle);
        return ret;
    }
};
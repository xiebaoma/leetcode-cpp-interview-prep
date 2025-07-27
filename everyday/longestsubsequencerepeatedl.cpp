/**
 * xiebaoma
 * 2025-06-27
 */

#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool check(string &s, string &sub, int k)
    {
        int count = 0;
        int i = 0;
        for (char c : s)
        {
            if (c == sub[i])
            {
                i++;
            }
            if (i == sub.size())
            {
                i = 0;
                count++;
            }
            if (count == k)
            {
                return true;
            }
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k)
    {
        string ret;

        unordered_map<char, int> map;
        for (char c : s)
        {
            map[c]++;
        }
        vector<char> vec;
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (map[c] >= k)
            {
                vec.push_back(c);
            }
        }
        queue<string> que;
        string next = "";
        que.push(next);
        while (!que.empty())
        {
            next = que.front();
            que.pop();
            for (char c : vec)
            {
                string str= next+c;
                if (check(s, str, k))
                {
                    que.push(str);
                    if (str.size() > ret.size() || (str.size() == ret.size() && str > ret))
                    {
                        ret = str;
                    }
                }
            }
        }
        return ret;
    }
};
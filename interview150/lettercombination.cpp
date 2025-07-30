/**
 * xiebaoma
 * 2025-07-30
 */

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<char, vector<char>> map;

    void dfs(vector<string> &vec, int i, string &digits, string &cur)
    {
        if (cur.size() == digits.size())
        {
            vec.push_back(cur);
            return;
        }
        vector<char> v = map[digits[i]];
        for (int j = 0; j < v.size(); j++)
        {
            cur += v[j];
            dfs(vec, i + 1, digits, cur);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        map['2'] = {'a', 'b', 'c'};
        map['3'] = {'d', 'e', 'f'};
        map['4'] = {'g', 'h', 'i'};
        map['5'] = {'j', 'k', 'l'};
        map['6'] = {'m', 'n', 'o'};
        map['7'] = {'p', 'q', 'r', 's'};
        map['8'] = {'t', 'u', 'v'};
        map['9'] = {'w', 'x', 'y', 'z'};

        vector<string> vec;
        if (digits.size() == 0)
        {
            return vec;
        }
        string cur = "";
        dfs(vec, 0, digits, cur);
        return vec;
    }
};
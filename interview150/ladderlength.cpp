/**
 * xiebaoma
 * 2025-07-29
 */

#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> cnt;
        unordered_set<string> visited;
        for (auto &w : wordList)
        {
            cnt.emplace(w);
        }
        if (!cnt.count(endWord))
        {
            return 0;
        }
        queue<string> qu;
        qu.emplace(beginWord);
        visited.emplace(beginWord);
        int step = 1;
        while (!qu.empty())
        {
            int sz = qu.size();
            for (int i = 0; i < sz; i++)
            {
                string curr = qu.front();
                qu.pop();
                for (int j = 0; j < curr.size(); j++)
                {
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        if (c != curr[j])
                        {
                            string next = curr;
                            next[j] = c;
                            if (!visited.count(next) && cnt.count(next))
                            {
                                if (next == endWord)
                                {
                                    return step + 1;
                                }
                                qu.emplace(next);
                                visited.emplace(next);
                            }
                        }
                    }
                }
            }
            step++;
        }
        return 0;
    }
};
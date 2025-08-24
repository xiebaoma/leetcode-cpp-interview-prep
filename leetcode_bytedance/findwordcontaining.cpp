/**
 * xiebaoma
 * 2025-08-24
 */

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (words[i].find(x) != words[i].npos) {
                res.push_back(i);
            }
        }
        return res;
    }
};
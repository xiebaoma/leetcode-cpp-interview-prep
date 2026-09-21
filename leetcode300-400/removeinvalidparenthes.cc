/**
 *xiebaoma
 *2026-1-08
 */

#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    bool isValid(const string& s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '(') cnt++;
            else if (c == ')') {
                cnt--;
                if (cnt < 0) return false;
            }
        }
        return cnt == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front(); q.pop();

                if (isValid(cur)) {
                    res.push_back(cur);
                    found = true;
                }

                if (found) continue;

                for (int j = 0; j < cur.size(); j++) {
                    if (cur[j] != '(' && cur[j] != ')') continue;

                    string next = cur.substr(0, j) + cur.substr(j + 1);
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            if (found) break;
        }

        return res;
    }
};

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int windowLen = wordLen * wordCount;
        if (s.size() < windowLen) return result;

        unordered_map<string, int> wordMap;
        for (const string& word : words)
            ++wordMap[word];

        // 从每个偏移开始滑动窗口（最多 wordLen 种偏移）
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            unordered_map<string, int> seen;
            int count = 0;

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordMap.count(word)) {
                    ++seen[word];
                    ++count;

                    // 超出词频，窗口左边收缩
                    while (seen[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        --seen[leftWord];
                        --count;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // 遇到不合法的单词，窗口全部清空
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};

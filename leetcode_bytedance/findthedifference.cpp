/**
 * xiebaoma
 * 2025-08-24
 */

#include<string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int ret = 0;
        for (char ch: s) {
            ret ^= ch;
        }
        for (char ch: t) {
            ret ^= ch;
        }
        return ret;
    }
};

/**
 * xiebaoma
 * 2025-07-18
 */

#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> map{{')', '('}, {']', '['}, {'}', '{'}};
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                char cs = st.top();
                st.pop();
                char cx = map[c];
                if (cs != cx)
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
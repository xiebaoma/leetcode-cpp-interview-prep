/**
 * xiebaoma
 * 2025-07-05
 */

#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        int slow = 0;
        int fast = 0;
        int len = s.size();
        while (fast < len)
        {
            if (s[slow] != ' ' && s[fast] == ' ')
            {
                st.push(s.substr(slow, fast - slow));
                slow = fast;
            }
            else if (fast == len - 1 && s[slow] != ' ')
            {
                st.push(s.substr(slow, fast - slow + 1));
                break;
            }
            else if (s[slow] == ' ' && s[fast] == ' ')
            {
                slow++;
                fast++;
            }
            else
            {
                fast++;
            }
        }
        string ret = "";
        string first = st.top();
        st.pop();
        ret += first;
        while (!st.empty())
        {
            string str = st.top();
            st.pop();
            ret += " ";
            ret += str;
        }
        return ret;
    }
};
/**
 * xiebaoma
 * 2025-07-19
 */

#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> mstack;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                int v1 = mstack.top();
                mstack.pop();
                int v2 = mstack.top();
                mstack.pop();
                mstack.push(v1 + v2);
            }
            else if (tokens[i] == "-")
            {
                int v1 = mstack.top();
                mstack.pop();
                int v2 = mstack.top();
                mstack.pop();
                mstack.push(v2 - v1);
            }
            else if (tokens[i] == "*")
            {
                int v1 = mstack.top();
                mstack.pop();
                int v2 = mstack.top();
                mstack.pop();
                mstack.push(v1 * v2);
            }
            else if (tokens[i] == "/")
            {
                int v1 = mstack.top();
                mstack.pop();
                int v2 = mstack.top();
                mstack.pop();
                mstack.push(v2 / v1);
            }
            else
            {
                int val = stoi(tokens[i]);
                mstack.push(val);
            }
        }
        return mstack.top();
    }
};
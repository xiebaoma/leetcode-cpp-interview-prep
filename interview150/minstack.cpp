/**
 * xiebaoma
 * 2025-07-19
 */

#include <stack>
using namespace std;

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        mstack.push(val);
        if (minstack.empty() || minstack.top() >= val)
            minstack.push(val);
    }

    void pop()
    {
        if (mstack.top() == minstack.top())
            minstack.pop();
        mstack.pop();
    }

    int top()
    {
        return mstack.top();
    }

    int getMin()
    {
        return minstack.top();
    }

private:
    stack<int> mstack;
    stack<int> minstack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Permutation
{
public:
    vector<string> res;

    void backtrack(string &s, int start)
    {
        if (start == s.size() - 1)
        {
            res.push_back(s);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            swap(s[start], s[i]);    // 选择
            backtrack(s, start + 1); // 递归
            swap(s[start], s[i]);    // 撤销选择
        }
    }

    vector<string> getPermutations(string s)
    {
        res.clear();
        backtrack(s, 0);
        return res;
    }
};

int main()
{
    string str;
    cout << "请输入字符串: ";
    cin >> str;

    Permutation p;
    vector<string> ans = p.getPermutations(str);

    cout << "全排列结果:" << endl;
    for (auto &perm : ans)
    {
        cout << perm << endl;
    }

    return 0;
}

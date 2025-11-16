#include <bits/stdc++.h>
using namespace std;

/*
任务：
给定偏序集<A, ≤>，输入元素集合A（字母），以及覆盖关系（哈斯图边 <x,y>），
计算并输出极小元与极大元。
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string Aline, Rline;
    getline(cin, Aline);   // 第一行：元素集合
    getline(cin, Rline);   // 第二行：覆盖关系（哈斯图中的边）

    // ---- 1. 解析元素集合 A ----
    vector<char> elems;
    {
        string tmp;
        for (char c : Aline) {
            if (isalpha(c)) elems.push_back(c);
        }
    }

    // 元素数量
    int n = elems.size();

    // 按字母排序（保证输出顺序）
    sort(elems.begin(), elems.end());

    // 构建字符 -> 索引映射
    unordered_map<char, int> idx;
    for (int i = 0; i < n; ++i) {
        idx[elems[i]] = i;
    }

    // ---- 2. 解析覆盖关系（哈斯图边）----
    vector<vector<int>> R(n, vector<int>(n, 0));

    for (int i = 0; i < (int)Rline.size(); ++i) {
        if (Rline[i] == '<') {
            // 解析 <x,y>
            char x = Rline[i + 1];
            char y = Rline[i + 3];

            int u = idx[x];
            int v = idx[y];

            R[u][v] = 1; // x < y
        }
    }

    // ---- 3. 求传递闭包 (Floyd-Warshall) ----
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (R[i][k] && R[k][j])
                    R[i][j] = 1;

    // ---- 4. 求极小元与极大元 ----
    vector<char> minimal, maximal;

    for (int i = 0; i < n; ++i) {
        bool hasPred = false;
        bool hasSucc = false;

        for (int j = 0; j < n; ++j) {
            if (R[j][i]) hasPred = true;  // 存在 j < i
            if (R[i][j]) hasSucc = true;  // 存在 i < j
        }

        if (!hasPred) minimal.push_back(elems[i]);
        if (!hasSucc) maximal.push_back(elems[i]);
    }

    // ---- 5. 输出结果 ----
    // 极小元
    for (int i = 0; i < (int)minimal.size(); ++i) {
        cout << minimal[i];
        if (i + 1 < minimal.size()) cout << ",";
    }
    cout << "\n";

    // 极大元
    for (int i = 0; i < (int)maximal.size(); ++i) {
        cout << maximal[i];
        if (i + 1 < maximal.size()) cout << ",";
    }
    cout << "\n";

    return 0;
}

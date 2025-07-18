/**
 * xiebaoma
 * 2025-07-18
 */

#include <vector>
#include <numeric> // for iota
using namespace std;

class Solution
{
public:
    int find(int x, vector<int> &parent)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x], parent); // 路径压缩
        }
        return parent[x];
    }

    void unite(int x, int y, vector<int> &parent)
    {
        int rootX = find(x, parent);
        int rootY = find(y, parent);
        if (rootX != rootY)
        {
            parent[rootY] = rootX; // 合并集合
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (isConnected[i][j] == 1)
                {
                    unite(i, j, parent);
                }
            }
        }

        // 统计根节点数量
        int provinces = 0;
        for (int i = 0; i < n; ++i)
        {
            if (find(i, parent) == i)
            {
                provinces++;
            }
        }
        return provinces;
    }
};

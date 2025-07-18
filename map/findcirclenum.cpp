/**
 * xiebaoma
 * 2025-07-18
 */

#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(int i, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        visited[i] = true;
        for (int j = 0; j < isConnected.size(); ++j)
        {
            if (isConnected[i][j] == 1 && !visited[j])
            {
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }

        return provinces;
    }
};

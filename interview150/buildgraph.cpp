/**
 * xiebaoma
 * 2025-07-27
 */

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
    // 图结构：map<变量, map<邻接变量, 权重>>
    unordered_map<string, unordered_map<string, double>> graph;

    // 构建图
    void buildGraph(vector<vector<string>> &equations, vector<double> &values)
    {
        for (int i = 0; i < equations.size(); ++i)
        {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];
            graph[A][B] = val;
            graph[B][A] = 1.0 / val;
        }
    }

    // DFS 查找从 curr 到 target 的路径，返回累乘结果
    bool dfs(string curr, string target, unordered_set<string> &visited, double &result, double curProduct)
    {
        if (graph.find(curr) == graph.end())
            return false;
        if (curr == target)
        {
            result = curProduct;
            return true;
        }
        visited.insert(curr);
        for (auto &neighbor : graph[curr])
        {
            if (visited.count(neighbor.first))
                continue;
            if (dfs(neighbor.first, target, visited, result, curProduct * neighbor.second))
            {
                return true;
            }
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        buildGraph(equations, values);
        vector<double> results;

        for (auto &q : queries)
        {
            string start = q[0];
            string end = q[1];
            if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
            {
                results.push_back(-1.0);
                continue;
            }
            if (start == end)
            {
                results.push_back(1.0);
                continue;
            }
            unordered_set<string> visited;
            double res = -1.0;
            dfs(start, end, visited, res, 1.0);
            results.push_back(res);
        }
        return results;
    }
};

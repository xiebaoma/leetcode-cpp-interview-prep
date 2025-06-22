/**
 * xiebaoma
 * 2025-06-22
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int maxcount = 1;
    bool issamecolortree(vector<vector<int>> &childs, int index, vector<int> &colors)
    {
        vector<int> &par = childs[index];
        if (par.size() == 0)
        {
            return true;
        }
        for (int child : par)
        {
            if (colors[index] != colors[child])
            {
                return false;
            }
            if (!issamecolortree(childs, child, colors))
            {
                return false;
            }
        }
        return true;
    }

    int getcount(int index, vector<vector<int>> &edges)
    {
        int ret = 1;
        vector<int> &childs = edges[index];
        if (childs.size() == 0)
        {
            return 1;
        }
        for (int child : childs)
        {
            ret += getcount(child, edges);
        }
        return ret;
    }

    void dp(vector<vector<int>> &edges, int index, vector<int> &colors)
    {
        if (issamecolortree(edges, index, colors))
        {
            maxcount = max(maxcount, getcount(index, edges));
            return;
        }
        vector<int> &childs = edges[index];
        for (int child : childs)
        {
            dp(edges, child, colors);
        }
    }
    int maximumSubtreeSize(vector<vector<int>> &edges, vector<int> &colors)
    {
        int count = colors.size();
        vector<vector<int>> childs(count);
        for (auto it : edges)
        {
            int p = it[0];
            int c = it[1];
            childs[p].push_back(c);
        }
        dp(childs, 0, colors);
        return maxcount;
    }
};
/**
 * xiebaoma
 * 2025-08-12
 */

#include <vector>
#include <map>
#include <numeric>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n <= 2)
            return n;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            map<pair<int, int>, int> slopeCount;
            int samePoint = 1; // 包括自己
            int maxSlope = 0;

            for (int j = i + 1; j < n; j++)
            {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0)
                {
                    samePoint++;
                    continue;
                }

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                // 保证方向唯一性
                if (dx < 0)
                {
                    dx = -dx;
                    dy = -dy;
                }
                else if (dx == 0)
                {
                    dy = 1; // 垂直线
                }
                else if (dy == 0)
                {
                    dx = 1; // 水平线
                }

                slopeCount[{dy, dx}]++;
                maxSlope = max(maxSlope, slopeCount[{dy, dx}]);
            }
            ans = max(ans, maxSlope + samePoint);
        }
        return ans;
    }
};

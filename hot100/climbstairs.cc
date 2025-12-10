/**
 * xiebaoma
 * 2025-12-10
 */

#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> counts(n+1);
        if (n==1) return 1;
        if (n==2) return 2;
        counts[0]=0;
        counts[1]=1;
        counts[2]=2;
        for (int i=3;i<=n;i++)
        {
            counts[i]=counts[i-1]+counts[i-2];
        }
        return counts[n];
    }
};
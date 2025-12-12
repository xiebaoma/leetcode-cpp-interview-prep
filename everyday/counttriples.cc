/**
 * xiebaoma
 * 2025-12-08
 */
class Solution {
public:
    int countTriples(int n) {
        int res=0;
        for (int i=1;i<=n-2;i++)
        {
            for (int j=i+1;j<=n-1;j++)
            {
                int count = i*i+j*j;
                for (int k=j+1;k<=n;k++)
                {
                    if (k*k==count)
                    {
                        res++;
                        break;
                    }
                    if (k*k>count)
                    {
                        break;
                    }
                }
            }
        }
        return res*2;
    }
};
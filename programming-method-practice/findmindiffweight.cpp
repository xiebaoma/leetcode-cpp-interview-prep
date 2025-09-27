/**
 * xiebaoma
 * 2025-09-27
 */

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;  
#define N 1000000  
#define MaxNum 1000000000  
  
int S1[N],S2[N],S3[N];  
  
int DiffWeight(int i, int j, int k){  
    return abs(S1[i] - S2[j]) + abs(S2[j] - S3[k]) + abs(S3[k] - S1[i]);  
}  
// 返回S1[i],S2[j],S3[k]中最小的序号  
// 返回i表示Si对应的数最小  
int xls_min(int i, int j, int k){  
    if(S1[i] <= S2[j]){  
        if(S1[i] <= S3[k]){  
            return 1;  
        }  
        return 3;  
    }  
    else{  
        if(S2[j] <= S3[k]){  
            return 2;  
        }  
        return 3;  
    }  
}  
  
// n -> 集合的大小  
int findMinDiffWeight(int n);  
  
int main()  
{  
    int n;  
    scanf("%d", &n);  
    for (int i = 0; i < n; i++)  
        scanf("%d", &S1[i]);  
    for (int i = 0; i < n; i++)  
        scanf("%d", &S2[i]);  
    for (int i = 0; i < n; i++)  
        scanf("%d", &S3[i]);  
    printf("%d\n", findMinDiffWeight(n));  
    return 0;  
}  

int findMinDiffWeight(int n)
{
    int i = 0, j = 0, k = 0;
    int ans = INT_MAX;

    while (i < n && j < n && k < n) {
        // 计算当前三元组的 D
        int d = DiffWeight(i, j, k);
        ans = min(ans, d);

        // 判断谁最小
        int t = xls_min(i, j, k);

        // 移动最小值的指针
        if (t == 1) ++i;
        else if (t == 2) ++j;
        else ++k;
    }

    return ans;
}

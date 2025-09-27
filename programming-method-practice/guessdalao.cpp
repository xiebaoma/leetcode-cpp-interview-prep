/**
 * xiebaoma
 * 2025-09-27
 */

#include <cstdio>
using namespace std;  

const int maxn = 1005;  
int n;  
bool good[maxn][maxn];  
void guessdalao(int n); // you should finish this  
int better(int a, int b)  
{  
    if (a <= 0 || a > n || b <= 0 || b > n) return -1;  
    return good[a][b];  
}  
int main()  
{  
    scanf("%d", &n);  
    for (int i = 1; i <= n; i++)  
        for (int j = 1; j <= n; j++)  
        {  
            int t;  
            scanf("%d", &t);  
            good[i][j] = t;  
        }  
    guessdalao(n);  
    return 0;  
}  

void guessdalao(int n)
{
    // Step 1: 先找候选人
    int cand = 1;
    for (int i = 2; i <= n; ++i) {
        int res = better(cand, i);
        if (res == 0) cand = i;      // cand 不比 i 强，换掉 cand
        else if (res == -1) return;  // 非法参数
        // 若 res==1，cand 继续保留
    }

    // Step 2: 验证候选人
    for (int i = 1; i <= n; ++i) {
        if (i == cand) continue;

        int res1 = better(cand, i);    // cand 是否比 i 强
        if (res1 == -1) return;
        if (res1 == 0) {               // cand 无法击败 i
            printf("-1\n");
            return;
        }

        int res2 = better(i, cand);    // i 是否比 cand 强
        if (res2 == -1) return;
        if (res2 == 1) {               // 有人能击败 cand
            printf("-1\n");
            return;
        }
    }

    // Step 3: cand 确认是孟子
    printf("%d\n", cand);
}

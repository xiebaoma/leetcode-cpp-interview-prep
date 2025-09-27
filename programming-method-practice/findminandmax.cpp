/**
 * xiebaoma
 * 2025-09-27
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 200005;  
int n;  
int a[maxn];  
void findminandmax(int n); // you should finish this  
int cmp(int i, int j)  
{  
    if (i <= 0 || i > 2 * n || j <= 0 || j > 2 * n) return -2;  
    if (a[i] > a[j]) return 1;  
    if (a[i] == a[j]) return 0;  
    if (a[i] < a[j]) return -1;  
}  
int main()  
{  
    scanf("%d", &n);  
    for (int i = 1; i <= 2 * n; i++)  
        scanf("%d", &a[i]);  
    findminandmax(n);  
    return 0;  
}  

void findminandmax(int n)
{
    vector<int> mins, maxs;
    mins.reserve(n);
    maxs.reserve(n);

    // Step 1: 先两两分组比较
    for (int i = 1; i <= 2 * n; i += 2) {
        int res = cmp(i, i + 1);
        if (res <= 0) {           // a[i] <= a[i+1]
            mins.push_back(i);
            maxs.push_back(i + 1);
        } else {                  // a[i] > a[i+1]
            mins.push_back(i + 1);
            maxs.push_back(i);
        }
    }

    // Step 2: 在mins中找最小
    int minPos = mins[0];
    for (int i = 1; i < n; i++) {
        if (cmp(mins[i], minPos) < 0)  // mins[i] < current_min
            minPos = mins[i];
    }

    // Step 3: 在maxs中找最大
    int maxPos = maxs[0];
    for (int i = 1; i < n; i++) {
        if (cmp(maxs[i], maxPos) > 0)  // maxs[i] > current_max
            maxPos = maxs[i];
    }

    // Step 4: 输出答案
    printf("%d %d\n", minPos, maxPos);
}

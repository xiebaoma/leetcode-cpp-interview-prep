/**
 * xiebaoma
 * 2025-09-27
 */


 #include <cstdio>
using namespace std;

int x, n;  
void guessnumber(int n); // you should finish this  
int guess(int y)  
{  
    if (y < 1 || y > n) return -1;  
    if (x >= y) return 1;  
    if (x < y) return 0;   
}  
int main()  
{  
    scanf("%d%d", &x, &n);  
    guessnumber(n);  
    return 0;  
}  

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void guessnumber(int n) 
{
    int l = 1, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;   // 防止溢出
        int res = guess(mid);
        if (res == 1) {
            // x >= mid → 说明mid可能是答案，但还可能更大
            l = mid + 1;
        } else if (res == 0) {
            // x < mid → 说明mid太大了
            r = mid - 1;
        }
    }
    // 最终r指向x
    printf("%d\n", r);
}

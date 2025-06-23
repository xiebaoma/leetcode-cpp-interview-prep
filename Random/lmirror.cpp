/**
 * xiebaoma
 * 2025-06-23
 * 超时
 */
#include <string>
using namespace std;

class Solution
{
public:
    bool ismirror(string str)
    {
        int left = 0;
        int right = str.length() - 1;
        while (left < right)
        {
            if (str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    string getknum(int k, int n)
    {
        string ret = "";
        while (n > 0)
        {
            int temp = n % k;
            ret = char(temp + '0') + ret;
            n /= k;
        }
        return ret;
    }
    bool ismirrornum(int num)
    {
        int a = num;
        int ans = 0;
        while (a > 0)
        {
            int temp = a % 10;
            ans = ans * 10 + temp;
            a /= 10;
        }
        return ans == num;
    }
    long long kMirror(int k, int n)
    {
        long long ret = 0;
        int count = 0;
        int num = 1;
        while (count < n)
        {
            string str = getknum(k, num);
            if (ismirror(str) && ismirrornum(num))
            {
                count++;
                ret += num;
            }
            num++;
        }
        return ret;
    }
};
/**
 * xiebaoma
 * 2025-06-20
 * 没太懂
 */

#include <iostream>
#include <string>
using namespace std;

string baseNeg2(int n)
{
    if (n == 0)
        return "0";

    string result;

    while (n != 0)
    {
        int remainder = n % -2;

        // 处理负余数（保持digit为0或1）
        if (remainder < 0)
        {
            remainder += 2;
            n = (n / -2) + 1;
        }
        else
        {
            n = n / -2;
        }

        result = char(remainder + '0') + result;
    }

    return result;
}

std::string toNegativeBase(int n, int base)
{
    if (base >= -1 || base >= 0)
    {
        throw std::invalid_argument("Base must be <= -2");
    }

    if (n == 0)
        return "0";

    std::string result;
    int k = std::abs(base);

    while (n != 0)
    {
        int digit = n % base;
        if (digit < 0)
        {
            digit += k;
            n = (n / base) + 1;
        }
        else
        {
            n = n / base;
        }

        result = char('0' + digit) + result;
    }

    return result;
}

int main()
{
    int n;
    cout << "输入一个整数 n: ";
    cin >> n;
    cout << "它的负二进制表示是: " << baseNeg2(n) << endl;
    return 0;
}

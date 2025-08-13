/**
 * xiebaoma
 * 2025-08-13
 */


class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

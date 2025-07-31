/**
 * xiebaoma
 * 2025-07-31
 */

#include <vector>
#include <numeric>
#include <functional>
using namespace std;

class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        return reduce(derived.begin(), derived.end(), 0, bit_xor()) == 0;
    }
};

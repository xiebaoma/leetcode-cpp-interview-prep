/**
 * 数组 [1,2,3,0,-5,-4,-4,10]
 * 连续和最大
 */

#include <vector>
#include <iostream>
using namespace std;

vector<int> maxsubarray(vector<int> &nums)
{
    int left = 0;
    int right = 1;
    vector<int> ans;
    int n = nums.size();
    if (n == 0)
    {
        return ans;
    }
    int ret = nums[left];
    int maxsum = ret;
    int leftmaxid = 0;
    int rightmaxid = 0;
    while (right < n)
    {
        if (nums[right] - 1 == nums[right - 1])
        {
            ret += nums[right];
            if (ret > maxsum)
            {
                leftmaxid = left;
                rightmaxid = right;
                maxsum = ret;
            }
            right++;
        }
        else
        {
            left = right;
            ret = nums[left];
            if (ret > maxsum)
            {
                leftmaxid = left;
                rightmaxid = right;
                maxsum = ret;
            }
            right++;
        }
    }
    for (int i = leftmaxid; i <= rightmaxid; i++)
    {
        ans.push_back(nums[i]);
    }
    return ans;
}

int main()
{
    vector<int> vec = {-4, -6, -8, 0, 0, 0, 1, 2, 3, 4, 5, 7};
    vector<int> ans = maxsubarray(vec);
    int sum = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
        sum += ans[i];
    }
    cout << endl;
    cout << sum;

    return 0;
}
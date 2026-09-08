#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();

    // 前缀和，使用 long long 防止溢出
    vector<long long> sums(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        sums[i] = sums[i - 1] + nums[i - 1];
    }

    deque<int> q;  // 保存前缀和的下标
    int res = n + 1;

    for (int i = 0; i <= n; i++) {

        // 1. 如果当前前缀和 - 队头前缀和 >= k
        // 说明找到了一个满足条件的子数组
        while (!q.empty() && sums[i] - sums[q.front()] >= k) {
            res = min(res, i - q.front());
            q.pop_front();
        }

        // 2. 保证队列中的前缀和单调递增
        while (!q.empty() && sums[i] <= sums[q.back()]) {
            q.pop_back();
        }

        q.push_back(i);
    }

    return res == n + 1 ? -1 : res;
}

int main() {
    vector<int> nums = {2, -1, 2};
    int k = 3;

    cout << shortestSubarray(nums, k) << endl;

    return 0;
}
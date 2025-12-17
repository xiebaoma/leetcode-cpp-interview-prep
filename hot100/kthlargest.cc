/**
 * xiebaoma
 * 2025-12-16
 */

#include <vector>
using namespace std;

class Solution {
public:

    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l-1;
        for (int j = l; j < r; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i+1; // pivot 的最终位置
    }

    int quickSelect(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[l];

        int p = partition(nums, l, r);

        if (p == k) return nums[p];
        else if (p < k) return quickSelect(nums, p + 1, r, k);
        else return quickSelect(nums, l, p - 1, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }

};
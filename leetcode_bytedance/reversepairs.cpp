/**
 * xiebaoma
 * 2025-08-23
 */

#include <vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& record) {
        if (record.empty()) return 0;
        return mergeSort(record, 0, record.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int cnt = 0;
        cnt += mergeSort(nums, left, mid);
        cnt += mergeSort(nums, mid + 1, right);
        cnt += merge(nums, left, mid, right);
        return cnt;
    }

    int merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> tmp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        int cnt = 0;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                // nums[i] > nums[j] → (mid - i + 1) 个逆序对
                cnt += (mid - i + 1);
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid) tmp[k++] = nums[i++];
        while (j <= right) tmp[k++] = nums[j++];
        for (int t = 0; t < tmp.size(); ++t) {
            nums[left + t] = tmp[t];
        }
        return cnt;
    }
};

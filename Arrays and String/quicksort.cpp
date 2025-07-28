/**
 * xiebaoma
 * 2025-07-28
 */

#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

// 快速排序的核心函数
void quickSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return; // 递归终止条件

    int pivot = arr[right]; // 选择最后一个元素作为基准
    int i = left - 1;       // i 用来定位小于 pivot 的区间末尾

    for (int j = left; j < right; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]); // 把 pivot 放到正确位置
    int pivotIndex = i + 1;

    // 递归处理左右区间
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

int main()
{
    vector<int> nums = {5, 2, 9, 1, 3, 7, 6, 8, 4};
    quickSort(nums, 0, nums.size() - 1);

    cout << "排序结果: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

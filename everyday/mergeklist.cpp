#include <iostream>
#include <vector>

using namespace std;

// 合并两个有序数组
vector<int> mergeTwoArrays(const vector<int> &a, const vector<int> &b) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            merged.push_back(a[i++]);
        } else {
            merged.push_back(b[j++]);
        }
    }
    while (i < a.size()) merged.push_back(a[i++]);
    while (j < b.size()) merged.push_back(b[j++]);
    return merged;
}

// 分治合并数组
vector<int> mergeKArrays(const vector<vector<int>> &arrays, int left, int right) {
    if (left == right) {
        return arrays[left];
    }
    int mid = left + (right - left) / 2;
    vector<int> leftMerged = mergeKArrays(arrays, left, mid);
    vector<int> rightMerged = mergeKArrays(arrays, mid + 1, right);
    return mergeTwoArrays(leftMerged, rightMerged);
}

// 对外接口
vector<int> mergeKSortedArrays(const vector<vector<int>> &arrays) {
    if (arrays.empty()) return {};
    return mergeKArrays(arrays, 0, arrays.size() - 1);
}

int main() {
    vector<vector<int>> arrays = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };

    vector<int> result = mergeKSortedArrays(arrays);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    int range = maxVal - minVal + 1;

    vector<int> count(range, 0);

    // 统计次数（加偏移）
    for (int x : arr) count[x - minVal]++;

    // 回写排序结果
    int idx = 0;
    for (int i = 0; i < range; ++i) {
        while (count[i]--) {
            arr[idx++] = i + minVal;
        }
    }
}

int main() {
    vector<int> arr = {-2, 3, 0, -1, 3, 2};
    countingSort(arr);

    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> R;
    string line;

    // 首先读入整矩阵
    // 方法：逐行读取，直到输入结束
    while (true) {
        vector<int> row;
        int x;

        // 尝试读入一行第一个元素
        if (!(cin >> x)) break;   // 输入结束
        row.push_back(x);

        // 读取该行剩余的所有数字（根据第一行数字个数确定列数会更安全）
        // 但这里题目保证是方阵，所以读到换行就行
        while (cin.peek() == ' ') cin.get(); // 跳过空格

        // 继续读取当前行，直到遇到换行或文件结束
        while (cin.peek() != '\n' && cin >> x) {
            row.push_back(x);
            while (cin.peek() == ' ') cin.get();
        }

        R.push_back(row);

        if (cin.peek() == '\n') cin.get();  // 消费换行符
    }

    int n = R.size();

    // 保险起见：不是 n×n 就直接退出
    for (auto &row : R) {
        if ((int)row.size() != n) {
            cerr << "输入矩阵不是方阵！\n";
            return 1;
        }
    }

    // Floyd-Warshall 求传递闭包
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (R[i][k] && R[k][j])
                    R[i][j] = 1;

    // 输出传递闭包矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << R[i][j];
            if (j + 1 < n) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}

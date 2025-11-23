#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 构造坏字符位移表
vector<int> buildShiftTable(const string& pattern) {
    int m = pattern.size();
    const int ALPHABET_SIZE = 256; // 假设ASCII字符集
    vector<int> shift(ALPHABET_SIZE, m); // 默认移动 m 个单位

    for (int i = 0; i < m - 1; ++i) {
        shift[(unsigned char)pattern[i]] = m - 1 - i;
    }
    return shift;
}

// Horspool 字符串匹配
int horspoolSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    if (m > n) return -1;

    vector<int> shift = buildShiftTable(pattern);

    int i = m - 1; // 模式串末尾对应文本位置
    while (i < n) {
        int k = 0; // 已匹配的字符数
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            ++k;
        }

        if (k == m) {
            return i - m + 1; // 找到匹配位置
        } else {
            i += shift[(unsigned char)text[i]]; // 右移模式串
        }
    }
    return -1; // 未找到
}

int main() {
    string text = "HERE IS A SIMPLE EXAMPLE";
    string pattern = "EXAMPLE";

    int pos = horspoolSearch(text, pattern);
    if (pos != -1)
        cout << "匹配成功，位置索引：" << pos << endl;
    else
        cout << "未找到匹配" << endl;

    return 0;
}

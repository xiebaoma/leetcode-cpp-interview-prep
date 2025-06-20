#include <iostream>
#include <string>

// 匹配函数：支持 '*' 和 '?' 通配符
bool isMatch(const std::string& str, const std::string& pattern) {
    int sLen = str.size(), pLen = pattern.size();
    int s = 0, p = 0, starIdx = -1, match = 0;

    while (s < sLen) {
        if (p < pLen && (pattern[p] == '?' || pattern[p] == str[s])) {
            ++s;
            ++p;
        } else if (p < pLen && pattern[p] == '*') {
            starIdx = p;
            match = s;
            ++p;
        } else if (starIdx != -1) {
            p = starIdx + 1;
            ++match;
            s = match;
        } else {
            return false;
        }
    }

    // 检查 pattern 剩余是否全是 '*'
    while (p < pLen && pattern[p] == '*') {
        ++p;
    }

    return p == pLen;
}

// 测试程序
int main() {
    std::string str, pattern;

    std::cout << "输入要匹配的字符串: ";
    std::getline(std::cin, str);
    std::cout << "输入模式(支持 * 和 ?): ";
    std::getline(std::cin, pattern);

    if (isMatch(str, pattern)) {
        std::cout << "匹配成功！" << std::endl;
    } else {
        std::cout << "匹配失败！" << std::endl;
    }

    return 0;
}

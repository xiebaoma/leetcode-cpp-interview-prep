#include <iostream>
using namespace std;


int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a;
    cin >> a;

    // Z_18 中元素取模
    a = ((a % 18) + 18) % 18;

    // 0 元的阶为 1
    if (a == 0) {
        cout << 1 << endl;
        return 0;
    }

    int g = gcd(18, a);
    cout << 18 / g << endl;

    return 0;
}

/**
 * xiebaoma
 * 2025-10-12
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 10;
int board[MAXN + 1][MAXN + 1];
int tile_id = 0;

void tileBoard(int tr, int tc, int dr, int dc, int size) {
    if (size == 1) return;
    int t = ++tile_id;
    int s = size / 2;
    int sr = tr + s, sc = tc + s;

    // 左上
    if (dr < sr && dc < sc)
        tileBoard(tr, tc, dr, dc, s);
    else {
        board[sr - 1][sc - 1] = t;
        tileBoard(tr, tc, sr - 1, sc - 1, s);
    }

    // 右上
    if (dr < sr && dc >= sc)
        tileBoard(tr, sc, dr, dc, s);
    else {
        board[sr - 1][sc] = t;
        tileBoard(tr, sc, sr - 1, sc, s);
    }

    // 左下
    if (dr >= sr && dc < sc)
        tileBoard(sr, tc, dr, dc, s);
    else {
        board[sr][sc - 1] = t;
        tileBoard(sr, tc, sr, sc - 1, s);
    }

    // 右下
    if (dr >= sr && dc >= sc)
        tileBoard(sr, sc, dr, dc, s);
    else {
        board[sr][sc] = t;
        tileBoard(sr, sc, sr, sc, s);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;
    int size = 1 << n;

    board[x - 1][y - 1] = 0;
    tileBoard(0, 0, x - 1, y - 1, size);

    // ====== 重新编号阶段 ======
    // 找出所有 tile_id 并记录其最上最左出现位置
    vector<pair<pair<int, int>, int>> order;
    unordered_set<int> seen;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int id = board[i][j];
            if (id == 0 || seen.count(id)) continue;
            seen.insert(id);
            order.push_back({{i, j}, id});
        }
    }

    // 按行优先排序（行小优先，再列小）
    sort(order.begin(), order.end());

    // 建立重映射表
    unordered_map<int, int> newId;
    for (int i = 0; i < (int)order.size(); ++i) {
        newId[order[i].second] = i + 1;
    }

    // 替换旧编号为新编号
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (board[i][j] != 0)
                board[i][j] = newId[board[i][j]];

    // ====== 输出 ======
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << board[i][j];
            cout << " ";
        }
        cout << "\n";
    }
}

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<vector<int>> adj;       // 原图邻接矩阵
vector<vector<int>> adj_rev;   // 反向图邻接矩阵
bool visited[105];

/* DFS */
void dfs(int u, const vector<vector<int>>& graph) {
    visited[u] = true;
    for (int v = 0; v < N; ++v) {
        if (graph[u][v] > 0 && !visited[v]) {
            dfs(v, graph);
        }
    }
}

/* 判断强连通 */
bool isStronglyConnected() {
    memset(visited, false, sizeof(visited));
    dfs(0, adj);
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) return false;
    }

    memset(visited, false, sizeof(visited));
    dfs(0, adj_rev);
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) return false;
    }

    return true;
}

/* 判断 u 是否能到 v */
bool canReach(int u, int v) {
    memset(visited, false, sizeof(visited));
    dfs(u, adj);
    return visited[v];
}

/* 判断单向连通 */
bool isUnilaterallyConnected() {
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (!canReach(i, j) && !canReach(j, i)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> N;

    adj.assign(N, vector<int>(N));
    adj_rev.assign(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> adj[i][j];
            adj_rev[j][i] = adj[i][j];  // 构造反向图
        }
    }

    if (isStronglyConnected()) {
        cout << "A" << endl;
    } else if (isUnilaterallyConnected()) {
        cout << "B" << endl;
    } else {
        cout << "C" << endl;
    }

    return 0;
}

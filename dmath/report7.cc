#include <iostream>  
#include <vector>  
#include <queue>  
  
using namespace std;  
  
int main() {  
    int n;  
    cin >> n;  
  
    vector<vector<int>> adj(n, vector<int>(n));  
    for (int i = 0; i < n; ++i) {  
        for (int j = 0; j < n; ++j) {  
            cin >> adj[i][j];  
        }  
    }  
  
    // color[i] = -1 表示未染色，0/1 表示两种颜色  
    vector<int> color(n, -1);  
  
    // 检查是否存在自环  
    for (int i = 0; i < n; ++i) {  
        if (adj[i][i] > 0) {  
            cout << "no" <<endl;  
            return 0;  
        }  
    }  
  
    // BFS 检查二部图  
    for (int i = 0; i < n; ++i) {  
        if (color[i] != -1) continue;  
  
        queue<int> q;  
        color[i] = 0;  
        q.push(i);  
  
        while (!q.empty()) {  
            int u = q.front();  
            q.pop();  
  
            for (int v = 0; v < n; ++v) {  
                if (adj[u][v] > 0) {  // 有边  
                    if (color[v] == -1) {  
                        color[v] = 1 - color[u];  
                        q.push(v);  
                    } else if (color[v] == color[u]) {  
                        cout << "no" << endl;  
                        return 0;  
                    }  
                }  
            }  
        }  
    }  
  
    cout << "yes" << endl;  
    return 0;  
} 
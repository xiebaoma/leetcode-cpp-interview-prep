#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);

    // 构建图 + 计算入度
    for (auto& p : prerequisites) {
        int a = p[0], b = p[1];
        graph[b].push_back(a);  // b -> a
        indegree[a]++;
    }

    // 将入度为 0 的课程放入队列
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> order;

    // BFS 拓扑排序
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        // 当前课程的后续课程入度减 1
        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    // 如果拓扑排序没有包含所有课程，则说明存在环
    if ((int)order.size() != numCourses) return {};

    return order;
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0}, {2, 0}, {3, 1}, {3, 2}
    };

    vector<int> order = findOrder(numCourses, prerequisites);

    if (order.empty()) {
        cout << "No valid course order (cycle detected)" << endl;
    } else {
        cout << "A valid course order: ";
        for (int c : order) cout << c << " ";
        cout << endl;
    }

    return 0;
}

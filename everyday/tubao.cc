#include <vector>
#include <iostream>
using namespace std;

struct Point {
    long long x, y;
    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

// 叉积，用来判断三点的转向
long long cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) -
           (A.y - O.y) * (B.x - O.x);
}

// 返回按逆时针排序的凸包顶点
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n <= 1) return points;

    sort(points.begin(), points.end());

    vector<Point> hull;

    // 构建下凸包
    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 &&
               cross(hull[hull.size()-2], hull[hull.size()-1], points[i]) <= 0) {
            hull.pop_back();
               }
        hull.push_back(points[i]);
    }

    // 构建上凸包
    int lower_size = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while ((int)hull.size() > lower_size &&
               cross(hull[hull.size()-2], hull[hull.size()-1], points[i]) <= 0) {
            hull.pop_back();
               }
        hull.push_back(points[i]);
    }

    hull.pop_back(); // 最后一个点和第一个点重复

    return hull;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> hull = convexHull(points);

    cout << "Convex Hull (counter-clockwise):\n";
    for (auto& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
    return 0;
}

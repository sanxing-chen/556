#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-5, pi = acos(-1.0);
inline int dcmp(double x) {
    return (x > eps) - (x < -eps);
}

struct Point {
    double x, y;
    Point(double x = 0, double y = 0)
        : x(x)
        , y(y) {}
    void input() {
        scanf("%lf%lf", &x, &y);
    }
    bool operator<(const Point &R) const {
        if (dcmp(x - R.x) == 0) return dcmp(y - R.y) < 0;
        return dcmp(x - R.x) < 0;
    }
    bool operator==(const Point &R) const {
        return dcmp(x - R.x) == 0 && dcmp(y - R.y) == 0;
    }
    Point operator+(const Point &R) const {
        return Point(x + R.x, y + R.y);
    }
    Point operator-(const Point &R) const {
        return Point(x - R.x, y - R.y);
    }
    Point operator*(const double &R) const {
        return Point(x * R, y * R);
    }
    Point operator/(const double &R) const {
        return Point(x / R, y / R);
    }
    double operator^(const Point &R) const {
        return x * R.y - y * R.x;
    }
    double operator%(const Point &R) const {
        return x * R.x + y * R.y;
    }
    double len() {
        return sqrt(*this % *this);
    }
};
double DistancePointToLine(Point P, Point A, Point B) {
    Point v = B - A;
    return (v ^ (P - A)) / v.len();
}
struct Line {
    Point st;
    Point ed;
    double k;
    void getk() {
        k = (st.y - ed.y) / (st.x - ed.x);
    }
};
int R, l, w;
int t;
double a1, a2;
Point p1, p2, p3, p4;
double DistancePointToSegment(Point P, Point A, Point B) {
    if (A == B) return (P - A).len();
    Point v1 = B - A, v2 = P - A, v3 = P - B;
    if (dcmp(v1 % v2) < 0) return v2.len();
    if (dcmp(v1 % v3) > 0) return v3.len();
    return fabs(v1 ^ v2) / v1.len();
}
int main() {
    // ios::sync_with_stdio(false);
    scanf("%d%d%d", &R, &l, &w);
    // cin >> R >> l >> w;
    scanf("%d", &t);
    // cin >> t;
    while (t--) {
        scanf("%lf%lf", &a1, &a2);
        // cin >> a1 >> a2;
        // cin >> a1 >> a2;
        p1.x = l, p1.y = w;
        p2.x = l, p2.y = 0;
        p3.x = 0, p3.y = w;
        p4.x = 0, p4.y = 0;
        Point p5, p6, p7, p8;
        p5.x = l - l * cos(a1);
        p5.y = w + l * sin(a1);
        p6.x = l - l * cos(a2);
        p6.y = l * sin(a2);
        p8.x = 2 * l;
        p8.y = w;
        double rr = 2 * R;
        double dis1 = DistancePointToSegment(p3, p1, p5);
        double dis3 = DistancePointToSegment(p6, p1, p5);
        double dis4 = DistancePointToSegment(p6, p1, p8);
        double dis5 = DistancePointToSegment(p1, p2, p6);

        rr = min(rr, dis1);
        rr = min(rr, dis3);
        rr = min(rr, dis4);
        rr = min(rr, dis5);
        // cout << a1 << endl;
        // rr = min(judge1(a1, rr), rr);
        // printf("%.9f\n", rr);
        // rr = min(judge2(a1, a2, rr), rr);
        rr = rr / 2;
        printf("%.9f\n", rr);
        // cout << setprecision(9) << rr << endl;
    }
    return 0;
}
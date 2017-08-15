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
int t;
int n;
const double eps = 1e-10, pi = acos(-1.0);
inline int dcmp(double x) {
    return (x > eps) - (x < -eps);
}

struct Point {
    double x, y;
    int v;
    int flag;
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
double cross(const Point &p1, const Point &p2, const Point &q1, const Point &q2) {
    return (q2.y - q1.y) * (p2.x - p1.x) - (q2.x - q1.x) * (p2.y - p1.y);
}

bool cmp(const Point &a, const Point &b) {
    Point origin;
    origin.x = origin.y = 0;
    return cross(origin, b, origin, a) < 0;
}

Point p[60005];
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n;
        ll suma = 0;
        ll sumb = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int x, y, v;
            cin >> x >> y >> v;
            if (y == 0) {
                if (x < 0) {
                    p[i].flag = 0;
                    p[i].x = -x;
                    p[i].y = y;
                    p[i].v = v;
                    sumb += v;
                } else {
                    p[i].x = x, p[i].y = y;
                    p[i].v = v;
                    p[i].flag = 1;
                    suma += v;
                }
            } else if (y > 0) {
                p[i].x = x, p[i].y = y;
                p[i].v = v;
                p[i].flag = 1;
                suma += v;
            } else {
                p[i].x = -x, p[i].y = -y;
                p[i].v = v;
                p[i].flag = 0;
                sumb += v;
            }
        }
        sort(p, p + n, cmp);
        for (int i = 0; i < n; i++) {
            if (p[i].flag == 1) {
                ans = max(ans, max((suma - p[i].v) * (sumb + p[i].v), suma * sumb));
                suma -= p[i].v;
                sumb += p[i].v;
            } else {
                ans = max(ans, max((suma + p[i].v) * (sumb - p[i].v), suma * sumb));
                suma += p[i].v;
                sumb -= p[i].v;
            }
        }
        cout << ans << endl;
        // for (int i = 0; i < n; i++) {
        //     cout << p[i].x << " " << p[i].y << endl;
        // }
    }
    return 0;
}
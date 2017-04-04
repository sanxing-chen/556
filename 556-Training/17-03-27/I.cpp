#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
#define PI acos(-1.0)
#define eps 1e-3
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
double fuck(double a, double b) {
    return cos(a * PI / (b + 1)) * cos(a * PI / (b + 1));
}
int main() {
    int n, m;
    while (cin >> n >> m && n + m) {
        if ((n & 1) && (m & 1)) {
            puts("0");
            continue;
        }
        double ans = 1;
        for (int i = 1; i <= n / 2; ++i) {
            for (int j = 1; j <= m / 2; ++j) {
                ans *= 4 * (fuck(i, n) + fuck(j, m));
            }
        }
        cout << (ll)(ans + eps) << endl;
    }
}
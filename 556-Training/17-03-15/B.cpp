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
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int _x[] = {-1, 0, 0, 1}, _y[] = {0, 1, -1, 0};
int n, m;
bool cango(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m) return false;
    return true;
}
int dfs(int x, int y) {
    int ans = 0, x1, y1;
    if (cango(x + 1, y)) {
        x1 = n - x;
        y1 = min(y, m - y + 1);
        ans = max(ans, min(x1, y1));
    }
    if (cango(x - 1, y)) {
        x1 = x - 1;
        y1 = min(y, m - y + 1);
        ans = max(ans, min(x1, y1));
    }
    if (cango(x, y + 1)) {
        y1 = m - y;
        x1 = min(x, n - x + 1);
        ans = max(ans, min(x1, y1));
    }
    if (cango(x, y - 1)) {
        y1 = y - 1;
        x1 = min(x, n - x + 1);
        ans = max(ans, min(x1, y1));
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    int x, y, ans, x1, y1;
    while (cin >> n >> m >> x >> y) {
        int rawx = x, rawy = y;
        ans = dfs(x, y);
        x1 = (n + 1) / 2;
        y1 = (m + 1) / 2;
        if (x1 == rawx && y1 == rawy) {
            if (x1 == y1)
                ans = max(ans, x1 - 1);
            else
                ans = max(ans, min(x1, y1));
        } else
            ans = max(ans, min(x1, y1));
        cout << ans << endl;
    }
    return 0;
}
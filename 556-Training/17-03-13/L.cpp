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
inline int readT() {
    char c;
    int ret = 0, flag = 0;
    while (c = getchar(), (c < '0' || c > '9') && c != '-')
        ;
    if (c == '-')
        flag = 1;
    else
        ret = c ^ 48;
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c ^ 48);
    return flag ? -ret : ret;
}
struct Node {
    int x, y, r;
    bool operator<(const Node n) const {
        return r < n.r;
    }
} a[40020];
bool involve(int i, int j) {
    int x1 = a[i].x, x2 = a[j].x;
    int y1 = a[i].y, y2 = a[j].y;
    int r1 = a[i].r, r2 = a[j].r;
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) < (r1 - r2) * (r1 - r2);
}
int dp[20020];
vector<int> son[20020];
void dfs(int p) {
    if (dp[p]) return;
    int ans = 0;
    for (auto i : son[p]) {
        dfs(i);
        ans ^= dp[i] + 1;
    }
    dp[p] = ans;
}
int root[20020];
int main() {
    int t, x, y, r, n;
    t = readT();
    while (t--) {
        n = readT();
        for (int i = 1; i <= n; i++) {
            a[i].x = readT();
            a[i].y = readT();
            a[i].r = readT();
        }
        sort(a + 1, a + n + 1);
        // for (int i = 1; i <= n; i++) a[i].output();
        // cout << endl;
        for (int i = 1; i <= n; i++) {
            son[i].clear();
            root[i] = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (involve(j, i)) {
                    root[i] = j, son[j].push_back(i);
                    break;
                }
            }
        }
        int ans = 0;
        mems(dp, 0);
        for (int i = 1; i <= n; i++) {
            if (root[i] == i) {
                dfs(i);
                ans ^= dp[i] + 1;
            }
        }
        cout << (ans ? "Alice" : "Bob") << endl;
    }
    return 0;
}
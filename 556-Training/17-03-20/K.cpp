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
int dp[110];
int root[110];
vector<int> v[110];
int dfs(int p) {
    int ans = 0;
    if (dp[p]) return dp[p];
    for (auto i : v[p]) {
        ans += dfs(i) + 1;
    }
    return dp[p] = ans;
}
int main() {
    int n, k, x, y;
    ios::sync_with_stdio(false);
    while (cin >> n >> k) {
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            root[i] = i;
        }
        mems(dp, 0);
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            v[x].push_back(y);
            root[y] = x;
        }
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            if (root[i] == i) dfs(i);
        }
        for (int i = 1; i <= n; i++) {
            // cout << dp[i] << endl;
            if (dp[i] == k) ret++;
        }
        cout << ret << endl;
    }
    return 0;
}
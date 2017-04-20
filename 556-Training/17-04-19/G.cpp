#include <algorithm>
#include <cassert>
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

#define all(a) (a).begin(), (a).end()
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int k, cnt;
map<vector<int>, ll> dp;
int digit[19];
ll dfs(int pos, vector<int> v, bool isFirst, bool fuck) {
    if (pos == -1) {
        return 1;
    }
    if (dp.find(v) != dp.end()) return dp[v];
    ll ans = 0;
    bool vis[10];
    mems(vis, false);
    for (int i = 3; i < v.size(); i++) vis[v[i]] = true;
    int to = isFirst ? digit[pos] : 9;
    vector<int> _v;
    for (int d = 0; d <= to; d++) {
        _v.clear();
        _v = v;
        if (!fuck && !d) {
            _v[0] = pos - 1, _v[1] = isFirst && d == to, _v[2] = 0;
            ans += dfs(_v[0], _v, _v[1], _v[2]);
        } else if (!vis[d]) {
            _v[0] = pos - 1, _v[1] = isFirst && d == to, _v[2] = d || fuck;
            if (_v.size() == k + 2) {
                assert(_v.size() > 3);
                _v.erase(_v.begin() + 3);
                _v.push_back(d);
                ans += dfs(_v[0], _v, _v[1], _v[2]);
            } else {
                _v.push_back(d);
                ans += dfs(_v[0], _v, _v[1], _v[2]);
            }
        }
    }
    return isFirst ? ans : dp[v] = ans;
}
ll solve(ll x) {
    cnt = 0;
    while (x) {
        digit[cnt++] = x % 10;
        x /= 10;
    }
    vector<int> v;
    v.clear();
    v.push_back(cnt - 1);
    v.push_back(1);
    v.push_back(0);
    return dfs(cnt - 1, v, true, false);
}
int main() {
    ios::sync_with_stdio(false);
#ifdef FF
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ll l, r;
    while (cin >> l >> r >> k) {
        dp.clear();
        cout << solve(r) - solve(l - 1) << endl;
    }
}
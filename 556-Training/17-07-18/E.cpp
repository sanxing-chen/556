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
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 108;
int n, m, ss;
vector<int> edges[maxn];
bool mp[maxn][maxn];
int now;
int vi[maxn];
int dfs(int s) {
    int ret = 0;
    REP(i, 1, s - 1) {
        if (!mp[now][vi[i]]) return 0;
    }
    if (s == ss) {
        return 1;
    }
    vi[s] = now;
    for (auto &to : edges[vi[s]]) {
        now = to;
        ret += dfs(s + 1);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    int t, u, v;
    cin >> t;
    while (t--) {
        cin >> n >> m >> ss;
        REP(i, 0, n + 1) edges[i].clear();
        mems(mp, false);
        REP(i, 0, m) {
            cin >> u >> v;
            if (v < u) swap(u, v);
            edges[u].push_back(v);
            mp[v][u] = true;
        }
        ll ans = 0;
        REP(i, 1, n + 1) {
            now = i;
            ans += dfs(1);
        }
        cout << ans << endl;
    }
}
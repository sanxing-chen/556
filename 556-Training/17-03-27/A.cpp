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
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
struct edge {
    int u, v, cost;
};

bool cmp(const edge &e1, const edge &e2) {
    return e1.cost < e2.cost;
}

edge es[1000005];
int V, E, fa[100005];
vector<pii> v[100005];
int find(int x) {
    if (fa[x] == x)
        return x;
    else {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}
void unite(int x, int y) {
    fa[find(x)] = fa[find(y)];
    return;
}
bool same(int x, int y) {
    return (find(x) == find(y));
}
void init_union_find(int x) {
    for (int i = 1; i <= x; i++) {
        fa[i] = i;
        v[i].clear();
    }
}
ll kruskal() {
    sort(es, es + E, cmp);
    init_union_find(V);
    ll res = 0;
    for (int i = 0; i < E; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
            v[e.u].push_back(pii(e.v, e.cost));
            v[e.v].push_back(pii(e.u, e.cost));
        }
    }
    return res;
}
int dp[100005], dps[100005], vis[100005];
int fuck(int u) {
    int ans = 1;
    vis[u] = true;
    for (auto i : v[u]) {
        if (vis[i.first]) continue;
        ans += fuck(i.first);
        dps[i.first] = i.second;
    }
    return dp[u] = ans;
}
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
int main() {
    int t;
    t = readT();
    while (t--) {
        V = readT();
        E = readT();
        for (int i = 0; i < E; i++) {
            es[i].u = readT();
            es[i].v = readT();
            es[i].cost = readT();
        }
        if (V == 1) {
            cout << 0 << " "
                 << "0.00" << endl;
            continue;
        }
        cout << kruskal() << " ";
        mems(vis, false);
        fuck(1);
        double ans = 0;
        for (int i = 2; i <= V; i++) {
            ans += dps[i] * 1.0 * dp[i] * (V - dp[i]);
        }
        cout << fixed << setprecision(2) << ans * 2.0 / ((ll) V * V - V) << endl;
    }
    return 0;
}
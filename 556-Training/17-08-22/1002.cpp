#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 200010;
pii a[N];
// BIT
ll c[N];
int nn;
ll get(int x) {
    ll ret = 0;
    for (; x; x -= x & -x) ret += c[x];
    return ret;
}
void update(int x, int cc) {
    for (; x <= nn; x += x & -x) c[x] += cc;
}

// 建树
const int M = N;
int pre[N], ecnt;
struct edge {
    int x;
    int next;
} e[M];
void initGragh() {
    mems(pre, -1);
    ecnt = 0;
}
void addedge(int u, int v) {
    e[ecnt].x = v, e[ecnt].next = pre[u];
    pre[u] = ecnt++;
    e[ecnt].x = u, e[ecnt].next = pre[v];
    pre[v] = ecnt++;
}

// 树链剖分
int size[N], heavy[N], tid[N], Top[N], ncnt, dep[N], Fa[N];
void FindHE(int x, int fa, int Dep) {
    heavy[x] = 0, size[x] = 1, dep[x] = Dep, Fa[x] = fa;
    for (int i = pre[x]; ~i; i = e[i].next)
        if (e[i].x != fa) {
            int y = e[i].x;
            FindHE(y, x, Dep + 1);
            size[x] += size[y];
            if (!heavy[x] || size[y] > size[heavy[x]]) heavy[x] = y;
        }
}
void ConnectHE(int x, int anc) {
    tid[x] = ++ncnt, Top[x] = anc;
    if (heavy[x]) ConnectHE(heavy[x], anc);
    for (int i = pre[x]; ~i; i = e[i].next)
        if (e[i].x != Fa[x] && e[i].x != heavy[x]) ConnectHE(e[i].x, e[i].x);
}
ll query(int x, int y) {
    ll ans = 0;
    while (Top[x] != Top[y]) {
        if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
        ans += get(tid[x]) - get(tid[Top[x]] - 1);
        x = Fa[Top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    ans += get(tid[y]) - get(tid[x] - 1);
    return ans; //如果权在边上就不考虑左边的点了
}

struct node {
    int l, r, k, i;
    bool operator<(node b) {
        return this->k < b.k;
    }
} q[N];
ll ans[N];
int main() {
    ios::sync_with_stdio(false);
    int n, m, t, l, r, k, u, v;
    while (cin >> n >> m) {
        nn = n;
        REP(i, 0, n) {
            cin >> a[i].first;
            a[i].second = i + 1;
        }
        initGragh();
        REP(i, 0, n - 1) {
            cin >> u >> v;
            addedge(u, v);
        }
        ncnt = 0;
        FindHE(1, 0, 0);
        ConnectHE(1, 1);
        REP(i, 0, m) {
            cin >> q[i].l >> q[i].r >> q[i].k;
            cin >> q[i + m].k;
            q[i].k--;
            q[i].i = i;
            q[i + m].l = q[i].l;
            q[i + m].r = q[i].r;
            q[i + m].i = q[i].i;
        }
        sort(a, a + n);
        sort(q, q + 2 * m);
        mems(c, 0);
        mems(ans, -1);
        int cnt = 0;
        REP(i, 0, 2 * m) {
            while (cnt < n && a[cnt].first <= q[i].k) {
                update(tid[a[cnt].second], a[cnt].first);
                cnt++;
            }
            if (ans[q[i].i] == -1)
                ans[q[i].i] = query(q[i].l, q[i].r);
            else
                ans[q[i].i] = query(q[i].l, q[i].r) - ans[q[i].i];
        }
        REP(i, 0, m) cout << ans[i] << " \n"[i == m - 1];
    }
    return 0;
}
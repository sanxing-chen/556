const int N = 50000;
int ans[300];
vector<pii> ed[N];
vector<pii> q[N];

struct Tarjan {
    bool vis[N];
    int fa[N], dis[N], anc[N];
    void init(int n) {
        mems(vis, false);
        mems(dis, 0);
        REP(i, 0, n + 1) fa[i] = i;
    }
    int find(int x) {
        return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
    }
    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) fa[y] = x;
    }
    void dfs(int x, int w) {
        vis[x] = true;
        dis[x] = w;
        REP(i, 0, ed[x].size()) {
            int v = ed[x][i].first;
            if (vis[v]) continue;
            dfs(v, w + ed[x][i].second);
            uni(x, v);
            anc[find(x)] = x;
        }
        REP(i, 0, q[x].size()) {
            int u = q[x][i].first;
            if (vis[u]) {
                int t = anc[find(u)];
                // 在此记录离线
                ans[q[x][i].second] = dis[x] + dis[u] - dis[t] * 2;
            }
        }
    }
} solver;
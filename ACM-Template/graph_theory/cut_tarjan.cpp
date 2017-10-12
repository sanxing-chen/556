const int N = 1000;
int dfsno[N], lowlink[N], dfs_clock;
bool iscut[N];
vector<int> g[N];
int dfs(int u, int fa) {
    lowlink[u] = dfsno[u] = ++dfs_clock;
    int child = 0;
    REP(i, 0, g[u].size()) {
        int v = g[u][i];
        if (!dfsno[v]) {
            child++;
            int lowv = dfs(v, u);
            lowlink[u] = min(lowlink[u], lowv);
            if (lowv >= dfsno[u]) iscut[u] = true;
        } else if (dfsno[v] < dfsno[u] && v != fa) {
            lowlink[u] = min(lowlink[u], dfsno[v]);
        }
    }
    if (fa == -1 && child == 1) iscut[u] = 0;
    return lowlink[u];
}
void init() {
    dfs_clock = 0;
    mems(iscut, false);
    mems(dfsno, 0);
    dfs(1, -1);
}
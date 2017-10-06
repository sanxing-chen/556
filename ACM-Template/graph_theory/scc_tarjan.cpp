int dfsno[N], lowlink[N], sccno[N], dfs_clock, scc_cnt;
vector<int> s;
void dfs(int u) {
    dfsno[u] = lowlink[u] = ++dfs_clock;
    s.push_back(u);
    REP(i, 0, g[u].size()) {
        int v = g[u][i];
        if (!dfsno[v]) {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        } else if (!sccno[v]) {
            lowlink[u] = min(lowlink[u], dfsno[v]);
        }
    }

    if (lowlink[u] == dfsno[u]) {
        scc_cnt++;
        for (int x;;) {
            x = s.back();
            s.pop_back();
            sccno[x] = scc_cnt;
            if (x == u) break;
        }
    }
}
void find_scc(int n) {
    s.clear();
    dfs_clock = scc_cnt = 0;
    mems(sccno, 0);
    mems(dfsno, 0);
    REP(i, 0, n) if (!dfsno[i]) dfs(i);
}
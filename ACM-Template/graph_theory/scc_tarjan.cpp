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
int in[N], out[N];
int main() {
    // 缩点为 DAG
    mems(in, 0);
    mems(out, 0);
    REP(i, 0, n) {
        for (auto j : g[i]) {
            if (sccno[i] != sccno[j]) {
                in[sccno[j]]++;
                out[sccno[i]]++;
            }
        }
    }
}
/* Kruskal O(elog(e)) */
const int N = ; //最大点数
const int M = ; //最大边数
struct edge {
    int u, v, cost;
    bool operator<(const edge &e) const {
        return this->cost < e.cost;
    }
};
struct Kruskal {
    vector<edge> es;
    int root[N];
    void init(int v) {
        es.clear();
        for (int i = 0; i <= v; i++) root[i] = i;
    }
    void add_edge(int u, int v, int cost) {
        es.push_back(edge{u, v, cost});
    }
    int uni(int u) {
        return u == root[u] ? u : root[u] = uni(root[u]);
    }
    ll go() {
        sort(es.begin(), es.end());
        ll res = 0;
        for (int i = 0; i < es.size(); i++) {
            edge &e = es[i];
            int x = uni(e.u), y = uni(e.v);
            if (x != y) {
                res += e.cost;
                root[x] = y;
            }
        }
        return res;
    }
} K;

/* 次小生成树 O(n2) */
bool vis[N];
int mcos[N][N], nn, mm;
void dfs(int pos) {
    for (int i = 0; i < v[pos].size(); i++) {
        int temp = v[pos][i].v;
        if (!vis[temp]) {
            for (int j = 0; j < nn; j++) {
                if (vis[j]) mcos[temp][j] = mcos[j][temp] = max(mcos[j][pos], v[pos][i].cost);
            }
            vis[temp] = true;
            dfs(temp);
        }
    }
}
/* 返回增大的值 */
int next_MST() {
    int ans = INF;
    mems(mcos, 0);
    mems(vis, false);
    dfs(0);
    for (int i = 0; i < mm; i++) {
        edge &temp = K.es[i];
        /* 边交换：用一条没用过的边替换最小瓶颈路上的最长边 */
        if (!use[i]) ans = min(ans, temp.cost - mcos[temp.u][temp.v]);
        // if (!use[i] && temp.cost == mcos[temp.u][temp.v]) return true;
    }
    return ans;
}
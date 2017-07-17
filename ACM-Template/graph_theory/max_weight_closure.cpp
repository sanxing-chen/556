// Header
const ll INF = 1e15;
const int maxn = 15000;
const int maxm = 250000;
// 点与边
struct Edge {
    int from, to;
    ll cap, flow;
};
struct ISAP {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn]; // 邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
    bool vis[maxn];      // BFS使用
    bool vi[maxn];       // DFS使用
    int d[maxn];         // 从起点到i的距离
    int cur[maxn];       // 当前弧指针
    int p[maxn];         // 可增广路上的上一条弧
    int num[maxn];       // 距离标号计数

    void AddEdge(int from, int to, ll cap) {
        edges.push_back((Edge){from, to, cap, 0});
        edges.push_back((Edge){to, from, 0, 0});
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(t);
        vis[t] = 1;
        d[t] = 0;
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < G[x].size(); i++) {
                Edge &e = edges[G[x][i] ^ 1];
                if (!vis[e.from] && e.cap > e.flow) {
                    vis[e.from] = 1;
                    d[e.from] = d[x] + 1;
                    Q.push(e.from);
                }
            }
        }
        return vis[s];
    }

    // 遍历残量网络，遍历到的点即为闭合子图中的点
    void dfs(int u, int t) {
        if (u == t) return;
        vi[u] = true;
        for (int i = 0; i < G[u].size(); i++) {
            Edge &e = edges[G[u][i]];
            if (e.cap > e.flow && !vi[e.to]) dfs(e.to, t);
        }
    }

    int getdfs(int u, int t) {
        int ret = 0;
        mems(vi, false);
        dfs(u, t);
        REP(i, 1, n + 1) {
            if (vi[i]) ret++;
        }
        return ret;
    }

    void ClearAll(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    ll Augment() {
        int x = t;
        ll a = INF;
        while (x != s) {
            Edge &e = edges[p[x]];
            a = min(a, e.cap - e.flow);
            x = edges[p[x]].from;
        }
        x = t;
        while (x != s) {
            edges[p[x]].flow += a;
            edges[p[x] ^ 1].flow -= a;
            x = edges[p[x]].from;
        }
        return a;
    }

    ll Maxflow(int s, int t) {
        this->s = s;
        this->t = t;
        ll flow = 0;
        BFS();
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++) num[d[i]]++;
        int x = s;
        memset(cur, 0, sizeof(cur));
        while (d[s] < n) {
            if (x == t) {
                flow += Augment();
                x = s;
            }
            int ok = 0;
            for (int i = cur[x]; i < G[x].size(); i++) {
                Edge &e = edges[G[x][i]];
                if (e.cap > e.flow && d[x] == d[e.to] + 1) { // Advance
                    ok = 1;
                    p[e.to] = G[x][i];
                    cur[x] = i; // 注意
                    x = e.to;
                    break;
                }
            }
            if (!ok) {         // Retreat
                int m = n - 1; // 初值注意
                for (int i = 0; i < G[x].size(); i++) {
                    Edge &e = edges[G[x][i]];
                    if (e.cap > e.flow) m = min(m, d[e.to]);
                }
                if (--num[d[x]] == 0) break;
                num[d[x] = m + 1]++;
                cur[x] = 0; // 注意
                if (x != s) x = edges[p[x]].from;
            }
        }
        return flow;
    }
} fuck;
int a[10000];
// 收益与起始点连边，花费与终点连边，(u, v, INF) 表示 u 需要 v
int main() {
    ios::sync_with_stdio(false);
    int n, m, u, v;
    while (cin >> n >> m) {
        fuck.ClearAll(n + 2);
        ll ans = 0;
        int s = 0, t = n + 1;
        REP(i, 1, n + 1) {
            cin >> a[i];
            if (a[i] > 0) {
                fuck.AddEdge(s, i, a[i]);
                ans += a[i];
            } else {
                fuck.AddEdge(i, t, -a[i]);
            }
        }
        REP(i, 0, m) {
            cin >> u >> v;
            fuck.AddEdge(u, v, INF);
        }
        ans -= fuck.Maxflow(s, t);
        cout << fuck.getdfs(s, t) << " " << ans << endl;
    }
    return 0;
}
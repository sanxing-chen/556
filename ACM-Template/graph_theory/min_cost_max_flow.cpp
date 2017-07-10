double INF = 1e9;
const double eps = 1e-7;
struct Edge {
    int from, to, cap, flow;
    double cost;                               //@type
    Edge(int u, int v, int c, int f, double w) //@type
        : from(u)
        , to(v)
        , cap(c)
        , flow(f)
        , cost(w) {}
};
struct MCMF {
    int n, m;
    vector<Edge> edges;
    vector<int> G[2 * maxn];
    int inq[2 * maxn];
    double d[2 * maxn]; //@type
    int p[2 * maxn];
    int a[2 * maxn];

    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap, double cost) { //@type
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BellmanFord(int s, int t, int &flow, double &cost) { //@type
        for (int i = 0; i < n; i++) d[i] = INF;               //@type
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = INF;

        queue<int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); ++i) {
                Edge &e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost + eps) { // eps to avoid TLE
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to]) {
                        Q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (d[t] == INF) return false;
        flow += a[t];
        cost += d[t] * a[t];
        for (int u = t; u != s; u = edges[p[u]].from) {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
        return true;
    }
    // 需保证无负环
    int MincostMaxflow(int s, int t, double &cost) { //@type
        int flow = 0;
        cost = 0;
        while (BellmanFord(s, t, flow, cost))
            ;
        return flow;
    }
};
int n, m;
MCMF fuck;
void solve() {
    fuck.init(n + 1); // 0 - n
    fuck.AddEdge();
    double ans = 0; //@type
    fuck.MincostMaxflow(0, n, ans);
    cout << fixed << setprecision(2) << ans << endl;
}
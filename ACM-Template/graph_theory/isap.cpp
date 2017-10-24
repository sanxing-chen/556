const int INF = 0x3f3f3f3f;
const int maxn = 25000;
const int maxm = 25000;
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

    // 遍历残量网络，正向边 cap > flow，若从终点开始遍历见 BFS
    // memset(vis)
    void dfs(int u) {
        for (int i = 0; i < G[u].size(); i++) {
            Edge &e = edges[G[u][i]];
            if (!vis[e.to] && e.cap > e.flow) {
                vis[e.to] = 1;
                dfs(e.to);
            }
        }
    }

    void ClearAll(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void ClearFlow() {
        for (int i = 0; i < m; i++) {
            edges[i].flow = 0;
        }
    }

    void print() {
        for (int i = 0; i < m; i += 2) {
            cout << edges[i].from << " -> " << edges[i].to << " = " << edges[i].cap << endl;
        }
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
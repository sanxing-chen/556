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
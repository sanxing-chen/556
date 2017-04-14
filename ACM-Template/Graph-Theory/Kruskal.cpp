const int N = ; //最大点数
const int M = ; //最大边数

struct edge {
    int u, v, cost;
};
edge es[M];

bool cmp(const edge &e1, const edge &e2) {
    return e1.cost < e2.cost;
}

struct Union {
    int fa[N];
    int find(int x) {
        if (fa[x] == x)
            return x;
        else {
            fa[x] = find(fa[x]);
            return fa[x];
        }
    }
    void unite(int x, int y) {
        fa[find(x)] = fa[find(y)];
        return;
    }
    bool same(int x, int y) {
        return (find(x) == find(y));
    }
    void init_union_find(int x) {
        for (int i = 1; i <= x; i++) {
            fa[i] = i;
        }
    }
};

struct Kruskal {
    Union U;

    int V, E; // 顶点数和边数
    void init(int v, int e) {
        V = v, E = e;
        U.init_union_find(V);
    }
    ll go() {
        sort(es, es + E, cmp);
        ll res = 0;
        for (int i = 0; i < E; i++) {
            edge e = es[i];
            if (!U.same(e.u, e.v)) {
                U.unite(e.u, e.v);
                res += e.cost;
            }
        }
        return res;
    }
};

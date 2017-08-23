// 建树
const int M = N;
int pre[N], ecnt;
struct edge {
    int x;
    int next;
} e[M];
void initGragh() {
    mems(pre, -1);
    ecnt = 0;
}
void addedge(int u, int v) {
    e[ecnt].x = v, e[ecnt].next = pre[u];
    pre[u] = ecnt++;
    e[ecnt].x = u, e[ecnt].next = pre[v];
    pre[v] = ecnt++;
}

// 树链剖分（点权）
int size[N], heavy[N], tid[N], Top[N], ncnt, dep[N], Fa[N];
void FindHE(int x, int fa, int Dep) {
    heavy[x] = 0, size[x] = 1, dep[x] = Dep, Fa[x] = fa;
    for (int i = pre[x]; ~i; i = e[i].next)
        if (e[i].x != fa) {
            int y = e[i].x;
            FindHE(y, x, Dep + 1);
            size[x] += size[y];
            if (!heavy[x] || size[y] > size[heavy[x]]) heavy[x] = y;
        }
}
void ConnectHE(int x, int anc) {
    tid[x] = ++ncnt, Top[x] = anc;
    if (heavy[x]) ConnectHE(heavy[x], anc);
    for (int i = pre[x]; ~i; i = e[i].next)
        if (e[i].x != Fa[x] && e[i].x != heavy[x]) ConnectHE(e[i].x, e[i].x);
}
// 区间更新查询，单点可以直接操作数据结构
ll query(int x, int y) {
    ll ans = 0;
    while (Top[x] != Top[y]) {
        if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
        ans += get(tid[x]) - get(tid[Top[x]] - 1); // 根据题意更改
        x = Fa[Top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    ans += get(tid[y]) - get(tid[x] - 1); // 根据题意更改
    return ans;                           //如果权在边上就不考虑左边的点了
}
void update(int x, int y, int c) {
    while (Top[x] != Top[y]) {
        if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
        update(tid[Top[x]], tid[x], c, 1, n);
        x = Fa[Top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    update(tid[x], tid[y], c, 1, n);
}

void init() {
    initGragh();
    ncnt = 0;
    FindHE(1, 0, 0);
    ConnectHE(1, 1);
}
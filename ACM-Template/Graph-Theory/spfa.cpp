struct arc {
    int x, f, next;
};
struct spfa {
    int pre[N], mcnt, s, dis[N];
    bool vis[N];
    arc e[2 * M];
    void init(int i) {
        mems(pre, -1);
        mcnt = 0;
        s = i;
    }
    void addarc(int x, int y, int z) {
        e[mcnt] = (arc){y, z, pre[x]}, pre[x] = mcnt++;
        e[mcnt] = (arc){x, z, pre[y]}, pre[y] = mcnt++;
    }
    void go() {
        queue<int> q;
        mems(dis, 0x3f);
        mems(vis, false);
        dis[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (int i = pre[u]; ~i; i = e[i].next) {
                int v = e[i].x, c = e[i].f;
                if (dis[v] > dis[u] + c) {
                    dis[v] = dis[u] + c;
                    if (!vis[v]) vis[v] = true, q.push(v);
                }
            }
        }
    }
};
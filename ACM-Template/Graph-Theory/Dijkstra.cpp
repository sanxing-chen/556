struct arc {
    int x, f, next;
};
// std::set implementation
struct Dijkstra {
    set<pii> st;
    int pre[N], mcnt, s, dis[N];
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
        mems(dis, 0x3f);
        dis[s] = 0;
        st.insert(pii(0, s));
        while (!st.empty()) {
            pii top = *st.begin();
            st.erase(st.begin());
            int d = top.first, u = top.second;
            for (int i = pre[u]; ~i; i = e[i].next) {
                int v = e[i].x, c = e[i].f;
                if (dis[v] > dis[u] + c) {
                    st.erase(pii(dis[v], v));
                    dis[v] = dis[u] + c;
                    st.insert(pii(dis[v], v));
                }
            }
        }
    }
} solver;
// std::priority_queue implementation
struct Dijkstra {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int pre[N], mcnt, s, dis[N];
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
        mems(dis, 0x3f);
        dis[s] = 0;
        pq.push(pii(0, s));
        while (!pq.empty()) {
            pii top = pq.top();
            pq.pop();
            int d = top.first, u = top.second;
            for (int i = pre[u]; ~i; i = e[i].next) {
                int v = e[i].x, c = e[i].f;
                if (dis[v] > dis[u] + c) {
                    dis[v] = dis[u] + c;
                    pq.push(pii(dis[v], v));
                }
            }
        }
    }
} solver;
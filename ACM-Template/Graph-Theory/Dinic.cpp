//dinic dfs 可能爆栈，扩栈或使用非递归版本或 ISAP
#pragma comment(linker, "/STACK:1024000000,1024000000")
const int INF = 0x3f3f3f3f;
const int N = 2020;
const int M = 60010;
// 点与边

struct arc {
    int x, f, next;
};
struct dinic {
    int pre[N], mcnt, s, t;
    arc e[M];
// 初始化，起点和终点
    void init(int n, int m) {
        mcnt = 0;
        memset(pre, -1, sizeof pre);
        s = n, t = m;
    }
    void addarc(int x, int y, int z) {
        e[mcnt] = (arc){y, z, pre[x]}, pre[x] = mcnt++;
        e[mcnt] = (arc){x, 0, pre[y]}, pre[y] = mcnt++;
    }
    int d[N], cur[N], q[N];
    bool BFS() {
        memset(d, -1, sizeof(d));
        int top = 0, bot = -1;
        q[++bot] = t, d[t] = 1;
        while (top != bot + 1) {
            int x = q[top++];
            for (int i = pre[x]; ~i; i = e[i].next) {
                int y = e[i].x;
                if (!~d[y] && e[i ^ 1].f) {
                    d[y] = d[x] + 1, q[++bot] = y;
                    if (y == s) return true;
                }
            }
        }
        return false;
    }
    int DFS(int x, int flow = 1 << 30) {
        if (x == t || !flow) return flow;
        int sum = 0, u;
        for (int &i = cur[x]; ~i; i = e[i].next) {
            int y = e[i].x;
            if (d[x] == d[y] + 1 && (u = DFS(y, min(flow, e[i].f)))) {
                e[i].f -= u, e[i ^ 1].f += u;
                sum += u, flow -= u;
                if (!flow) break;
            }
        }
        if (!sum) d[x] = -1;
        return sum;
    }
    int go() {
        int ans = 0;
        while (BFS()) {
            memcpy(cur, pre, sizeof(cur));
            ans += DFS(s);
        }
        return ans;
    }
}
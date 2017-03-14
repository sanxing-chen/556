#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 2020;
const int M = 60010;

struct arc {
    int x, f, next;
};
struct dinic {
    int pre[N], mcnt, s, t;
    arc e[2 * M];
    void init(int n) {
        mcnt = 0;
        memset(pre, -1, sizeof pre);
        s = 1, t = n;
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
vector<int> g[N];
// bfs最小深度
int dis[N];
void bfs() {
    mems(dis, -1);
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    int j;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); i++) {
            j = g[u][i];
            if (dis[j] == -1) {
                dis[j] = dis[u] + 1;
                q.push(j);
            }
        }
    }
}
spfa fuck;
dinic solve;
int main() {
    ios::sync_with_stdio(false);
    int n, m, x, y, c;
    while (cin >> n >> m) {
        fuck.init(1);
        solve.init(n);
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> c;
            fuck.addarc(x, y, c);
        }
        fuck.go();
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            for (int j = fuck.pre[i]; ~j; j = fuck.e[j].next) {
                int v = fuck.e[j].x;
                if (fuck.dis[v] == fuck.dis[i] + fuck.e[j].f) {
                    solve.addarc(i, v, 1);
                    g[i].push_back(v);
                }
            }
        }
        bfs();
        cout << solve.go() << " " << m - dis[n] << "\n";
    }
    return 0;
}
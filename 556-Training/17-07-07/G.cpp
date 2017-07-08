#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int maxn = 110;
double INF = 1e9;
const double eps = 1e-7;
struct Edge {
    int from, to, cap, flow;
    double cost;
    Edge(int u, int v, int c, int f, double w)
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
    double d[2 * maxn];
    int p[2 * maxn];
    int a[2 * maxn];

    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap, double cost) {
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BellmanFord(int s, int t, int &flow, double &cost) {
        for (int i = 0; i < n; i++) d[i] = INF;
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
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost + eps) {
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

    int MincostMaxflow(int s, int t, double &cost) {
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
    fuck.init(n + 2);
    int s, b;
    for (int i = 1; i <= n; i++) {
        cin >> s >> b;
        if (s > b) {
            fuck.AddEdge(0, i, s - b, 0);
        } else if (s < b) {
            fuck.AddEdge(i, n + 1, b - s, 0);
        }
    }
    int u, v, c;
    double p;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> c >> p;
        if (c > 1) {
            fuck.AddEdge(u, v, c - 1, -log(1 - p));
            fuck.AddEdge(u, v, 1, 0);
        } else if (c == 1) {
            fuck.AddEdge(u, v, 1, 0);
        }
    }
    double ans = 0;
    fuck.MincostMaxflow(0, n + 1, ans);
    cout << fixed << setprecision(2) << 1 - exp(-ans) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        solve();
    }
}
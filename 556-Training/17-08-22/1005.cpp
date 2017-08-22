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
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
#define MAXN 2000
#define MAXM 10000
struct Edge {
    int u, v, next;
} edge[MAXM];
int NE, head[MAXN];
void addEdge(int u, int v) {
    edge[NE].u = u;
    edge[NE].v = v;
    edge[NE].next = head[u];
    head[u] = NE++;
}

int belong[MAXN], bn, stack[MAXN], top;
bool instack[MAXN];
int dn, dfn[MAXN], low[MAXN];
void dfs(int u) {
    dfn[u] = low[u] = ++dn;
    stack[++top] = u;
    instack[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (dfn[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (instack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        int v;
        ++bn;
        do {
            v = stack[top--];
            belong[v] = bn;
            instack[v] = 0;
        } while (u != v);
    }
}

int deg[MAXN];
bool toposort() {
    queue<int> que;
    for (int i = 1; i <= bn; ++i) {
        if (deg[i] == 0) que.push(i);
    }
    if (que.size() > 1) return 0;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (--deg[v] == 0) que.push(v);
        }
        if (que.size() > 1) return 0;
    }
    return 1;
}
int main() {
    int t, n, m, a, b;
    scanf("%d", &t);
    while (t--) {
        NE = 0;
        memset(head, -1, sizeof(head));
        scanf("%d%d", &n, &m);
        while (m--) {
            scanf("%d%d", &a, &b);
            addEdge(a, b);
        }
        top = bn = dn = 0;
        memset(instack, 0, sizeof(instack));
        memset(dfn, 0, sizeof(dfn));
        for (int i = 1; i <= n; ++i) {
            if (dfn[i] == 0) dfs(i);
        }

        int tmp = NE;
        NE = 0;
        memset(head, -1, sizeof(head));
        memset(deg, 0, sizeof(deg));
        for (int i = 0; i < tmp; ++i) {
            int u = belong[edge[i].u], v = belong[edge[i].v];
            if (u == v) continue;
            addEdge(u, v);
            ++deg[v];
        }
        if (toposort())
            puts("I love you my love and our love save us!");
        else
            puts("Light my fire!");
    }
    return 0;
}
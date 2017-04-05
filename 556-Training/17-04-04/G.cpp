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

#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef int mytype;
const int NV = 100050;
const int NE = 2 * NV;
int vis[NV], he[NV], ecnt, n;
struct edge {
    int v, next;
    mytype l;
} E[NE];
void adde(int u, int v, mytype l) {
    E[++ecnt].v = v;
    E[ecnt].l = l;
    E[ecnt].next = he[u];
    he[u] = ecnt;
}
mytype L;
void init() {
    ecnt = 0, L = 0;
    memset(he, -1, sizeof(he));
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        mytype l;
        scanf("%d%d", &u, &v);
        l = 1;
        adde(u, v, l);
        adde(v, u, l);
    }
}
int U;
void dfs(int u, int uu, mytype l) {
    if (l > L) {
        U = u;
        L = l;
    }
    for (int i = he[u]; i != -1; i = E[i].next) {
        if (E[i].v != uu) {
            dfs(E[i].v, u, l + E[i].l);
        }
    }
}
mytype solve() {
    dfs(1, 0, 0);
    dfs(U, 0, 0);
    return L;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        init();
        int temp = solve();
        cout << temp + (n - 1 - temp) * 2 << endl;
    }
    return 0;
}
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
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 1100000;
const int M = 1000100;
struct arc {
    int x, f, next;
};
struct spfa {
    int pre[N], mcnt, s, dis[N];
    bool vis[N];
    arc e[2 * M];
    void init() {
        mems(pre, -1);
        mcnt = 0;
    }
    void addarc(int x, int y, int z) {
        e[mcnt] = (arc){y, z, pre[x]}, pre[x] = mcnt++;
        e[mcnt] = (arc){x, z, pre[y]}, pre[y] = mcnt++;
    }
    void go(int s) {
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
} solver;
int mem[100010];
inline int readT() {
    char c;
    int ret = 0, flag = 0;
    while (c = getchar(), (c < '0' || c > '9') && c != '-')
        ;
    if (c == '-')
        flag = 1;
    else
        ret = c ^ 48;
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c ^ 48);
    return flag ? -ret : ret;
}
int main() {
    int t, n, m, a, b, tim, num, temp;
    t = readT();
    REP(cas, 1, t + 1) {
        n = readT();
        m = readT();
        solver.init();
        REP(i, 0, m) {
            tim = readT();
            num = readT();
            REP(j, 0, num) {
                temp = readT();
                solver.addarc(n + i + 1, temp, tim);
            }
        }
        solver.go(1);
        memcpy(mem, solver.dis, sizeof mem);
        solver.go(n);
        int minn = INF;
        REP(i, 1, n + 1) {
            mem[i] = max(mem[i], solver.dis[i]);
            minn = min(minn, mem[i]);
        }
        cout << "Case #" << cas << ": ";
        if (minn != INF) {
            cout << minn / 2 << endl;
            REP(i, 1, n + 1) {
                if (minn == mem[i]) {
                    cout << i;
                    REP(j, i + 1, n + 1)
                    if (minn == mem[j]) cout << " " << j;
                    cout << endl;
                    break;
                }
            }
        } else {
            cout << "Evil John" << endl;
        }
    }
    return 0;
}
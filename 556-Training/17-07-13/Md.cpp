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
const int M = 2000000;
struct arc {
    int x;
    int f;
    int next;
};
// std::set implementation
struct Dijkstra {
    set<pii> st;
    int pre[N], mcnt, s;
    int dis[N];
    arc e[M];
    void init() {
        mems(pre, -1);
        mcnt = 0;
    }
    void addarc(int x, int y, int z) {
        e[mcnt] = (arc){y, z, pre[x]}, pre[x] = mcnt++;
    }
    void go(int ss) {
        mems(dis, INF);
        dis[ss] = 0;
        st.insert(pii(0, ss));
        while (!st.empty()) {
            pii top = *st.begin();
            st.erase(st.begin());
            int u = top.second;
            for (int i = pre[u]; ~i; i = e[i].next) {
                int v = e[i].x;
                int c = e[i].f;
                if (dis[v] > dis[u] + c) {
                    st.erase(pii(dis[v], v));
                    dis[v] = dis[u] + c;
                    st.insert(pii(dis[v], v));
                }
            }
        }
    }
} solver;
int mem[100010];
vector<int> v, ans;
int main() {
    ios::sync_with_stdio(false);
    int t, n, m, a, b, tim, num, temp;
    cin >> t;
    REP(cas, 1, t + 1) {
        cin >> n >> m;
        solver.init();
        REP(i, 0, m) {
            cin >> tim >> num;
            v.clear();
            REP(j, 0, num) {
                cin >> temp;
                solver.addarc(n + i + 1, temp, tim);
                solver.addarc(temp, n + i + 1, 0);
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
            cout << minn << endl;
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
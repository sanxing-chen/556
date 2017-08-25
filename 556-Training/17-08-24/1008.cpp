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
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 101000;
vector<int> v[N];
int cnt[N];
int can[N];
bool vis[N];
int dfs(int pos) {
    vis[pos] = true;
    int ret = 0;
    cnt[pos] = 1;
    int temp = 0;
    for (auto to : v[pos]) {
        if (vis[to]) continue;
        ret += dfs(to);
        cnt[pos] += cnt[to];
        if (can[to]) temp++;
    }
    if (temp) {
        ret++;
        can[pos] = false;
    }
    return ret;
}
namespace fastIO {
#define BUF_SIZE 100000
// fread -> read
bool IOerror = 0;
inline char nc() {
    static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
    if (p1 == pend) {
        p1 = buf;
        pend = buf + fread(buf, 1, BUF_SIZE, stdin);
        if (pend == p1) {
            IOerror = 1;
            return -1;
        }
    }
    return *p1++;
}
inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void read(int &x) {
    char ch;
    while (blank(ch = nc()))
        ;
    if (IOerror) return;
    for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0')
        ;
}
#undef BUF_SIZE
};
using namespace fastIO;
int main() {
#ifdef FUCK
    freopen("test.in", "r", stdin);
#endif
    int t, u, w, n, k;
    read(t);
    while (t--) {
        mems(cnt, 0);
        mems(vis, false);
        mems(can, true);
        read(n);
        read(k);
        REP(i, 0, n + 1) v[i].clear();
        REP(i, 1, n) {
            read(u);
            v[u].push_back(i + 1);
            v[i + 1].push_back(u);
            // printf("%d -> %d\n", u, i + 1);
        }
        int ans = 0;
        REP(i, 1, n + 1) {
            if (!vis[i]) ans += dfs(i);
        }
        // printf("and: %d\n", ans);
        if (ans * 2 >= k) {
            if (k & 1)
                printf("%d\n", k / 2 + 1);
            else
                printf("%d\n", k / 2);
        } else {
            printf("%d\n", ans + k - 2 * ans);
        }
    }
    return 0;
}
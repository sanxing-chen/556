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
const int N = 110100;
pii a[N];
priority_queue<pii> q;
multiset<pii> st;
int endt[N], begint[N];
int main() {
    int t, n;
    read(t);
    while (t--) {
        read(n);
        REP(i, 0, n) {
            read(a[i].first);
            read(a[i].second);
        }
        sort(a, a + n);

        // end
        // available
        while (!q.empty()) q.pop();

        // end, id
        // working
        st.clear();
        ll ans = 0;
        int ncnt = 0;
        pii now;
        REP(i, 0, n) {
            auto it = st.begin();
            for (; it != st.end(); it++) {
                if (it->first > a[i].first)
                    break;
                else {
                    q.push(pii(it->first, it->second));
                }
            }
            st.erase(st.begin(), it);
            if (!q.empty()) {
                now = q.top();
                q.pop();
                st.insert(pii(a[i].second, now.second));
                endt[now.second] = a[i].second;
            } else {
                begint[ncnt] = a[i].first;
                endt[ncnt] = a[i].second;
                st.insert(pii(a[i].second, ncnt++));
            }
        }
        REP(i, 0, ncnt) {
            ans += endt[i] - begint[i];
        }
        printf("%d %lld\n", ncnt, ans);
    }
    return 0;
}
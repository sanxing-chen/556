#include <algorithm>
#include <bitset>
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
#define REP(i, a, n) for (int i = a; i < (n); ++i)
#define PER(i, a, n) for (int i = (n) -1; i >= a; --i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int mid = 3000;
const int maxn = 1000105;
bitset<maxn> Q1, Q2;
int a[2000];
char c[2000];
int k;
inline bool fuck1() {
    if (Q1.test(k)) return true;
    REP(i, k + 1, maxn) {
        if (Q1.test(i) && Q2.test(i - k)) {
            return true;
        }
    }
    return false;
}
inline bool fuck2() {
    if (Q2.test(k)) return true;
    REP(i, k + 1, maxn) {
        if (Q2.test(i) && Q1.test(i - k)) {
            return true;
        }
    }
    return false;
}
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
    int t, m, n;
    t = readT();
    while (t--) {
        n = readT();
        k = readT();
        Q1.reset();
        Q2.reset();
        Q1.set(0);
        Q2.set(0);
        REP(i, 0, n) a[i] = readT();
        REP(i, 0, n) scanf(" %c", &c[i]);
        int sum1 = 0, sum2 = 0;
        REP(i, 0, n) {
            if (c[i] == 'N') {
                sum1 += a[i];
                sum2 += a[i];
            } else if (c[i] == 'L') {
                sum1 += a[i];
            } else {
                sum2 += a[i];
            }
        }
        if ((k > 0 && sum1 < k) || (k < 0 && sum2 < -k)) {
            puts("no");
            continue;
        }
        REP(i, 0, n) {
            if (c[i] == 'N') {
                Q1 |= (Q1 << a[i]);
                Q2 |= (Q2 << a[i]);
                sum1 += a[i];
                sum2 += a[i];
            } else if (c[i] == 'L') {
                Q1 |= (Q1 << a[i]);
                sum1 += a[i];
            } else {
                Q2 |= (Q2 << a[i]);
                sum2 += a[i];
            }
        }
        if (k == 0)
            puts("yes");
        else if (k > 0) {
            fuck1() ? puts("yes") : puts("no");
        } else {
            k = -k;
            fuck2() ? puts("yes") : puts("no");
        }
    }
    return 0;
}
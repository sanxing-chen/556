#include <algorithm>
#include <climits>
#include <cmath>
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
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 1000000;
bool v[N + 1];
int f[N + 1];
int vv[8][N + 1];
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
int psolve() {
    for (int i = 2; i <= N; i++) {
        if (!v[i]) {
            f[i]++;
            for (int j = i + i; j <= N; j += i) {
                f[j]++;
                v[j] = true;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= 7; j++) {
            vv[j][i] = vv[j][i - 1] + (f[i] == j);
        }
    }
    return 0;
}
int main() {
    psolve();
    int t, x, y, m, g;
    int st[8];
    t = readT();
    while (t--) {
        x = readT();
        y = readT();
        m = 0;
        for (int i = 1; i <= 7; i++) {
            st[i] = vv[i][y] - vv[i][x - 1];
            if (st[i] > 1) m = i;
        }
        if (m < 3 && st[3] && st[6]) m = 3;
        if (m < 2 && st[2] && (st[6] || st[4])) m = 3;
        printf("%d\n", m);
    }
    return 0;
}
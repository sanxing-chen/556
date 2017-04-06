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
struct card {
    int kind, level, atk, k1, k2, k3;
    bool is;
} d[600];
card e[600];
bool cmp(card x, card y) {
    if (x.kind == y.kind) return x.atk < y.atk;
    return x.kind < y.kind;
}
bool cmp1(card x, card y) {
    return x.atk > y.atk;
}
int a, b, c, x, n, m;
int main() {
    ios::sync_with_stdio(false);
    int T;
    int sum = 0;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for(int i=1;i<=n;i++
    }
    {
        cin >> a >> b >> c;
        d[i].kind = a;
        d[i].level = b;
        d[i].atk = c;
        sum += c;
    }
    sort(d + 1, d + 1 + n, cmp);
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        e[i].level = a;
        e[i].atk = b;
        e[i].kind = c;
        if (c == 1)
            cin >> e[i].k1;
        else if (c == 2)
            cin >> e[i].k2 >> e[i].k3;
    }
    sort(e + 1, e + 1 + m, cmp1);
    for (int i = 1; i <= m; i++) {
        if (e[i].kind != 1 && e[i].kind != 2) {
            for (int j = 1; j <= n; j++) {
                if (!d[j].is)
                    for (int k = j + 1; k <= n; k++) }
        }
    }
    if (e[i].kind == 1) {
        j = e[i].k1;
        if (!d[j].is)
            for (int k = 1; k <= n; k++) {
            }
    }
    if (e[i].kind == 2) {
        j = e[i].k2;
        k = e[i].k3;
        if (!e[i]) }
}
cout << sum << endl;
}
return 0;
}
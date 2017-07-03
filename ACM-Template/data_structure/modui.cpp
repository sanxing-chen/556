#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 50010;
typedef long long ll;
ll num[maxn], up[maxn], dw[maxn], ans, aa, bb, cc;
int col[maxn], pos[maxn];
struct qnode {
    int l, r, id;
} qu[maxn];
bool cmp(qnode a, qnode b) {
    if (pos[a.l] == pos[b.l]) return a.r < b.r;
    return pos[a.l] < pos[b.l];
}
ll gcd(ll x, ll y) {
    ll tp;
    while (tp = x % y) {
        x = y;
        y = tp;
    }
    return y;
}
void update(int x, int d) {
    ans -= num[col[x]] * num[col[x]];
    num[col[x]] += d;
    ans += num[col[x]] * num[col[x]];
}
int main() {
    int n, m, i, j, bk, pl, pr, id;

    freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &m)) {
        memset(num, 0, sizeof num);
        bk = ceil(sqrt(1.0 * n));
        for (i = 1; i <= n; i++) {
            scanf("%d", &col[i]);
            pos[i] = (i - 1) / bk;
        }
        for (i = 0; i < m; i++) {
            scanf("%d%d", &qu[i].l, &qu[i].r);
            qu[i].id = i;
        }
        sort(qu, qu + m, cmp);
        pl = 1, pr = 0;
        ans = 0;
        for (i = 0; i < m; i++) {
            id = qu[i].id;
            if (qu[i].l == qu[i].r) {
                up[id] = 0, dw[id] = 1;
                continue;
            }
            if (pr < qu[i].r) {
                for (j = pr + 1; j <= qu[i].r; j++) update(j, 1);
            } else {
                for (j = pr; j > qu[i].r; j--) update(j, -1);
            }
            pr = qu[i].r;
            if (pl < qu[i].l) {
                for (j = pl; j < qu[i].l; j++) update(j, -1);
            } else {
                for (j = pl - 1; j >= qu[i].l; j--) update(j, 1);
            }
            pl = qu[i].l;
            aa = ans - qu[i].r + qu[i].l - 1;
            bb = (ll)(qu[i].r - qu[i].l + 1) * (qu[i].r - qu[i].l);
            cc = gcd(aa, bb);
            aa /= cc, bb /= cc;
            up[id] = aa, dw[id] = bb;
        }
        for (i = 0; i < m; i++) printf("%lld/%lld\n", up[i], dw[i]);
    }
    return 0;
}

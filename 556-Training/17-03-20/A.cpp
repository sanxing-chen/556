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
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll inf = 1ll << 61;
using namespace std;
const int NV = 100005;
ll a[NV], cnt = 1;
struct node {
    ll oo, ee, oe, eo;
};
node sum[NV << 2];
node fuck(node &a, node &b) {
    node c;
    c.oo = max(max(a.oo + b.eo, a.oe + b.oo), max(a.oo, b.oo));
    c.ee = max(max(a.eo + b.ee, a.ee + b.oe), max(a.ee, b.ee));
    c.oe = max(max(a.oo + b.ee, a.oe + b.oe), max(a.oe, b.oe));
    c.eo = max(max(a.eo + b.eo, a.ee + b.oo), max(a.eo, b.eo));
    return c;
}
void PushUp(int rt) {
    sum[rt] = fuck(sum[rt << 1], sum[rt << 1 | 1]);
}
void build(int l, int r, int rt = 1) {
    if (l == r) {
        node &no = sum[rt];
        if (l & 1) {
            no.oo = a[cnt];
        } else {
            no.ee = a[cnt];
        }
        cnt++;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}
node query(int L, int R, int l, int r, int rt = 1) {
    if (L <= l && r <= R) return sum[rt];
    int m = (l + r) >> 1;
    node result_1, result_2;
    bool flag1 = true, flag2 = true;
    if (L <= m) {
        result_1 = query(L, R, lson);
        flag1 = false;
    }
    if (m < R) {
        result_2 = query(L, R, rson);
        flag2 = false;
    }
    if (flag2) return result_1;
    if (flag1)
        return result_2;
    else
        return fuck(result_1, result_2);
}
void update(int pos, ll val, int l, int r, int rt = 1) {
    if (l == r) {
        node &no = sum[rt];
        if (l & 1) {
            no.oo = val;
            no.eo = no.ee = no.oe = -inf;
        } else {
            no.ee = val;
            no.eo = no.oo = no.oe = -inf;
        }
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m)
        update(pos, val, lson);
    else
        update(pos, val, rson);
    PushUp(rt);
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
    int t, n, m;
    cin >> t;
    while (t--) {
        cnt = 1;
        n = readT();
        m = readT();
        for (int i = 1; i <= n; i++) {
            a[i] = readT();
        }
        for (int i = 1; i <= (n << 2); i++) {
            sum[i].oo = sum[i].oe = sum[i].ee = sum[i].eo = -inf;
        }
        build(1, n);
        int op, x;
        ll y;
        while (m--) {
            op = readT();
            x = readT();
            y = readT();
            if (op) {
                update(x, y, 1, n);
            } else {
                node temp = query(x, y, 1, n);
                cout << max(temp.ee, max(temp.eo, max(temp.oe, temp.oo))) << endl;
            }
        }
    }
}
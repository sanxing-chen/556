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
using namespace std;
const int NV = 100005;
int a[NV], cnt = 1, n;
struct node {
    ll oo, ee, oe, eo;
};
node sum[NV << 2];
node fuck(node a, node b) {
    node c;
    c.oo = max(a.oo + b.eo, a.oe + b.oo);
    c.ee = max(a.eo + b.ee, a.ee + b.oe);
    c.oe = max(a.oo + b.ee, a.oe + b.oe);
    c.eo = max(a.eo + b.eo, a.ee + b.oo);
    return c;
}
void PushUp(int rt) {
    sum[rt] = fuck(sum[rt << 1], sum[rt << 1 | 1]);
}
void build(int l, int r, int rt = 1) {
    if (l == r) {
        node &no = sum[rt];
        if (a[cnt] & 1) {
            no.oo = 1;
            no.oe = no.eo = no.ee = 0;
        } else {
            no.ee = 1;
            no.oo = no.eo = no.oe = 0;
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
    if (L <= m) result_1 = query(L, R, lson);
    if (m < R) result_2 = query(L, R, rson);
    return fuck(result_1, result_2);
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
    cin >> t;
    while (t--) {
        n = readT();
        m = readT();
        for (int i = 0; i < n; i++) {
            a[i] = readT();
        }
        build(0, n - 1)
    }
}
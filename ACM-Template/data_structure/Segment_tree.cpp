#include <iostream>
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int MAXN = 10005;
int sum[MAXN << 2], add[MAXN << 2];
void pushup(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void pushdown(int rt, int m /*区间长度*/) {
    if (add[rt] != 0) {
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        sum[rt << 1] += add[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] += add[rt] * (m >> 1);
        add[rt] = 0;
    }
    return;
}
void build(int l, int r, int rt /*=1*/) {
    add[rt] = 0;
    if (l == r) {
        sum[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
    return;
}
void update(int L /*需要更新的点*/, int c, int l, int r, int rt /*=1*/) { //单点
    if (L == l && l == r) {
        sum[rt] += c;
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, c, lson);
    else
        update(L, c, rson);
    pushup(rt);
    return;
}

int query(int L, int R, int l, int r, int rt /*=1*/) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    int ret = 0;
    int m = (l + r) >> 1;
    if (L < m) ret += query(L, R, lson);
    if (m < R) ret += query(L, R, rson);
    return ret;
}
void update2(int L /*左*/, int R /*右端点*/, int c, int l, int r, int rt /*=1*/) {
    if (L <= l && r <= R) {
        add[rt] += c;
        sum[rt] += c * (r - l + 1);
        return;
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update2(L, R, c, lson);
    if (m < R) update2(L, R, c, rson);
    pushup(rt);
    return;
}
int query2(int L, int R, int l, int r, int rt /*=1*/) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += query2(L, R, lson);
    if (m < R) ret += query2(L, R, rson);
    return ret;
}
int discrete(int data[] /*初始数组*/, int n, int dis[] /*离散化数组*/, int idx[]) {
    int sub[n + 1];
    memcpy(sub, data, sizeof(sub));
    sort(sub + 1, sub + n + 1);
    int m = unique(sub + 1, sub + n + 1) - sub - 1;
    for (int i = 1; i <= n; i++) {
        dis[i] = lower_bound(sub + 1, sub + 1 + m, data[i]) - sub;
        idx[dis[i]] = data[i];
    }
    return m;
}
using namespace std;

int main() {
    return 0;
}
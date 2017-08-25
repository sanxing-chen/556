// 线段树区间更新
#define LSON l, m, rt << 1
#define RSON m + 1, r, rt << 1 | 1
#define lson rt << 1
#define rson rt << 1 | 1
ll sum[N << 2], add[N << 2];
// 更新答案
void Maintain(int rt) {
    sum[rt] = sum[lson] + sum[rson];
    return;
}
// 延时标记下传
void Pushdown(int rt, int m) {
    if (add[rt] != 0) { // 倍数变化 add[rt] != 1
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        sum[rt << 1] += add[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] += add[rt] * (m >> 1);
        add[rt] = 0;
    }
}
void build(int l, int r, int rt = 1) {
    add[rt] = 0; // 倍数变化更改为1
    if (l == r) {
        sum[rt] = a[rk[l]];
        return;
    }
    int m = (l + r) >> 1;
    build(LSON);
    build(RSON);
    Maintain(rt);
    return;
}
void update(int L, int R, int c, int l, int r, int rt = 1) {
    if (L <= l && r <= R) {
        add[rt] += c;
        sum[rt] += c * (r - l + 1);
        return;
    }
    Pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, c, LSON);
    if (m < R) update(L, R, c, RSON);
    Maintain(rt);
    return;
}
int query(int L, int R, int l, int r, int rt = 1) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    Pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += query(L, R, LSON);
    if (m < R) ret += query(L, R, RSON);
    return ret;
}

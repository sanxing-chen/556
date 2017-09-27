// 线段树单点更新
#define LSON l, m, rt << 1
#define RSON m + 1, r, rt << 1 | 1
#define lson rt << 1
#define rson rt << 1 | 1
ll sum[N << 2];

void Maintain(ll rt) { //更新答案
    sum[rt] = sum[lson] + sum[rson];
    return;
}
void build(int l, int r, int rt = 1) {
    if (l == r) {
        sum[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(LSON);
    build(RSON);
    Maintain(rt);
    return;
}

void update(int L, ll c, int l, int r, int rt = 1) {
    if (l == r) {
        sum[rt] = c;
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, c, LSON);
    else
        update(L, c, RSON);
    Maintain(rt);
    return;
}

ll query(int L, int R, int l, int r, int rt = 1) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    ll ret = 0;
    int m = (l + r) >> 1;
    if (L <= m) ret += query(L, R, LSON);
    if (m < R) ret += query(L, R, RSON);
    return ret;
}

#include <bits/stdc++.h>
#define endl "\n"
#define LSON l, m, rt << 1
#define RSON m + 1, r, rt << 1 | 1
#define lson rt << 1
#define rson rt << 1 | 1
const long long MAXN = 200005;
using namespace std;
long long sum[MAXN << 2], tag[MAXN << 2], Max[MAXN << 2];

void Maintain(long long rt) { //更新答案
    sum[rt] = sum[lson] + sum[rson];
    Max[rt] = max(Max[lson], Max[rson]);
    return;
}
void Pushdown(long long rt, long long m /*区间长度*/) { //标记下传
    if (tag[rt] != 0) {
        tag[lson] = tag[rt];
        tag[rson] = tag[rt];
        sum[lson] %= tag[rt];
        sum[rson] %= tag[rt];
        Max[rson] %= tag[rt];
        Max[lson] %= tag[rt];
        tag[rt] = 0;
    }
    return;
}
void PutTag(long long c, long long rt) {
    Pushdown(rt, 1);
    sum[rt] %= c;
    Max[rt] %= c;
    tag[rt] = c;
    return;
}
void build(long long l, long long r, long long rt /*=1*/) {
    Max[rt] = 0;
    tag[rt] = 0;
    if (l == r) {
        sum[rt] = 0;
        return;
    }
    long long m = (l + r) >> 1;
    build(LSON);
    build(RSON);
    // Maintain(rt);
    return;
}
inline bool Cut(long long c, long long rt) { //剪枝
    if (Max[rt] < c) return true;
    return false;
}
inline bool Check(long long l, long long r) { //判断标记是否要打
    return (l == r);
}
/****************************************************************/
void update(long long L /*需要更新的点*/, long long c, long long l, long long r, long long rt /*=1*/) { //单点
    if (L == l && l == r) {
        sum[rt] = c;
        Max[rt] = c;
        return;
    }
    Pushdown(rt, r - l + 1);
    long long m = (l + r) >> 1;
    if (L <= m)
        update(L, c, LSON);
    else
        update(L, c, RSON);
    Maintain(rt);
    return;
}

long long query(long long L, long long R, long long l, long long r, long long rt /*=1*/) { // LR为要查询的区间 下同
    if (L <= l && r <= R) {
        return sum[rt];
    }
    long long ret = 0;
    long long m = (l + r) >> 1;
    if (L <= m) ret += query(L, R, LSON);
    if (m < R) ret += query(L, R, RSON);
    return ret;
}
/****************************************************************/

void update2(long long L /*左*/, long long R /*右端点*/, long long c, long long l, long long r, long long rt /*=1*/) {
    if (L > r || R < l || Cut(c, rt)) return;
    if (L <= l && r <= R && Check(l, r)) {
        PutTag(c, rt);
        return;
    }
    Pushdown(rt, r - l + 1);
    long long m = (l + r) >> 1;
    if (L <= m) update2(L, R, c, LSON);
    if (m < R) update2(L, R, c, RSON);
    Maintain(rt);
    return;
}
long long query2(long long L, long long R, long long l, long long r, long long rt /*=1*/) {
    if (L <= l && r <= R) {
        // cout<< l<<" "<<r<<" "<<sum[rt]<<endl;
        return sum[rt];
    }
    Pushdown(rt, r - l + 1);
    long long m = (l + r) >> 1;
    long long ret = 0;
    if (L <= m) ret += query2(L, R, LSON);
    if (m < R) ret += query2(L, R, RSON);
    return ret;
}
/****************************************************************/
long long discrete(long long data[] /*初始数组*/, long long n, long long dis[] /*离散化数组*/, long long idx[]) {
    long long sub[n + 1];
    memcpy(sub, data, sizeof(sub));
    sort(sub + 1, sub + n + 1);
    long long m = unique(sub + 1, sub + n + 1) - sub - 1;
    for (long long i = 1; i <= n; i++) {
        dis[i] = lower_bound(sub + 1, sub + 1 + m, data[i]) - sub;
        idx[dis[i]] = data[i];
    }
    return m;
}
long long n, m;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    build(1, n, 1);
    for (long long i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        update(i, x, 1, n, 1);
    }
    for (long long i = 1; i <= m; i++) {
        long long op, l, r, x;
        cin >> op;
        if (op == 1) {
            cin >> l >> r;
            cout << query2(l, r, 1, n, 1) << endl; // true
        }
        if (op == 2) {
            cin >> l >> r >> x;
            update2(l, r, x, 1, n, 1); // true
        }
        if (op == 3) {
            cin >> l >> x;
            update(l, x, 1, n, 1); // true
        }
    }
    return 0;
}
for (int i = 0; i < all; i++) {
    int U = i, cnt = 0;
    for (int j = 1; j <= n; j++) vis[j] = U & 1, U >>= 1, cnt += vis[j]; //记录每种情况
    cnt = cnt & 1 ? -1 : 1;
    ans += 1LL * cnt * F;
}

for (int i = 0; i < (1 << fn); i++) {
    int cnt = 0;
    int num = 1;
    for (int j = 0; j < fn; j++) {
        if ((1 << j) & i) { //计算每种情况
            num = num * fac[j];
            cnt++;
        }
    }
    LL d = R / num;
    if (cnt & 1)
        ans -= 1LL * num * d * (d + 1) / 2;
    else
        ans += 1LL * num * d * (d + 1) / 2;
}
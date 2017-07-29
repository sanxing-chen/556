//线性筛求mu
#include <bits/stdc++.h>
using namespace std;
void init() {
    memset(vis, 0, sizeof(vis));
    mu[1] = 1;
    tot = 0;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < tot; j++) {
            if (i * prime[j] >= maxn) break;
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    return;
}

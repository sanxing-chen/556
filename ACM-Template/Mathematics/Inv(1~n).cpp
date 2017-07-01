const int mod = 1000000009;
const int maxn = 10005;
int inv[maxn];
inv[1] = 1;
for(int i = 2; i < 10000; i++)
    inv[i] = inv[mod % i] * (mod - mod / i) % mod;




    
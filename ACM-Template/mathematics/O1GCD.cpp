#define MX 111111
#define MK 444
bool isprime[MX];
int prime[MX];
int G[MK + 5][MK + 5];
int s[MX][3];
void gcd_init() {
    s[1][0] = s[1][1] = s[1][2] = 1;
    memset(isprime, 1, sizeof isprime);
    prime[0] = 0;
    for (int i = 2; i < MX; i++) {
        if (isprime[i]) {
            prime[++prime[0]] = i;
            s[i][0] = i;
            s[i][1] = s[i][2] = 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MX; j++) {
            int v = i * prime[j];
            for (int k = 0; k < 3; k++) s[v][k] = s[i][k];
            if (s[v][0] * prime[j] < MK)
                s[v][0] *= prime[j];
            else if (s[v][1] * prime[j] < MK)
                s[v][1] *= prime[j];
            else
                s[v][2] *= prime[j];
            isprime[v] = 0;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i < MK; i++)
        for (int j = 0; j < i; j++)
            if (!j)
                G[i][j] = i;
            else
                G[i][j] = G[j][i] = G[j][i % j];
}
int Gcd(int x, int y) {
    if (!x || !y) return x + y;
    if (x < MK && y < MK) return G[x][y];
    int ans = 1, d;
    for (int i = 0; i < 3; i++) {
        if (s[x][i] == 1)
            continue;
        else if (s[x][i] < MK)
            d = G[s[x][i]][y % s[x][i]];
        else if (y % s[x][i] == 0)
            d = s[x][i];
        else
            d = 1;
        y /= d;
        ans *= d;
    }
    return ans;
}
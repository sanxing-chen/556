#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
ll d;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    return (!b) ? (x = 1, y = 0, a = a) : (d = exgcd(b, a % b, y, x), y -= x * (a / b), d = d);
}
ll M, x, y, a, b, n;
int main() {
    scanf("%lld", &n);
    while (n--) {
        scanf("%lld", &M);
        ll A = 0;
        A = sqrt(M);
        ll m;
        ll ans = 0;
        for (int i = 1; i <= A; i++) {
            for (int j = 1; j <= M - i; j++) {
                x = 0, y = 0;
                m = exgcd(i * i, j, x, y);
                if (M % m) continue;
                x *= (M / m);
                y *= (M / m);
                if ((x / j + y / (i * i)) > 2)
                    ans++;
                else {
                    ll up = ceil(y * 1.0 / (i * i));
                    ll down = -x / j;
                    if (down + 1 < up) {
                        ans++;
                        continue;
                        // cout << i * i << " " << j << " " << x << " " << y << " " << m << endl;
                    }
                    // cout << down << " " << up << endl;
                    up = ceil(x * 1.0 / j);
                    down = -y / (i * i);
                    if (down + 1 < up) {
                        ans++;
                        continue;
                        //  cout << i * i << " " << j << " " << x << " " << y << " " << m << endl;
                    }
                    // cout << down << " " << up << endl;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
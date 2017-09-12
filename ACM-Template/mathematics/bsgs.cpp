#include <algorithm>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;
//给定y,z,p，计算满足Y^x ≡ Z ( mod P)的最小非负整数。
map<int, int> mp;
int solve1(ll y, int z, int p) {
    y %= p;
    ll ans = 1;
    for (int i = z; i; i >>= 1, y = y * y % p)
        if (i & 1) ans = ans * y % p;
    return ans;
}
void solve3(int y, int z, int p) {
    y %= p;
    if (!y && !z) {
        puts("1");
        return;
    }
    if (!y) {
        puts("Orz, I cannot find x!");
        return;
    }
    mp.clear();
    ll m = ceil(sqrt(p)), t = 1;
    mp[1] = m + 1;
    for (ll i = 1; i < m; i++) {
        t = t * y % p;
        if (!mp[t]) mp[t] = i;
    }
    ll tmp = solve1(y, p - m - 1, p), ine = 1;
    for (ll k = 0; k < m; k++) {
        int i = mp[z * ine % p];
        if (i) {
            if (i == m + 1) i = 0;
            printf("%lld\n", k * m + i);
            return;
        }
        ine = ine * tmp % p;
    }
    puts("Orz, I cannot find x!");
}
/*

LL D=1%C; LL g=0,d;
while(  ( d=gcd(A,C)   )  !=1 )
{
        if(B%d)return -1;
        B/=d;C/=d;
        g++;D=D*(A/d)%C;
}

*/
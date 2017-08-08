#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
ll qpow(ll a, ll b, ll p) { // return a^b %p
    ll t = 1;
    for (a %= p; b; b >>= 1LL, a = a * a % p)
        if (b & 1LL) t = t * a % p;
    return t;
}
int main() {
    ios::sync_with_stdio(false);
    ll n, k, cas = 1;
    while (cin >> n >> k) {
        ll ans = 0;
        ans = qpow(n, k, MOD);
        cout << "Case #" << cas++ << ": " << ans << endl;
    }
    return 0;
}
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
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define PI acos(-1.0)
using namespace std;
const int MOD = 1e9 + 7;
const int N = 100000;
const int INF = 0x3f3f3f3f;
int mem[N];
ll inv[N];
int main() {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    ios::sync_with_stdio(false);
    ll n, t;
    mem[1] = 1;
    for (int i = 2; i < N; i++) {
        mem[i] = (ll) mem[i - 1] * i % MOD;
    }
    inv[1] = 1;
    for (int i = 2; i < N; i++) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 4) {
            cout << n << endl;
            continue;
        }
        ll x = (sqrt(8 * n + 9.0) - 1) * 0.5;
        while ((x + 1) * (x + 2) / 2 <= 1 * n + 1) x++;
        ll gap = n - x * (x + 1) / 2 + 1;
        ll ans;
        if (gap == 0) {
            cout << mem[x] << endl;
            continue;
        }
        if (x == gap) {
            cout << (((mem[x] * ((inv[2] + MOD) % MOD)) % MOD) * (x + 2) % MOD) << endl;
            continue;
        }
        ll ni, feiwu;
        ni = (inv[x - gap + 1] + MOD) % MOD;
        ans = ((mem[x] * ni) % MOD) * (x + 1) % MOD;
        cout << ans << endl;
    }
    return 0;
}
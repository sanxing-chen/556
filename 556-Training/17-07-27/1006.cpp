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
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 2;
struct Mat {
    ll mat[N][N]; //每个Mat使用前都要memset 。  否则会出现奇奇怪怪的错误
} fuck1, fuck2;
Mat operator*(Mat a, Mat b) {
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    int i, j, k;
    for (k = 0; k < N; ++k) {
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
            }
        }
    }
    return c;
}
Mat operator^(Mat a, ll k) {
    Mat c;
    int i, j;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j) c.mat[i][j] = (i == j);

    for (; k; k >>= 1) {
        if (k & 1) c = c * a;
        a = a * a;
    }
    return c;
}
long long qpow(long long a, long long b, long long p) { // return a^b %p
    long long t = 1;
    for (a %= p; b; b >>= 1LL, a = a * a % p)
        if (b & 1LL) t = t * a % p;
    return t;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    ll n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (m == 1) {
            cout << 1 << endl;
            continue;
        }
        if (n & 1) {
            ll k = (2 * qpow(4, n / 2, MOD) - 1) % MOD;
            ll k2 = ((qpow(4, n / 2, MOD * 3) - 1 + 3 * MOD) / 3 * 2) % MOD;
            ll s = ((qpow(4, (n + 1) / 2, MOD * 3) - 1 + 3 * MOD) / 3) % MOD;
            // cout << k << " " << k2 << " " << s << endl;
            {
                ll temp[2][2] = {{k, -k2}, {0, 1}};
                REP(i, 0, 2) {
                    REP(j, 0, 2) {
                        fuck1.mat[i][j] = temp[i][j];
                    }
                }
            }
            {
                ll temp[2][2] = {{s, 0}, {1, 0}};
                REP(i, 0, 2) {
                    REP(j, 0, 2) {
                        fuck2.mat[i][j] = temp[i][j];
                    }
                }
            }
            cout << ((((fuck1 ^ (m - 2)) * fuck2).mat[0][0] + MOD) % MOD) << endl;
        } else {
            ll k = (qpow(2, n, MOD) - 1) % MOD;
            ll s = ((qpow(4, n / 2, MOD * 3) - 1 + 3 * MOD) / 3 * 2) % MOD;
            cout << (s * qpow(k, m - 2, MOD) % MOD) << endl;
        }
    }
    return 0;
}
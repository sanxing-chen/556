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
typedef pair<int, int> pii;
typedef long long ll;
const ll MOD = 2147493647;
const int INF = 0x3f3f3f3f;
const int N = 7;
struct Mat {
    ll mat[N][N]; //每个Mat使用前都要memset 。  否则会出现奇奇怪怪的错误
} fuck, you;
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
Mat operator^(Mat a, int k) {
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

int main() {
    ios::sync_with_stdio(false);
    ll t, n, a, b;
    cin >> t;
    mems(fuck.mat, 0);
    ll temp[N][N] = {{1, 2, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0}, {0, 0, 1, 2, 1, 0, 0}, {0, 0, 1, 3, 3, 1, 0}, {0, 0, 1, 4, 6, 4, 1}};
    memcpy(fuck.mat, temp, sizeof temp);
    while (t--) {
        cin >> n >> a >> b;
        a %= MOD;
        b %= MOD;
        if (n == 1) {
            cout << (a % MOD) << endl;
            continue;
        } else if (n == 2) {
            cout << (b % MOD) << endl;
            continue;
        }
        ll temp2[N][N] = {{b, 0, 0, 0, 0, 0, 0}, {a, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {3, 0, 0, 0, 0, 0, 0}, {9, 0, 0, 0, 0, 0, 0}, {27, 0, 0, 0, 0, 0, 0}, {81, 0, 0, 0, 0, 0, 0}};
        memcpy(you.mat, temp2, sizeof temp2);
        cout << (((fuck ^ (n - 2)) * you).mat[0][0] % MOD) << endl;
    }
    return 0;
}
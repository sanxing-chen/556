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
const int N = 1e2 + 10; // range to screen

ll f[N][N];
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    REP(n, 1, 30) {
        REP(m, 1, 30) {
            mems(f, 0);
            f[1][1] = f[1][2] = 1;
            REP(i, 3, 100) {
                f[1][i] = (f[1][i - 1] + 2 * f[1][i - 2]) % MOD;
            }
            REP(i, 2, 100) {
                REP(j, 1, 100 - n - 1) {
                    ll temp = 0;
                    REP(k, j, j + n) {
                        temp += f[i - 1][k];
                    }
                    f[i][j] = temp % MOD;
                }
            }
            cout << f[m][1] << " ";
        }
        cout << endl;
    }
    return 0;
}

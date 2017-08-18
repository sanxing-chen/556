
#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); ++i)
#define PER(i, a, n) for (int i = (n) -1; i >= a; --i)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int mid = 3000;
const int maxn = 2010;
int s[maxn][maxn];
/*
 * Stirling numbers of the first kind
 * 将p个物体排成k个非空循环排列的方法数
 */
void init1() {
    REP(p, 1, maxn) {
        s[p][0] = 0;
        REP(k, 1, p) {
            s[p][k] = ((ll)(p - 1) * s[p - 1][k] + s[p - 1][k - 1]);
        }
        s[p][p] = 1;
    }
}
/*
 * Stirling numbers of the second kind
 * 将p个物体划分成k个非空的不可辨别的（可以理解为盒子没有编号）集合的方法数
 */
void init2() {
    REP(p, 1, maxn) {
        s[p][0] = 0;
        REP(k, 1, p) {
            s[p][k] = ((ll) k * s[p - 1][k] + s[p - 1][k - 1]) % MOD;
        }
        s[p][p] = 1;
    }
}
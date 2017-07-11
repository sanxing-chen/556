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
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int n, d, temp;
    while (cin >> n >> d) {
        double ans = 0;
        REP(i, n) {
            cin >> temp;
            ans += sin(temp / 360.0 * (2 * PI));
        }
        ans *= d * d * 0.5;
        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}
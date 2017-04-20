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
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 1000005;
ll a[N];
int main() {
#ifdef FF
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    int nn, cas, temp;
    while (cin >> nn) {
        ll cnt = 0, ans = 0;
        for (int i = 1; i <= nn; i++) cin >> a[i];
        for (int i = nn; i > 0; i--) {
            cnt += a[i];
            if (cnt >= 0) {
                ans++;
                cnt = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
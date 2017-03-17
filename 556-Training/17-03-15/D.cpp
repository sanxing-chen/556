#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<ll, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int t, n, K;
ll L, x, a;
ll cl[100005], cr[100005];
int main() {
    ios::sync_with_stdio(false);
    vector<int> vl;
    vector<int> vr;
    cin >> t;
    while (t--) {
        vl.clear(), vr.clear();
        cin >> L >> n >> K;
        while (n--) {
            cin >> x >> a;
            if (x * 2 < L)
                while (a--) vl.push_back(x);
            else
                while (a--) vr.push_back(L - x);
        }
        sort(vl.begin(), vl.end()), sort(vr.begin(), vr.end());
        cl[0] = cr[0] = 0;
        for (int i = 1; i <= vl.size(); i++) {
            if (i <= K)
                cl[i] = vl[i - 1];
            else
                cl[i] = cl[i - K] + vl[i - 1];
        }
        for (int i = 1; i <= vr.size(); i++) {
            if (i <= K)
                cr[i] = vr[i - 1];
            else
                cr[i] = cr[i - K] + vr[i - 1];
        }
        ll ans = 2 * (cl[vl.size()] + cr[vr.size()]);
        for (int i = 0; i <= K; i++) {
            ans = min(ans, 2 * (cl[max(0, (int) vl.size() - i)] + cr[max(0, (int) vr.size() - (K - i))]) + L);
        }
        cout << ans << endl;
    }
}
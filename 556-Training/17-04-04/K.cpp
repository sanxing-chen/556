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

#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
vector<pii> v;
map<pii, bool> _mp;
bool mp[200005];
int main() {
    ios::sync_with_stdio(false);
    ll t, a, b, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        v.clear();
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            v.push_back(pii(a, b));
        }
        sort(v.begin(), v.end());
        bool fg = false;
        mems(mp, 0);
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                a = v[j].first - v[i].first;
                b = abs(v[j].second - v[i].second);
                if (mp[a + b]) {
                    fg = true;
                    break;
                } else
                    mp[a + b] = 1;
            }
            if (fg) break;
        }
        cout << (fg ? "YES" : "NO") << endl;
    }
    return 0;
}
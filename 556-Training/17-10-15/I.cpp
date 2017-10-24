#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
deque<int> v1, v2;
int main() {
    ios::sync_with_stdio(false);
    int t;
    ll l, r;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        v1.clear();
        v2.clear();
        while (l) {
            v1.push_back(l % 2);
            l >>= 1;
        }
        while (r) {
            v2.push_back(r % 2);
            r >>= 1;
        }
        reverse(all(v1));
        reverse(all(v2));
        int c = v2.size() - v1.size();
        REP(i, 0, c) v1.push_front(0);
        ll ans = 0;
        bool fg = false;
        REP(i, 0, v2.size()) {
            ans <<= 1;
            if (v1[i] || v2[i] || fg) {
                ans |= 1;
                if (!(v1[i] && v2[i])) fg = true;
            }
        }
        cout << ans << endl;
    }
}
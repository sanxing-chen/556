#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> v[40010];
int main() {
    ios::sync_with_stdio(false);
    int t, n, m, x, y, z;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        REP(i, 0, n + 1) v[i].clear();
        REP(i, 1, n) {
            cin >> x >> y >> z;
            v[x].push_back(pii(y, z));
            v[y].push_back(pii(x, z));
        }
        REP(i, 0, n + 1) sort(all(v[i]));
        int op;
        REP(i, 0, m) {
            cin >> op;
            if (op) {
                cin >> x >> y >> z;
                auto pos = lower_bound(all(v[x]), pii(y, 0));
                pos->second = z;
                pos = lower_bound(all(v[y]), pii(x, 0));
                pos->second = z;
            } else {
                cin >> x;
                int ans = 0;
                REP(i, 0, v[x].size()) {
                    ans ^= v[x][i].second;
                }
                if (!ans)
                    cout << "Boys win!" << endl;
                else
                    cout << "Girls win!" << endl;
            }
        }
    }
}
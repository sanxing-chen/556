#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 200;
const int INF = 0x3f3f3f3f;
int a[N], b[N];
vector<pii> v;
int main() {
    ios::sync_with_stdio(false);
    int t;
    int n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        REP(i, 0, n) cin >> a[i];
        cin >> m;
        REP(i, 0, m) cin >> b[i];
        v.clear();
        REP(i, 0, n) {
            int tmp = a[i];
            v.push_back(pii(tmp, -1));
            REP(j, i + 1, n) {
                tmp ^= a[j];
                v.push_back(pii(tmp, -(j - i + 1)));
            }
        }
        v.push_back(pii(0, 0));
        sort(all(v));
        // REP(i, 0, v.size()) cout << "(" << v[i].first << "," << v[i].second << ")";
        // cout << endl;
        int ans;
        REP(i, 0, m) {
            auto pos = lower_bound(all(v), pii(b[i], -INF));
            if (pos == v.end()) {
                pii tmp = v.back();
                auto now = lower_bound(all(v), pii(tmp.first, -INF));
                ans = now->second;
            } else {
                int ind = pos - v.begin();
                if (ind != 0) {
                    if (abs(v[ind - 1].first - b[i]) == abs(v[ind].first - b[i])) {
                        ans = v[ind].second;
                        PER(j, 0, ind) {
                            if (v[j].first != v[ind - 1].first) break;
                            ans = min(ans, v[j].second);
                        }
                    } else if (abs(v[ind - 1].first - b[i]) < abs(v[ind].first - b[i])) {
                        ans = v[ind - 1].second;
                        PER(j, 0, ind) {
                            if (v[j].first != v[ind - 1].first) break;
                            ans = min(ans, v[j].second);
                        }
                    } else {
                        ans = v[ind].second;
                    }

                } else {
                    ans = v[ind].second;
                }
            }
            cout << -ans << endl;
        }
        cout << endl;
    }
}
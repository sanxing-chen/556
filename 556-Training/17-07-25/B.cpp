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
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 1010000;
short cnt[26][maxn];
int ans[maxn], anss;
bool vis[26];
pair<vector<short>, pair<short, short>> big[26];
int main() {
    ios::sync_with_stdio(false);
    ll t, n, k;
    string str;
    int cas = 1;
    while (cin >> n) {
        mems(cnt, 0);
        mems(ans, 0);
        mems(vis, false);
        int sz = 0;
        REP(i, 0, n) {
            cin >> str;
            int temp;
            for (int j = str.size() - 1, k = 0; j >= 0; j--, k++) {
                temp = str[j] - 'a';
                cnt[temp][k]++;
                int kk = k;
                while (cnt[temp][kk] == 26) {
                    cnt[temp][kk] = 0;
                    cnt[temp][kk + 1]++;
                    sz = max(sz, kk + 1);
                    kk += 1;
                }
                sz = max(sz, k);
            }
            if (str.size() > 1) {
                vis[str[0] - 'a'] = true;
            }
        }
        REP(i, 0, 26) {
            big[i].first.clear();
            big[i].second = pii(vis[i], i);
            PER(j, 0, sz + 1) {
                big[i].first.push_back(cnt[i][j]);
            }
        }
        sort(big, big + 26, greater<pair<vector<short>, pair<short, short>>>());
        if (big[25].second.first) {
            int pos = -1;
            PER(i, 0, 25) {
                if (!big[i].second.first) {
                    pos = i;
                    break;
                }
            }
            REP(i, pos, 25) {
                swap(big[i], big[i + 1]);
            }
        }
        sz++;
        REP(i, 0, 26) {
            int p = big[i].first.size();
            REP(j, 0, p) {
                ans[p - j] += big[i].first[j] * (25 - i);
            }
        }
        anss = ans[sz--];
        while (sz > 0) {
            anss = ((ll) ans[sz--] + (ll) anss * 26) % MOD;
        }
        cout << "Case #" << cas++ << ": " << anss << endl;
    }
    return 0;
}
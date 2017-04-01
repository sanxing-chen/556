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
bool vis[100005], flag, can;
int cnt[100005][30], _cnt[30];
int main() {
    // freopen("1012.in", "r", stdin);
    // freopen("L.out", "w", stdout);

    ios::sync_with_stdio(false);
    string str, pat;
    int cas, n, m;
    cin >> cas;
    while (cas--) {
        cin >> n >> m;
        cin >> str >> pat;
        mems(cnt, 0), mems(_cnt, 0);
        cnt[1][str[0] - 'a']++;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                cnt[i + 1][j] = cnt[i][j];
            }
            cnt[i + 1][str[i] - 'a']++;
        }
        for (int i = 0; i < m; i++) {
            _cnt[pat[i] - 'a']++;
        }
        mems(vis, true);
        for (int i = n - m + 1; i < n; i++) vis[i] = false;
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j < 26; j++) {
                if (_cnt[j] != cnt[i + m][j] - cnt[i][j]) {
                    vis[i] = false;
                    break;
                }
            }
            if (vis[i])
                for (int j = i; j < i + m; j++) {
                    if (str[j] != pat[j - i] && j + 1 < i + m) {
                        if (str[j + 1] == pat[j - i] && str[j] == pat[j - i + 1])
                            j++;
                        else {
                            vis[i] = false;
                            break;
                        }
                    }
                }
        }
        for (int i = 0; i < n; i++) {
            cout << vis[i];
        }
        cout << endl;
    }
    return 0;
}
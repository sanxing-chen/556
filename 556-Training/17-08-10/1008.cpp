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
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int pre[6000];
int main() {
    ios::sync_with_stdio(false);
    int t, m;
    string str;
    cin >> t;
    while (t--) {
        cin >> m;
        cin >> str;
        int sz = str.size();
        int ans = 0;
        REP(i, 1, sz) {
            int len = 0;
            int num = 0;
            int head = 0, rear = 0;
            pre[rear++] = abs(str[i] - str[i - 1]);
            num += pre[0];
            if (num <= m) len = 1;
            for (int j = i + 1, k = i - 2; j < sz && k >= 0; ++j, --k) {
                pre[rear++] = abs(str[j] - str[k]);
                num += pre[rear - 1];
                while (num > m && head < rear) {
                    num -= pre[head++];
                }
                len = max(len, rear - head);
            }
            ans = max(len, ans);
        }
        REP(i, 1, sz - 1) {
            int len = 0;
            int num = 0;
            int head = 0, rear = 0;
            pre[rear++] = abs(str[i + 1] - str[i - 1]);
            num += pre[0];
            if (num <= m) len = 1;
            for (int j = i + 2, k = i - 2; j < sz && k >= 0; ++j, --k) {
                pre[rear++] = abs(str[j] - str[k]);
                num += pre[rear - 1];
                while (num > m && head < rear) {
                    num -= pre[head++];
                }
                len = max(len, rear - head);
            }
            ans = max(len, ans);
        }
        cout << ans << endl;
    }
    return 0;
}
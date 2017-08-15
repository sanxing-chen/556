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
ll br[20000], cnt[20000];
map<int, int> real;
int main() {
    ios::sync_with_stdio(false);
    int t, n, m, temp;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        REP(i, 0, m + 1) {
            cin >> br[i];
        }
        mems(cnt, 0);
        real.clear();
        cnt[0] = 1;
        REP(i, 1, m + 1) {
            if (br[i] - cnt[i] > 0) {
                int temp = real[i] = br[i] - cnt[i];
                REP(k, 1, temp + 1) {
                    int temp2 = i;
                    PER(j, temp2, m + 1) {
                        cnt[j] += cnt[j - temp2];
                    }
                }
            }
        }
        bool flag = true;
        for (auto i : real) {
            if (flag) {
                cout << i.first;
                int temp = i.second - 1;
                while (temp--) cout << " " << i.first;
                flag = false;
            } else {
                int temp = i.second;
                while (temp--) cout << " " << i.first;
            }
            // cout << i.first << " " << i.second << endl;
        }
        cout << endl;
    }
    return 0;
}
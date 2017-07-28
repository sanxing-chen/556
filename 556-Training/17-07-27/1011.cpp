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
pii ar[600];
bool vis[410][410];
int main() {
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        ll ans = 0;
        mems(vis, false);
        REP(i, 0, n) {
            cin >> ar[i].first >> ar[i].second;
            ar[i].first += 100;
            ar[i].second += 100;
            vis[ar[i].first][ar[i].second] = true;
        }
        int d, x, y, posx1, posy1, posx2, posy2;
        REP(i, 0, n) {
            REP(j, 0, n) {
                if (i == j) continue;
                x = ar[i].first - ar[j].first;
                y = ar[i].second - ar[j].second;
                swap(x, y);
                y = -y;
                posx1 = ar[i].first + x, posy1 = ar[i].second + y;
                posx2 = ar[j].first + x, posy2 = ar[j].second + y;
                if (posx1 >= 0 && posx2 >= 0 && posy1 >= 0 && posy2 >= 0 && vis[posx1][posy1] && vis[posx2][posy2])
                    ans++;
                x = -x;
                y = -y;
                posx1 = ar[i].first + x, posy1 = ar[i].second + y;
                posx2 = ar[j].first + x, posy2 = ar[j].second + y;
                if (posx1 >= 0 && posx2 >= 0 && posy1 >= 0 && posy2 >= 0 && vis[posx1][posy1] && vis[posx2][posy2])
                    ans++;
            }
        }
        cout << ans / 8 << endl;
    }
    return 0;
}
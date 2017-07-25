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
const int maxn = 10000;
priority_queue<int, vector<int>, greater<int>> q;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    ll t, n, k;
    while (cin >> n >> k) {
        while (!q.empty()) q.pop();
        REP(i, 1, n + 1) {
            q.push(i);
        }
        v.clear();
        while (k--) {
            bool flag = false;
            if (v.size() == n - 1) {
                flag = true;
            }
            int top = q.top();
            cout << top << endl;
            q.pop();
            if (flag) {
                for (auto i : v) {
                    q.push(i);
                }
                v.clear();
            }
            v.push_back(top);
        }
    }
    return 0;
}

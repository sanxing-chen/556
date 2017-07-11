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
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int n, ans, temp;
    vector<int> v;
    cin >> n;
    ans = 0;
    v.clear();
    REP(i, n) {
        cin >> temp;
        while (temp) {
            v.push_back(temp % 256);
            temp /= 256;
        }
    }
    for (auto j : v)
        if (j == 97) ans++;
    cout << ans << endl;
    return 0;
}
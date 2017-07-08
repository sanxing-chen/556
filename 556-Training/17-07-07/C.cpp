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
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int t;
    double a, b;
    long long ans = 0;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a <= b) {
            cout << "0.000000" << endl;
        } else
            cout << fixed << setprecision(6) << 1 + log(a / b) << endl;
    }
    return 0;
}
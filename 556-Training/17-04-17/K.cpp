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
string str[] = {"Cleveland Cavaliers ",
                "Golden State Warriors ",
                "San Antonio Spurs ",
                "Miami Heat ",
                "Miami Heat ",
                "Dallas Mavericks ",
                "L.A. Lakers ",
                "L.A. Lakers ",
                "Boston Celtics ",
                "San Antonio Spurs ",
                "Miami Heat ",
                "San Antonio Spurs ",
                "Detroit Pistons ",
                "San Antonio Spurs ",
                "L.A. Lakers ",
                "L.A. Lakers ",
                "L.A. Lakers ",
                "San Antonio Spurs ",
                "Chicago Bulls ",
                "Chicago Bulls ",
                "Chicago Bulls ",
                "Houston Rockets ",
                "Houston Rockets ",
                "Chicago Bulls ",
                "Chicago Bulls ",
                "Chicago Bulls ",
                "Detroit Pistons ",
                "Detroit Pistons ",
                "L.A. Lakers ",
                "L.A. Lakers ",
                "Boston Celtics ",
                "L.A. Lakers ",
                "Boston Celtics ",
                "Philadelphia 76ers ",
                "L.A. Lakers ",
                "Boston Celtics ",
                "L.A. Lakers ",
                "Seattle Sonics ",
                "Washington Bullets ",
                "Portland Trail Blazers ",
                "Boston Celtics ",
                "Golden State Warriors ",
                "Boston Celtics ",
                "New York Knicks ",
                "L.A. Lakers ",
                "Milwaukee Bucks ",
                "New York Knicks ",
                "Boston Celtics ",
                "Boston Celtics ",
                "Philadelphia 76ers ",
                "Boston Celtics ",
                "Boston Celtics ",
                "Boston Celtics ",
                "Boston Celtics ",
                "Boston Celtics ",
                "Boston Celtics ",
                "Boston Celtics ",
                "Boston Celtics ",
                "St. Louis Hawks ",
                "Boston Celtics ",
                "Philadelphia Warriors ",
                "Syracuse Nats ",
                "Minneapolis Lakers ",
                "Minneapolis Lakers ",
                "Minneapolis Lakers ",
                "Rochester Royals ",
                "Minneapolis Lakers ",
                "Minneapolis Lakers ",
                "Baltimore Bullets ",
                "Philadelphia Warriors "};
int main() {
    ios::sync_with_stdio(false);
    map<string, int> st;
    for (int i = 0; i < 70; i++) {
        st[str[i].substr(0, str[i].size() - 1)]++;
    }
    int n;
    string pat;
    cin >> n;
    getline(cin, pat);
    for (int i = 1; i <= n; i++) {
        getline(cin, pat);
        cout << "Case #" << i << ": " << st[pat] << endl;
    }
    return 0;
}
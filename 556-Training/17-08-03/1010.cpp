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
string s[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
map<string, int> mp;
int main() {
    ios::sync_with_stdio(false);
    int t;
    string str[7];
    cin >> t;
    REP(i, 0, 10) {
        mp[s[i]] = i;
    }
    while (t--) {
        REP(i, 0, 7) {
            cin >> str[i];
        }

        string a, b, c, d;
        // 1
        if (str[0][1] == 'X')
            a += '1';
        else
            a += '0';
        if (str[0][6] == 'X')
            b += '1';
        else
            b += '0';
        if (str[0][13] == 'X')
            c += '1';
        else
            c += '0';
        if (str[0][18] == 'X')
            d += '1';
        else
            d += '0';
        // 2
        if (str[1][0] == 'X')
            a += '1';
        else
            a += '0';
        if (str[1][5] == 'X')
            b += '1';
        else
            b += '0';
        if (str[1][12] == 'X')
            c += '1';
        else
            c += '0';
        if (str[1][17] == 'X')
            d += '1';
        else
            d += '0';
        // 3
        if (str[1][3] == 'X')
            a += '1';
        else
            a += '0';
        if (str[1][8] == 'X')
            b += '1';
        else
            b += '0';
        if (str[1][15] == 'X')
            c += '1';
        else
            c += '0';
        if (str[1][20] == 'X')
            d += '1';
        else
            d += '0';
        // 4
        if (str[3][1] == 'X')
            a += '1';
        else
            a += '0';
        if (str[3][6] == 'X')
            b += '1';
        else
            b += '0';
        if (str[3][13] == 'X')
            c += '1';
        else
            c += '0';
        if (str[3][18] == 'X')
            d += '1';
        else
            d += '0';
        // 5
        if (str[4][0] == 'X')
            a += '1';
        else
            a += '0';
        if (str[4][5] == 'X')
            b += '1';
        else
            b += '0';
        if (str[4][12] == 'X')
            c += '1';
        else
            c += '0';
        if (str[4][17] == 'X')
            d += '1';
        else
            d += '0';
        // 6
        if (str[4][3] == 'X')
            a += '1';
        else
            a += '0';
        if (str[4][8] == 'X')
            b += '1';
        else
            b += '0';
        if (str[4][15] == 'X')
            c += '1';
        else
            c += '0';
        if (str[4][20] == 'X')
            d += '1';
        else
            d += '0';

        // 7
        if (str[6][1] == 'X')
            a += '1';
        else
            a += '0';
        if (str[6][6] == 'X')
            b += '1';
        else
            b += '0';
        if (str[6][13] == 'X')
            c += '1';
        else
            c += '0';
        if (str[6][18] == 'X')
            d += '1';
        else
            d += '0';
        cout << mp[a] << mp[b] << ":" << mp[c] << mp[d] << endl;
    }
    return 0;
}
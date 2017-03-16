#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define LL long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int main() {
    int n;
    for (n = 4; n < 100; n++) {
        if (n < 4)
            puts("-1");
        else if (n == 4) {
            puts("1 * 2");
            puts("5 + 3");
            puts("6 + 4");
        } else if (n == 5) {
            puts("1 / 2");
            puts("6 / 3");
            puts("4 - 7");
            puts("5 * 8");
        } else if (n == 6) {
            puts("1 * 2");
            puts("3 * 7");
            puts("8 / 4");
            puts("9 - 5");
            puts("10 - 6");
        } else if (n == 7) {
            puts("1 * 2");
            puts("3 / 4");
            puts("8 - 9");
            puts("5 + 6");
            puts("10 / 11");
            puts("12 * 7");
        } else if (n == 8) {
            puts("1 - 2");
            for (int i = 3; i < 6; i++) {
                cout << i << " * " << i + 6 << endl;
            }
            puts("12 + 6");
            puts("13 + 7");
            puts("14 + 8");
        } else if (n == 9) {
            for (int i = 0; i < 6; i += 2) {
                cout << i + 1 << " / " << i + 2 << endl;
            }
            puts("10 + 11");
            puts("13 + 12");
            puts("7 + 8");
            puts("15 + 9");
            puts("16 - 14");
        } else if (n > 9 && n <= 12) {
            int res = 24 - 2 * n;
            int cnt = 1, base = n;
            for (int i = 0; i < res; i++) {
                cout << cnt++ << " / " << cnt++ << endl;
                base++;
            }
            if (n != 10) {
                cout << cnt++ << " - " << cnt++ << endl;
                base++;
            }
            for (int i = cnt; i <= n - 2; i++) {
                cout << base++ << " * " << i << endl;
            }
            cnt = base;
            cout << n - 1 << " + " << n << endl;
            base++;
            for (int i = 0; i < res; i++) {
                cout << i + n + 1 << " + " << base++ << endl;
            }
            if (n != 10) {
                cout << cnt << " + " << base++ << endl;
            }
        } else if (n < 15) {
            int res = 2 * n - 24;
            int cnt = 1, base = n;
            for (int i = 0; i < res; i++) {
                cout << cnt++ << " / " << cnt++ << endl;
                base++;
            }
            cout << cnt++ << " - " << cnt++ << endl;
            base++;
            for (int i = cnt; i <= n - 2; i++) {
                cout << base++ << " * " << i << endl;
            }
            cnt = base;
            cout << n - 1 << " + " << n << endl;
            base++;
            for (int i = 0; i < res; i++) {
                cout << base++ << " - " << i + n + 1 << endl;
            }
            if (n != 10) {
                cout << cnt << " + " << base++ << endl;
            }
        } else {
            int base = n, cnt = 1;
            int x[3];
            for (int i = 0; i < 3; i++) {
                cout << cnt++ << " + " << cnt++ << endl;
                base++;
                cout << base << " / " << cnt++ << endl;
                base++;
                x[i] = base;
            }
            cout << cnt++ << " + " << cnt++ << endl;
            base++;
            cout << base << " + " << cnt++ << endl;
            base++;
            cout << base << " / " << cnt++ << endl;
            base++;
            for (int i = 0; i < 3; i++) {
                cout << base++ << " * " << x[i] << endl;
            }
            if (n == 15) {
                cout << base++ << " * " << cnt++ << endl;
                cout << base++ << " / " << cnt++ << endl;
            } else {
                int mark = base;
                cout << cnt++ << " - " << cnt++ << endl;
                base++;
                for (int i = cnt; i <= n; i++) {
                    cout << base++ << " * " << i << endl;
                }
                cout << mark << " + " << base << endl;
            }
        }
    }
}
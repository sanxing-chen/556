#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
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
void merge(auto &a, auto &b) {
    if (a.size() < b.size()) swap(a, b);
    while (!b.empty()) {
        a.push(b.top());
        b.pop();
    }
}
priority_queue<pii> l1, l2;
int main() {
    ios::sync_with_stdio(false);
    string op, st;
    int nn, num, cas = 1;
    while (cin >> nn && nn) {
        bool fg = false;
        string foc;
        while (!l1.empty()) l1.pop();
        while (!l2.empty()) l2.pop();
        cout << "Case #" << cas++ << ":" << endl;
        for (int i = 0; i < nn; i++) {
            cin >> op >> st;
            if (op == "push") {
                cin >> num;
                if (st == "A") {
                    if (fg && foc == "A") {
                        merge(l2, l1);
                        fg = false;
                    }
                    l1.push(pii(i, num));
                } else {
                    if (fg && foc == "B") {
                        merge(l1, l2);
                        fg = false;
                    }
                    l2.push(pii(i, num));
                }
            } else if (op == "merge") {
                cin >> st;
                if (st == "B") {
                    fg = true, foc = "B";

                } else {
                    fg = true, foc = "A";
                }
            } else if (op == "pop") {
                if (fg) {
                    if (foc == "B") {
                        merge(l1, l2);
                    } else {
                        merge(l2, l1);
                    }
                    fg = false;
                }
                if (st == "A") {
                    cout << l1.top().second << endl;
                    l1.pop();
                } else {
                    cout << l2.top().second << endl;
                    l2.pop();
                }
            }
        }
    }
    return 0;
}
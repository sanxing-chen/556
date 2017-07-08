#include <algorithm>
#include <iostream>
using namespace std;
int T;
int m[100][100], n[100][100];
bool check() {
    bool flag = true;
    for (int i = 1; i <= 6; i++) {
        for (int j = 2; j <= 4; j++) {
            if (m[i][j] != m[i][j - 1]) return false;
        }
    }
    return true;
}
void copy() {
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 4; j++) {
            m[i][j] = n[i][j];
        }
    }
}
void swap1() {
    int t1, t2;
    t1 = m[1][1];
    t2 = m[1][2];
    m[1][1] = m[6][1];
    m[1][2] = m[6][2];
    m[6][1] = m[3][4];
    m[6][2] = m[3][3];
    m[3][4] = m[5][1];
    m[3][3] = m[5][2];
    m[5][1] = t1;
    m[5][2] = t2;
}
void swap2() {
    int t1, t2;
    t1 = m[1][2];
    t2 = m[1][4];
    m[1][2] = m[2][2];
    m[1][4] = m[2][4];
    m[2][2] = m[3][2];
    m[2][4] = m[3][4];
    m[3][2] = m[4][2];
    m[3][4] = m[4][4];
    m[4][2] = t1;
    m[4][4] = t2;
}
void swap3() {
    int t1, t2;
    t1 = m[2][1];
    t2 = m[2][2];
    m[2][1] = m[6][3];
    m[2][2] = m[6][1];
    m[6][3] = m[4][4];
    m[6][1] = m[4][3];
    m[4][4] = m[5][2];
    m[4][3] = m[5][4];
    m[5][2] = t1;
    m[5][4] = t2;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        for (int i = 1; i <= 6; i++) {
            for (int j = 1; j <= 4; j++) {
                cin >> m[i][j];
                n[i][j] = m[i][j];
            }
        }
        if (check()) {
            cout << "YES" << endl;
            continue;
        } else {
            swap1();
            if (check()) {
                cout << "YES" << endl;
                continue;
            }
            swap1();
            swap1();
            if (check()) {
                cout << "YES" << endl;
                continue;
            }
            copy();
            swap2();
            if (check()) {
                cout << "YES" << endl;
                continue;
            }
            swap2();
            swap2();
            if (check()) {
                cout << "YES" << endl;
                continue;
            }
            copy();
            swap3();
            if (check()) {
                cout << "YES" << endl;
                continue;
            }
            swap3();
            swap3();
            if (check()) {
                cout << "YES" << endl;
                continue;
            }
            cout << "NO" << endl;
        }
    }
    return 0;
}
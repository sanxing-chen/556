#include <cstring>
#include <iostream>
#include <string>

using namespace std;
int T, n, ans, m;
string s[100];
int dfs() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '.' && s[i][j] != 'B') {
                int x = 0;
                while (i + x < n && j + x < m && s[i + x][j + x] != '.' && s[i + x][j + x] != 'B') {
                    if (s[i + x][j + x] == 'G')
                        s[i + x][j + x] = 'B';
                    else
                        s[i + x][j + x] = '.';
                    x++;
                }
                ans++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '.') {
                int x = 0;
                while (i + x < n && j - x > -1 && s[i + x][j - x] != '.') {
                    s[i + x][j - x] = '.';
                    x++;
                }
                ans++;
            }
        }
    }
    return ans;
}
int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> s[i];
        m = s[0].length();
        ans = 0;
        cout << dfs() << "\n";
    }
    return 0;
}
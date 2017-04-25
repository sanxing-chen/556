#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    long long ans, temp, a, b;
    cin >> a;
    while (a--) {
        cin >> b;
        ans = 0;
        for (int i = 0; i < b; i++) {
            cin >> temp;
            if (temp % 8 == 7)
                ans ^= temp + 1;
            else if (temp % 8 == 0)
                ans ^= temp - 1;
            else
                ans ^= temp;
        }
        if (ans) {
            cout << "First player wins." << endl;
        } else {
            cout << "Second player wins." << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("data.in", "w", stdout);
    const int N = 1000000;
    cout << N << endl;
    for (int i = 0; i < N; i++) {
        cout << rand() % (int) (1e9 + 7) << endl;
    }
}
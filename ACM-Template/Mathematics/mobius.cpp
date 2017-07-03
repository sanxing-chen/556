#include <cstdlib>
#include <iostream>
using namespace std;
int mobi(int n) {
    int m = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            m *= -1;
            int k = 0;
            do {
                k++;
                if (k > 1) {
                    m = 0;
                    break;
                }
                n /= i;
            } while (n % i == 0);
        }
    }
    if (n > 1) m *= -1;
    return m;
}
int main() {
    int n;
    while (cin >> n) {
        cout << mobi(n) << endl;
    }
    return 0;
}
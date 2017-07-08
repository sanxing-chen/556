#include <bits/stdc++.h>
using namespace std;
#define N 99999 // range to screen
vector<long long> prime;
bool vis[N] = {true, true};
void screen() {
    for (long long i = 2; i < N; i++) {
        if (!vis[i]) prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] < N; j++) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    screen();
    cout << prime[3000 - 1] << endl; // 3000th prime
}
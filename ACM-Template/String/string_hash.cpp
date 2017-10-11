// 字符串哈希，可求出一个字符串中所有子串哈希值。
#define ull unsigned long long
string str;
ull xp[maxn], hash0[maxn];

void init() {
    xp[0] = 1;
    for (int i = 1; i < maxn; i++) xp[i] = xp[i - 1] * 175;
}

ull get_hash(int i, int L) {
    return hash0[i] - hash0[i + L] * xp[L];
}

int main() {
    init();
    cin >> str;
    int n = str.size();
    hash[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        hash0[i] = hash0[i + 1] * 175 + (str[i] - 'a' + 1);
    }
    now = get_hash(pos, l);
}
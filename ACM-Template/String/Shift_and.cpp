// Shift_and 匹配字符串

#include <bitset>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
bitset<1005> bst_b[128]; //按照题目要求更换，模式串字符数
// s为目标串 p为模式串
int shift_and(string s, int len_s, string p, int len_p) { //如果速度慢可以直接写到主函数中
    bitset<1005> bst_d;
    for (int i = 0; i < len_p; i++) {
        bst_b[p[i]].set(i);
    }
    for (int i = 0; i < len_s; i++) {
        bst_d = bst_d << 1;
        bst_d.set(0);                      //将第一位设置为1
        bst_d = bst_d & bst_b[s[i] - '0']; //与运算判断它是否是后缀
        if (bst_d[n - 1] == 1) {
            // 输出字符串
            // char tmp = s[i + 1];
            // s[i + 1] = '\0';
            // cout << s + i + 1 - len_p << endl;
            // s[i + 1] = tmp;
            return s + i - n + 1; //返回找到的字符串首地址，若有多个可以储存到vector中
        }
    }
    return 0;
}
string mode;
string strr;
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 0; i < 128; i++) {
            bst_b[i].reset();
        }
        // memset(B, 0, (B));
        cin >> mode;
        cin >> sstr;
        shift_and(sstr, strr.size(), mode, mode.size());
    }
    return 0;
}

// char版本
// Shift_and 匹配字符串

#include <bitset>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
bitset<1005> bst_b[128]; //按照题目要求更换，模式串字符数
// s为目标串 p为模式串
int shift_and(char s[], int len_s, char p[], int len_p) { //如果速度慢可以直接写到主函数中
    bitset<1005> bst_d;
    for (int i = 0; i < len_p; i++) {
        bst_b[p[i]].set(i);
    }
    for (int i = 0; i < len_s; i++) {
        bst_d = bst_d << 1;
        bst_d.set(0);                      //将第一位设置为1
        bst_d = bst_d & bst_b[s[i] - '0']; //与运算判断它是否是后缀
        if (bst_d[n - 1] == 1) {
            // 输出字符串
            // char tmp = s[i + 1];
            // s[i + 1] = '\0';
            // cout << s + i + 1 - len_p << endl;
            // s[i + 1] = tmp;
            return s + i - n + 1; //返回找到的字符串首地址，若有多个可以储存到vector中
        }
    }
    return 0;
}
char mode[1005];
char strr[1005];
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 0; i < 128; i++) {
            bst_b[i].reset();
        }
        // memset(B, 0, (B));
        cin >> mode;
        cin >> sstr;
        shift_and(sstr, strlen(sstr), mode, strlen(mode));
    }
    return 0;
}

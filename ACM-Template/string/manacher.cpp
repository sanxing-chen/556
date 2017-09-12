
void findBMstr(string &str) {
    int *p = new int[str.size() + 1]; //新建一个数组，记录每个元素向左向右扩张的位置
    memset(p, 0, sizeof(p));

    int mx = 0, id = 0;
    for (int i = 1; i <= str.size(); i++) {
        if (mx > i) {
            p[i] = (p[2 * id - i] < (mx - i) ? p[2 * id - i] : (mx - i));
        } else {
            p[i] = 1;
        }

        while (str[i - p[i]] == str[i + p[i]]) p[i]++;

        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }
    int max = 0, ii;
    for (int i = 1; i < str.size(); i++) {
        if (p[i] > max) {
            ii = i;
            max = p[i];
        }
    }

    max--;

    cout << max << endl;
    //输出最长回文子串长度

    int start = ii - max;
    int end = ii + max;
    for (int i = start; i <= end; i++) {
        if (str[i] != '#') {
            cout << str[i]; //输出字符串，若需要计算长度加入count
        }
    }
    cout << endl;
    // 输出最长回文字符串
    delete p;
}

int main() {
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    string str0;
    str0 += "$#"; //防止越界
    for (int i = 0; i < str.size(); i++) {
        str0 += str[i];
        str0 += "#";
    }
    cout << str0 << endl; //处理后的字符串
    findBMstr(str0);
    return 0;
}
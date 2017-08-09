//最小表示法，返回初始位置在原串中的位置
string s;
int getmin(string s) {
    int len = s.size();
    int i = 0;
    int j = 1, k = 0;
    while (i < len && j < len && k < len) {
        int t = s[(i + k) % len] - s[(j + k) % len];
        if (!t) { //相等
            k++;
        } else {
            t > 0 ? i = i + k + 1 : j = j + k + 1; // i的字典序是否比j大
            if (i == j) {
                j++;
            }
            k = 0;
        }
    }
    return i < j ? i : j;
}
//最大表示法，同上
int getmax(string s) {
    int len = s.size();
    int i = 0;
    int j = 1, k = 0;
    while (i < len && j < len && k < len) {
        int t = s[(i + k) % len] - s[(j + k) % len];
        if (!t) { //相等
            k++;
        } else {
            t < 0 ? i = i + k + 1 : j = j + k + 1; // i的字典序是否比j小
            if (i == j) {
                j++;
            }
            k = 0;
        }
    }
    return i < j ? i : j;
}
const int N = 1000;
int seq[N];
int LIS(vector<int> a) {
    int pos, len = 0;
    for (auto i : a) {
        // pos = lower_bound(seq, seq + len, i) - seq; // 上升
        // pos = upper_bound(seq, seq + len, i) - seq; // 不下降
        seq[pos] = i;
        len = max(len, pos + 1); // 是否成为最大的元素使 LIS 增长，如无，则保留原来的长度
    }
    return len;
}
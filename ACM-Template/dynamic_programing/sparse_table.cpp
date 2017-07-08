// RMQ 问题的 ST 算法，建表复杂度 O(nlogn)，查询复杂度 O(1)
const int mx = 100000 + 10; //数组最大长度
int n;                      //数组长度
ll a[mx];                   //数组内容

int st[mx][30]; // DP数组 维护最小
void initRMQ() {
    for (int i = 0; i < n; i++) st[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) //使用位运算加速
        for (int i = 0; i + (1 << j) - 1 < n; i++) st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int RMQ(int u, int v) {
    int k = (int) (log(v - u + 1.0) / log(2.0)); //类型转换优先级高，除法整体要加括号
    return min(st[u][k], st[v - (1 << k) + 1][k]);
}

// 保存最小元素的下标
void initRMQIndex() {
    for (int i = 0; i < n; i++) st[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i + (1 << j) - 1 < n; i++)
            st[i][j] = a[st[i][j - 1]] < a[st[i + (1 << (j - 1))][j - 1]] ? st[i][j - 1] : st[i + (1 << (j - 1))][j - 1];
}

int RMQIndex(int s, int v) //返回最小值的下标
{
    int k = int(log(v - s + 1.0) / log(2.0));
    return a[st[s][k]] < a[st[v - (1 << k) + 1][k]] ? st[s][k] : st[v - (1 << k) + 1][k];
}
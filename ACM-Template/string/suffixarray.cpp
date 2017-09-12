/*
 2016.7.31
 rk的有效信息从0到n-1
 sa,ht的有效信息从1到n
 在传参的时候要多传一位*/

const int maxn = 100000 + 5;
int rk[maxn], sa[maxn], ht[maxn], wa[maxn], wb[maxn], wx[maxn], wv[maxn];

bool isq(int *r, int a, int b, int len) {
    return r[a] == r[b] && r[a + len] == r[b + len];
}

bool isEqual(int *r, int a, int b, int len) {
    return r[a] == r[b] && r[a + len] == r[b + len];
}
// r数组有效信息为0~n-1，m为（数组中最大值的上界+1)
void getSa(char r[], int n, int m) {
    int i, j, p, *t, *x = wa, *y = wb;
    for (i = 0; i < m; ++i) wx[i] = 0;
    for (i = 0; i < n; ++i) ++wx[x[i] = r[i]];
    for (i = 1; i < m; ++i) wx[i] += wx[i - 1];
    for (i = n - 1; i >= 0; --i) sa[--wx[x[i]]] = i;
    for (j = 1, p = 0; p < n; j <<= 1, m = p) {
        for (p = 0, i = n - j; i < n; ++i) y[p++] = i;
        for (i = 0; i < n; ++i) sa[i] >= j ? y[p++] = sa[i] - j : 0;
        for (i = 0; i < m; ++i) wx[i] = 0;
        for (i = 0; i < n; ++i) ++wx[wv[i] = x[y[i]]];
        for (i = 1; i < m; ++i) wx[i] += wx[i - 1];
        for (i = n - 1; i >= 0; --i) sa[--wx[wv[i]]] = y[i];
        p = 1, t = x, x = y, y = t;
        x[sa[0]] = 0;
        for (i = 1; i < n; ++i) x[sa[i]] = isEqual(y, sa[i], sa[i - 1], j) ? p - 1 : p++;
    }
}

void getHet(char r[], int n) {
    int i, j, k = 0;
    for (i = 1; i <= n; ++i) rk[sa[i]] = i;
    for (i = 0; i < n; ht[rk[i++]] = k) {
        k = k > 0 ? k - 1 : 0;
        j = sa[rk[i] - 1];
        while (r[i + k] == r[j + k]) ++k;
    }
}
int main() {
    char s[maxn] = "banana";
    int len = strlen(s);

    //用法
    getSa(s, len + 1, 'z' + 1); //对于从0开始的字符串s，长度为len，最大值为'z'
    getHet(s, len);             //当获取过Sa数组后 对于从0开始的字符串，长度为len

    //备注：sa[]和rk符合逆运算 即同时满足sa[i]=j rk[j]=i
    for (int i = 1; i <= len; i++) {
        printf("%d%c", sa[i], " \n"[i == len]);
    } // 输出sa数组 下标从 1~len 值为：5 3 1 0 4 2

    for (int i = 0; i < len; i++) {
        printf("%d%c", rk[i], " \n"[i == len - 1]);
    } // 输出rk数组 下标从 0~len-1 值为：4 3 6 2 5 1

    for (int i = 1; i <= len; i++) {
        printf("%d%c", ht[i], " \n"[i == len]);
    } // 输出ht数组 下标从 1~len 值为：0 1 3 0 0 2
}

// 1、基本定义。
// 子串：字符串S的子串r[i...j]。
// 后缀：以i开始的后缀表示为Suffix(i)。
// 大小比较：按字典序。
// 后缀数组：SA是一个一维数组。将S的后缀从小到大排序后，后缀的开头位置顺次放入SA。(SA[i]=j：排在第i个的是Suffix(j))
// 名词数组：Rank[i]是Suffix(i)在后缀中从小到大排列的名次。(Rank[i]=j：Suffix(i)排在第j个)
// 后缀数组和名次数组为互逆运算：设Rank[i]=j，则SA[j]=i。
// 2、倍增算法。
// 目的：设字符串长度为n，在O(nlog2n)求出SA数组和Rank数组。
// 3、后缀数组的应用。
// height数组：height[i]=Suffix(sa[i-1])和Suffix(sa[i])的最长公共前缀，也就是排名相邻的两个后缀的最长公共前缀。
// h数组：h[i]=height[rank[i]]=Suffix(i)和在它前一名的后缀的最长公共前缀。
// h数组的性质：h[i]>=h[i-1]-1。
// 证明：设Suffix(k)是排在Suffix(i-1)前一名的后缀，则它们的最长公共前缀就是h[i-1]。那么Suffix(k+1)将排在Suffix(i)的前面。
// a、若Suffix(k)与Suffix(i-1)的最长公共前缀<=1，即h[i-1]<=1，h[i]>=0显然成立。
// b、若Suffix(k)与Suffix(i-1)的最长公共前缀>=2，Suffix(k)与Suffix(i-1)同时去掉首字符得到Suffix(k+1)
// 与Suffix(i)，则Suffix(k+1)排在Suffix(i)的前面，且Suffix(k+1)与Suffix(i)的最长公共前缀=h[i-1]-1。
// 设Suffix(t)是排在Suffix(i)前一名的后缀，则它们的最长公共前缀就是h[i]，那么Suffix(t)=Suffix(k+1)
// 或者Suffix(t)排在Suffix(k+1)前面，则h[i]>=h[i-1]-1。
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
#define MAXN 500 + 10
#define INF 0x3f3f3f3f
using namespace std;
int Map[MAXN][MAXN];
bool vis[MAXN]; //是否已并入集合
int wage[MAXN]; //记录每个点的连通度
bool In[MAXN];  //该点是否已经合并到其它点
int N, M;
void getMap() {
    memset(Map, 0, sizeof(Map));
    int a, b, c;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        a++, b++;
        Map[a][b] += c;
        Map[b][a] += c;
    }
}
int S, T; //记录每次找s-t割  所遍历的最后两个点
int work() {
    int Mincut; //每一步找到的s-t割
    memset(wage, 0, sizeof(wage));
    memset(vis, false, sizeof(vis));
    int Next;
    for (int i = 1; i <= N; i++) {
        int Max = -INF;
        for (int j = 1; j <= N; j++) {
            if (!In[j] && !vis[j] && Max < wage[j]) //找最大的wage值
            {
                Next = j;
                Max = wage[j];
            }
        }
        if (Next == T) break;        //找不到点 图本身不连通
        vis[Next] = true;            //标记 已经并入集合
        Mincut = Max;                //每次更新
        S = T, T = Next;             // 记录前、后点
        for (int j = 1; j <= N; j++) //继续找不在集合 且 没有被合并过的点
        {
            if (In[j] || vis[j]) continue;
            wage[j] += Map[Next][j]; //累加 连通度
        }
    }
    return Mincut;
}
int Stoer_wagner() {
    memset(In, false, sizeof(In));
    int ans = INF;
    for (int i = 0; i < N - 1; i++) {
        ans = min(ans, work());
        if (ans == 0) return 0; //本身不连通
        In[T] = true;
        for (int j = 1; j <= N; j++) //把T点合并到S点
        {
            if (In[j]) continue; //已经合并
            Map[S][j] += Map[T][j];
            Map[j][S] += Map[j][T];
        }
    }
    return ans;
}
int main() {
    while (scanf("%d%d", &N, &M) != EOF) {
        getMap();
        printf("%d\n", Stoer_wagner());
    }
    return 0;
}
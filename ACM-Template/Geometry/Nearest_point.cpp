// 分治算法求最近点对
struct point //保存每一个点
{
  double x, y;
} p[maxn];

int a[maxn]; //保存筛选的坐标点的索引即2min(dl,dh)区间的坐标点索引

int cmpx(point a, point b) //对n个点按横坐标由小到大排序
{
  return a.x < b.x;
}

int cmpy(int a, int b) //（这里用的是下标索引）对筛选的点按纵坐标由小到大排序
{
  return p[a].y < p[b].y;
}

inline double dis(point a, point b) //求点对间的距离
{
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double closest(int low, int high) //求最近点对
{
  int i, j, k;
  if (low + 1 == high) //只有两个点
    return dis(p[low], p[high]);
  if (low + 2 == high) //只有三个点
    return min(dis(p[low], p[high]),
               min(dis(p[low], p[low + 1]), dis(p[low + 1], p[high])));
  int mid = (low + high) >> 1; //求中点即左右子集的分界线
  double d = min(closest(low, mid), closest(mid + 1, high));
  for (i = low, k = 0; i <= high;
       ++i) //把x坐标在p[mid].x-d  ~  p[mid].x+d范围内的点筛选出来
  {
    if (p[i].x >= p[mid].x - d && p[i].x <= p[mid].x + d)
      a[k++] = i; //保存这些点的下标索引
  }
  sort(a, a + k, cmpy); //按y坐标进行升序排序
  for (i = 0; i < k; ++i) {
    for (j = i + 1; j < k; ++j) {
      if (p[a[j]].y - p[a[i]].y >= d) //注意下标索引
        break;
      d = min(d, dis(p[a[i]], p[a[j]]));
    }
  }
  return d;
}
int main() {
  ios::sync_with_stdio(0);
  int n;
  while (1) // n个点
  {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    for (int i = 0; i < n; ++i) {
      scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    sort(p, p + n, cmpx); //按x坐标进行升序排序
    double ans = closest(0, n - 1);
    ans = ans / 2;
    cout << fixed << setprecision(2) << ans << endl;
  }
  return 0;
}

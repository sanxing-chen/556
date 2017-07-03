int father[20001];
int m, n, i, x, y, q;
int find(int x) //用于查找一个元素的所在集合即根节点
{
    if (father[x] != x) father[x] = find(father[x]); //路径压缩，递归将路径上的元素父亲指针都指向根节点
    return father[x];
}
void u(int r1, int r2) //合并两个集合
{
    r1 = find(r1);
    r2 = find(r2);
    if (r1 != r2) father[r2] = r1;
}
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string.h>
using namespace std;

const int MAXN = 2010;
int pre[MAXN];
int dis;
struct Node
{
    int s;
    int e;
    int distance;
};

//存放节点之间的互相联通信息
Node node[MAXN * MAXN];
//存放输入信息
char str[MAXN][10];

int gd(char *a, char *b)
{
    int t = 0;
    for (int i = 0; a[i]; i++)
    {
        if (a[i] != b[i])
            t++;
    }
    return t;
}

int find(int x)
{
    int r = x;
    while (r != pre[r])
    {
        r = pre[r];
    }
    int i = x, j;
    while (i != r)
        j = pre[i], pre[i] = r, i = j;
    return r;
}

bool cmp(Node a, Node b)
{
    return a.distance < b.distance;
}

int main()
{
    int N;
    while (scanf("%d", &N) && N)
    {
        int num = 1;
        memset(pre, -1, sizeof(pre));
        for (int i = 0; i < N; i++)
        {
            scanf("%s", str[i]);
        }
        // clock_t start_time = clock();
        int k = 0;
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                node[k].e = i;
                node[k].s = j;
                node[k].distance = gd(str[i], str[j]);
                k++;
            }
        }
        sort(node, node + k, cmp);
        dis = 0;
        for (int i = 0; i < k; i++)
        {
            if (pre[node[i].e == -1])
                pre[node[i].e] = node[i].e;
            if (pre[node[i].s == -1])
                pre[node[i].s] = node[i].s;
            int e = find(node[i].e);
            int s = find(node[i].s);
            if (e != s)
            {
                num++;
                pre[s] = e;
                dis += node[i].distance;
            }
            if (num == N)
                break;
        }
        printf("The highest possible quality is 1/%d.\n", dis);
    }
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int MAXN = 2010;

int pre[MAXN], anser, num, N;

struct Node
{
    int s, e, dis;
};

Node dt[MAXN * MAXN];
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
        r = pre[r];
    int i = x, j;
    while (i != r)
        j = pre[i], pre[i] = r, i = j;
    return r;
}

void initial()
{
    memset(pre, -1, sizeof(pre));
    anser = 0;
}

int cmp(Node a, Node b)
{
    return a.dis < b.dis;
}

int main()
{
    while (scanf("%d", &N), N)
    {
        num = 1;
        initial();
        for (int i = 0; i < N; i++)
        {
            scanf("%s", str[i]);
        }
        int k = 0;
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                dt[k].s = i;
                dt[k].e = j;
                dt[k].dis = gd(str[i], str[j]);
                k++;
            }
        }
        sort(dt, dt + k, cmp);
        int f1, f2;
        for (int i = 0; i < k; i++)
        {
            if (pre[dt[i].s] == -1)
                pre[dt[i].s] = dt[i].s;
            if (pre[dt[i].e] == -1)
                pre[dt[i].e] = dt[i].e;
            f1 = find(dt[i].s);
            f2 = find(dt[i].e);
            if (f1 != f2)
            {
                num++;
                pre[f1] = f2;
                anser += dt[i].dis;
            }
            if (num == N)
                break;
        }
        printf("The highest possible quality is 1/%d.\n", anser);
    }
    return 0;
}
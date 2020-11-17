//求解将哪些物品装入背包可使这些物品的重量总和不超过背包承重量t，且价值总和最大。
#include <stdio.h>
#include <string.h>
#include <algorithm>
int f[100011], w[101], v[101]; //f记录不同承重量背包的总价值，w记录不同物品的重量，v记录不同物品的价值
using namespace std;

#define MAXVALUE 100000
const int MAXMUN = 1000000001;

int main()
{
    int t, m, i, j, k, d;
    for (int n = 1; n < 100001; n++)
    {
        f[n] = MAXMUN;
    }
    //memset(f+1, MAXMUN, sizeof(f));
    scanf("%d %d", &m, &t); //输入背包承重量t、物品的数目m
    for (i = 1; i <= m; i++)
        scanf("%d %d", &w[i], &v[i]); //输入m组物品的重量w[i]和价值v[i]
    for (i = 1; i <= m; i++)
    { //尝试放置每一个物品
        for (j = 100010; j >= v[i]; j--)
        { //倒叙是为了保证每个物品都使用一次
            f[j] = min(f[j - v[i]] + w[i], f[j]);
            //在放入第i个物品前后，检验不同j价值量背包的总重量，如果放入第i个物品后比放入前的重量减少了，则修改j价值量背包的重量，否则不变
        }
    }
    for (d = MAXVALUE; d >= 0; d--)
    {
        if (f[d] <= t)
            break;
    }
    printf("%d\n", d);
    return 0;
}

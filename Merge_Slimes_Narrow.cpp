#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define inf 0x3f3f3f3f3f3f3f3f

const int maxn = 500;
int num, SlimesSize[maxn];
long long int dp[maxn][maxn]; //dp[i][j]表示从第i堆到第j堆合并的代价
long long int sum[maxn][maxn];
int main()
{
    scanf("%d", &num);
    memset(sum, 0, sizeof(sum));
    fill(dp[0], dp[0] + maxn * maxn, inf); //fill填充量必须是常数
    for (int i = 1; i <= num; i++)
    {
        scanf("%d", &SlimesSize[i]);
    }

    for (int i = 1; i <= num; i++)
        sum[i][i] = SlimesSize[i],
        dp[i][i] = 0;

    for (int len = 1; len < num; len++)
    { //区间长度
        for (int i = 1; i <= num && i + len <= num; i++)
        {                                //区间起点
            int j = i + len;             //区间终点
            for (int k = i; k <= j; k++) //用k来表示分割区间
            {
                sum[i][j] = sum[i][k] + sum[k + 1][j];
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[i][j]);
            }
        }
    }
    printf("%lld\n", dp[1][num]);
    return 0;
}
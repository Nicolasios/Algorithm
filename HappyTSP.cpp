#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int CityNum;
int CityIndex[18][3];
int CityDistance[18][18];
int dp[1 << 18][18];
int getdistance(int i, int j)
{
    int x = abs(CityIndex[i][0] - CityIndex[j][0]);
    int y = abs(CityIndex[i][1] - CityIndex[j][1]);
    int z = max(0, CityIndex[i][2] - CityIndex[j][2]);
    return x + y + z;
}
int main()
{
    scanf("%d", &CityNum);
    for (int i = 0; i < CityNum; i++)
    {
        scanf("%d %d %d", &CityIndex[i][0], &CityIndex[i][1], &CityIndex[i][2]);
    }
    for (int i = 0; i < CityNum; i++)
    {
        for (int j = 0; j < CityNum; j++)
        {
            CityDistance[i][j] = getdistance(i, j);
        }
    }
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[1][0] = 0;
    //f(i,V′+i)=minV′{d(k,V′)+Cki}
    //V'代表当前点集，i代表下一个加入点
    //用状态压缩来表示点集信息
    int CityState = 1 << CityNum;
    for (int i = 1; i < CityState; i++)
    {
        for (int j = 1; j < CityNum; j++)
        { //如果点j在点集i中
            if (i & 1 << j)
            {
                continue;
            }
            if (!(i & 1))
            {
                continue;
            }
            for (int k = 0; k < CityNum; k++)
            { //k必须在当前点集i中
                if (i & (1 << k))
                { //将j加入集合i然后对集合i'进行更新
                    dp[(1 << j) | i][j] = min(dp[1 << j | i][j],
                                              dp[i][k] + CityDistance[k][j]);
                }
            }
        }
    }
    //形成环之后得回到原点
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < CityNum; i++)
    {
        if (dp[CityState - 1][i] + CityDistance[i][0] < ans)
        {
            ans = dp[CityState - 1][i] + CityDistance[i][0];
        }
    }
    printf("%d\n", ans);
}
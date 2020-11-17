#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int f[10010], Hurt[1011], Magic[1011];

int main()
{
    int num, health;
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    scanf("%d %d", &health, &num); //读取血条和技能个数
    for (int k = 1; k <= num; k++)
    {
        scanf("%d %d", &Hurt[k], &Magic[k]);
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = 0; j < Hurt[i]; j++)
        {
            f[j] = min(f[j], Magic[i]);
        }
        for (int j = Hurt[i]; j <= health; j++)
        {
            f[j] = min(f[j - Hurt[i]] + Magic[i], f[j]);
        }
    }
    printf("%d\n", f[health]);
    return 0;
}
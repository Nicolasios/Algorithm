#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long int slimes[410];

bool cmp(long long int a, long long int b)
{
    return a > b;
}
int main()
{
    int num;
    long long int HugeSlime = 0;
    scanf("%d", &num);
    memset(slimes, 0, sizeof(slimes));
    for (int i = 0; i < num; i++)
    {
        scanf("%lld", &slimes[i]);
    }
    if (num == 1)
    {
        HugeSlime = slimes[0];
    }
    for (; num > 1; num--)
    {
        sort(slimes, slimes + num, cmp);
        slimes[num - 2] += slimes[num - 1];
        slimes[num - 1] = 0;
        HugeSlime += slimes[num - 2];
    }
    printf("%lld\n", HugeSlime);
    return 0;
}
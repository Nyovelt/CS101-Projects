#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define MAXN 500
#define INF 0x3f3f3f3f
#define MAX_TIME 1
int dis[MAXN][MAXN], route[MAXN], ans[MAXN];
bool vis[MAXN];
int i = 1, j, k, n, old_dis = INF, new_dis, res, ans_dis = INF, city, n_city;

double Rand() { return (double)rand() / RAND_MAX; }

inline int calcDistance()
{
    res = 0;
    for (i = 1; i < n; i++)
        res += dis[route[i]][route[i + 1]];
    return res + dis[n][1];
}

inline void printResult()
{
    for (i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    printf("\n");
}

inline void simulateAnneal()
{
    double t = 10;
    while (t >  1e-31)
    {
        for (j = 0; j <= 200; j++)
        {
            int c1 = 2 + Rand() * (n - 1), c2 = 2 + Rand() * (n - 1);
            if (c1 != c2)
            {
                std::swap(route[c1], route[c2]);
                new_dis = calcDistance();
                if (ans_dis > new_dis)
                {
                    for (i = 1; i <= n; i++)
                        ans[i] = route[i];
                    ans_dis = new_dis;
                }
                if (new_dis < old_dis)
                {
                    old_dis = new_dis;
                }
                else if (exp(-new_dis / t) > Rand())
                {
                    old_dis = new_dis;
                }
                else
                {
                    std::swap(route[c1], route[c2]);
                }
            }
        }
        t *= 0.97;
    }
}

int main()
{
    srand(time(0));
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
            scanf("%d", &dis[i][j]);
    }
    vis[1] = 1;
    route[1] = 1;
    city = 1;
    for (i = 2; i <= n; ++i)
    {
        int tmp = INF;
        for (j = 1; j <= n; ++j)
        {
            if (!vis[j] && dis[city][j] < tmp)
                n_city = j, tmp = dis[city][j];
        }
        vis[n_city] = 1;
        route[i] = n_city;
        city = n_city;
    }
    for (i = 1; i <= n; ++i)
        ans[i] = route[i];
    old_dis = calcDistance();
    ans_dis = old_dis;
    // for (i = 1; i < n; i++)
    //     printf("%d ", route[i]);
    // printf("%d", route[n]);'
      int t1 = clock() ;
    simulateAnneal();
    int t2 =clock() ;
     while (((double)clock()+ t2 - t1) / CLOCKS_PER_SEC < MAX_TIME)
     {
        simulateAnneal();
     }
    //simulateAnneal();
    for (i = 1; i < n; ++i)
        printf("%d ", ans[i]);
    printf("%d", ans[n]);
}
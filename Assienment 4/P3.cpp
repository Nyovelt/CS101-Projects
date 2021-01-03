#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define MAXN 500
#define INF 0x3f3f3f3f
#define MAX_TIME 1
int dis[MAXN][MAXN], route[MAXN], ans[MAXN];
int i = 1, j,k, n, old_dis = INF, new_dis, res, ans_dis=INF;

double Rand() { return (double)rand() / RAND_MAX; }

int calcDistance()
{
    res=0;
    for (i = 1; i < n; i++)
        res += dis[route[i]][route[i + 1]];
    return res + dis[n][1];
}

void printResult(){
    for (i=1;i<=n;i++)
        printf("%d ", ans[i]);
    printf("\n");
}


void simulateAnneal()
{
    double t = 10000000;
    while (t > 0.1)
    {
        
        int c1 = 2 + Rand() * (n-1) , c2 = 2 +  Rand() * (n-1) ;
        if (c1 != c2)
        {
            std::swap(route[c1], route[c2]);
            new_dis = calcDistance();
            if (ans_dis > new_dis)
            {
                memcpy(ans, route, sizeof(route));
                ans_dis = new_dis;
            }
            if ( new_dis < old_dis)
            {
                old_dis = new_dis;
            }
            else if(exp(- new_dis / t) > Rand() ){
                old_dis = new_dis;
            }
            else
            {
                std::swap(route[c1], route[c2]);
            }
            t *= 0.99999;
        }
    }
}



int main()
{
    srand(time(0));
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            scanf("%d", &dis[i][j]), route[i] = i;
    // while ((double)clock() / CLOCKS_PER_SEC < MAX_TIME)
    // {
    //    simulateAnneal();
    // }
    int t1 = clock() ;
    simulateAnneal();
    int t2 =clock()  ;
    while (((double)clock()+ t2 - t1) / CLOCKS_PER_SEC < MAX_TIME)
    {
       simulateAnneal();
    }
    for (i = 1; i < n; i++)
        printf("%d ", ans[i]);
    printf("%d", ans[n]);
}
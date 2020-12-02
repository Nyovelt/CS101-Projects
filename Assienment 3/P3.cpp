#include <bits/stdc++.h>
#define MAXN 7000
#define MAXM 56000

using namespace std;

int n, k, cnt, ans;
int x[MAXN], y[MAXN], fa[MAXN], head[MAXM];

int fnd(int x)
{
    return fa[x] == x ? x : fa[x] = fnd(fa[x]);
}

int dis(int i, int j)
{
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

struct Edge
{
    int u, v, w;
} edg[MAXM];

void add(int u, int v, int w)
{
    if (w < 0 || w >= 0x3f3f3f3f)
        return;
    edg[cnt].u = u;
    edg[cnt].v = v;
    edg[cnt].w = w;
    cnt++;
}

bool cmp(const Edge &a, const Edge &b)
{
    return a.w < b.w;
}

int main()
{
    for (int i = 0; i < MAXN; i++)
        fa[i] = i;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        int t_w[8], t_u[8], t_v[8];
        memset(t_w, 0x3f3f3f3f, sizeof(t_w));
        memset(t_u, 0, sizeof(t_u));
        memset(t_v, 0, sizeof(t_v));
        scanf("%d %d", &x[i], &y[i]);
        for (int j = 1; j < i; j++)
        {
            int angle = 4 * (y[i] <= y[j]) + 2 * (x[i] >= x[j]) + (abs(x[i] - x[j]) >= abs(y[i] - y[j]));
            //cout << "angle: "<<angle<<endl;
            int d = dis(i, j);

            if (t_w[angle] > d)
            {
                t_w[angle] = d;
                t_u[angle] = i;
                t_v[angle] = j;
            }
        }
        for (int j = 0; j < 8; j++)
        {
            add(t_u[j], t_v[j], t_w[j]);
        }
    }
    std::sort(edg, edg + cnt, cmp);
    int m = 0;
    for (int i = 0; i < cnt; i++)
    {

        int f1 = fnd(edg[i].u);
        //cout << "f1: " << f1 << endl;
        int f2 = fnd(edg[i].v);
        //cout << "f2: " << f2 << endl;
        if (f1 == f2)
        {
            //cout << "yo" << endl;
            continue;
        }
        
        fa[fnd(edg[i].v)] = fnd(edg[i].u);
        //std::cout << edg[i].u << " " << edg[i].v << " " << edg[i].w << std::endl;
        // for (int j = 1; j < 10; j++)
        // {
        //     cout << fa[j];
        // }
        // cout << endl;
        m = max(m, edg[i].w);
        ans += edg[i].w;
    }
    cout << ans - m << flush;
}
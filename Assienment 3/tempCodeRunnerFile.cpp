#include <bits/stdc++.h>
#define MAXN 100005
#define MAXM 2000006

int cnt, n, m, v, e, a_v, a_e;
int head[MAXN], vis[MAXN], vis_e[2 * MAXM];

using namespace std;

struct Edge
{
    int to, nxt;
} edg[2 * MAXM];

void add(int u, int v)
{
    edg[cnt].to = v;
    edg[cnt].nxt = head[u];
    head[u] = cnt++;
}

void dfs(int node)
{
    //cout << "node "<<node << endl;
    if (!vis[node])
        v++;
    vis[node] = 1;
    for (int i = head[node]; i != -1; i = edg[i].nxt)
    {
        //cout << node << " to " << edg[i].to << endl;
        if (vis_e[i] != 1)
        {
            vis_e[i] = 1;
            e++;
            dfs(edg[i].to);
        }
    }
}

int main()
{
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; i++)
    {

        if (!vis[i])
        {
            v = 0;
            e = 0;
            //cout << "node: " << i << endl;
            dfs(i);
            //cout << v << " " << e << endl;
            if ((e / 2 - v) > 0)
            {
                a_v += v;
                a_e += (e / 2);
            }
            //std::cout << "ans " << (a_e - a_v) << std::endl;
        }
    }
    printf("%d",  (a_e - a_v));
}

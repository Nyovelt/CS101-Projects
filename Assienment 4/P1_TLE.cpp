#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#define MAXN 30000
#define MAXE 500000
#define INF 0x3f3f3f3f

using namespace std;

int n, m, k, s, cnt, ql = 1, qr;
int head[MAXN], dis[MAXN];
bool vis[MAXN];
int que[MAXN * 100];
bool inQue[MAXN];

struct edge
{
    int to, nxt, wei;
    bool ein;
} edg[MAXE];

struct vertex
{
    int pos, dis;
    bool operator<(const vertex &x) const
    {
        return x.dis < dis;
    }
};

void add(int u, int v, int w, bool ein)
{
    edg[cnt].to = v;
    edg[cnt].nxt = head[u];
    edg[cnt].ein = ein;
    edg[cnt].wei = w;
    head[u] = cnt++;
}

std::priority_queue<vertex> q;

inline void dijkstra(int s)
{
    q.push((vertex){s, dis[s]});
    while (!q.empty())
    {
        vertex t = q.top(); //tmp node
        int pos = t.pos;
        q.pop();
        if (vis[pos])
            continue;
        vis[pos] = 1;
        for (int i = head[pos]; i != -1; i = edg[i].nxt)
        {
            if (edg[i].ein)
            {
              if (dis[pos] + edg[i].wei < dis[edg[i].to]){
                if (!inQue[edg[i].to])
                {
                    que[++qr] = edg[i].to;
                    inQue[edg[i].to] = 1;
                }

                dis[edg[i].to] =  dis[pos] + edg[i].wei;
              }
              else if (dis[edg[i].to] == INF){
                if (!inQue[edg[i].to])
                {
                    que[++qr] = edg[i].to;
                    inQue[edg[i].to] = 1;
                }
              }
            }
            else
            {
                dis[edg[i].to] = std::min(dis[edg[i].to], dis[pos] + edg[i].wei);
                // cout << dis[4] << endl;
                // cout << dis[pos] << endl;
                // cout << edg[i].wei << endl;
                if (!vis[edg[i].to])
                {
                    q.push((vertex){edg[i].to, dis[edg[i].to]});
                }
            }
        }
    }
}

int main()
{
    memset(head, -1, sizeof(head));
    memset(dis, 0x3f, sizeof(dis));
    //std::cout << dis[1]<<std::flush;
    scanf("%d %d %d %d", &n, &m, &k, &s);
    dis[s] = 0;
    for (register int i = 0; i < m; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w, 0);
        add(v, u, w, 0);
    }
    for (register int i = 0; i < k; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w, 1);
    }

    // for(int i=1; i<=6; i++){
    //     cout << i << endl;
    //     for(int j = head[i]; j!= -1; j=edg[j].nxt){
    //         cout << i << " "<<edg[j].to << " " << edg[j].wei <<" " << edg[j].ein << endl;
    //     }
    // }

    dijkstra(s);
    
    while (ql <= qr)
    {
        memset(inQue, 0, sizeof(inQue));
        memset(vis, 0, sizeof(vis));
        dijkstra(que[ql]);
        ql++;
    }
    for (register int i = 1; i <= n; ++i)
    {
        if (dis[i] == INF)
        {
            printf("UNREACHABLE\n");
        }
        else
        {
            printf("%d\n", dis[i]);
        }
    }
}
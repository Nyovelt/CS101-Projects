#pragma GCC optimize(3)

#include <bits/stdc++.h>
#define MAXN 30000
#define MAXE 500000
#define INF 0x3f3f3f3f

int u, v, w, n, m, k, s, cnt, ql = 1, qr, cnt2,siz;
int head[MAXN], dis[MAXN], dpt[MAXN], fa[MAXN], in[MAXN];
bool vis[MAXN];
int que[MAXN * 100];



inline int fnd(int x)
{
    return fa[x] == x ? x : fa[x] = fnd(fa[x]);
}

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
        //return (dpt[pos] == dpt[x.pos]) ? dis > x.dis : dpt[pos] > dpt[x.pos];
        return dpt[pos] > dpt[x.pos] || dpt[pos] == dpt[x.pos] && dis > x.dis ;
    }
} heap[MAXN];

inline void push(vertex e)
{
    int j = ++siz;
    for (; j != 1 && e < heap[j / 2]; j /= 2)
    {
        heap[j] = heap[j / 2];
    }
    heap[j] = e;
}

inline vertex pop()
{
    vertex ans = heap[1];
    heap[1] = heap[siz--];

    // for (int i = siz / 2; i > 0; i--)
    //     min_heapify( i, siz);
    
    int i = 1;
    while(i*2  <= siz){
        int j = i * 2;
        if(  heap[j+1] < heap[j] && j+1<=siz){
            j++;
        }
        if ( heap[i] < heap[j]) break;
        std::swap(heap[i], heap[j]);
        i = j;
    }

    //min_heapify(siz/2, siz);
    return ans;
}

inline void add(int u, int v, int w, bool ein)
{
    edg[cnt].to = v;
    edg[cnt].nxt = head[u];
    edg[cnt].ein = ein;
    edg[cnt].wei = w;
    head[u] = cnt++;
}

std::priority_queue<vertex> q;

inline void calcDepth()
{
    for (register int i = 1; i <= n; i++)
        if (fa[i] == i && !in[i])
            que[++qr] = i;
    while (ql <= qr)
    {
        u = que[ql];
        ++ql;
        dpt[u] = ++cnt2;
        for (register int i = head[u]; i != -1; i = edg[i].nxt)
            if (edg[i].ein == 1)
                if (--in[edg[i].to] == 0)
                    que[++qr] = edg[i].to;
    }
    for (register int i = 1; i <= n; i++)
        dpt[i] = dpt[fnd(i)];
}

inline void dijkstra(int s)
{
    //q.push((vertex){s, dis[s]=0});
    push((vertex){s, dis[s]=0});
    while (siz)
    //while(!q.empty())
    {
        //vertex t = q.top();
        //q.pop();
        vertex t = pop();
        int pos = t.pos;
        //std::cout << "pos: "<<pos<<std::endl;
        
        if (t.dis != dis[pos])
            continue;
        for (int i = head[pos]; i != -1; i = edg[i].nxt)
        {
            if (edg[i].ein == 0 && dis[edg[i].to] > dis[pos] + edg[i].wei)
            {
                dis[edg[i].to] = dis[pos] + edg[i].wei;
                push((vertex){edg[i].to, dis[edg[i].to]});
                //q.push((vertex){edg[i].to, dis[edg[i].to]});
            }
        }
    }
}

int main()
{
    for (int i = 0; i < MAXN; i++)
        fa[i] = i;
    memset(head, -1, sizeof(head));
    memset(dis, 0x3f, sizeof(dis));
    //std::cout << dis[1]<<std::flush;
    scanf("%d %d %d %d", &n, &m, &k, &s);
    dis[s] = 0;
    for (register int i = 0; i < m; ++i)
    {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w, 0);
        add(v, u, w, 0);
        fa[fnd(u)] = fnd(v);
    }
    for (register int i = 0; i < k; ++i)
    {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w, 0);
        add(fnd(u), fnd(v), w, 1);
        in[fnd(v)]++;
    }

    // for(int i=1; i<=6; i++){
    //     cout << i << endl;
    //     for(int j = head[i]; j!= -1; j=edg[j].nxt){
    //         cout << i << " "<<edg[j].to << " " << edg[j].wei <<" " << edg[j].ein << endl;
    //     }
    // }

    calcDepth();
    ql = 1;
    qr = 0;
    memset(vis, 0, sizeof(vis));

    // for(int i=1; i<=n; i++){
    //     std::cout << i<<": "<<dpt[i] << std::endl;
    // }

    dijkstra(s);

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

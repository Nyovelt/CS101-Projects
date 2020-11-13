#include <bits/stdc++.h>
#define MAXN 1000006
#define MAXM 10000007
#define ll long long
using namespace std;
int head[MAXN];
int m, n, cnt, u, v;
long long int ans;
int fa[MAXN], pre[MAXN];
int vis[MAXN];

int fnd(int x)
{
    return fa[x] == x ? x : fa[x] = fnd(fa[x]);
}

struct Edge
{
    int to, nxt;
} edg[MAXM];

ll desi[MAXN];

struct Desire
{
    long long desire;
    int id;
};

struct Desire des[MAXM];

bool cmp(const Desire &a, const Desire &b)
{
    return a.desire > b.desire;
}

void add(int u, int v)
{
    edg[cnt].to = v;        //出节点
    edg[cnt].nxt = head[u]; //边集的另一条边
    head[u] = cnt++;
}

void printD()
{
    cout << "Desire" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << des[i].id << ": " << des[i].desire << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": " << endl;
        for (int j = head[i]; j != -1; j = edg[j].nxt)
        {
            cout << i << " " << edg[j].to << endl;
        }
    }
}

void ins(int id)
{
    vis[id]++;
    ll min_d = 1e9, max_d = 0;
    for (int i = head[id]; i != -1; i = edg[i].nxt)
        if (vis[edg[i].to])
        {
            min_d = min(min_d, desi[fnd(edg[i].to)]);
            max_d = max(max_d, desi[fnd(edg[i].to)]);
            if(fnd(edg[i].to) != id) 
                pre[fnd(edg[i].to)] =id, fa[fnd(edg[i].to)] = id;
        }
    desi[id] = min(min_d, desi[id]);
}

int find(int id)
{
    for (int i = 1; i <= n; i++)
    {
        if (des[i].id == id)
        {
            return i;
        }
    }
}

int main()
{
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= n; i++)
    {
        cin >> des[i].desire;
        des[i].id = i;
        desi[i] = des[i].desire;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    sort(des + 1, des + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        ins(des[i].id);
    //std::cout<<ans<<std::endl;
    for (int i = 1; i <= n; i++)
        ans += desi[i] - desi[pre[i]];
    cout << ans << flush;
}
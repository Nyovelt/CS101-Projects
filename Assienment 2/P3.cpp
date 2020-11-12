#include <bits/stdc++.h>
#define MAXN 1000006
#define MAXM 10000007
using namespace std;
int head[MAXN];
int m, n, cnt, u, v;
long long int ans;

struct Edge
{
    int to;
    int nxt;
};

struct Edge edg[MAXN];

struct Desire
{
    long long int desire;
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

void del(int i)
{
    int tmp[MAXN];
    long long int max_des = 0;
    memset(tmp, 0, sizeof(tmp));
    for (int j = head[i]; j != -1; j = edg[j].nxt)
    {
        int k = find(edg[j].to);
        tmp[++*tmp] = k;
        max_des = max(max_des, des[k].desire);
        //del_edge
    }
    //add  edge
    ans += des[1].desire - max_des;
    //del  des[1]
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
    for (int i = 1; i <= n; i++)
    {
        cin >> des[i].desire;
        des[i].id = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    while (des[1].desire)
    {
        sort(des + 1, des + n + 1, cmp);
        del(des[1].id);
        printD();
    }
    cout << ans << flush;
}
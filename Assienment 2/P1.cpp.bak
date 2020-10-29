#include <bits/stdc++.h>
const int MAXN = 5e5;
int head[MAXN], edge[MAXN], to[MAXN], nxt[MAXN], val[MAXN];
int n;
int ans;

using namespace std;

void add(int a, int b, int c)
{
    edge[b] = c;
    head[b] = a;
    if (to[a])
    {
        int tmp = to[a];
        while (nxt[tmp])
        {
            tmp = nxt[tmp];
        }
        nxt[tmp] = b;
    }
    else
    {
        to[a] = b;
    }
}

void trans(int node)
{
    val[node] = val[head[node]] - edge[node];
    if (to[node])
    {
        trans(to[node]);
    }
    if (nxt[node])
    {
        trans(nxt[node]);
    }
}

void show()
{
    for (int i = 1; i <= n; i++)
    {
        std::cout << i << ": " << val[i] << " head: " << head[i] << " nxt: " << nxt[i] << " to: " << to[i] << " edge: " << edge[i] << std::endl;
    }
}

int weak_signal(int node)
{
    int ans = 0;
    if (val[node] <= 0)
    {
        ans += 1;
    }
    if (to[node])
    {
        ans += weak_signal(to[node]);
    }
    if (nxt[node])
    {
        ans += weak_signal(nxt[node]);
    }
    return ans;
}

int v_change_father(int node)
{
    int father = head[node];
    int t_val = val[father];
    val[father] = val[1];
    int res = weak_signal(1);
    val[father] = t_val;
    return res;
}

void change_father(int node)
{
    int father = head[node];
    val[father] = val[1];
}

int return_first_weak(int node)
{
    if (val[node] <= 0)
    {
        return node;
    }

    if (to[node])
    {
        return return_first_weak(to[node]);
    }
    if (nxt[node])
    {
        return return_first_weak(nxt[node]);
    }
    return 0;
}

void dp()
{
    while (return_first_weak(1))
    {
        int node = return_first_weak(1);
        int min = 5e5, t_node;
        while (head[node] - 1)
        {
            if (v_change_father(node) < min)
            {
                t_node = (node);
                min = v_change_father(node);
            }
            node = head[node];
        }
        change_father(t_node);
        ans++;
    }
}

int main()
{
    head[1] = 1;
    edge[1] = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
    }
    int tmp;
    scanf("%d", &tmp);
    val[1] = tmp;
    trans(1);
    show();
    cout << return_first_weak(1);
    //dp();
    printf("%d", ans);
}

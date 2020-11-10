#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

struct Edge
{
	int next;
	int to;
	int w;
};

void dfs(int node, int fa);
void printG();
int find_father(int node);
int weak();
int light[500005];
struct Edge edge[500005];
int cnt, n, m, weight, ans;
int head[500005];
int weig[500005];
int dis[500005];
int fat[500005];
void add(int u, int v, int w)
{
	edge[cnt].w = w;		  //边权
	edge[cnt].to = v;		  //出节点
	edge[cnt].next = head[u]; //边集的另一条边
	head[u] = cnt++;
}

int main()
{
	memset(head, -1, sizeof(head));
	int u, v, w;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}

	cin >> weight;
	weig[1] = weight;

	dfs(1, 0);
	// printG();
	// cout << find_father(10)<< endl;
	// cout << weak();
	cout << ans << flush;
}

void dfs(int node, int fa)
{
	for (int i = head[node]; i != -1; i = edge[i].next)
	{
		if (edge[i].to != fa)
		{
			weig[edge[i].to] = weig[node] - edge[i].w;
			fat[edge[i].to] = edge[i].w;
			//cout << "Fa" << edge[i].to << ":" << fat[edge[i].to] <<"="<<edge[i].w << endl;

			// cout << weig[edge[i].to] << "=" <<  node <<"："<< weig[node] << "-" << edge[i].w << endl;

			dfs(edge[i].to, node);

			dis[node] = max(dis[edge[i].to] + edge[i].w, dis[node]);
		}
	}
	if (dis[node] + fat[node] >= weig[1])
	{
		//cout << "add at" << node << endl;
		dis[node] = 0;
		ans++;
	}
}

int find_father(int node)
{
	for (int i = 1; i <= n; i++) 
	{
		for (int j = head[i]; j != -1; j = edge[j].next)
		{
			if (edge[j].to == node)
			{
				return i;
			}
		}
	}
}

int weak()
{
	int tmp = 0;
	for (int i = 1; i <= n; i++)
	{
		if (weig[i] <= 0)
		{
			tmp++;
		}
	}
	return tmp;
}

void printG()
{

	cout << "weig" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << i << " " << weig[i] << endl;
	}
	cout << "fat" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << i << " " << fat[i] << endl;
	}
	cout << "dis" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << i << " " << dis[i] << endl;
	}
}
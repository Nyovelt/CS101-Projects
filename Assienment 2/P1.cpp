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

struct Edge edge[500005];
int cnt = 0, n, m;
int head[500005];

void add(int u, int v, int w)
{
	edge[cnt].w = w;
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

int main()
{
	memset(head, -1, sizeof(head));
	int n, u, v, w;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> u >> v >> w;
		add(u, v, w);
	}
	for (int i = 1; i <= n; i++) //n个起点
	{
		cout << i << endl;
		for (int j = head[i]; j != -1; j = edge[j].next) //遍历以i为起点的边
		{
			cout << i << " " << edge[j].to << " " << edge[j].w << endl;
		}
		cout << endl;
	}
}

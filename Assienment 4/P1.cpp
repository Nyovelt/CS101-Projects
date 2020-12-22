#include <iostream>
#include <cstdio>
#define MAXN 30000

int n,m,k,s,cnt;
int head[MAXN];

struct Edge{
    int to,nxt,wei;
} edg[2*MAXN];

void add(int u, int v, int w){
    edg[cnt].to  =v;
    edg[cnt].nxt = head[u];
    head[u]  = cnt++;
}

int main(){
    memset(head, -1, sizeof(head));
    scanf("%d %d %d %d", &n, &m, &k, &s);
}

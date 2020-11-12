#include <bits/stdc++.h>
#define MAXN 1000006
#define MAXM 10000007
using namespace std;
long long des[MAXN]; //desire
int head[MAXN];
int  m,n,cnt,u,v;

struct Edge{
    int to;
    int nxt;
};

struct Edge edg[MAXN];

void add(int u, int v)
{
	edg[cnt].to = v;		  //出节点
	edg[cnt].nxt = head[u]; //边集的另一条边
	head[u] = cnt++;
}



void printD(){
    cout << "Desire" << endl;
    for(int i=1; i<=n; i++){
        cout << i << ": " << des[i]<< endl;
    }
    for(int i = 1 ; i <= n;i++){
        cout << i<<": "<< endl;
        for(int j = head[i]; j!=-1; j=edg[j].nxt){
            cout << i << " " << edg[j].to << endl; 
        }
    }
}
int main(){
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> des[i];
    }
    for(int i=0; i<m; i++){
        cin >> u>>v;
        add(u,v);
        add(v,u);
    }
    printD();
}
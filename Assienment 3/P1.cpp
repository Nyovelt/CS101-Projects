#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define N 1000006

using namespace std;
int n, rt, opt, x, cnt, a_size;
#define lc t[x].son[0]
#define rc t[x].son[1]
class Splay
{
	struct Splaytree
	{
		int son[2], fa, size, cnt, v;
	}t[N];
	inline void pushup (int x) 
	{ 
		t[x].size = t[lc].size + t[rc].size + t[x].cnt; 
	}
	inline void rotate (int x, int& k)
	{
		int y = t[x].fa, z = t[y].fa, l, r;
		l = (t[y].son[0] == x) ? 0 : 1; r = l ^ 1;
		if (y == k) k = x;
		else if (t[z].son[0] == y) t[z].son[0] = x;
		else t[z].son[1] = x;
		t[x].fa = z, t[y].fa = x, t[t[x].son[r]].fa = y;
		t[y].son[l] = t[x].son[r], t[x].son[r] = y;
		pushup (y), pushup (x);
	}
	inline void splay (int x, int& k)
	{
		while (x != k)
		{
			int y = t[x].fa, z = t[y].fa;
			if (y != k)
			{
				if (t[z].son[0] == y ^ t[y].son[0] == x) rotate (x, k);
				rotate (y, k);
			}
			rotate (x, k);
		}
	}
	inline int create (int x) { t[++cnt].v = x, t[cnt].size = t[cnt].cnt = 1; return cnt; }
public:
    inline int size(){
        return t[rt].size;
    }
	inline int pre ()
	{
		int x = t[rt].son[0];
		while(rc) x = rc;
		return x;
	}
	inline int nex ()
	{
		int x = t[rt].son[1];
		while(lc) x = lc;
		return x;
	}
	inline void insert (int x)
	{
		if (!rt) return (void)(rt = create (x));
		int now = rt, fa = 0;
		for(int now = rt, fa = 0;; fa = now, now = t[now].son[(t[now].v <= x)])
		{
			if (!now)
			{
				create (x); t[cnt].fa = fa;
				t[fa].son[(t[fa].v <= x)] = cnt;
				pushup (fa), splay (cnt, rt); return;
			}
			if (t[now].v == x)
			{
				t[now].cnt++; pushup (now), pushup (fa), splay (now, rt); return;
			}
		}
	}

    inline int kth(int k){
        int x = rt;
        while(1){
            if(lc  && k <= t[lc].size){
                x = lc;
            }
            else{
                k -= t[x].cnt + t[lc].size;
                if (k<= 0 ){
                    splay(x, rt);
                    return t[x].v;
                }
                x = rc;
            }
        }
    }

    inline int rk(int k){
        int res=0, x=rt;
        while(lc || rc){
            if(k < t[x].v){
                x = lc;
            }
            else{
                res += t[lc].size;
                if (k == t[x].v ){
                    splay(x, rt);
                    return res ;
                }
                res += t[x].cnt;
                x = rc;
            }
        }
    }

	inline int findpos (int x)
	{
		int now = rt, ret = 0;
		while (1)
		{
			if (t[now].v > x) now = t[now].son[0];
			else
			{
				ret += t[t[now].son[0]].size;
				if (t[now].v == x) { splay (now, rt); return ret + 1; }
				ret += t[now].cnt, now = t[now].son[1];
			}
		}
	}
	inline int findpit (int x)
	{
		int now = rt;
		while (1)
		{
			if (t[t[now].son[0]].size < x)
			{
				x -= t[t[now].son[0]].size;
				if (x <= t[now].cnt) { splay (now, rt); return t[now].v; }
				x -= t[now].cnt, now = t[now].son[1];
			}
			else now = t[now].son[0];
		}
	}
	inline void Delete (int x)
	{
		findpos (x);
		if (t[rt].cnt > 1) { --t[rt].cnt, --t[rt].size; return; }

		if (!t[rt].son[0] && !t[rt].son[1]) { rt = 0; return; }
		if (!t[rt].son[0]) { rt = t[rt].son[1], t[rt].fa = 0; return; }
		if (!t[rt].son[1]) { rt = t[rt].son[0], t[rt].fa = 0; return; }
		int newrt = pre (), las = rt;
		splay (newrt, rt);
		t[rt].son[1] = t[las].son[1], t[t[las].son[1]].fa = rt;
		pushup (rt);
	}
	inline void findpre (int x) { insert (x), printf ("%d\n", t[pre ()].v), Delete (x); }
	inline void findnex (int x) { insert (x), printf ("%d\n", t[nex ()].v), Delete (x); }
}T;

struct AVL
{
    inline void insert(int v) { T.insert(v); a_size++;};
    inline void remove(int v) { T.Delete(v); a_size--;};
    int kth(int k) {  return T.kth(k + 1);};
    int rank(int v) { T.insert(v); int res = T.rk(v); T.Delete(v); return res;};
    int size() { return a_size; };
};

/* PLEASE DO NOT CHANGE BELOW*/
int A, B, C, lfsr;
double P[4][4];
int lfsr_generator()
{
    auto ret = lfsr;
    return (lfsr ^= lfsr << 13, lfsr ^= lfsr >> 17, lfsr ^= lfsr << 5, ret);
}
tuple<int, int> command()
{
    auto imm = lfsr_generator();
    static int state = 0;
    auto p = double(lfsr_generator() & 0x7fffffff) / INT32_MAX;
    for (int i = 0; i < 4; i++)
        if ((p -= P[state % 4][i]) < 0)
        {
            state += 4 - state % 4 + i;
            break;
        }
    return {state % 4, (imm * A + state * B + C) & 0x7fffffff};
}
/* PLEASE DO NOT CHANGE ABOVE*/
int main()
{
    AVL tree;
    int m;
    cin >> m >> lfsr >> A >> B >> C;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> P[i][j];
    int tans = 0;
    for (int i = 1; i <= m; i++)
    {
        int op, imm;
        tie(op, imm) = command();
        if (op == 0) tree.insert(imm);
        if (op == 1) tree.remove(tree.kth(imm % tree.size()));
        if (op == 2) tans ^= tree.rank(imm);
        if (op == 3) tans ^= tree.kth(imm % tree.size());
    }
    cout << tans << "\n";
}
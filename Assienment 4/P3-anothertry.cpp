#pragma GCC optimize(3)

#include <bits/stdc++.h>

int distance[500][500], suiji[500], jieguo[500], qvguo[500], n, jvli0, jvli1;

inline void jisuanjvli2(int a, int b)
{

    if (a == n)
    {
        jvli0 -= distance[suiji[a]][1];
        jvli0 -= distance[suiji[a - 1]][suiji[a]];
        jvli0 -= distance[suiji[b]][suiji[b + 1]];
        jvli0 -= distance[suiji[b - 1]][suiji[b]];
        std::swap(suiji[a], suiji[b]);
        jvli0 += distance[suiji[a]][1];
        jvli0 += distance[suiji[a - 1]][suiji[a]];
        jvli0 += distance[suiji[b]][suiji[b + 1]];
        jvli0 += distance[suiji[b - 1]][suiji[b]];
    }
    else if (b == n)
    {
        jvli0 -= distance[suiji[b]][1];
        jvli0 -= distance[suiji[b - 1]][suiji[b]];
        jvli0 -= distance[suiji[a]][suiji[a + 1]];
        jvli0 -= distance[suiji[a - 1]][suiji[a]];

        std::swap(suiji[a], suiji[b]);

        jvli0 += distance[suiji[b]][1];
        jvli0 += distance[suiji[b - 1]][suiji[b]];
        jvli0 += distance[suiji[a]][suiji[a + 1]];
        jvli0 += distance[suiji[a - 1]][suiji[a]];
    }
    else
    {
        jvli0 -= distance[suiji[a]][suiji[a + 1]];
        jvli0 -= distance[suiji[a - 1]][suiji[a]];
        jvli0 -= distance[suiji[b]][suiji[b + 1]];
        jvli0 -= distance[suiji[b - 1]][suiji[b]];
        std::swap(suiji[a], suiji[b]);
        jvli0 += distance[suiji[a]][suiji[a + 1]];
        jvli0 += distance[suiji[a - 1]][suiji[a]];
        jvli0 += distance[suiji[b]][suiji[b + 1]];
        jvli0 += distance[suiji[b - 1]][suiji[b]];
    }
}

inline void suijiyouzou()
{
    int a1 = (double)rand() * (n - 1) / RAND_MAX + 2;
    int a2 = (double)rand() * (n - 1) / RAND_MAX + 2;
    if (a1 - a2 && a1 <= n && a2 <= n)
    {
        jisuanjvli2(a1, a2);
        if (jvli0 < jvli1)
        {
            jvli1 = jvli0;
            std::swap(jieguo[a1], jieguo[a2]);
        }
    }
}

inline void tongbu()
{
    for (register int i = 1; i <= n; ++i)
    {
        jieguo[i] = suiji[i];
    }
}

inline void tongbu1()
{
    for (register int i = 1; i <= n; ++i)
    {
        suiji[i] = jieguo[i];
    }
}

inline int jisuanjvli1()
{
    register int ans = 0;
    for (register int i = 1; i <= n - 1; ++i)
    {
        ans += distance[qvguo[i]][qvguo[i + 1]];
    }
    ans += distance[qvguo[n]][1];
    return ans;
}

inline int jisuanjvli()
{
    register int ans = 0;
    for (register int i = 1; i <= n - 1; ++i)
    {
        ans += distance[jieguo[i]][jieguo[i + 1]];
    }
    ans += distance[jieguo[n]][1];
    return ans;
}

inline void tanxin()
{
    register int xz = 1;
    qvguo[1] = true;
    jieguo[1] = 1;
    for (register int i = 2; i < n + 1; ++i)
    {
        register int zuidazhi = 99999999, tmp_city;
        for (register int j = 1; j <= n; ++j)
        {
            if (qvguo[j] == false)
            {
                if (distance[xz][j] < zuidazhi)
                {
                    tmp_city = j;
                    zuidazhi = distance[xz][j];
                }
            }
        }

        jieguo[i] = tmp_city;
        qvguo[tmp_city] = true;
        xz = tmp_city;
    }
    tongbu1();
    jvli1 = jvli0 = jisuanjvli();
}

int main()
{

    srand(time(NULL));
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    for (register int i = 1; i <= n; ++i)
        for (register int j = 1; j <= n; ++j)
            std::cin >> distance[i][j];
    tanxin();
    while ((double)clock() / CLOCKS_PER_SEC < 1)
    {
        suijiyouzou();
    }
    for (register int i = 1; i < n; ++i)
    {
        std::cout << jieguo[i] << " ";
    }
    std::cout << jieguo[n] << std::flush;
}
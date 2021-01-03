#pragma GCC optimize(3)
#include <bits/stdc++.h>

#define MAXN 1003

int i, j, k, n, t;
int a[MAXN];
__int128 c[MAXN][MAXN];

void write(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

__int128 pow(__int128 a)
{
    return a * a * a;
}

int main()
{
    scanf("%d", &n);
    memset(c, 1, sizeof(c));
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        c[i][i] = 0;
        c[i][i + 1] = 0;
    }

    for (i = 1; i <= n - 2; ++i)
    {
        c[i][i + 2] = pow(a[i] + a[i + 1] + a[i + 2]);
    }

    for (j = 3; j < n; ++j)
        for (i = 1; i <= n - j; ++i)
            for (k = i + 1; k < i + j; ++k)
                c[i][i + j] = std::min(c[i][i + j], c[i][k] + c[k][i + j] + pow(a[i] + a[k] + a[i + j])) ;

    write(c[1][n]);
}
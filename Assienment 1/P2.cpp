#include <iostream>
#include <algorithm>
int a[1000006];
int sub[1000006];
using namespace std;

void my_sort (int a[], int n){
    
}


int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++)
    {
        sub[i] = a[i + 1] - a[i];
    }
    sort(sub, sub + n - 1);
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += sub[i];
    }
    cout << ans;
}
#include <iostream>
#include <algorithm>
int a[1000006];
int sub[1000006];
using namespace std;

int Partition(int A[], int left, int right)
{
    int p = A[left];
    while (left < right)
    {
        while (left < right && A[right] >= p)
        {
            right--;
        }
        A[left] = A[right];
        while (left < right && A[left] <= p)
        {
            left++;
        }
        A[right] = A[left];
    }
    A[left] = p;
    return left;
}

void QuickSort(int A[], int left, int right){
    if(left < right){
        int p = Partition(A, left, right);
        QuickSort(A, left, p - 1);
        QuickSort(A, p+1 , right);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    QuickSort(a, 0,  n-1);

    for (int i = 0; i < n - 1; i++)
    {
        sub[i] = a[i + 1] - a[i];
    }
    QuickSort(sub, 0, n-2 );

    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += sub[i];
    }
    cout << ans;
}
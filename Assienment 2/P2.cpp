#include <bits/stdc++.h>
#define MAXN 1000006

using namespace std;

int n, ans, ans1, siz;
int heap[MAXN];

void printHeap()
{
    cout << "size: "
         << siz << " | " << flush;
    for (int i = 0; i < siz; i++)
    {
        cout << heap[i + 1] << " " << flush;
    }
    cout << endl;
}

void max_heapify(int arr[], int start, int end)
{
    int fa = start;
    int chd = 2 * fa + 1;
    while (chd <= fa)
    {
        if (arr[chd] < arr[chd + 1] && chd + 1 <= end)
            chd++;
        if (arr[fa] > arr[chd])
        {
            return;
        }
        else
        {
            swap(arr[fa], arr[chd]);
            chd = 2 * fa + 1;
        }
    }
}

void push(int e)
{
    int j = ++siz;
    for (; j != 1 && e > heap[j / 2]; j /= 2)
    {
        heap[j] = heap[j / 2];
    }
    heap[j] = e;
    printHeap();
}

int pop()
{
    int ans = heap[0];
    heap[0] = heap[--siz];
    for (int i = siz / 2 - 1; i >= 0; i--)
        max_heapify(heap, i, siz - 1);
    printHeap();
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 0, t; i < n; i++)
    {
        cin >> t;
        cout << "push(t)" << endl;
        push(t);

        if (heap[1] < t)
        {
            cout << " ans += t - pop();" << endl;
            ans += t - pop();
            cout << "push(t)" << endl;
            push(t);

            ans1++;
        }
    }
    cout << ans << " " << ans1 << flush;
}

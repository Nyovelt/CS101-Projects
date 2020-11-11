#include <bits/stdc++.h>
#define MAXN 1000006

long long int n, ans, ans1, siz;
int heap[MAXN];
int flag[MAXN];


void push(int e)
{
    int j = ++siz;
    for (; j != 1 && e < heap[j / 2]; j /= 2)
    {
        heap[j] = heap[j / 2];
    }
    heap[j] = e;
}

int pop()
{
    int ans = heap[1];
    heap[1] = heap[siz--];

    // for (int i = siz / 2; i > 0; i--)
    //     min_heapify( i, siz);
    
    int i = 1;
    while(i*2  <= siz){
        int j = i * 2;
        if(heap[j] > heap[j+1] && j+1<=siz){
            j++;
        }
        if (heap[j] > heap[i]) break;
        std::swap(heap[i], heap[j]);
        i = j;
    }

    //min_heapify(siz/2, siz);
    return ans;
}

int main()
{
    scanf("%lld", &n); //n = 100000;
    srand(time(0));
    for (int i = 0, t; i < n; i++)
    {
        // cin >> t;
        scanf("%d", &t);

        //t = rand() % 100000 + 100000;
        if (heap[1] < t && siz)
        {
           
            // cout << " ans += t - pop();" << endl;
            //std::cout << t << " " << heap[1] << std::endl;

            
            if(flag[heap[1]] > 0) {
                flag[heap[1]]--;
            }
            else{
                ans1+=2;
            }
            ans += t - pop();
            // cout << "ans"
            //      << " " << ans << endl;
            // cout << "push(t)" << endl;
            push(t);
            push(t);
            flag[t]++;
        }
        else{
            push(t);
        }
    }
    //cout << ans << " " << ans1 << endl;
    printf("%lld %lld\n", ans, ans1);
}

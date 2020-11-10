#include <iostream>
#include <stack>
#include <cstdio>
int s[1000005];
int s1[1000005];

using namespace std;

int main()
{
    int num = 0;
    int ans = 0;
    cin >> num;
    s[0] = 0;
    s1[0] = 0;

    for (int i = 0; i < num; i++)
    {
        //cout << "i:" << i << endl;
        int input;
        cin >> input;
        int times = 1;
        while (s[0] && s[*s] <= input)
        {
            ans += s1[*s1];
            if (s[*s] == input)
                times += s1[*s1];
            s1[0]--;
            s[0]--;
        }
        //cout << *s1 << endl;

        if (s[0])
            ans++;

        //s.push(input);
        //s1.push(times);
        s[++*s] = input;
        s1[++*s1] = times;
    }
    cout << ans;
}

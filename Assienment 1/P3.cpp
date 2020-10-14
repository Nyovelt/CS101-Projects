#include <iostream>
#include <cstdio>

int n, k;
char input[1000005];
unsigned long hash[20771][150];
int ans = 0;
int alphabet[26];


//using namespace std;
int main()
{
    scanf("%d%d ", &n, &k);
    fgets(input, sizeof(input), stdin);
    // cout << n << k << endl;
    // cout << input << flush;
    for (register int i = 0; i <= n - k; i++)
    {
        //memset(alphabet, 0, sizeof(alphabet));
        if (i == 0)
        {
            for (register int j = 0; j < k; j++)
            {
                //std::cout << input[i+j];
                alphabet[input[i + j] - 'a']++;
                //str += input[i + j];
            }
        }
        else
        {
            alphabet[input[i - 1] - 'a']--;
            alphabet[input[i + k - 1] - 'a']++;
        }

        unsigned  long tmp = 0;
        unsigned  long str = 0;
        for (int j = 0; j < 26; j++)
        {
            int a = alphabet[j];
            while (a)
            {

                int b = a % 10;
                tmp = (tmp * 37 + b)  % 20771;
                str = (str * 41 + b) % 4294967291;
                a /= 10;
            }
            tmp = (tmp * 37 + j + 10) % 20771;
            str = (str * 41 + j + 10) % 4294967291;
        }
        //std::cout << " " <<tmp << std::endl;
        if (hash[tmp][0] != 0)
        {
            int flag = 0;
            for (int j = 0; j < hash[tmp][0]; j++)
            {
                if (str == hash[tmp][j + 1])
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                ++hash[tmp][0];
                hash[tmp][hash[tmp][0]] = str;
                ans++;
            }
        }
        else
        {
            ans++;
            ++hash[tmp][0];
            hash[tmp][hash[tmp][0]] = str;
        }
    }

    printf("%d", ans);
}
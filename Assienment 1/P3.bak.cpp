#include <iostream>
#include <cstdio>
#include <string.h>


char input[1000006];
int hash[19260818][10];
int k, n;
long long  ans=0;

int prime[26]= { 3 ,5, 7 ,11, 13, 17 ,19 ,23, 29,31 ,37 ,41 ,43, 47, 53, 59, 61, 67 ,71, 73, 79 ,83 ,89 ,97, 101 ,103};
unsigned long long prime_inv[26] = {1431655764,3435973833,613566756,390451572,991146298,3284386752,4068916381,2427590208,3110148728,138547332,2089443547,3352169593,3895435450,3015615332,810371187,3639802789,2393916195,3525719418,3206102344,1588549546,380566722,3518768383,965161189,1859676559,340195429,3627787906};
unsigned long long  t_tmp = 1;
int tt_tmp;

//using namespace std;
int main()
{
    for (int i=0; i<19260818;i++){
        hash[i][0] = 0;
    }
    scanf("%d%d ", &n, &k);
    fgets(input, sizeof(input), stdin);
    // cout << n << k << endl;
    // cout << input << flush;

    for (int i = 0; i <= n - k; i++)
    {
        
        unsigned long long tmp = 1;
        if (i == 0){
            for (int j=0; j<k; j++){
                //cout << input[i+j] ;
                tmp = (tmp * prime[input[i+j] -'a']) %  4294967291;
            }
            t_tmp = (tmp * 29) %  4294967291 ;
            tt_tmp = t_tmp % 19260817;
        }
        

        if(i){
            t_tmp = ( t_tmp * prime_inv[input[i-1] -'a'] * prime[input[i+k-1]-'a']) %  4294967291;
            tt_tmp = t_tmp % 19260817;
        }
        //std::cout << " " <<tt_tmp << std::endl;

        if(hash[tt_tmp][0] != 0){
            int flag=0;
            for (int j =0; j< hash[tt_tmp][0];j++){
                if (tt_tmp == hash[tt_tmp][j+1]){
                    flag=1;
                    break;
                }
            }
            if (!flag){
                hash[tt_tmp][++hash[tt_tmp][0]] = tt_tmp;
                ans++;
            }
        }
        else{
            ans ++;
            hash[tt_tmp][++hash[tt_tmp][0]] = tt_tmp;
        }
    }
    printf("%lld", ans);
}
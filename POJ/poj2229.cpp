#include<stdio.h>
#include<string.h>

typedef long long ll;
const ll mod = 1000000000;
const int maxn = 1000005;

int dp[maxn];
int n;


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        dp[i] = 1;
    for(int i=1;(1<<i)<=n;i++){
        int temp = (1<<i);
        for(int j = temp;j<=n;j++){
            dp[j] = (dp[j]+dp[j-temp])%mod;
        }
        // for(int iter=0;iter<=n;iter++){
        //     printf("%d ", dp[(i+1)&1][iter]);
        // }
        // printf("\n");
    }
    printf("%lld\n",dp[n]);
    return 0;
}

// #include<iostream>
// #include<stdio.h>
// #include<string.h>
// using namespace std;

// typedef long long ll;
// const int maxn = 1000005;
// const ll mod = 1000000000;
// ll dp[maxn];
// int n;

// int main(){
//     scanf("%d", &n);
//     dp[1] = 1;
//     for(int i=2;i<=n;i++){
//         if(i&1==1){
//             dp[i] = dp[i-1];
//         }else{
//             dp[i] = (dp[i-1] + dp[i>>1])%mod;
//         }
//     }
//     printf("%lld",dp[n]);

//     return 0;
// }




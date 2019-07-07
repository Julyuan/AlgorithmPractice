#include<stdio.h>
#include<string.h>

const int maxn = 1005;
const int inf = 0x3f3f3f3f;
int a[maxn];
int dp[maxn];
int n;

int max(int a, int b){
    return a>b?a:b;
}

void solve_n2(){
    memset(dp,0,sizeof(dp));
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            dp[i] = max(dp[i], dp[j] + (a[i]>=a[j]));
        }
    }
    printf("%d\n", dp[n-1]);
}

void solve_nlogn(){
    memset(dp, inf, sizeof(dp));


}
int main(){

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    solve_n2();
    return 0;
}
#include<string.h>
#include<stdio.h>

const int maxn = 505;
int dp[maxn][maxn];
int a[maxn][maxn];
int N;

int max(int a, int b){
    return a > b ? a : b;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d", &N);
    for(int i=1;i<=N;i++){
        for(int j = 1;j <= i; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] = a[i][j]+max(dp[i-1][j], dp[i-1][j-1]);
        }
    }

    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=i;j++){
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    int res = 0;
    for(int i=1;i<=N;i++){
        res = res < dp[N][i] ? dp[N][i] : res;
    }

    printf("%d\n", res);
    return 0;
}
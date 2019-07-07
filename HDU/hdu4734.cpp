#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>

using namespace std;

const int N = 10005;
int dp[12][N];

int f(int x){
    if(x==0)
        return 0;
    int ans = f(x/10);
    return ans * 2 + (x%10);
}

int all;
int a[12];

int dfs(int pos, int sum, bool limit){
    if(pos==-1)
        return sum <= all;
    if(sum > all)
        return 0;

    if(!limit && dp[pos][all-sum] != -1)
        return dp[pos][all-sum];

    int up = limit ? a[pos] : 9;
    int ans = 0;

    for(int i=0;i<=up;i++){
        ans += dfs(pos - 1, sum + i*(1<<pos), limit && i==a[pos]);
    }

    if(!limit)
        dp[pos][all-sum] = ans;
    return ans;
}

int solve(int x){
    int pos = 0;

    while(x){
        a[pos++] = x % 10;
        x /= 10;
    }

    return dfs(pos - 1, 0, true);
}

int main(){
  //  freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    int a, ri;
    int T;

    int Case = 1;
    scanf("%d",&T);

    memset(dp, -1, sizeof(dp));

    while(T--){
        scanf("%d%d", &a, &ri);
        all = f(a);
        printf("Case #%d: %d\n",Case++,solve(ri));

    }
}
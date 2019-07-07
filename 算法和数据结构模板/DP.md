# 各类动态规划范例整理

## 01背包问题DP

从后往前MAX_N，MAX_W代表最大的物品数目和最大的容量
dp[i][j]从第i个物品开始挑选总重小于j时，总价值的最大值

```cpp
int dp[MAX_N + 1][MAX_W + 1];

void solve(){
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= W; j++){
            if(j<w[j]){
                dp[i][j] = dp[i+1][j];
            }
            else{
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[0][W]);
}
```

## 01背包问题，从前往后

dp[i + 1][j] := 从前i个物品中选出总重量不超过j的物品时总价值的最大值

```cpp
void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            if(j<w[j]){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = max(dp[i][j],dp[i][j-w[i]]+v[i]);
            }
        }
    }
    printf("%d\n", dp[n][W]);
}
```

### 从前向后的另一种形式

```cpp
void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j+w[i] <= W){
                dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j]+v[i]);
            }
        }
    }
    printf("%d\n", dp[n][W]);
}
```

 LCS，最长公共子序列

```cpp
int n, m;
char s[MAX_N], t[MAX_M];

int dp[MAX_N + 1][MAXM + 1];

void solve(){
    for(int i = 0; i < n; i++){
        for(int j=0;j<m;j++){
            if(s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    printf("%d\n",dp[n][m]);
}
```

// 完全背包问题

```cpp
void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            if(j<w[i]){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = max(dp[i][j], dp[i+1][j-w[i]] + v[i]);
            }
        }
    }

    printf("%d\n", dp[n][W]);
}
```

// DP的滚动数组实现，只需要开一位数组即可

// 01背包

```cpp
int dp[MAX_W + 1];

void solve(){
    for(int i=0;i<n;i++){
        for(int j=W;j>=w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    printf("%d\n",dp[W]);
}

// van全背包
void solve(){
    for(int i=0;i<n;i++){
        for(int j=w[i];j<=W;j++){
            dp[j] = max(dp[j],dp[j-w[i]] + v[i]);
        }
    }
}
```

// 奇偶滚动数组

```cpp
int dp[2][MAX_W + 1];

void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            if(j<w[i]){
                dp[(i+1) & 1][j] = dp[i & 1][j];
            }else{
                dp[(i+1)&1][j] = max(dp[(i)&1][j], dp[(i+1) & 1][j-w[i]]+v[i]);
            }
        }
    }
}
```

// 针对背包问题重量大，价值小的情况
// dp[i+1][j] := 前i个物品挑选出价值总和为j时总重量的最小值（不存在则为inf)

```cpp
int dp[MAX_N + 1][MAX_N * MAX_V + 1];

void solve(){
    fill(dp[0], dp[0]+MAX_N*MAX_V+1,INF);
    dp[0][0] = 0;
    for(int i=0;j<n;i++){
        for(int j=0;j<=MAX_N*MAX_V;j++){
            if(j<v[i]){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i]);
            }
        }
    }

    int res = 0;
    for(int i=0;i<=MAX_N*MAX_V;i++)
        if(dp[n][i]<=W)
            res = i;
    
    printf("%d\n",res);
}
```


// 多重部分和问题

// dp[i+1][j] :=  用前i种数加和得到j时第i种数最多剩余多少个（不能加和得到i的情况下为-1）
// dp[i+1][j] = dp[i+1][j-ai] - 1

```cpp
int dp[MAX_K + 1];
void solve(){
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<=K;j++){
            if(dp[j]>=0)
                dp[j] = m[i];
            else if(j<a[i] || dp[j-a[i]] <= 0){
                dp[j] = -1;
            }else{
                dp[j] = dp[j-a[i]] - 1;
            }
        }
    }
    if(dp[K] >= 0)printf("Yes\n");
    else printf("No\n");
}
```

// 最长上升子序列（LIS）

```cpp
// nlogn
int dp[MAX_N];

void solve(){
    fill(dp, dp+n, INF);

    for(int i=0;i<n;i++){
        *lower_bound(dp, dp+n, a[i]) = a[i];
    }
    printf("%d\n", lower_bound(dp, dp+n, INF) - dp);
}
```

// n的m划分

```cpp
int n, m;

int dp[MAX_M + 1][MAX_N + 1];

void solve(){
    dp[0][0] = 1;

    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(j-i>=0){
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%M;
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    printf("%d\n",dp[m][n]);
}
```
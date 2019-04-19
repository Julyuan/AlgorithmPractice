#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int maxn = 10005;
const int inf = 0x3f3f3f3f;
int N,P,K;
int A[maxn],B[maxn],L[maxn];
int p[maxn];
int level[maxn];

vector<int>jly[1005];
vector<int>edge[1005];

int find(int x){
    return p[x] == x ? x : p[x] = find(p[x]);
}

int flag = 0;

bool C(int x){
    for(int i=1;i<=N;i++){
        p[i] = i;
    }
    memset(level, -1, sizeof(level));
    for(int i=0;i<P;i++){
        if(L[i]<=x){
            int u = find(A[i]);
            int v = find(B[i]);
            if(u!=v){
                p[u] = v;
            }
        }
    }

    for(int i=1;i<=N;i++){
        jly[i].clear();
    }
    for(int i=1;i<=N;i++){
        jly[find(i)].push_back(i);
    }

    queue<int>que;
    int start = find(1);
    int end = find(N);
    level[start] = 0;
    for(int i=0;i<jly[start].size();i++){
        que.push(jly[start][i]);
    }

    while(!que.empty()){
        int node = que.front();
        que.pop();
        for(int i=0;i<edge[node].size();i++){
            int ano = edge[node][i];
            if(level[find(ano)]<0){
                for(int i=0;i<jly[find(ano)].size();i++){
                    que.push(jly[find(ano)][i]);
                }
                level[find(ano)] = level[find(node)] + 1;
            }
        }
    }

    if(level[end]==-1 || level[end] > K)
        return true;
    else
    {
        return false;
    }
    
}
void solve(){
    int lb, ub;
    lb = 0;
    ub = inf;
    while(lb < ub){
        int mid = (ub+lb)>>1;
        if(C(mid)){
            lb = mid + 1;
        }else{
            flag =1;
            ub = mid;
        }
    }    
    if(flag)
        printf("%d\n", lb);
    else
    {
        printf("-1\n");
    }
    
}

int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    scanf("%d%d%d",&N,&P,&K);
    for(int i=0;i<P;i++){
        scanf("%d%d%d",&A[i],&B[i],&L[i]);
        edge[A[i]].push_back(B[i]);
        edge[B[i]].push_back(A[i]);
    }

    solve();
    return 0;
}
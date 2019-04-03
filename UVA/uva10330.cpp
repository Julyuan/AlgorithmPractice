#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_V 100005
using namespace std;

struct edge{int to, cap, rev;};

vector<edge>G[MAX_V];
const int inf = 0x3f3f3f3f;
int level[MAX_V];
int iter[MAX_V];

int N,M,C,B,D;

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size() - 1});
}

void bfs(int s){
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;

    que.push(s);
    while(!que.empty()){
        int v = que.front();
        que.pop();

        for(int i=0;i<G[v].size();i++){
            edge &e = G[v][i];
        //    printf("v = %d e.to = %d e.cap = %d\n",v,e.to,e.cap);

            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f){
    if(v==t)
        return f;
   // printf("iter[v] = %d\n", iter[v]);
    for(int &i = iter[v]; i < G[v].size(); i++){
        edge &e = G[v][i];
     //   printf("e.cap = %d\n", e.cap);
        if(e.cap > 0 && level[v] < level[e.to]){
            int d = dfs(e.to, t, min(f, e.cap));
       //     printf("d = %d\n",d);
            if(d>0){
                e.cap -= d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0;
    for(;;){
        bfs(s);
    //    printf("level[t] = %d\n", level[t]);
        if(level[t]<0)
            return flow;
        memset(iter,0,sizeof(iter));
        int f;

        while((f=dfs(s,t,inf)) > 0){
            flow += f;
        }
    }
} 

int main(){
    while(~scanf("%d",&N)){
        memset(iter,0,sizeof(iter));
        for(int i=0;i<MAX_V;i++)
            G[i].clear();
        for(int i=1;i<=N;i++){
            int temp;
            scanf("%d", &temp);
        //    printf("temp = %d i = %d\n", temp, i);
            add_edge(i*2,i*2+1,temp);
        }

        scanf("%d",&M);

        //printf("N = %d, M = %d\n",N,M);
        for(int i=0;i<M;i++){
            int s,e,C;
            scanf("%d%d%d",&s,&e,&C);
        //    printf("s = %d, e = %d\n",s,e);
            add_edge(2*s+1,2*e,C);
        }

        scanf("%d%d", &B,&D);
        //printf("B = %d D = %d\n", B, D);
        for(int i=0;i<B;i++){
            int temp;
            scanf("%d",&temp);
            add_edge(0, 2*temp, inf);
        }

        // for(int i=0;i<2*N;i++){
        //     printf("size%d = %d\n",i,G[i].size());
        // }
        for(int i=0;i<D;i++){
            int temp;
            scanf("%d",&temp);
        //    printf("temp = %d N = %d\n", temp,N);
            add_edge(2*temp+1,2*N+2,inf);
        }

        int res = max_flow(0,2*N+2);
        printf("%d\n",res);
    }
    return 0;
}
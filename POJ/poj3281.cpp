#include<string.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1005;

struct edge{
    int to, cap, rev;
};

vector<edge>G[maxn];
int iter[maxn];
int level[maxn];
int N,F,D;

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size() - 1});
}

void bfs(int s){
    memset(level, -1, sizeof(level));
    level[s] = 0;
    queue<int>que;
    que.push(s);
    while(!que.empty()){
        int v = que.front();que.pop();
        for(int i = 0; i < G[v].size(); i++){
            edge&e = G[v][i];
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
    for(int&i=iter[v];i<G[v].size();i++){
        edge&e = G[v][i];
        if(e.cap > 0 && level[e.to] > level[v]){
            int d = dfs(e.to, t, min(f,e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
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
        if(level[t]<0)
            return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,inf))!=0){
            flow+=f;
        }
    }
}

int main(){
    scanf("%d%d%d", &N, &F, &D);
    for(int i=1;i<=N;i++){
        int Fi, Di;
        int temp;

        scanf("%d%d",&Fi,&Di);
        for(int j=0;j<Fi;j++){
            scanf("%d", &temp);
            add_edge(2*N+temp,i,1);
        }

        for(int j=0;j<Di;j++){
            scanf("%d", &temp);
            add_edge(i+N,temp+2*N+F,1);
        }
   //     add_edge(0,i,1);
  //      add_edge(i+N,2*N+F+D+1,1);
        add_edge(i, i+N,1);
    }
    for(int i=1;i<=F;i++){
        add_edge(0, 2*N+i, 1);
    }
    for(int j=F+2*N+1;j<F+2*N+D+1;j++){
        add_edge(j, 2*N+F+D+1,1);
    }
    int res = max_flow(0,2*N+F+D+1);
    printf("%d\n", res);
    return 0;
}
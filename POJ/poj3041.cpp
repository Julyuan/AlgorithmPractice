#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int maxn = 1005;
const int inf = 0x3f3f3f3f;

struct edge{int to, cap, rev;};

vector<edge>G[maxn];
int level[maxn];
int iter[maxn];
int N,K;


void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
}

void bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()){
        int v = que.front();que.pop();
        for(int i=0;i<G[v].size();i++){
            edge& e = G[v][i];
            if(e.cap>0 && level[e.to] <0){
                que.push(e.to);
                level[e.to] = level[v] + 1;
            }
        }
    }
}

int dfs(int v, int t, int f){
    if(v==t)
        return f;
    for(int& i=iter[v];i<G[v].size();i++){
        edge& e = G[v][i];
        if(e.cap>0 && level[e.to] > level[v]){
            int d = dfs(e.to,t,min(f,e.cap));
            if(d>0){
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
        if(level[t] < 0)
            return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f = dfs(s,t,inf)) > 0){
            flow+=f;
        }
    }
}

int main(){
    scanf("%d%d",&N,&K);
    for(int i=0;i<K;i++){
        int a1,a2;
        scanf("%d%d",&a1,&a2);
        add_edge(a1, a2+N, 1);
    }

    for(int i=1;i<=N;i++){
        add_edge(0, i, 1);
        add_edge(i+N, 2*N+1, 1);
    }

    int res = max_flow(0,2*N+1);
    printf("%d\n",res);
    return 0;
}
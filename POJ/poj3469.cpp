#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 100005;

struct edge{
    int to, cap, rev;
};

vector<edge>G[maxn];
int iter[maxn];
int level[maxn];


void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}

void bfs(int s){
    memset(level, -1, sizeof(level));
    level[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int i = 0; i < G[v].size(); i++){
            edge& e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f){
    if(v == t)
        return f;
    for(int &i = iter[v]; i < G[v].size(); i++){
        edge& e = G[v][i];
        if(e.cap > 0 && level[e.to] > level[v]){
            int d = dfs(e.to, t, min(f, e.cap));
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
        if(level[t] < 0)
            return flow;
        int f;
        memset(iter,0,sizeof(iter));
        while((f = dfs(s, t, inf)) > 0){
            flow += f;
        }
    }
}


int N, M;

int main(){
    scanf("%d%d",&N,&M);

    for(int i=1;i<=N;i++){
        int Ai,Bi;
        scanf("%d%d",&Ai,&Bi);
        add_edge(0,i,Ai);
        add_edge(i,N+1,Bi);
    }

    for(int i=1;i<=M;i++){
        int a,b,w;
        scanf("%d%d%d", &a, &b, &w);
        add_edge(a,b,w);
        add_edge(b,a,w);
    }

    int res = max_flow(0,N+1);
    printf("%d\n", res);
    return 0;
}
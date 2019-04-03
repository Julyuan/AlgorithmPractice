#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1005;
struct edge{
    int to, cap, rev;
};

vector<edge>G[maxn];
int iter[maxn];
int level[maxn];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size() - 1});
}

void bfs(int s){
    queue<int>que;
    memset(level, -1, sizeof(level));
    level[s] = 0;
    que.push(s);

    while(!que.empty()){
        int v = que.front();que.pop();

        for(int i=0;i<G[v].size();i++){
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
    for(int& i=iter[v];i < G[v].size();i++){
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
    int res = 0;
    for(;;){
        bfs(s);
        if(level[t] < 0)
            return res;
        memset(iter,0,sizeof(iter));
        int f;
        while((f = dfs(s, t, inf)) > 0){
            res+=f;
        }
    }
}

int R,T,C;
int r[maxn],c[maxn];

int main(){
    
    scanf("%d",&T);
    for(int iter = 0; iter < T; iter++){
        scanf("%d%d",&R,&C);

        for(int i=0;i<maxn;i++){
            G[i].clear();
        }
        for(int i=1;i<=R;i++){
            scanf("%d",&r[i]);
        }

        for(int i=1;i<=C;i++){
            scanf("%d",&c[i]);
        }

        for(int i=R-1;i!=0;i--){
            r[i+1] -= r[i];
            r[i+1] -= C;
            add_edge(0,i+1,r[i+1]);
        }
        r[1] -= C;
        add_edge(0, 1, r[1]);

        for(int i=C-1;i!=0;i--){
            c[i+1] -= c[i];
            c[i+1] -= R;
            add_edge(i + R + 1, C+R+1, c[i+1]);
        }
        c[1] -= R;
        add_edge(R + 1, C + R + 1, c[1]);
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                add_edge(i,j+R,19);
            }
        }

        int res = max_flow(0,C+R+1);
        if(iter!=0)
            printf("\n");
        printf("Matrix %d\n", iter+1);

        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                printf("%d%c", 20 - G[i][j].cap, j==C ? '\n' : ' ');
            }
        }
    }

    return 0;
}
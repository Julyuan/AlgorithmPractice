#include<string.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1005;
int N,M;

struct edge{
    int to, cap, cost, rev;
};

vector<edge>G[maxn];
int dist[maxn];
int h[maxn];
typedef pair<int, int> P;
int V; // 代表顶点的数量
int prevv[maxn];
int preve[maxn];


void add_edge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0, -cost, G[from].size() - 1});
}

int min_cost_flow(int s, int t, int f){
    memset(h,0,sizeof(h));
    int res = 0;
    while(f > 0){
        priority_queue<P, vector<P>, greater<P> > que;
        memset(dist,inf,sizeof(dist));
        dist[s] = 0;
        que.push(P(0,s));

        while(!que.empty()){
            P p = que.top();
            que.pop();
            int v = p.second;
            if(p.first > dist[v])continue;
            for(int i=0;i<G[v].size();i++){
                edge&e = G[v][i];
                if(e.cap>0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    que.push(P(dist[e.to], e.to));
                    prevv[e.to] = v;
                    preve[e.to] = i;
                }
            }
        }
        if(dist[t]==inf)
            return -1;
        int d = f;
        for(int v = t; v!=s; v = prevv[v]){
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        for(int i=0;i<V;i++){
            h[i] += dist[i];
        }
        res += d * h[t];
        f-=d;
        for(int v = t; v != s; v = prevv[v]){
            edge& e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }

    return res;
}

int main(){
    scanf("%d%d",&N,&M);
    V = N;
    for(int i=0;i<M;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        add_edge(a-1,b-1,1,w);
        add_edge(b-1,a-1,1,w);

    }
    int res = min_cost_flow(0,N-1,2);
    printf("%d\n", res);
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 10005;

typedef pair<int,int> P;
struct edge{
    int to, cap, cost, rev;
};

vector<edge>G[maxn];
int dist[maxn];
int h[maxn];
int prevv[maxn];
int preve[maxn];
int n,m;
int V;

void add_edge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to, cap, cost, G[to].size()});
    G[to].push_back((edge){from, 0, -cost, G[from].size()-1});
}

int min_cost_flow(int s, int t, int f){

    int res = 0; // 这里是最终的费用
    while(f>0){
        priority_queue<P, vector<P>, greater<P> >que;
        memset(dist, inf, sizeof(dist));
        dist[s] = 0;
        que.push(P(0, s));

        while(!que.empty()){
            P p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first){
                continue;
            }
            for(int i=0;i<G[v].size();i++){
                edge&e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }
        if(dist[t] == inf)
            return -1;
        for(int v=0;v<V;v++){
            h[v] += dist[v];
        }
        int d = f;
        for(int v = t; v != s; v = prevv[v]){
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += h[t] * d;
        //printf("res = %d h[t] = %d\n", res, h[t]);
        for(int v = t; v != s; v = prevv[v]){
            edge& e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d; 
        }
    }
    return res;
}
int main(){
    while(scanf("%d",&n)){
        if(n==0)
            break;
        scanf("%d",&m);
        V = n;
        for(int i=0;i<maxn;i++){
            G[i].clear();
        }
        memset(prevv, 0, sizeof(prevv));
        memset(preve, 0, sizeof(preve));
        memset(h, 0, sizeof(h));
        memset(dist, 0, sizeof(dist));

        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add_edge(a - 1, b - 1, 1, c);
            add_edge(b - 1, a - 1, 1, c);

        }
        
        int ans = min_cost_flow(0, n-1, 2);
        if(ans==-1){
            printf("Back to jail\n");
        }else{
            printf("%d\n",ans);
        }
    }


    return 0;
}
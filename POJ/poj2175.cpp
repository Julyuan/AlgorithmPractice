// #include<stdio.h>
// #include<string.h>
// #include<vector>
// #include<queue>
// #include<algorithm>

// using namespace std;

// const int inf = 0x3f3f3f3f;
// const int maxn = 1005;

// struct edge{
//     int to, cap, cost, rev;
// };

// vector<edge>G[maxn];
// typedef pair<int, int> P;
// int dist[maxn];
// int h[maxn];
// int prevv[maxn];
// int preve[maxn];

// int V; // 网络中顶点个数

// void add_edge(int from, int to, int cap, int cost){
//     G[from].push_back((edge){to, cap,cost, G[to].size()});
//     G[to].push_back((edge){from, 0, -cost, G[from].size() - 1});
// }

// int min_cost_flow(int s, int t, int f){
//     int res = 0;
//     while(f > 0){
//         priority_queue<P, vector<P>, greater<P> >que;
//         memset(dist, inf, sizeof(dist));
//         dist[s] = 0;
//         que.push(P(0, s));

//         while(!que.empty()){
//             P p = que.top();
//             que.pop();
//             int v = p.second;
//             if(dist[v] < p.first){
//                 continue;
//             }

//             for(int i=0;i<G[v].size();i++){
//                 edge& e = G[v][i];
//                 if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
//                     dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
//                     prevv[e.to] = v;
//                     preve[e.to] = i;
//                     que.push(P(dist[e.to], e.to));
//                 }
//             }
//         }

//         if(dist[t] == inf)
//             return -1;
        
//         for(int i=0;i<V;i++)
//             h[i] += dist[i];
        
//         int d = f;
//         for(int v = t; v != s; v = prevv[v]){
//             d = min(d, G[prevv[v]][preve[v]].cap);
//         }
//         //printf("d = %d\n", d);
//         f -= d;
//         res += h[t] * d;
//        // printf("res = %d\n", res);
//         for(int v = t; v != s; v = prevv[v]){
//             edge& e = G[prevv[v]][preve[v]];
//             e.cap -= d;
//             G[v][e.rev].cap += d;
//         }
//     }
//     return res;
// }

// int N,M;
// int D[maxn][maxn];
// int E[maxn][maxn];
// int B[maxn][3];
// int S[maxn][3];

// int main(){

//     scanf("%d%d",&N,&M);
//     int sum = 0;
//     V = N + M + 2;
//     for(int i = 1; i <= N; i++){
//         scanf("%d%d%d",&B[i][0],&B[i][1],&B[i][2]);
//         sum+=B[i][2];
//     }

//     for(int i = 1; i <= M; i++){
//         scanf("%d%d%d",&S[i][0],&S[i][1],&S[i][2]);
//     }

//     for(int i=1;i<=N;i++){
//         for(int j=1;j<=M;j++){
//             scanf("%d",&E[i][j]);
//             D[i][j] = abs(B[i][0] - S[j][0]) + abs(B[i][1] - S[j][1]) + 1;
//         }
//     }

//     for(int i=1;i<=N;i++){
//         add_edge(0, i, B[i][2], 0);
//     }

//     for(int i = N+1;i <= N+M;i++){
//         add_edge(i,N+M+1,S[i-N][2],0);
//     }

//     for(int i=1;i<=N;i++){
//         for(int j=1;j<=M;j++){
//             add_edge(i, j+N, inf, D[i][j]);
//         }
//     }
//     int total_cost = 0;
//     for(int i=1;i<=N;i++){
//         for(int j=1;j<=M;j++){
//             total_cost += D[i][j] * E[i][j];
//         }
//     }
//     int res = min_cost_flow(0,N+M+1,sum);
//   //  printf("res = %d total_cost = %d\n", res, total_cost);
//     if(res < total_cost){
//         printf("SUBOPTIMAL\n");
//         for(int i=1;i<=N;i++){
//             for(int j=1;j<G[i].size();j++){
//                 printf("%d%c",inf-G[i][j].cap, j==G[i].size() - 1 ? '\n':' ');
//             }
//         }
//     }else{
//         printf("OPTIMAL\n");
//     }
//     return 0;
// }

#include<stdio.h>
#include<string.h>

const int maxn = 505;
const int inf = 0x3f3f3f3f;

int N,M;
int X[maxn], Y[maxn], B[maxn];
int P[maxn], Q[maxn], C[maxn];
int E[maxn][maxn];

int g[maxn][maxn];
int prev[maxn][maxn];
bool used[maxn];

int abs(int a){
    return a>0?a:-a;
}
void solve(){
    int V = N+M+1;

    memset(g,inf,sizeof(g));
    for(int j=0;j<M;j++){
        int sum = 0;
        for(int i=0;i<N;i++){
            int c = abs(X[i] - P[j]) + abs(Y[i] - Q[j]) + 1;
            g[i][N + j] = c;
            if(E[i][j] > 0)g[N+j][i] = -c;

            sum += E[i][j];
        }

        if(sum > 0)
            g[N+M][N+j] = 0;
        if(sum < C[j])
            g[N+j][N+M] = 0;
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            prev[i][j] = i;
        }
    }

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(g[i][j] > g[i][k] + g[k][j]){
                    g[i][j] = g[i][k] + g[k][j];
                    prev[i][j] = prev[k][j];
                    if(i==j && g[i][i]<0){
                        memset(used, false, sizeof(used));
                        for(int v = i; !used[v]; v = prev[i][v]){
                            used[v] = true;
                            if(v != N+M && prev[i][v] != N+M){
                                if(v >= N){
                                    E[prev[i][v]][v-N]++;
                                }else{
                                    E[v][prev[i][v] - N]--;
                                }
                            }
                        }

                        printf("SUBOPTIMAL\n");
                       // printf("N = %d, M = %d\n",N,M);
                        for(int x=0;x<N;x++){
                            for(int y=0;y<M;y++){
                                printf("%d%c", E[x][y], y+1 == M ? '\n':' ');
                            }
                        }
                        return;
                    }
                }
            }
        }
    }
    printf("OPTIMAL\n");
}

int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        scanf("%d%d%d",&X[i],&Y[i],&B[i]);

    for(int i=0;i<M;i++)
        scanf("%d%d%d",&P[i],&Q[i],&C[i]);

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf("%d",&E[i][j]);
    solve();
    return 0;
}






















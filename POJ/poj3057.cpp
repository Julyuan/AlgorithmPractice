// #include<stdio.h>
// #include<string.h>
// #include<vector>
// #include<algorithm>
// #include<queue>

// using namespace std;

// const int inf = 0x3f3f3f3f;
// const int maxn = 15;
// const int maxm = 5005;
// const int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};

// int T;
// int X,Y;
// int V;
// vector<int>G[maxm];
// int match[maxm];
// int used[maxm];

// char field[maxn][maxn];
// vector<int> dX, dY;
// vector<int> pX, pY;
// int dist[maxn][maxn][maxn][maxn];


// void add_edge(int u, int v){
//     G[u].push_back(v);
//     G[v].push_back(u);
// }
// bool dfs(int v){
//     used[v] = true;
//     for(int i=0;i<G[v].size();i++){
//         int u = G[v][i];
//         int w = match[u];
//         if(w<0 || (!used[w] && dfs(w))){
//             match[v] = u;
//             match[u] = v;
//             return true;
//         }
//     }
//     return false;
// }

// int bipartite_matching(){
//     memset(match, -1, sizeof(match));
//     int res = 0;
//     for(int i=0;i<V;i++){
//         if(match[i] < 0){
//             memset(used,0,sizeof(used));
//             if(dfs(i))
//                 res++;
//         }
//     }
//     return res;
// }

// bool C(int t){
//     int d = dX.size();
//     int p = pX.size();
//     V = t*d + p;
//     for(int v = 0; v < V; v++)
//         G[v].clear();
    
//     for(int i=0;i<d;i++){
//         for(int j=0;j<p;j++){
//             if(dist[dX[i]][dY[i]][pX[j]][pY[j]] >= 0){
//                 for(int k = dist[dX[i]][dY[i]][pX[j]][pY[j]]; k <= t; k++){
//                     add_edge((k-1)*d+i, t*d + j);
//                 }
//             }
//         }
//     }

//    // printf("131\n");
//     return bipartite_matching() == p;
// }

// bool judge(int x, int y){
//     if(0 <= x && x < X && 0 <= y && y < Y && field[x][y] == '.'){
//     //    printf("judge success\n");
//         return true;
//     }else{
//         return false;
//     }
// }

// void bfs(int x, int y, int d[maxn][maxn]){
//     queue<int>qx, qy;
//     d[x][y] = 0;

//     qx.push(x);
//     qy.push(y);
//     while(!qx.empty()){
//         x = qx.front(); qx.pop();
//         y = qy.front(); qy.pop();

//         for(int k=0;k<4;k++){
//             int x2 = x + dx[k];
//             int y2 = y + dy[k];
//            // printf("x2 = %d, y2 = %d\n",x2,y2);
//             if(judge(x2, y2) &&  d[x2][y2] < 0){
//            //     printf("jlyy\n");
//                 d[x2][y2] = d[x][y] + 1;
//                 qx.push(x2);
//                 qy.push(y2);
//             }
//         }
//     }
// }

// void solve(){
//     int n = X * Y;
//     dX.clear(); dY.clear();
//     pX.clear(); pY.clear();
//     memset(dist, -1,sizeof(dist));
//     //printf("127\n");
//     for(int x = 0; x < X; x++){
//         for(int y = 0; y < Y; y++){
//             if(field[x][y] == 'D'){
//                 //printf("jlyyy\n");
//                 dX.push_back(x);
//                 dY.push_back(y);
//                 bfs(x, y, dist[x][y]);
//             }else if(field[x][y]=='.'){
//                 pX.push_back(x);
//                 pY.push_back(y);
//             }
//         }
//     }
//     //printf("128\n");
//     int lb = -1;
//     int ub = n + 1;
//     while(ub - lb > 1){
//         int mid = (lb + ub) >> 1;
//         if(C(mid)) ub = mid; 
//         else lb = mid;
//     }

//     //printf("129\n");
//     if(ub > n){
//         printf("impossible\n");
//     }else{
//         printf("%d\n",ub);
//     }
// }
// int main(){
//     scanf("%d",&T);
//     for(int iter=0;iter<T;iter++){
//         scanf("%d%d", &X, &Y);
//         getchar();
//         for(int i=0;i<X;i++){
//             scanf("%s",field[i]);
//        //     printf("%s\n",field[i]);
//         }
//         //printf("\n");
//         solve();
//     }

//     return 0;
// }

#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 15;
const int maxm = 10005;
const int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};

int T;
int X,Y;
int V;
vector<int>G[maxm];
int match[maxm];
int used[maxm];

char field[maxn][maxn];
vector<int> dX, dY;
vector<int> pX, pY;
int dist[maxn][maxn][maxn][maxn];


void add_edge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v){
    used[v] = true;
    for(int i=0;i<G[v].size();i++){
        int u = G[v][i];
        int w = match[u];
        if(w<0 || (!used[w] && dfs(w))){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int bipartite_matching(){
    memset(match, -1, sizeof(match));
    int res = 0;
    for(int i=0;i<V;i++){
        if(match[i] < 0){
            memset(used,0,sizeof(used));
            if(dfs(i))
                res++;
        }
    }
    return res;
}

bool judge(int x, int y){
    if(0 <= x && x < X && 0 <= y && y < Y && field[x][y] == '.'){
    //    printf("judge success\n");
        return true;
    }else{
        return false;
    }
}

void bfs(int x, int y, int d[maxn][maxn]){
    queue<int>qx, qy;
    d[x][y] = 0;

    qx.push(x);
    qy.push(y);
    while(!qx.empty()){
        x = qx.front(); qx.pop();
        y = qy.front(); qy.pop();

        for(int k=0;k<4;k++){
            int x2 = x + dx[k];
            int y2 = y + dy[k];
           // printf("x2 = %d, y2 = %d\n",x2,y2);
            if(judge(x2, y2) &&  d[x2][y2] < 0){
           //     printf("jlyy\n");
                d[x2][y2] = d[x][y] + 1;
                qx.push(x2);
                qy.push(y2);
            }
        }
    }
}

void solve(){
    int n = X * Y;
    dX.clear(); dY.clear();
    pX.clear(); pY.clear();
    memset(dist, -1,sizeof(dist));
    //printf("127\n");
    for(int x = 0; x < X; x++){
        for(int y = 0; y < Y; y++){
            if(field[x][y] == 'D'){
                //printf("jlyyy\n");
                dX.push_back(x);
                dY.push_back(y);
                bfs(x, y, dist[x][y]);
            }else if(field[x][y]=='.'){
                pX.push_back(x);
                pY.push_back(y);
            }
        }
    }
    //printf("128\n");
    int d = dX.size();
    int p = pX.size();
    V = n*d + p;
    for(int v = 0; v < V; v++)
        G[v].clear();
    
    for(int i=0;i<d;i++){
        for(int j=0;j<p;j++){
            if(dist[dX[i]][dY[i]][pX[j]][pY[j]] >= 0){
                for(int k = dist[dX[i]][dY[i]][pX[j]][pY[j]]; k <= n; k++){
                    add_edge((k-1)*d+i, n*d + j);
                }
            }
        }
    }

    if(p==0){
        printf("0\n");
        return;
    }
    //printf("129\n");
    int num = 0;
    memset(match, -1, sizeof(match));
    for(int v = 0; v < n * d; v++){
        memset(used, 0, sizeof(used));
        if(dfs(v)){
            if(++num == p){
                printf("%d\n", v / d + 1);
                return;
            }
        }
    }

    printf("impossible\n");
}
int main(){
    scanf("%d",&T);
    for(int iter=0;iter<T;iter++){
        scanf("%d%d", &X, &Y);
        getchar();
        for(int i=0;i<X;i++){
            scanf("%s",field[i]);
       //     printf("%s\n",field[i]);
        }
        //printf("\n");
        solve();
    }

    return 0;
}
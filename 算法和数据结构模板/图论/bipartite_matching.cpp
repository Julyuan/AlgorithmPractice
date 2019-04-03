#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int maxn = 1005;
int V;
vector<int>G[maxn];
int match[maxn];
int used[maxn];

void add_edge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v){
    used[v] = 0;
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
    int res = 0;
    memset(match,-1,sizeof(match));
    for(int i=0;i<V;i++){
        if(match[i]<0){
            memset(used,0,sizeof(used));
            res+=dfs(i);
        }
    }
    return res;
}

int main(){

    return 0;
}
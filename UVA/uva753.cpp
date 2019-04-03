#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string>
#include<iostream>
#include<map>
#include<set>

using namespace std;

struct edge{
    int to, cap, rev;
};

const int maxn = 1005;
const int inf = 0x3f3f3f3f;

typedef pair<int, int> pii;

map<string, int>m1;
set<string>s1;
int cnt = 2;

vector<edge>G[maxn];

int iter[maxn];
int level[maxn];
int m,n,k,num;

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
        int v = que.front();
        que.pop();
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
    if(v == t)
        return f;
    for(int&i = iter[v]; i < G[v].size(); i++){
        edge&e = G[v][i];
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
        while((f = dfs(s,t,inf))>0){
            flow += f;
        }
    }
    return -1;
}

int main(){
    scanf("%d",&num);

    for(int iter=0;iter<num;iter++){
        s1.clear();
        m1.clear();
        cnt = 2;
        for(int i=0;i<maxn;i++){
            G[i].clear();
        }
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            string temp;
            cin >> temp;
            if(s1.count(temp)==0){
                s1.insert(temp);
                m1.insert(make_pair(temp, cnt++));
            }
            auto p = m1.find(temp);
        //    cout << "temp = "<< temp << " p->second = " << p->second << endl;
            add_edge(0,p->second,1);
        }

        scanf("%d",&m);
        for(int i=0;i<m;i++){
            string temp1, temp2;
            cin >> temp1 >> temp2;
            if(s1.count(temp1)==0){
                s1.insert(temp1);
                m1.insert(make_pair(temp1,cnt++));
            }
            auto p = m1.find(temp1);
            if(s1.count(temp2)==0){
                s1.insert(temp2);
                m1.insert(make_pair(temp2,cnt++));
            }
            auto p2 = m1.find(temp2);
            add_edge(p->second, 1, 1);
            add_edge(p2->second, p->second, 1);
        //    cout << "temp1 = "<< temp1 << " temp2 = " << temp2 << endl;
        //    cout << "p->second = " << p->second << " p2->second = " << p2->second << endl;
        }   
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            string temp1, temp2;
            cin >> temp1 >> temp2;
            if(s1.count(temp1)==0){
                s1.insert(temp1);
                m1.insert(make_pair(temp1,cnt++));
            }

            if(s1.count(temp2)==0){
                s1.insert(temp2);
                m1.insert(make_pair(temp2,cnt++));
            }
            auto p1 = m1.find(temp1);
            auto p2 = m1.find(temp2);

            add_edge(p2->second, p1->second, inf);
            //    cout << "temp1 = "<< temp1 << " temp2 = " << temp2 << endl;
            //    cout << "p1->second = " << p1->second << " p2->second = " << p2->second << endl;                
        }

        int res = max_flow(0,1);
        printf("%d\n", m-res);
        if(iter!=num-1)
            printf("\n");
    }

    
    return 0;
}

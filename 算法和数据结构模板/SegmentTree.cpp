#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

#define maxn 800010
#define root 1

using namespace std;
typedef long long ll;
ll mod, v;
int m,n,k;


struct Segtree{
    #define lc(x) ((x)<<1)
    #define rc(x) (((x)<<1) | 1)

    int l[maxn], r[maxn];
    ll s[maxn], ADD[maxn];

    void update(int x){
        s[x] = max(s[lc(x)], s[rc(x)]);
    }

    void push(int x){
        ADD[lc(x)] = ADD[lc(x)] + ADD[x];
        ADD[rc(x)] = ADD[rc(x)] + ADD[x];
        s[lc(x)] += ADD[x];
        s[rc(x)] += ADD[x];
        ADD[x] = 0;
    }

    void op_add(int x, int L, int R){
        push(x);
        if(R < l[x] || r[x] < L)
            return;
        
        if(L <= l[x] && r[x] <= R){
            s[x]++;
            ADD[x]++;
            return;
        }

        op_add(lc(x), L,R);
        op_add(rc(x),L,R);
        update(x);
    }

    ll op_query(int x, int L, int R){
        push(x);
        if(R<l[x] || r[x]<L)
            return 0;
        if(L <= l[x] && r[x] <= R)
            return s[x];
        return max(op_query(lc(x), L, R), op_query(rc(x), L, R));
    }

    void build(int x, int L, int R){
        l[x] = L, r[x] = R;
        ADD[x] = 0;
        s[x] = 0;

        int mid = (L+R) >> 1;
        build(lc(x), L, mid);
        build(rc(x), mid+1, R);
    }
}seg;

const int maxk = 200000;
int main(){
    scanf("%d%d%d",&n, &m, &k);
    seg.build(1, 1, maxk);
    int i;
    for(i=1;i<=n;i++){
        int temp;
        scanf("%d", &temp);
        seg.op_add(1, temp, temp+k);
        if(seg.op_query(1,1,maxk)>=m){
            printf("%d",i);
            break;
        }
    }

    if(i>n){
        printf("impossible\n");
    }
}
#include<stdio.h>
#include<string.h>
#include<math.h>

typedef long long ll;

const int DAT_SIZE = (1<<18) - 1;
const int maxn = 100005;

int N,Q;
int A[maxn];
char T[maxn];
int L[maxn],R[maxn],X[maxn];

ll data[DAT_SIZE], datb[DAT_SIZE];

ll max(ll a, ll b){
    return a>b?a:b;
}

ll min(ll a, ll b){
    return a>b?b:a;
}


void add(int a, int b, int x, int k, int l, int r){
    if(a<=l && r<=b){
        data[k] += x;
    }
    else if (l<b && a<r){
        datab[k] += (min(b,r) - max(a,l)) * x;
        int m = (l+r)>>1;
        add(a, b, x, k*2+1, l, m);
        add(a,b,x,k*2+2,m,r);
    }
}

ll sum(int a, int b, int k, int l, int r){
    if(b<=l || r<=a){
        return 0;
    }else if(a<=l && r<=b){
        return data[k] * (r-l) + datb[k];
    }else{
        ll res = (min(b,r) - max(a,l)) * data[k];
        m = (l+r) >> 1;
        res += sum(a, b, k*2+1,l,m);
        res += sum(a, b, k*2+2, m, r);
        return res;
    }
}

void solve(){
    for(int i=0;i<N;i++){
        add(i,i+1,A[i],0,0,N);
    }
    
    for(int i=0;i<Q;i++){
        if(T[i]=='C'){
            add(L[i], R[i]+1, X[i], 0,0,N);
        }else{
            printf("%lld\n", sum(L[i], R[i]+1, 0, 0, N));
        }
    }
}
int main(){


    return 0;
}
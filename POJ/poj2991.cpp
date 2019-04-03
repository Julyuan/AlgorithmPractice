#include<stdio.h>
#include<math.h>
#include<string.h>

const int maxn = (1<<15)-1;
const int maxm = 10005;
#define M_PI 3.14159265358
int N,C;
int L[maxm];
int S[maxn],A[maxn];

double vx[maxn], vy[maxn];
double ang[maxn];

double prv[maxm];

void init(int k, int l, int r){
    ang[k] = vx[k] = 0.0;
    if(r-l == 1){
        vy[k] = L[l];
    }else{
        int chl = 2*k+1,chr = 2*k+2;
        init(chl,l,(l+r)>>1);
        init(chr,(l+r)>>1,r);
        vy[k] = vy[chl] + vy[chr];
    }
}

void change(int s, double a, int v, int l, int r){
    if(s<=l) return;
    else if(s<r){
        int chl = 2*v+1, chr = 2*v+2;
        int m = (l+r) >> 1;
        change(s,a,chl,l,m);
        change(s,a,chr,m,r);
        if(s <= m){
            ang[v] += a;
        }

        double s = sin(ang[v]), c = cos(ang[v]);
        vx[v] = vx[chl] + (c*vx[chr]-s*vy[chr]);
        vy[v] = vy[chl] + (s*vx[chr]+c*vy[chr]);
    }

}

void solve(){
    init(0,0,N);
    for(int i=1;i<N;i++)
        prv[i] = M_PI;
    for(int i=0;i<C;i++){
        int s = S[i];
        double a = A[i] / 360.0 *2 *M_PI;
        change(s,a-prv[s],0,0,N);
        prv[s] = a;

        printf("%.2f %.2f\n",vx[0],vy[0]);
    }
}
int main(){
  //  freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);

    while(scanf("%d%d",&N,&C)!=EOF){
        for(int i=0;i<N;i++)
            scanf("%d",&L[i]);
        for(int i=0;i<C;i++)
            scanf("%d%d",&S[i],&A[i]);
        solve();
        printf("\n");
    }

    return 0;
}
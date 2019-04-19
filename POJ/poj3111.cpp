#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 100005;
int n,k;
int v[maxn], w[maxn];
int r[maxn];
double jly;
double y[maxn];

int cmp(const int&x, const int&y){
    return (v[x]-w[x]*jly) > (v[y]-w[y]*jly);
}
bool C(double x){
    for(int i=0;i<n;i++){
        y[i] = 1.0*(v[i] - w[i] * x);
    }

    sort(y, y+n);
    double total = 0;
    for(int i=0;i<k;i++)
        total += y[n-1-i];
    return total >= 0;
}

void solve(){
    double lb = 0;
    double ub = 10000005;
    double mid;
    for(int i=0;i<40;i++){
        mid = (lb+ub) / 2;
        if(C(mid)){
            lb = mid;
        }else{
            ub = mid;
        }
    }
    jly = mid;
    for(int i=0;i<n;i++)
        r[i] = i;
    
    sort(r,r+n,cmp);
    // for(int i=0;i<n;i++){
    //     printf("%d%c",r[i],i==n-1 ? '\n' : ' ');
    // }
    //printf("ub = %lf\n", ub);
    for(int i=0;i<k;i++){
        printf("%d%c",r[i] + 1, i==k-1 ? '\n':' ');
    }
}
int main(){
 //   freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);

    scanf("%d%d",&n, &k);
    for(int i=0;i<n;i++)
        scanf("%d%d",&v[i],&w[i]);

    solve();
    return 0;
}
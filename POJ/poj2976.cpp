#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

typedef long long ll;
const int maxn = 1005;
const int inf = 0x3f3f3f3f;
int n, k;
double a[maxn], b[maxn];
double c[maxn];

bool C(double x){
    for(int i=0;i<n;i++){
        c[i] = a[i] - x*b[i];
    }
    sort(c, c+n);

    double sum = 0;
    for(int i=0;i<n-k;i++){
        sum+=c[n-i-1];
    }
    return sum >= 0;
}


void solve(){
    double lb=0, ub = inf;
    for(int i=0;i<100;i++){
        double mid = 0.5*(lb+ub);
        if(C(mid))
            lb = mid;
        else
            ub = mid;
    }
    printf("%d\n", int(0.5+ub*100));
}
int main(){
 //   freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);

    while(~scanf("%d%d",&n,&k)){
        if(n==0 && k==0)
            break;
        ll total;
        for(int i=0;i<n;i++){
            scanf("%lf",&a[i]);
        }

        for(int i=0;i<n;i++){
            scanf("%lf", &b[i]);
        }

        solve();
    }
    return 0;
}
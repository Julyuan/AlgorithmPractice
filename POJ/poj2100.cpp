#include<stdio.h>
#include<string.h>
#include<vector>

typedef long long ll;

using namespace std;

vector<vector<ll> > ans;
ll n;

void solve(){
    ll s = 1;
    ll e = 2;
    ll sum = 1; // 区间[s, e)
    while((e-1) * (e-1) <= n){
        if(sum==n){
            vector<ll>temp;
            for(ll i=s;i<e;i++){
                temp.push_back(i);
            }
            ans.push_back(temp);
            sum -= s*s;
            s++;
            if(s==e){
                sum+=e*e;
                e++;
            }
        }else if(sum > n){
            sum -= s*s;
            s++;
            if(s==e){
                sum += e*e;
                e++;
            }
        }else{
            sum += e*e;
            e++;
        }
    }
    printf("%d\n", ans.size());
    for(int i=0;i < ans.size(); i++){
        printf("%d", ans[i].size());
        for(int j=0;j<ans[i].size();j++){
            printf(" %lld",ans[i][j]);
        }
        printf("\n");
    }
}


int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    scanf("%lld",&n);

    solve();
    return 0;
}
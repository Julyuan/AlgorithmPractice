#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int maxn = 20005;
vector<int>prime;

bool a[maxn];
int N;
    int jly = 0;

void solve(){
 //   printf("jly = %d\n", jly++);
    int cnt = 0,sum = prime[0];
    int left = 0, right = 1;
    while(prime[right-1]<=N){
    //    printf("sum = %d\n", sum);
        if(sum==N){
            cnt++;
            left++;
            sum-=prime[left-1];
            if(right==left){
                sum+=prime[right++];
            }
        }else if(sum>N){
            left++;
            sum-=prime[left-1];
            if(right==left){
                sum+=prime[right++];
            }
        }else{
            right++;
            sum+=prime[right-1];
        }
    }
    printf("%d\n", cnt);
}

void init(){
    for(int i=2;i<maxn;i++){
        a[i] = 1;
    }    
    for(int i=2;i<maxn;i++){
        if(a[i]){
            prime.push_back(i);
            for(int j=2;i*j<maxn;j++){
                a[i*j] = 0;
            }
        }
    }

    // for(int i=0;i<20;i++){
    //     printf("%d%c", prime[i], i==19?'\n':' ');
    // }
}

int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    init();

    while(~scanf("%d", &N)){
        if(N==0)
            break;
        solve();
    }
    return 0;
}
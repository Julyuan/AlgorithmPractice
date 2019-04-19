#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int maxn = 100005;
int N,newN;
int X[maxn];

// method 1
// void solve(){
//     int lb = ;
//     int ub = ;
//     int cnt;
//     while(){
//         int mid = (lb + ub) >> 1;
//         cnt = 0;
//         for(int i=0;i<N;i++){
//             int res = mid + X[i];
//             cnt += N - (lower_bound(X+i,X+N,res) - X);
//         }

//         if(cnt<n/2+1){
//             left = mid + 1;
//         }else{
//             right = mid;
//         }
//     }

// }

// method 2
void solve(){
    int lb = 0;
    int ub = 1000000005;
    int cnt = 0;
    while(lb<ub){
        //printf("1277\n");
        int mid = (lb + ub) >> 1;
        //printf("mid = %d\n",mid);
        cnt = 0;
        for(int i=0;i<N;i++){
            int res = mid + X[i];
            int temp;
            temp = (upper_bound(X+i,X+N,res) - X);
            //printf("temp = %d\n", temp);
            cnt += N - temp;
        }
       // printf("cnt = %d\n", cnt);
        if(cnt > newN/2){
            lb = mid + 1;
        }else{
            ub = mid;
        }
    }

    printf("%d\n", lb);
}

int main(){
 //   freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);

    while(scanf("%d",&N)!=EOF){
        for(int i=0;i<N;i++){
            scanf("%d",&X[i]);
        }

        sort(X, X+N);
        newN = (N-1)*N / 2;
        solve();
    }


    return 0;
}
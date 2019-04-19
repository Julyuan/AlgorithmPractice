// #include<stdio.h>
// #include<string.h>
// #include<vector>
// #include<queue>
// #include<algorithm>

// using namespace std;

// const int maxn = 100005;
// const int inf = 0x3f3f3f3f;
// const int yiwan = 10000;
// int N,M;
// int row[maxn], col[maxn];

// int find1(double x){
//     return lower_bound(row,row+N,x) - row - 1;
// }

// int find2(double x){
//     return upper_bound(row, row+N, x) - row;
// }

// bool C(int x){
//     int cnt = 0;
//     for(int i=0;i<N;i++){
//         int colv = col[i];

//         double gap = -(100000+colv) / 2;

//         if(gap < 0){
//             int lb,ub;
//             lb = 0;
//             ub = N;
//             while(lb < ub){
//                 int mid = (lb + ub) >> 1;
//                 if(row[mid] * row[mid] + row[mid] * (yiwan+colv) < x-colv*colv+yiwan*colv){
                    
//                 }else{

//                 }
//             }
//             cnt+=lb;
//         }else if(gap > row[N]){
//             int lb,ub;
//             lb = 0;
//             ub = N;
//             while(lb < ub){
//                 int mid = (lb+ub) >> 1;
//                 if(row[mid] * row[mid] + row[mid] * (yiwan+colv) < x-colv*colv+yiwan*colv){
                    
//                 }else{

//                 }
//             }

//             cnt += ub;
//         }else{
//             int lb, ub, temp;
//             int a1 = find1(gap);
//             int a2 = find2(gap);
//             lb = 0;
//             ub = a1;
//             while(lb<ub){
//                 int mid = (lb+ub) >> 1;
//                 if(row[mid] * row[mid] + row[mid] * (yiwan+colv) < x-colv*colv+yiwan*colv){
                    
//                 }else{

//                 }
//             }
//             temp = lb;
//             lb = a2;
//             ub = N;
//             while(lb<ub){
//                 int mid = (lb+ub) >> 1;
//                 if(row[mid] * row[mid] + row[mid] * (yiwan+colv) < x-colv*colv+yiwan*colv){
                    
//                 }else{

//                 }
//             }
//             cnt += (lb - temp);
//         }
//     }
//     return cnt > M;
// }

// void solve(){
//     int lb = 0;
//     int ub = inf;

//     while(lb < ub){
//         int mid = (lb + ub) >> 1;
//         if(C(mid)){

//         }else{

//         }
//     }
// }

// int main(){
//     freopen("in.txt","r",stdin);
//     freopen("out.txt","w",stdout);

//     scanf("%d%d",&N,&M);
//     for(int i=0;i<N;i++){
//         scanf("%d%d",&row[i],&col[i]);
//     }

//     sort(row, row+N);
    
//     solve();
//     return 0;
// }

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef long long ll;

const int maxn = 100005;
const int yiwan = 10000;
ll N,M;
int T;

void solve(){

    if((N+1) * N >= 2 * M){
        ll n = sqrt(M*2+0.1);
        if(n*(n+1)>=M*2){
            n--;
            //printf("127\n");
        }
        M -= (n+1)*n  / 2;
        ll i = M;
        ll j = N-n+M-1;
       // printf("case 1: n = %lld, i = %d, j = %d\n",n,i,j);
        printf("%lld\n", i*i + 100000 * i + j*j - 100000 * j + i * j);
    }else{
        M = N*N - M + 1;
        ll n = sqrt(M*2+0.1);
        if(n*(n+1) >= 2*M){
            n--;
        //    printf("128\n");
       //     printf("128 n = %lld M = %lld\n",n,M);
        }
        M -= (n+1)*n/2;
        ll i = N-M+1;
        ll j = n+1-M+1;
        //printf("case 2: n = %lld, i = %d, j = %d M = %lld\n",n,i,j,M);
        printf("%lld\n", i*i + 100000 * i + j*j - 100000 * j + i * j);
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
   // int mat_size = 4;
    // for(int i=1;i<=mat_size;i++){
    //     for(int j=1;j<=mat_size;j++){
    //         printf("%7d%c",i*i + 100000 * i + j*j - 100000 * j + i * j, j==mat_size?'\n':' ');
    //     }
    // }
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%lld%lld",&N,&M);
        solve();
    }
    
    return 0;
}

// #include<stdio.h>
// #include<string.h>


// const int mat_size = 10;
// int main(){
//     freopen("out.txt","w",stdout);

//     for(int i=1;i<=mat_size;i++){
//         for(int j=1;j<=mat_size;j++){
//             printf("%7d%c",i*i + 100000 * i + j*j - 100000 * j + i * j, j==mat_size?'\n':' ');
//         }
//     }
//     return 0;
// }
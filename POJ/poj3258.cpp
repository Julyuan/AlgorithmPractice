#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;

const int maxn = 50005;
const int inf = 0x3f3f3f3f;
int L,M,N;
int S;
int D[maxn];
int left, right, mid;
int main(){
 //   freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);


    scanf("%d%d%d",&L,&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&D[i]);
    }
    S = N-M;
    left = 0;
    right = L+1;
    sort(D,D+N);

    while(right - left>1){
        mid = (left+right) >> 1;
    //    printf("mid = %d left = %d, right = %d\n", mid, left, right);
        int cnt = 0,cur = 0;
        for(int i=0;i<N;i++){
            if(D[i]-cur >= mid && L-D[i]>=mid){
                cnt++;
    //            printf("D[%d] = %d\n", i, D[i]);
                cur = D[i];
            }
        }

        if(cnt<S){
            right = mid;
        }else{
            left = mid;
        }
    } 
 //   printf("right = %d, minimum = %d\n", right, minimum);
    printf("%d\n",left);
    return 0;
}
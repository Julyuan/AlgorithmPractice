#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

typedef long long ll;
const long long inf = 0x3f3f3f3f;
const int maxn = 100005;

ll n,k;
ll a[maxn];
int main(){
 //  freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);

    // while(gets(str)){
    //    // printf("str = %s\n",str);
    //     if(strlen(str)<5)
    //         break;
    //     T++;
        scanf("%lld", &n);
        ll left,right,mid;
        right = 0;
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
            if(a[i]>right)
                right = a[i];
        }

        scanf("%lld", &k);
        if(k==1){
            printf("%lld\n",right);
            return 0;
        }
        left = 0;

        while(left<right){
            mid = (left + right) >> 1;
            ll cnt = 0;
            for(int i=0;i<n;i++){
                if(a[i]<=mid)
                    continue;
                cnt += (a[i] - mid - 1) / (k-1) + 1;
            }
            if(cnt > mid){
                left = mid+1;
            }else{
                right = mid;
            }
        }
  //      if(T!=1)
 //           printf("\n");
//        printf("sample output #%d\n",T);
        printf("%lld\n",right);
        // getchar();
        // getchar();
    //}
    return 0;
}
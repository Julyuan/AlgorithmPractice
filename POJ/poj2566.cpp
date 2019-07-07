#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 100005;
typedef pair<int,int> P;
vector<P>sum;
int n,k;
int seq[maxn];
int query[maxn];


void solve(){
    int temp = 0;
    for(int i=0;i<=n;i++){
        temp+=seq[i];
        sum.push_back(make_pair(temp,i));
    }
    sort(sum.begin(),sum.end());

    int start,end;

    for(int iter=0;iter<k;iter++){
        start = 0;
        end = 1;
        int left = 0, right = 1;
        int mingap = inf;
        int ans = 0;
        while(right<=n && mingap!=0){
            int cur = sum[right].first - sum[left].first;
          //  printf("cur = %d\n", cur);
            if(abs(cur-query[iter]) < mingap){
                mingap = abs(cur-query[iter]);
                start = sum[right].second;
                end = sum[left].second;
                ans = cur;
            }
            if(cur>query[iter]){
                left++;
                if(left==right){
                    right++;
                }
            }else{
                right++;
            }   
        }
        if(end<start){
            int temp = start;
            start = end;
            end = temp;
        }
        printf("%d %d %d\n",ans,start+1,end);
    }
}
int main(){
 //   freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);

    while(~scanf("%d%d",&n,&k)){
        if(n==0 && k==0)
            break;
        else{
            sum.clear();
            memset(seq,0,sizeof(seq));
            memset(query,0,sizeof(query));

            for(int i=1;i<=n;i++){
                scanf("%d",&seq[i]);
            }
            for(int i=0;i<k;i++){
                scanf("%d",&query[i]);
            }
            solve();
        }
    }

    return 0;
}
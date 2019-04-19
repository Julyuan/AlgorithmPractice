#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int inf = 2000000005;
typedef pair<int,int> P;
vector<P>calf;
vector<int>svec;
int N,C,F;
int flag;

void solve(){
    sort(svec.begin(), svec.end());
    sort(calf.begin(), calf.end());
    int lb =0,ub = C;
    int cnt1;
    int cnt2;
    int temp_F;

    flag = 0;
    while(lb+1<ub){
        int mid = (lb + ub) >> 1;
        int target = svec[mid];
        temp_F = F;
        cnt1 = cnt2 = 0;
        for(int i=0;i<calf.size();i++){
            P p = calf[i];
            int score = p.second;
            int aid = p.first;
           // printf("score = %d target = %d temp_F = %d aid = %d\n", score, target, temp_F, aid);

            if(score>=target && temp_F>=aid){
             //   printf("127\n");
                cnt1++;
                temp_F -= aid;
            }else if(score<target && cnt2<N/2 && temp_F>=aid){
                cnt2++;
                temp_F -= aid;
            }
            if(cnt1+cnt2==N){
                flag = 1;
                break;
            }
        }
        //printf("cnt1 = %d, cnt2 = %d, mid = %d, target = %d\n", cnt1, cnt2, mid, target);

        if(cnt1+cnt2<N){
            ub = mid;
        }else{
            lb = mid;
        }
    }
    if(!flag)
        printf("-1\n");
    else
        printf("%d\n",svec[lb]);
}
int main(){
 //   freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);

    scanf("%d%d%d",&N,&C,&F);

    for(int i=0;i<C;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        calf.push_back(make_pair(b,a));
        svec.push_back(a);
    }
    solve();

    return 0;
}


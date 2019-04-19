#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

const int maxn = 100005;
const int inf = 0x3f3f3f3f;

int money[maxn];
int N,M;
int max_money = 0;
int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    scanf("%d%d",&N,&M);

    for(int i=0;i<N;i++){
        scanf("%d",&money[i]);
        if(money[i]>max_money){
            max_money = money[i];
        }
    }

    int mid, left = max_money, right = inf;
    int cnt;
    while(right - left > 1){
        mid = (left + right) >> 1;
        cnt = 1;
        int content = mid;
        for(int i=0;i<N;i++){
            if(content >= money[i]){
                content -= money[i];
            }else{
                content = mid-money[i];
                cnt++;
            }
        }
        
        if(cnt > M){
            left = mid;
        }else{
            right = mid;
        }
        //printf("left = %d, right = %d, cnt = %d\n", left, right, cnt);
    }

    int flag;
    cnt = 1;
    int content = left;
    for(int i=0;i<N;i++){
        if(content >= money[i]){
            content -= money[i];
        }else{
            content = left-money[i];
            cnt++;
        }
    }
    if(cnt>M)
        flag = 1;
    else
    {
        flag = 0;
    }
    
    printf("%d\n",flag?right:left);
    return 0;
}
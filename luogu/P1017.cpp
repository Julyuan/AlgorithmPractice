#include<stdio.h>
#include<string.h>

const int maxn = 105;
int N,R;
int flag;
int a[maxn], res[maxn];
int cnt = 0;

void print(int a){
    if(a>=0 && a<10){
        printf("%d",a);
    }else{
        printf("%c",a-10+'A');
    }
}
int main(){
   // freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&R);
    int temp = N;
    if(N<0){
        flag = 1;
        N = -N;

    }else
    {
        flag = 0;
    }
    
    R = -R;
    while(N>0){
        a[cnt++] = N % R;
        N /= R;
    }
    for(int i=0;i<cnt;i++){
        if(a[i]==0)
            continue;
        if((flag + i) % 2 == 0){
            res[i] = a[i]%R;
            a[i+1] += a[i]/R;
        }else{
            res[i] = R - a[i];
            a[i+1]++;
        }
    }
    if(a[cnt]!=0){
        if((flag+cnt) % 2==0){
         //   printf("127\n");
            res[cnt] = a[cnt];
        }else{
           // printf("128\n");
            res[cnt] = R-a[cnt];
            res[cnt+1] = 1;
            ++cnt;
        }
        cnt++;
    }
    printf("%d=",temp);

    for(int i=cnt-1;i>=0;i--){
        print(res[i]);
    }
    printf("(base-%d)\n",R);
    // printf("\n");
    return 0;
}
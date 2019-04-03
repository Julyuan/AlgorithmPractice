#include<stdio.h>
#include<string.h>

const int maxn = 50005 * 4;
int n, dat[maxn];

void init(int n_){
    n = 1;
    while(n<n_){
        n*=2;
    }
    for(int i=0;i<n*2-1;i++)
        dat[i] = 0;
}

void update(int k,int a){
    k+=(n-1);
    dat[k]+=a;
    while(k>0){
        k = (k-1)/2;
        dat[k]+=a;
    }
}

int query(int a, int b, int k, int l, int r){
    if(r<=a || b<= l) return 0;
    if(a<=l && r <= b)return dat[k];
    else{
        int vl = query(a,b,2*k+1,l,(l+r)>>1);
        int vr = query(a,b,2*k+2,(l+r)>>1,r);
        return vl+vr;
    }
}

int main(){
 //   freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);

    int cas = 0;
    scanf("%d",&cas);
    for(int iter=1;iter<=cas;iter++){
        printf("Case %d:\n",iter);
        int N;
        scanf("%d\n",&N);
        init(N);
        for(int i=0;i<N;i++){
            int temp;
            scanf("%d",&temp);
            update(i,temp);
        }
        char str[100];
        
        while(true){
            gets(str);
            if(str[0]=='Q'){
                int b,a;
                sscanf(str,"Query %d %d",&a,&b);
                int res = query(a-1,b,0,0,n);
                printf("%d\n",res);
            }else if(str[0]=='A'){
                int k,a;
                sscanf(str,"Add %d %d",&k,&a);
                update(k-1,a);
            }else if(str[0]=='S'){
                int k,a;
                sscanf(str,"Sub %d %d",&k,&a);
                update(k-1,-a);
            }else if(str[0]=='E'){
                break;
            }
        }
    }
    return 0;
}
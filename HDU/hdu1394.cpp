#include<stdio.h>
#include<string.h>

const int maxn = 5000*4;
int n,sum;
int dat[maxn],N;
int a[maxn];
void init(int n_){
    n = 1;
    while(n<n_)
        n*=2;
    for(int i=0;i<2*n;i++){
        dat[i] = 0;
    }
    sum = 0;
}

void update(int k, int a){
    k+=n-1;
    dat[k]++;
    while(k>0){
        k = (k-1)/2;
        dat[k]++;
    }
}

int query(int a, int b, int k, int l, int r){
  //  printf("k = %d\n",k);
    if(a>=r || b<=l)
        return 0;
    if(a<=l && r <= b)return dat[k];
    else{
        int m = (l+r)>>1;
        int vl =  query(a,b,k*2+1,l,m);
        int vr =  query(a,b,2*k+2,m,r);
        return vl+vr;
    }

}

int main(){
    
    while(scanf("%d",&N)!=EOF){
        init(N);
    // printf("n = %d\n",n);
        int res;
        for(int i=0;i<N;i++){
            int temp;
            scanf("%d",&temp);
            a[i] = temp;
        //    printf("temp = %d\n", temp);
            sum += query(temp+1,n,0,0,n);
            update(temp,0);
        }
        res = sum;
        for(int i=0;i<N-1;i++){
            sum = sum + (N-a[i]-1) - a[i];
        //    printf("sum = %d\n", sum);
            if(sum<res){
                res = sum;
            }
        }

        printf("%d\n",res);
    }
    return 0;
}

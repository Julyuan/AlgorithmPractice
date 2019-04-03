#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

int n,m,k;
int mod;
mat A,I;


mat mul(mat a, mat b){
    mat c(a.size(), vec(b[0].size()));

    for(int i=0;i<a.size();i++){
        for(int j=0;j<b[0].size();j++){
            for(int k=0;k<a[0].size();k++){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
               // printf("12777\n");
            }
        }
    }

    return c;
}


mat pow(mat a,int n){
    mat b(a.size(), vec(a[0].size()));
    for(int i=0;i<a.size();i++){
        b[i][i] = 1;
    }
    while(n>0){
        if(n&1)
            b = mul(b,a);
        a = mul(a,a);
        n >>=1;
       // printf("n = %d\n",n);
    }
    return b;
}

void solve(){
    mod = m;
    mat res = mul(pow(A,k),I);
    mat res1(n,vec(n));
    mat A1(n,vec(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res1[i][j] = res[n+i][j];
            A1[i][j] = A[i][j];
        }
    }
    mat res2 = mul(res1,A1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d%c",res2[i][j],j==n-1?'\n':' ');
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&k,&m);

    A = mat(n*2,vec(n*2));
    I = mat(n*2,vec(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        A[n+i][i] = A[n+i][n+i] = 1;
    }

    // for(int i=0;i<n*2;i++){
    //     for(int j=0;j<n*2;j++){
    //         printf("%d ",A[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int i=0;i<n;i++)
        I[i][i] = 1;
    solve();

    return 0;
}
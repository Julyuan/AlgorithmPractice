#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

const int mod = 10007;
int T,N;

mat mul(mat a, mat b){
    mat c(a.size(), vec(b[0].size()));

    for(int i=0;i<a.size();i++){
        for(int j=0;j<b[0].size();j++){
            for(int k=0;k<a[0].size();k++){
                c[i][j] += (a[i][k] * b[k][j]) % mod;
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
    mat trans(3,vec(3));
    trans[0][0] = 2;
    trans[0][1] = 1;
    trans[0][2] = 0;
    trans[1][0] = 2;
    trans[1][1] = 2;
    trans[1][2] = 2;
    trans[2][0] = 0;
    trans[2][1] = 1;
    trans[2][2] = 2;
    mat ini(3,vec(1));
    ini[0][0] = 0;
    ini[1][0] = 0;
    ini[2][0] = 1;

    mat res = pow(trans,N);
    // for(int i=0;i<3;i++){
    //     printf("%d ",res[i][0]);
    // }
    // printf("\n");
    mat res1 = mul(res,ini);

    printf("%d\n",res1[2][0]);
}

int main(){

    scanf("%d",&T);
    for(int iter=0;iter<T;iter++){
        scanf("%d",&N);
        solve();
    }

    return 0;
}

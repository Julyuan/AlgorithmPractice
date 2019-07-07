#include<string.h>
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>


using namespace std;

int N;
double A;

int main(){
  //  freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);

    scanf("%d%lf",&N,&A);

    double b = -1.0 * sqrt(4*A);
    int x1 = (-b/2.0);  // 找到中轴线两边的点
    int x2 = x1 + 1;    //
    double b1 = 1.0*(-A-x1*x1)/x1;  // 求新的b
    double b2 = 1.0*(-A-x2*x2)/x2;

    double x = N - 1.0;
    if(x<=x2)
        printf("%.2f\n",0.0);
    else
        printf("%.2f\n", (x*x+max(b1,b2)*x+A));    

    return 0;
}
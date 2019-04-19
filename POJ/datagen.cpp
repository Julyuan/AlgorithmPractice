#include<stdio.h>
#include<stdlib.h>

int main(){
    freopen("in.txt","w",stdout);
    printf("100\n");
    for(int i=0;i<100;i++){
        int a = rand()%50000+1;
        int b = rand()%(a*a)+1;
        printf("%d %d\n", a,b);
    }
    return 0;
}
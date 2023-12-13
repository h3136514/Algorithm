#include<cstdio>
int n, r, i;

int main(){
    for(i=0;i<5;i++){
        scanf("%d", &n);
        r = r + (n*n)%10;
    }
    r %=10;
   
    printf("%d", r);
    return 0;
}
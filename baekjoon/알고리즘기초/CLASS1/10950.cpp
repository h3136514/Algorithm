#include<cstdio>
int T, a, b, r;
int main(){
    scanf("%d", &T);
    while(T>0){
        scanf("%d %d", &a, &b);
        r=a+b;
        printf("%d\n", r);
        T--;
    }
   
    return 0;
}
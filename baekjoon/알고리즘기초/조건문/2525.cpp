#include<cstdio>
int a, b, c, h, m;

int main(){
    scanf("%d %d", &a, &b);
    scanf("%d", &c);
    m= c+b; //분 총합
    h= a + (m/60);
    m = m%60;
    if(h>23)
        h=h-24;
    
    printf("%d %d", h, m);

    return 0;
}
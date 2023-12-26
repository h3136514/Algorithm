#include<cstdio>

int A, B, V, day, cnt;

int main(){
    scanf("%d %d %d", &A, &B, &V);
    day = (V - A)/(A - B);
    if((V - A)%(A - B)==0)
        day= day + 1;
    else
        day= day + 2;
    printf("%d\n", day);
    return 0;
}
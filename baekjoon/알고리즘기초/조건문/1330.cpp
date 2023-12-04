#include<cstdio>
int a, b;

int main(){
    scanf("%d %d", &a, &b);
    if(a>b)
        printf(">");
    else if(a<b)
        printf("<");
    else
        printf("==");

    return 0;
}
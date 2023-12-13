#include<cstdio>
int a;

int main(){
    scanf("%d", &a);
    if(a%4==0 && a%100 !=0)
        printf("1");
    else if(a%400==0)
        printf("1");
    else
        printf("0");

    return 0;
}
#include<cstdio>
int num, i;

int main(){
    scanf("%d", &num);
    num /= 4;
    for(i=0;i<num;i++)
        printf("long ");
    printf("int");
    
    return 0;
}
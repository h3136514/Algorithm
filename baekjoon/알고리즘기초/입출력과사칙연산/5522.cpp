#include<cstdio>
int num, i, sum;

int main(){
    for(i=0;i<5;i++){
        scanf("%d\n", &num);
        sum+=num;
    }
    printf("%d\n",sum);
    return 0;
}
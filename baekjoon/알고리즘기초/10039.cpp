#include<cstdio>
int i, num, sum;

int main(){
    for(i=0;i<5;i++){
        scanf("%d", &num);
        if(num<40)
            num = 40;
        sum +=num;
    }
    printf("%d\n", sum/5);
    return 0;
}
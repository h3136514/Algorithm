#include<cstdio>
int i, N, tmp, count;
int main(){
    scanf("%d", &N);
    for(i=1;i<=N;i++){
        tmp=i;
        while(true){
            if((tmp%10)== 3 || (tmp%10)== 6 || (tmp%10)== 9) //3, 6, 9판별
                count++;
            tmp = tmp/10;
            if(tmp == 0)
                break;
        }
        if(count == 0)
            printf("%d",i);
        else
            while(count>0)
            {
                printf("-");
                count--;
            }
        printf(" ");
    }
    return 0;
}
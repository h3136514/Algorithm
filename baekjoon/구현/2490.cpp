#include<cstdio>
int num, cnt, i, j;

int main() {
    while(3 > i++){
        cnt=0;
        for(j=0;j<4;j++){
            scanf("%d", &num);
            if(!num)
                cnt++;
        }
        if(cnt==4)
            printf("D\n");
        else if(cnt==3)
            printf("C\n");
        else if(cnt==2)
            printf("B\n");
        else if(cnt==1)
            printf("A\n");
        else
            printf("E\n");
    }
    return 0;
}
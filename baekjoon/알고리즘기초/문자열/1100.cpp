#include<cstdio>
#include<cstring>
char str[8][9];
int i, j, check, cnt;

int main(){
    for(i=0;i<8;i++){
        scanf("%s", &str[i]);
    }
    
    for(i=0;i<8;i++){
        //홀수번째면 처음에 하얀칸 (시작점 설정)
        if((i+1)%2 == 1)
            check = 1;
        else
            check = 0;

        for(j=0;j<8;j++){
            if(check){   
                if(str[i][j]=='F')
                    cnt++;
                check = 0;
            }else
                check = 1;
        }
    }
        printf("%d\n", cnt);
    return 0;
}
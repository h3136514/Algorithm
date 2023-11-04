#include<cstdio>
int T, i , j, k, N[11], num[11][7][7];

int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d", &N[i]);
        for(j=0;j<N[i];j++){
            for(k=0;k<N[i];k++){
                scanf("%d", &num[i][j][k]);
            }
        }
    }
    for(i=1;i<=T;i++){
        printf("#%d\n", i);
        for(j=0;j<N[i];j++){
             //90도 회전
            for(k=N[i]-1;k>=0;k--){
                printf("%d",num[i][k][j]);
            }
            printf(" ");
            //180도 회전
            for(k=N[i]-1;k>=0;k--){
                printf("%d",num[i][N[i]-1-j][k]);
            }
            printf(" ");
            //270도 회전
            for(k=0;k<N[i];k++){
                printf("%d",num[i][k][N[i]-1-j]);
            }
            printf("\n");
        }

    }

    return 0;
}
#include<cstdio>

int T, N, i, j, k, num[100][100], result[11], r;

int main(){
    for(i=1;i<=10;i++){
        scanf("%d", &N);
        for(j=0;j<N;j++)
            for(k=0;k<N;k++)
                scanf("%d", &num[j][k]);

        for(j=0;j<N;j++){
            r=0;
            for(k=0;k<N;k++){
                if(r==1){
                    if(num[k][j]==2){
                        result[i]++;
                        r=0; 
                    }
                }
                if(r==0){
                    if(num[k][j]==1)
                        r=1;
                }
            }
        }
    }
    for(i=1;i<=10;i++){
        printf("#%d %d\n",i, result[i]);
    }
    return 0;
}
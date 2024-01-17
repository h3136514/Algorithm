#include<cstdio>
int N, x, y, i, j, cnt, num[50][2], result[50];

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d %d", &num[i][0], &num[i][1]);
    }
    for(i=0;i<N;i++){
        cnt=0;
        for(j=0;j<N;j++){
            if(i==j)
                continue;
            if(num[i][0]<num[j][0] && num[i][1]<num[j][1])
                cnt++;
        }
        result[i]=++cnt;
    }
    for(i=0;i<N;i++)
        printf("%d ",result[i]);
    printf("\n");

    return 0;
}
#include<cstdio>
int N, M, i, j, cnt, tmp, num[101];

int main(){
    scanf("%d %d", &N, &M);
    for(cnt=1;cnt<=N;cnt++){
        num[cnt]=cnt;
    }
    for(cnt=1;cnt<=M;cnt++){
        scanf("%d %d", &i, &j);
        tmp=num[i];
        num[i]=num[j];
        num[j]=tmp;
    }
    for(cnt=1;cnt<=N;cnt++){
        printf("%d ",num[cnt]);
    }
    printf("\n");
    return 0;
}
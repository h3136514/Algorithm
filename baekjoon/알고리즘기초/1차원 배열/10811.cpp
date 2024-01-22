#include<cstdio>
int N, M, i, j, cnt1, cnt2, tmp, num[101];

int main(){
    scanf("%d %d", &N, &M);
    for(cnt1=1;cnt1<=N;cnt1++){
        num[cnt1]=cnt1;
    }
    for(cnt1=1;cnt1<=M;cnt1++){
        scanf("%d %d", &i, &j);
        for(cnt2=0;cnt2<=(j-i)/2;cnt2++){
            tmp=num[i+cnt2];
            num[i+cnt2]=num[j-cnt2];
            num[j-cnt2]=tmp;
        }
    }

    for(cnt1=1;cnt1<=N;cnt1++){
        printf("%d ",num[cnt1]);
    }
    printf("\n");


    return 0;
}
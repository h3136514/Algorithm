#include<cstdio>
int N, num[4], i, a, b, tmp;

int main() {
    num[1] = 1;
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d %d", &a, &b);
        tmp = num[a];
        num[a] = num[b];
        num[b] = tmp;
    }

    for(i=1;i<4;i++){
        if(num[i]){
            printf("%d\n",i);
            break;
        }
    }
    if(i==4)    //공이 컵 밑에 없는 경우
         printf("-1\n");

    return 0;
}
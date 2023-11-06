#include<cstdio>

int T, N, R, i, j, count, min, best[21], num[21];

int main(){
    scanf("%d", &T);
     //초기화
    for(i=1;i<=T;i++){
        best[i] = 100001;
    }
    for(i=1;i<=T;i++){
        scanf("%d", &N);
        for(j=0;j<N;j++){
            scanf("%d", &R);
            if(R<0)
                R=-R;
            if(best[i] > R){
                best[i] = R;
                count=1;
            }else if(best[i] == R)
                count++;
            }
            num[i]=count;
            count=0;
    }
    for(i=1;i<=T;i++){
        printf("#%d %d %d\n", i, best[i], num[i]);
    }
    return 0;
}

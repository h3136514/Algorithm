#include<cstdio>
int T, N, K, i, j, l, count, result[11], num[16][16];
void init(){
    count=0;
    for(j=0;j<N;j++){
        for(l=0;l<N;l++){
                num[j][l]=0;
            }
        }
}

int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        init();
        scanf("%d", &N);
        scanf("%d", &K);
        for(j=0;j<N;j++){
            for(l=0;l<N;l++){
                scanf("%d", &num[j][l]);
            }
        }
        //가로 줄 검사
        for(j=0;j<N;j++){
            count=0;
            for(l=0;l<N;l++){
                if(num[j][l] == 1)   //흰색일때
                    count++;
                else    //검은색일때
                    count=0;
                
                if(count == K)
                    result[i]++;
                if(count == K+1)
                    result[i]--;
      
            }
        }
        //세로 줄 검사
        for(l=0;l<N;l++){
            count=0;
            for(j=0;j<N;j++){
                if(num[j][l] == 1)   //흰색일때1
                    count++;
                else    //검은색일때
                    count=0;

                if(count == K)
                    result[i]++;
                if(count == K+1)
                    result[i]--;
  
            }
        }
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n", i, result[i]);
    }

    return 0;
}
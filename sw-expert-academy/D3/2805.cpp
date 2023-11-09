#include<cstdio>

int T, N, i, j, k, mid, num[50][50], sum[51];
char numstr[50][51];

int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d",&N);
        for(j=0;j<N;j++){
            for(k=0;k<=N;k++)   //공백 주의(k<=N, 0인덱스는 아스키코드 10(LF) ( Line Feed => 다음 줄로))
            {  
                scanf("%c",&numstr[j][k]);
                num[j][k]=numstr[j][k]-'0'; //문자 => 정수
            }
        }
        mid=N/2;
        for(j=0;j<=mid;j++){
            for(k=mid-j+1;k<=mid+j+1;k++){
                sum[i]+=num[j][k];
            }
        }
        for(j=mid+1;j<N;j++){
            for(k=j-mid+1;k<=mid+(N-j);k++){
                sum[i]+=num[j][k];
            }
        }
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n",i,sum[i]);
    }
    return 0;
}

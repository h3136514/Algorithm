#include<cstdio>
int N, num[101], i, sum, cnt;

int main() {
    scanf("%d", &N);
    for(i=1;i<=N;i++)
        scanf("%d", &num[i]);
    for(i=1;i<=N;i++){
        if(num[i]){
            cnt++;
            if(!num[i-1]){
                cnt = 1;
            }
            sum += cnt;
        }
    
    }
    printf("%d\n", sum);
  
    return 0;
}
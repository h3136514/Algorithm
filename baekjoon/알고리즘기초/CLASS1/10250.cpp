#include<cstdio>
int T, H, H1, W, W1, N;

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &H, &W, &N);
        if(N%H == 0){
            H1=H;
            W1 = N/H;
        }
        else{
            H1 = N%H;
            W1 = N/H + 1;
        }
            
        printf("%d", H1);
        if(W1<10)
            printf("0%d", W1);
        else
            printf("%d", W1);
        printf("\n");
    }
    return 0;
}
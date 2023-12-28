#include<cstdio>
int N, i, n, num[10001]; //int형은 4바이트, 8MB(1024*1024B(1024KB)*8)/4= 약200만개 가능

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &n);
        num[n]++;
    }
    for(int i=1;i<10001;i++){
        if(num[i]==0)
            continue;
        while(true){
            if(num[i]==0)
                break;
            printf("%d\n", i);
            num[i]--;
        }
        
    }
    return 0;
}

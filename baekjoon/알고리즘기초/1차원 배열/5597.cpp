#include<cstdio>
int N, i, num[31];

int main(){
    for(i=0;i<28;i++){
        scanf("%d", &N);
        num[N] = 1;
    }
     for(i=1;i<=30;i++){
        if(!num[i])
            printf("%d\n",i);
     }
    
   
    return 0;
}
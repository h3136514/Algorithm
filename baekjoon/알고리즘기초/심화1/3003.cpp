#include<cstdio>
int i, input[6], num[6]={1, 1, 2, 2, 2, 8};

int main(){
    for(i=0;i<6;i++){
        scanf("%d", &input[i]);
    }
    for(i=0;i<6;i++){
        printf("%d ",num[i] - input[i]);
    }
    return 0;
}
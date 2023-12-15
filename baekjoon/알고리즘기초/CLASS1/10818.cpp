#include<cstdio>
int N, num, i, min, max;

int main(){
    min = 1000001;
    max = -1000001;
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d", &num);
        if(min > num)
            min = num;
        if(max < num)
            max = num;
    }
    printf("%d %d\n", min, max);
    return 0;
}
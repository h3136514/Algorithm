#include<cstdio>
int N, i, sum, check, min =100;

int main() {
    for(i=0;i<7;i++){
        scanf("%d", &N);
        if(N%2 != 0){
            sum += N;
            if(N < min)
                min = N;
        }
        else
            check++;
    }
    if(check == 7)
        printf("-1\n");
    else {
        printf("%d\n", sum);
        printf("%d\n", min);
    }

    return 0;
}
#include<cstdio>
int A,B;

int main(){
    while(true){
        scanf("%d %d", &A, &B);
        if(A==0 && B==0)
            break;
        printf("%d\n", A+B);
    }
    return 0;
}
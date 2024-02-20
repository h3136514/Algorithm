#include<cstdio>
int A, B, C;

int main(){
    scanf("%d %d %d", &A, &B, &C);
    if(A+B+C != 180){
        printf("Error\n");
    }else{
        if(A==60 && B==60 && C==60)
            printf("Equilateral\n");
        else{
            if(A==B || A==C || B==C)
                printf("Isosceles\n");
            else
                printf("Scalene\n");
        }
    }
    return 0;
}
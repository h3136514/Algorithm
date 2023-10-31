#include<cstdio>
int A, B;
int main(){
    scanf("%d", &A);
    scanf("%d", &B);
    switch (A)
    {
    case 1:
        if(B==2)
            printf("B");
        else
            printf("A");
        break;
    case 2:
        if(B==1)
            printf("A");
        else
            printf("B");
        break;
    default:
        if(B==1)
            printf("B");
        else
            printf("A");
        break;
    }

    return 0;
}
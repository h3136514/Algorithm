#include<cstdio>
int M, D;

int main() {
    scanf("%d", &M);
    scanf("%d", &D);
    if(M < 2)
        printf("Before\n");
    else if(M == 2) {
        if(D == 18)
            printf("Special\n");
        else if(D < 18)
            printf("Before\n");
        else
            printf("After\n");
    }else {
        printf("After\n");
    }

    return 0;
}
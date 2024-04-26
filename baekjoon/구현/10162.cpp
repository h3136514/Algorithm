#include<cstdio>
int A, B, C, T;

int main() {
    scanf("%d", &T);
    A = T/300;
    T = T%300;
    B = T/60;
    T = T%60;
    C = T/10;
    T = T%10;
    if(T) {
        printf("-1\n");
    } else {
        printf("%d %d %d\n", A, B, C);
    }

    return 0;
}
#include<cstdio>
int L, P, i, num, r[5];

int main() {
    scanf("%d %d", &L, &P);
    for(i=0;i<5;i++) {
        scanf("%d", &num);
        r[i]= num - L*P;
    }
    for(i=0;i<5;i++) {
        printf("%d ", r[i]);
    }
    printf("\n");

    return 0;
}
#include<cstdio>
int A, B, R, r1, r2, r3;

int main(){
    scanf("%d %d", &A, &B);
    r1=(B%10) * A;
    B = B/10;
    r2= (B%10) * A;
    B = B/10;
    r3 =A * B;
    R= r1 + r2*10 +r3*100;
    printf("%d\n", r1);
    printf("%d\n", r2);
    printf("%d\n", r3);
    printf("%d\n", R);
    return 0;
}
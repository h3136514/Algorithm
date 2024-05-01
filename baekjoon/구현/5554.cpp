#include<cstdio>
int a, b, c, d, sum, x, y;

int main() {
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    
    sum = a + b + c + d;
        
    printf("%d\n", sum/60);
    printf("%d\n", sum%60);

    return 0;
}
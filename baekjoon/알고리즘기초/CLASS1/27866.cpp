#include<cstdio>
int n;
char c[1001];

int main(){
    scanf("%s", &c);
    scanf("%d", &n);
    printf("%c", c[n-1]);
    return 0;
}
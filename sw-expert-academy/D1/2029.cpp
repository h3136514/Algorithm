#include<cstdio>
int T, i, a, b, share[4], rest[4];

int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d", &a);
        scanf("%d", &b);
        share[i] = a/b;
        rest[i] = a%b;
    }
    for(i=1;i<=T;i++)
        printf("#%d %d %d\n", i, share[i], rest[i]);
        
    return 0;
}
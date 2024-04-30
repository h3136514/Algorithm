#include<cstdio>
int S, T, i, num;

int main() {
    for(i=0;i<4;i++) {
        scanf("%d", &num);
        S += num;
    }
    for(i=0;i<4;i++) {
        scanf("%d", &num);
        T += num;
    }
    if(S > T)
        printf("%d\n", S);
    else
        printf("%d\n", T);
        
    return 0;
}
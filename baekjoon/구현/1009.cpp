#include<cstdio>
int T, i, a, b;

int main() {
    scanf("%d", &T);
    while(0 < T--) {
        scanf("%d %d", &a, &b);
        int result = a;
        for(i=2;i<=b;i++) {
            result = (result*a)%10;
            if(result == 0)
                result = 10;
        }
        
        printf("%d\n",result);
    }
    return 0;
}
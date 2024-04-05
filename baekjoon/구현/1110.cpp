#include<cstdio>
int N, i, num, cnt, a, b;

int main() {
    scanf("%d", &N);
    num = N;
    while(true) {
        if(num == N && cnt >0 ){
            break;
        }
        a = num / 10;
        b = num % 10;
        num = b*10 + (a+b)%10;
        
        cnt++;
    }

    printf("%d\n",cnt);
    return 0;
}
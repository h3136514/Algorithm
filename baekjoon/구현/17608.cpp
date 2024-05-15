#include<cstdio>
int N, num[100000], i, max, cnt;

int main() {
    scanf("%d", &N);
    for(i=0;i<N;i++)
        scanf("%d", &num[i]);
    for(i=N-1;i>=0;i--){
        if(max < num[i]){
            max = num[i];
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
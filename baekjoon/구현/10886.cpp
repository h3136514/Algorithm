#include<cstdio>
int N, agree, i, cnt;

int main() {
    scanf("%d", &N);
    for(i=0;i<N;i++) {
        scanf("%d", &agree);
        if(agree)
            cnt++;
    }
    if(cnt > N/2)
        printf("Junhee is cute!\n");
    else
        printf("Junhee is not cute!\n");
    
    return 0;
}
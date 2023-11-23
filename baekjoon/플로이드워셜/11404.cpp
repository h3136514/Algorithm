#include<cstdio>
#define INF 1000000000 

int n, d[101][101], i, j, k, l;
int main(){
    scanf("%d %d", &n, &i);
    for(j = 1; j <= n; j++) {
        for (k = 1; k <= n; k++) {
            if(j==k)
                d[j][k] =0; //자기 자신안감
            else
                d[j][k] = INF;
        }
    }
    while (i--) {
        scanf("%d %d %d", &j, &k, &l);
        if (d[j][k] > l) {
            d[j][k] = l; //최솟값 갱신
        }
    }
    //플로이드-워셜 알고리즘
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    //출력
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if(d[i][j] >= INF)
                printf("0 ");
            else
                printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    return 0;
}
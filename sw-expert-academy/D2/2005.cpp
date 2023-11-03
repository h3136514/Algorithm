#include<cstdio>

int T, N, i, j, k, num[11], pascal[11][11]={{1}, {1, 1}};
//파스칼 삼각형 만들기
void pascal_tree(){
    for(i=2;i<10;i++){
        pascal[i][0]=1;
        for(j=1;j<=i+1;j++){
             pascal[i][j] =pascal[i-1][j-1] + pascal[i-1][j];
        }
    }
}

int main(){
    pascal_tree();
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d", &num[i]);
    }
    for(i=1;i<=T;i++){
        printf("#%d\n", num[i]);
        for(j=0;j<num[i];j++){
            for(k=0;k<j+1;k++)
                printf("%d ", pascal[j][k]);
            printf("\n");
        }
    }
    return 0;
}
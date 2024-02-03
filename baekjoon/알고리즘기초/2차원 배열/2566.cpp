#include<cstdio>
int i, j, num, row, col, max;

int main(){
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            scanf("%d", &num);
            if(num >= max){
                max = num;
                row = i+1;
                col = j+1;
            }
        }
    }
    printf("%d\n", max);
    printf("%d %d\n", row, col);
    return 0;
}
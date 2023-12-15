#include<cstdio>
int num, i, indx, max;

int main(){
    max = -1;
    for(i=1;i<10;i++){
        scanf("%d", &num);
        if(max < num){
            max = num;
            indx = i;
        }
    }
    printf("%d\n", max);
    printf("%d\n", indx);
    return 0;
}
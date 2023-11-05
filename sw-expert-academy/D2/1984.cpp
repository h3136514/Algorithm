#include<cstdio>
#include<cmath>

int T, i, j, num, max, min, avg[11];
double sum;

int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d", &num);
        sum=max=min=num;
        for(j=0;j<9;j++){
            scanf("%d", &num);
            if(max < num)
                max=num;
            if(min > num)
                min =num;
            sum+=num;
        }
        sum = sum - max - min;
        avg[i] = round(sum/8); 
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n", i, avg[i]);
    }
    return 0;
}
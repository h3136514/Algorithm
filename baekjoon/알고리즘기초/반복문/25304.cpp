#include<cstdio>
int i, n, price, num, sum, sum2;

int main(){
    scanf("%d", &sum);
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d %d", &price ,&num);
        sum2 +=price*num;
    }
    if(sum == sum2)
        printf("Yes");
    else
        printf("No");

    return 0;
}
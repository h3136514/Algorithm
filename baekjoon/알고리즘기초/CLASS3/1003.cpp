#include<cstdio>
int N, num, i, j, one[41], zero[41];
int main(){
    scanf("%d", &N);
    one[1]=1;
    zero[0]=1;
    zero[1]=0;
    for(i=0;i<N;i++){
        scanf("%d", &num);
        for(j=2;j<=num;j++){
            one[j]=one[j-1]+one[j-2];
            zero[j]=zero[j-1]+zero[j-2];
        }
        printf("%d %d\n",zero[num], one[num]);

    }

    return 0;
}
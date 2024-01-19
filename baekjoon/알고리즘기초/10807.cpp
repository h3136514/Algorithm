#include<cstdio>
int N, v, i, input, result, num[201]; 

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d", &input);
        if(input < 0)
            num[100 -input]++;
        else
             num[input]++;
    }
    scanf("%d", &input);
     if(input < 0)
            result = num[100 -input];
        else
            result = num[input];
    printf("%d\n",result);
    return 0;
}
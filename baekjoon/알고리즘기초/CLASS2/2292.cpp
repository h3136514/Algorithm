#include<cstdio>
int N, i, r;

int main(){
    scanf("%d", &N);
    while(N>0){
        N -= 6 * i++; 
        r++;
        if(N==1)
            break;       
    }
    printf("%d", r);
    return 0;
}
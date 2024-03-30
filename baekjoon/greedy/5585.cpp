#include<cstdio>
int N, r, cnt;

int main(){
    scanf("%d", &N);
    r= 1000 - N;
    if(r>=500){
        cnt  += r/500;
        r -= 500*(r/500); 
    }
    if(r>=100){
        cnt  += r/100;
        r -= 100*(r/100); 
    }
    if(r>=50){
        cnt  += r/50;
        r -= 50*(r/50); 
    }
    if(r>=10){
        cnt  += r/10;
        r -= 10*(r/10); 
    }
    if(r>=5){
        cnt  += r/5;
        r -= 5*(r/5); 
    }
    cnt += r;
    printf("%d\n", cnt);
        
    return 0;
}
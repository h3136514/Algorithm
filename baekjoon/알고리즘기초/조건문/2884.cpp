#include<cstdio>
int H, M;

int main(){
    scanf("%d %d", &H, &M);
    if(45<=M)
        M -=45;
    else if(H==0){
        H = 23;
        M +=60;
        M -=45;
    }
    else{
        H -=1;
        M +=60;
        M -=45;
    }
    printf("%d %d", H, M);

    return 0;
}
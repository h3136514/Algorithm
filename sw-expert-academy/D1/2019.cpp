#include<cstdio>
int num, i=1;

int main(){
    scanf("%d",&num);
    while(num>=0){
        printf("%d ",i);
        i =i*2;
        num--;
    }
    return 0;
}
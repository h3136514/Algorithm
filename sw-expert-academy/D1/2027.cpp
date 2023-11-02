#include<cstdio>
int i, j;

int main(){
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(i==j)
                printf("#");
            else
                printf("+");
        }
        printf("\n");
    }
    return 0;
}
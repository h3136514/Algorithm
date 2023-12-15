#include<cstdio>
int A,B;

int main(){
    while(true){
        int x = scanf("%d %d", &A, &B); //ctrl + z(EOF)를 눌렀는지
        if(x == EOF)
            break;
        printf("%d\n", A+B);
    }
    return 0;
}
#include<cstdio>
int num1, num2, i;
bool a, b;
int main(){
    while(true){
        a= false;
        b= false;
        scanf("%d %d", &num1, &num2);
        if(num1==0 && num2==0)
            break;
        if(num1 < num2 && num2%num1 == 0)
            a= true;
        else if(num1 > num2 && num1%num2 == 0)
            b= true;
        if(a)
            printf("factor\n");
        else if(b)
            printf("multiple\n");
        else
            printf("neither\n");
    }
    return 0;
}
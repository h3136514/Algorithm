#include<cstdio>
int num, num1, i;
bool asc, desc;

int main(){
    scanf("%d", &num);
    for(i=1;i<8;i++){
        scanf("%d", &num1);
        if(num < num1)
            asc = true;
        else
            desc = true;
        num = num1;
    }
    if(asc && desc)
        printf("mixed");
    else if(asc)
        printf("ascending");
    else
        printf("descending");
    return 0;
}
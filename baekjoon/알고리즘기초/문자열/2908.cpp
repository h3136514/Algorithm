#include<cstdio>
char  str1[4], str2[4];
int i, num1, num2;

int main(){
    scanf("%s %s", &str1, &str2);
    for(i=2;i>=0;i--){
        num1 += (str1[i]- '0');
        num1 *=10;
        num2 += (str2[i]- '0');
        num2 *=10;
    }
    
    if(num1 < num2){
        for(i=2;i>=0;i--){
            printf("%c", str2[i]);
        } 
    } else{
        for(i=2;i>=0;i--){
            printf("%c", str1[i]);
        }
    }     
    return 0;
}
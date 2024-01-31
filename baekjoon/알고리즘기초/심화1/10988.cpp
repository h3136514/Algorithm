#include<cstdio>
#include<cstring>
int i, mid, check=1;
char str[101]; 

int main(){
    scanf("%s", &str);
    if(strlen(str)%2 == 0)
        mid = strlen(str)/2 - 1;
    else
        mid = strlen(str)/2;
    for(i=0;i<=mid;i++){
        if(str[i] != str[strlen(str)-1-i])
        {
            check =0;
            break;
        }
    }
    printf("%d\n", check);
    
    return 0;
}
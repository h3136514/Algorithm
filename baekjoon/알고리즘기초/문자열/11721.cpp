#include<cstdio>
#include<cstring>
int i, j;
char str[101]; 

int main(){
    scanf("%s", &str);
    for(i=0;i<strlen(str);i+=10){
        for(j=i;j<i+10;j++){
            if(j>=strlen(str))
                break;
            printf("%c",str[j]);
        }
        printf("\n");
    }
    return 0;
}
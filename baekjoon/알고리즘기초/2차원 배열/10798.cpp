#include<cstdio>
#include<cstring>
int i, j;
char str[5][16]; 

int main(){
    for(i=0;i<5;i++)
        scanf("%s", &str[i]);
    for(i=0;i<15;i++){
        for(j=0;j<5;j++){
            if(strlen(str[j]) - 1 < i)
                continue;
             printf("%c",str[j][i]);
        }
    }
    printf("\n");
    return 0;
}
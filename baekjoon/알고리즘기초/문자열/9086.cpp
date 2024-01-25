#include<cstdio>
#include<cstring>
int T;
char str[1001]; 

int main(){
    scanf("%d", &T);
    while(0 < T--){
        scanf("%s", &str);
        printf("%c%c\n", str[0], str[strlen(str)-1]);
    }
    return 0;
}
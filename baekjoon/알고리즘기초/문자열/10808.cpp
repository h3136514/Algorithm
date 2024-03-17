#include<cstdio>
#include<cstring>
char str[101]; 
int i, N[26];

int main(){
    scanf("%s", &str);
    for(i=0;i<strlen(str);i++){
        int alp =str[i] - 97;
        N[alp]++;
    }
    for(i=0;i<26;i++){
        printf("%d ", N[i]);
    }
    printf("\n");

    return 0;
}
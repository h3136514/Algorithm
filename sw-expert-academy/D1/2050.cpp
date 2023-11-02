#include<cstdio>
#include<cstring>

int i, len;
char alphabet[200];

int main(){
    scanf("%s",&alphabet);
    len=strlen(alphabet);
    for(i=0;i<len;i++){
        printf("%d ",alphabet[i]-64);
    }
    return 0;
}
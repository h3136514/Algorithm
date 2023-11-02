#include<cstdio>
#include<cstring>   //strlen()사용

char headline[80];
int i, len;
int main(){
    scanf("%s",&headline);
    len=strlen(headline);
    for(i=0;i<len;i++){
        if('a'<=headline[i] && 'z'>=headline[i])
            headline[i] -=32;  //대문자, 소문자 아스키코드값 차이가 32
    }
    printf("%s",headline);
    return 0;
}
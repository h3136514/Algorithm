#include<cstdio>
#include<cstring>
int i, indx, alp[26];
char S[101];

int main(){
    //초기화
    for(i=0;i<26;i++){
        alp[i] =-1;
    }
    scanf("%s", &S);
    int len =strlen(S);
    for(i=0;i<len;i++){
        indx=S[i] - 97; //a의 아스키코드가 97이므로
        if(alp[indx]>=0)
            continue;
        alp[indx] =i;
    }
    for(i=0;i<26;i++){
        printf("%d ", alp[i]);
    }
    return 0;
} 
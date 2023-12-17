#include<cstdio>
#include<cstring>
int i, indx, max, alp[26];
char C, S[1000001];

int main(){
    scanf("%s", &S);
    int len =strlen(S);
    for(i=0;i<len;i++){
        indx=S[i];
        if(indx >= 97)
            indx -= 97; //a의 아스키코드가 97이므로
        else
            indx -= 65; //A의 아스키코드가 65이므로
        alp[indx]++;
        if(alp[indx] == max){   // 알파벳이 여러개 존재할 경우
            C = '?';
            continue;
        }else if(alp[indx] > max ){
            max =  alp[indx];
            C = 'A' + indx;
        }
    }
    printf("%c", C);
    
    return 0;
} 
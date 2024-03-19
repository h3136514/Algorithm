#include<cstdio>
#include<cstring>
char str[50][51];
char result[50];
int N, i, j, size;

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++)
        scanf("%s", &str[i]);
    size = strlen(str[0]);
    for(i=1;i<N;i++){
        for(j=0;j<size;j++){
            if(result[j]=='?')
                continue;
            if(str[i-1][j] == str[i][j]){
                result[j] = str[i][j];
            }
            else{
                result[j]='?';
            }
        }
    }
    if(N==1){
        printf("%s\n", str[0]);
    }else
        printf("%s\n", result);
    return 0;
}
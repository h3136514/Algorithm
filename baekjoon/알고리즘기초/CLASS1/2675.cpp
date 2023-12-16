#include<cstdio>
#include<cstring>
int T, i, j, num;
char S[21];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %s", &num, &S);
        int len = strlen(S);
        for(i=0;i<len;i++){
            for(j=0;j<num;j++){
                printf("%c", S[i]);
            }
        }
        printf("\n");
    }
    return 0;
}